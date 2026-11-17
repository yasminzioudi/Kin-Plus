#include "kine.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QString>
#include <QDate>
#include <QTableWidget>
#include "mainwindow.h"
#include <QtCharts>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QComboBox>

#include <windows.h>
#include <iostream>
#include <string>
#include <CommCtrl.h> // Ajoutez cette ligne pour inclure CommCtrl.h

kine::kine()
{
    nom="";
    prenom="";
    sexe="";
    tel=0;
    date_n="";
    image=QByteArray();
    specialite="";
    cv="";

}
kine::kine(QString nom,QString prenom,QString sexe,int tel,QString date_n,QByteArray image,QString specialite,QString cv)
{
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->tel=tel;
    this->date_n=date_n;
    this->image=image;
    this->specialite=specialite;
    this->cv=cv;


}
bool kine::ajouter_kine()
{

        QSqlQuery query_Insert;
        query_Insert.prepare("INSERT INTO KINE (NOM,PRENOM,SEXE,TEL,DATE_N,IMAGE,SPECIALITE,CV) VALUES (:nom,:prenom,:sexe,:tel,:date_n,:image,:specialite,:cv)");
        query_Insert.bindValue(":nom",nom);
        query_Insert.bindValue(":prenom",prenom);
        query_Insert.bindValue(":sexe",sexe);
        query_Insert.bindValue(":tel",tel);
        query_Insert.bindValue(":date_n",date_n);
        query_Insert.bindValue(":image",image);
        query_Insert.bindValue(":specialite",specialite);
        query_Insert.bindValue(":cv",cv);
        return query_Insert.exec();






}

bool kine::deleteFromDatabase() {
   QSqlQuery query;
   query.prepare("DELETE FROM KINE WHERE ID = :id");
   query.bindValue(":id",id);
   if(!query.exec()) {
       qDebug() << "Erreur de suppression : " << query.lastError();
       return false;

   }
   return true;
}
void kine::setId( int id) {
   this->id = id;
}
bool kine::modifier(int id, QByteArray imageData) {

   QSqlQuery query;
   query.prepare("UPDATE KINE SET PRENOM = :prenom, NOM = :nom, TEL = :tel, DATE_N = :date_n, SEXE = :sexe, IMAGE = :imageData, SPECIALITE= :specialite, CV= :cv WHERE ID = :id"); // Ajoutez IMAGE = :image
   query.bindValue(":prenom", prenom);
   query.bindValue(":nom", nom);
   query.bindValue(":tel", tel);
   query.bindValue(":date_n", date_n);
   query.bindValue(":sexe", sexe);
   query.bindValue(":specialite",specialite);
   query.bindValue(":cv",cv);
    query.bindValue(":imageData", imageData); // Ajoutez cette ligne
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur : " << query.lastError();
       return false;
   }

   return true;
}
void kine::displayTable(QTableWidget *table, bool test)
{
    Connection c;
    if (test) {

        qDebug() << "Connexion établie";
        QSqlDatabase::database().transaction();
        QSqlQuery Query_Get_Data(c.get_db());
        Query_Get_Data.prepare("SELECT * FROM KINE");

        if (Query_Get_Data.exec()) {
            int currentRow = 0;


                table->setRowCount(10);
                qDebug() <<Query_Get_Data.size();

            while (Query_Get_Data.next()) {
                    table->setRowCount(currentRow+1);
                    QByteArray imageData = Query_Get_Data.value("IMAGE").toByteArray();
                        QPixmap image;
                        image.loadFromData(QByteArray::fromBase64(imageData), "PNG");


                        QPixmap circularImage(image.size());
                        circularImage.fill(Qt::transparent);
                        QPainter painter(&circularImage);
                        QPainterPath path;
                        path.addEllipse(image.rect());
                        painter.setClipPath(path);
                        painter.drawPixmap(0, 0, image);


                        QLabel *imageLabel = new QLabel;
                        imageLabel->setPixmap(circularImage.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                        table->setCellWidget(currentRow, 1, imageLabel);
                    QTableWidgetItem *item = new QTableWidgetItem(Query_Get_Data.value("ID").toString());
                    QTableWidgetItem *item1 = new QTableWidgetItem(Query_Get_Data.value("NOM").toString());
                    QTableWidgetItem *item2 = new QTableWidgetItem(Query_Get_Data.value("PRENOM").toString());
                    QTableWidgetItem *item5 = new QTableWidgetItem(Query_Get_Data.value("SEXE").toString());
                    QTableWidgetItem *item6 = new QTableWidgetItem(Query_Get_Data.value("TEl").toString());
                    QTableWidgetItem *item7 = new QTableWidgetItem(Query_Get_Data.value("DATE_N").toString());
                    QTableWidgetItem *item8 = new QTableWidgetItem(Query_Get_Data.value("SPECIALITE").toString());
                    QTableWidgetItem *item9 = new QTableWidgetItem(Query_Get_Data.value("CV").toString());
                    // Assurez-vous que le tableau peut contenir la nouvelle ligne

                    table->setItem(currentRow,0, item);
                    table->setItem(currentRow,3, item1);
                    table->setItem(currentRow,2, item2);
                    table->setItem(currentRow,6, item5);
                    table->setItem(currentRow,5, item6);
                    table->setItem(currentRow,4, item7);
                    table->setItem(currentRow,7,item8);
                    table->setItem(currentRow,8,item9);

                    currentRow++;
                    qDebug() << "Nombre de lignes récupérées : " << currentRow;
                }
            }

        QSqlDatabase::database().commit();
}
}
// Définissez un message personnalisé pour détecter les clics sur l'icône de notification
#define WM_ICON_NOTIFY (WM_USER + 1)
kine s;
void kine::showNotification(const std::wstring& title, const std::wstring& message) {
    // Initialisez les données de l'icône de notification
        NOTIFYICONDATA nid;
        memset(&nid, 0, sizeof(NOTIFYICONDATA));
        nid.cbSize = sizeof(NOTIFYICONDATA);
        nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_INFO;
        nid.uCallbackMessage = WM_ICON_NOTIFY; // Utilisez le message personnalisé pour détecter les clics sur l'icône
        nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
        wcscpy_s(nid.szTip, title.c_str());

        // Affichez la notification toast
        Shell_NotifyIcon(NIM_ADD, &nid);
        Shell_NotifyIcon(NIM_MODIFY, &nid); // Rafraîchir l'icône pour la rendre visible dans la zone de notification
        nid.uTimeout = 3000; // Durée d'affichage de la notification en millisecondes
        nid.dwInfoFlags = NIIF_INFO;
        wcscpy_s(nid.szInfoTitle, title.c_str());
        wcscpy_s(nid.szInfo, message.c_str());
        Shell_NotifyIcon(NIM_MODIFY, &nid); // Affichez la notification toast
}

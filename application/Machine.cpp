#include "Machine.h"
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

#include <windows.h>
#include <iostream>
#include <string>
#include <CommCtrl.h> // Ajoutez cette ligne pour inclure CommCtrl.h

machine::machine()
{
    nom="";description="",etat="";
}

machine::machine(QByteArray  image,QString nom,QString description,QString etat)
{
    this->image=image;
    this->nom=nom;
    this->description=description;
    this->etat=etat;


}

QString machine::getimage(){return image;}
QString machine::getnom(){return nom;}
QString machine::getdescription(){return description;}
QString machine::getetat(){return etat;}


void machine::setImage(QByteArray  image){this->image=image;}
void machine::setnom(QString nom){this->nom=nom;}
void machine::setdescription(QString description){this->description=description;}
void machine::setetat(QString etat){this->etat=etat;}


bool machine::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO MACHINE (IMAGE , NOM, DESCRIPTION, ETAT)"
                       "VALUES (:image, :nom, :description, :etat)");
         query.bindValue(":image",image);
         query.bindValue(":nom", nom);
         query.bindValue(":description",description);
         query.bindValue(":etat",etat);

        return query.exec();

}

void machine::setId(int id) {
   this->id = id;
}

bool machine::deleteFromDatabase() {
   QSqlQuery query;
   query.prepare("DELETE FROM MACHINE WHERE ID_MACHINE = :id");
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur de suppression : " << query.lastError();
       return false;
   }
   return true;
}

bool machine::modifier(int id, QByteArray imageData) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flexiverse");
    db.setUserName("raif");
    db.setPassword("esprit18");

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError();
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE MACHINE SET IMAGE = :imageData, NOM = :nom, DESCRIPTION = :description, ETAT = :etat WHERE ID_MACHINE = :id"); // Ajoutez IMAGE = :image
    query.bindValue(":imageData", imageData); // Ajoutez cette ligne
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":etat", etat);
    query.bindValue(":id", id);
    if(!query.exec()) {
        qDebug() << "Erreur : " << query.lastError();
        return false;
    }

    return true;
}

void machine::displayTable(QTableWidget *table, bool test) {
Connection c;


if (test){
   QSqlDatabase::database().transaction();
   QSqlQuery Query_Get_Data(c.get_db());
   Query_Get_Data.prepare("SELECT * FROM MACHINE");

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
                   imageLabel->setPixmap(circularImage.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Ajustez la taille comme vous le souhaitez


                       table->setCellWidget(currentRow, 1, imageLabel);
               QTableWidgetItem *item0 = new QTableWidgetItem(Query_Get_Data.value("ID_Machine").toString());
              QTableWidgetItem *item2 = new QTableWidgetItem(Query_Get_Data.value("NOM").toString());
              QTableWidgetItem *item3 = new QTableWidgetItem(Query_Get_Data.value("DESCRIPTION").toString());
               QTableWidgetItem *item4 = new QTableWidgetItem(Query_Get_Data.value("ETAT").toString());

                table->setItem(currentRow, 0, item0);
                table->setItem(currentRow, 2, item2);
               table->setItem(currentRow, 3, item3);
                table->setItem(currentRow, 4, item4);
               currentRow++;
               qDebug() << "Nombre de lignes récupérées : " << currentRow;
           }
       }

   QSqlDatabase::database().commit();

}

}


// Définissez un message personnalisé pour détecter les clics sur l'icône de notification
#define WM_ICON_NOTIFY (WM_USER + 1)
machine session;
void machine::showNotification(const std::wstring& title, const std::wstring& message) {
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





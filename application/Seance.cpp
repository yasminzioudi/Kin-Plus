#include "Seance.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QIntValidator>
#include <QObject>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QComboBox>
#include <QTabWidget>
#include <QSqlTableModel>
#include <QDate>
#include <QSqlError>


#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>

#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QCheckBox>

#include <windows.h>
#include <iostream>
#include <string>
#include <CommCtrl.h> // Ajoutez cette ligne pour inclure CommCtrl.h


seance::seance()
{
    heure_debut="";heure_fin=""; type="";
}

seance::seance(QString heure_debut,QString heure_fin,QString type,QDate date_s)
{
    this->heure_debut=heure_debut;
    this->heure_fin=heure_fin;
    this->type=type;
    this->date_s=date_s;
}




QString seance::getheure_debut(){return heure_debut;}
QString seance::getheure_fin(){return heure_fin;}
QString seance::gettype(){return type;}
QDate seance::getdate_s(){return date_s;}

void seance::setheure_debut(QString heure_debut){this->heure_debut=heure_debut;}
void seance::setheure_fin(QString heure_fin){this->heure_fin=heure_fin;}
void seance::settype(QString type){this->type=type;}
void seance::setdate_s(QDate date_s){this->date_s=date_s;}


bool seance::ajouter()
{


   QSqlQuery query;
   query.prepare("INSERT INTO SEANCE (DATE_S, HEURE_DEBUT, HEURE_FIN, TYPE) "
                 "VALUES (:date_s, :heure_debut, :heure_fin, :type)");
   query.bindValue(":date_s", date_s);
   query.bindValue(":heure_debut", heure_debut);
   query.bindValue(":heure_fin", heure_fin);
   query.bindValue(":type", type);


   if(query.exec()) {
       return true;
   } else {
       qDebug() << "Error adding seance: " << query.lastError();
       return false;
   }

return query.exec();
}

void seance::setId(const int &id) {
   this->id = id;
}

bool seance::deleteFromDatabase() {
   QSqlQuery query;
   query.prepare("DELETE FROM SEANCE WHERE ID_SEANCE = :id");
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur de suppression : " << query.lastError();
       return false;
   }
   return true;
}


bool seance::modifier(int id) {
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("flexiverse");
   db.setUserName("raif");
   db.setPassword("esprit18");

   if (!db.open()) {
       qDebug() << "Erreur de connexion à la base de données : " << db.lastError();
       return false;
   }

   QSqlQuery query;
   query.prepare("UPDATE SEANCE SET DATE_S = :date_s, HEURE_DEBUT = :heure_debut, HEURE_FIN = :heure_fin, TYPE = :type WHERE ID_SEANCE = :id"); // Ajoutez IMAGE = :image
   query.bindValue(":date_s", date_s);
   query.bindValue(":heure_debut", heure_debut);
   query.bindValue(":heure_fin", heure_fin);
   query.bindValue(":type", type);
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur : " << query.lastError();
       return false;
   }

   return true;
}

void seance::setEtat(const QString &etat) {
    this->etat = etat;
}

QString seance::getEtat() const {
    return etat;
}

bool seance::modifierEtat(int id, const QString &etat) {
    QSqlQuery query;
    query.prepare("UPDATE SEANCE SET ETAT = :etat WHERE ID_SEANCE = :id");
    query.bindValue(":etat", etat);
    query.bindValue(":id", id);
    if (query.exec()) {
        qDebug() << "État de la séance mis à jour avec succès.";
        return true;
    } else {
        qDebug() << "Erreur lors de la mise à jour de l'état de la séance:" << query.lastError();
        return false;
    }
}


void seance::affichertab(QTableWidget *table, bool test) {
Connection c;


if (test){
    QSqlDatabase::database().transaction();
    QSqlQuery Query_Get_Data(c.get_db());
    Query_Get_Data.prepare("SELECT * FROM SEANCE");

    if (Query_Get_Data.exec()) {
        int currentRow = 0;

            table->setRowCount(10);
            qDebug() <<Query_Get_Data.size();


        while (Query_Get_Data.next()) {
                table->setRowCount(currentRow+1);



                QTableWidgetItem *item0 = new QTableWidgetItem(Query_Get_Data.value("ID_SEANCE").toString());
               QTableWidgetItem *item2 = new QTableWidgetItem(Query_Get_Data.value("DATE_S").toString());
               QTableWidgetItem *item3 = new QTableWidgetItem(Query_Get_Data.value("HEURE_DEBUT").toString());
                QTableWidgetItem *item4 = new QTableWidgetItem(Query_Get_Data.value("HEURE_FIN").toString());
                 QTableWidgetItem *item5 = new QTableWidgetItem(Query_Get_Data.value("TYPE").toString());

                 // Récupérez l'état de la séance à partir de la base de données
                 QString etatSeance = Query_Get_Data.value("ETAT").toString();

                 // Création de la case à cocher dans la colonne "État"
                 QCheckBox *checkBox = new QCheckBox;

                 // Mettez à jour l'état du checkbox en fonction de l'état de la séance
                 if (etatSeance == "validee") {
                     checkBox->setChecked(true); // Mettez le checkbox à l'état "checked" (vert)
                 } else {
                     checkBox->setChecked(false); // Mettez le checkbox à l'état "unchecked" (rouge)
                 }

                 // Définissez le style pour l'icône du checkbox (s'il s'agit d'une image)
                 checkBox->setStyleSheet("QCheckBox::indicator{"
                                         "width : 50px ;"
                                         "height : 50px;"
                                         "}"
                                         "QCheckBox::indicator::checked{"
                                         "image: url(\":/icon_ajout_P_N/ressource/icon_n/icon_ajoutPn/ch_on.png\");"
                                         "}"
                                         "QCheckBox::indicator::unchecked{"
                                         "image: url(\":/icon_ajout_P_N/ressource/icon_n/icon_ajoutPn/ch_off.png\");"
                                         "}");

                 table->setItem(currentRow, 0, item0);
                 table->setItem(currentRow, 1, item2);
                table->setItem(currentRow, 2, item3);
                 table->setItem(currentRow, 3, item4);
                 table->setItem(currentRow, 4, item5);
                currentRow++;
                qDebug() << "Nombre de lignes récupérées : " << currentRow;
            }
        }

    QSqlDatabase::database().commit();

}

 }

// Définissez un message personnalisé pour détecter les clics sur l'icône de notification
#define WM_ICON_NOTIFY (WM_USER + 1)
seance sess;
void seance::showNotification(const std::wstring& title, const std::wstring& message) {
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


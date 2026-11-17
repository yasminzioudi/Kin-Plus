#include "Salle.h"
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


salle::salle()
{
    nom="";capacite=0;location="";
}

salle::salle(QString nom,int capacite,QString location)
{
    this->nom=nom;
    this->capacite=capacite;
    this->location=location;

}

QString salle::getnom(){return nom;}
QString salle::getlocation(){return location;}
int salle::getcapacite(){return capacite;}

void salle::setnom(QString nom){this->nom=nom;}
void salle::setlocation(QString location){this->location=location;}
void salle::setcapacite(int capacite){this->capacite=capacite;}


bool salle::ajouter()
{


   QSqlQuery query;
   query.prepare("INSERT INTO SALLE (NOM, CAPACITY, LOCATION) "
                 "VALUES (:nom, :capacite, :location)");
   query.bindValue(":nom", nom);
   query.bindValue(":capacite", capacite);
   query.bindValue(":location", location);


   if(query.exec()) {
       return true;
   } else {
       qDebug() << "Error adding patient: " << query.lastError();
       return false;
   }

return query.exec();
}


void salle::setId(const int &id) {
   this->id = id;
}

bool salle::deleteFromDatabase() {
   QSqlQuery query;
   query.prepare("DELETE FROM TABLE_PATIENT WHERE ID = :id");
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur de suppression : " << query.lastError();
       return false;
   }
   return true;
}


bool salle::modifier(int id) {
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("flexiverse");
   db.setUserName("raif");
   db.setPassword("esprit18");

   if (!db.open()) {
       qDebug() << "Erreur de connexion à la base de données : " << db.lastError();
       return false;
   }

   QSqlQuery query;
   query.prepare("UPDATE SALLE SET NOM = :nom, CAPACITY = :capacite, LOCATION = :location WHERE ID_SALLE = :id"); // Ajoutez IMAGE = :image
   query.bindValue(":nom", nom);
   query.bindValue(":capacite", capacite);
   query.bindValue(":location", location);
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur : " << query.lastError();
       return false;
   }

   return true;
}



void salle::displayTable(QTableWidget *table, bool test) {
Connection c;


if (test){
   QSqlDatabase::database().transaction();
   QSqlQuery Query_Get_Data(c.get_db());
   Query_Get_Data.prepare("SELECT * FROM SALLE");

   if (Query_Get_Data.exec()) {
       int currentRow = 0;

           table->setRowCount(10);
           qDebug() <<Query_Get_Data.size();


       while (Query_Get_Data.next()) {
           table->setRowCount(currentRow+1);


               QTableWidgetItem *item0 = new QTableWidgetItem(Query_Get_Data.value("ID_SALLE").toString());
              QTableWidgetItem *item2 = new QTableWidgetItem(Query_Get_Data.value("NOM").toString());
              QTableWidgetItem *item3 = new QTableWidgetItem(Query_Get_Data.value("CAPACITY").toString());
               QTableWidgetItem *item4 = new QTableWidgetItem(Query_Get_Data.value("LOCATION").toString());

                table->setItem(currentRow, 0, item0);
                table->setItem(currentRow, 1, item2);
               table->setItem(currentRow, 2, item3);
                table->setItem(currentRow, 3, item4);
               currentRow++;
               qDebug() << "Nombre de lignes récupérées : " << currentRow;
           }
       }

   QSqlDatabase::database().commit();

}

}
// Définissez un message personnalisé pour détecter les clics sur l'icône de notification
#define WM_ICON_NOTIFY (WM_USER + 1)
salle sessionDat;
void salle::showNotification(const std::wstring& title, const std::wstring& message) {
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

#include "Employe.h"
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
#include <QSqlError>
#include "Employe.h"
#include "mainwindow.h"
#include <QTableWidget>

#include <windows.h>
#include <iostream>
#include <string>
#include <CommCtrl.h> // Ajoutez cette ligne pour inclure CommCtrl.h


employees::employees()
{
    nom="";prenom="";role="";sexe="";login="";mdp="";questionSecurite = "";
    reponseSecurite = "";
}
employees::employees(QString nom,QString prenom,QDate date_embauche,QString role,QString sexe,QString login,QString mdp, QString questionSecurite, QString reponseSecurite)
{
    this->nom=nom;
    this->prenom=prenom;
    this->date_embauche=date_embauche;
    this->role=role;
    this->sexe=sexe;
    this->login=login;
    this->mdp=mdp;
    this->questionSecurite = questionSecurite;
    this->reponseSecurite = reponseSecurite;

}

QString employees::getnom(){return nom;}
QString employees::getprenom(){return prenom;}
QDate employees::getdate_embauche(){return date_embauche;}
QString employees::getrole(){return role;}
QString employees::getsexe(){return sexe;}
QString employees::getlogin(){return login;}
QString employees::getmdp(){return mdp;}
QString employees::getQuestionSecurite(){return questionSecurite;}
QString employees::getReponseSecurite(){return reponseSecurite;}

void employees::setnom(QString nom){this->nom=nom;}
void employees::setprenom(QString prenom){this->prenom=prenom;}
void employees::setdate_embauche(QDate date_embauche ){this->date_embauche=date_embauche;}
void employees::setrole(QString role){this->role=role;}
void employees::setsexe(QString sexe){this->sexe=sexe;}
void employees::setlogin(QString login){this->login=login;}
void employees::setmdp(QString mdp){this->mdp=mdp;}
void employees::setQuestionSecurite(QString questionSecurite){this->questionSecurite=questionSecurite;}
void employees::setReponseSecurite(QString reponseSecurite){this->reponseSecurite=reponseSecurite;}



bool employees::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO EMPLOYE (NOM,PRENOM,DATE_EMBAUCHE,ROLE,SEXE,LOGIN,MDP,QUESTION_SECURITE,REPONSE_SECURITE) "
                       "VALUES (:nom, :prenom,:date_embauche,:role,:sexe,:login,:mdp,:questionSecurite,:reponseSecurite)");
         query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":date_embauche",date_embauche);
         query.bindValue(":role",role);
         query.bindValue(":sexe",sexe);
         query.bindValue(":login",login);
         query.bindValue(":mdp",mdp);
         query.bindValue(":questionSecurite", questionSecurite);
         query.bindValue(":reponseSecurite", reponseSecurite);
        return query.exec();

}

void employees::setId(const int &id) {
   this->id = id;
}

bool employees::deleteFromDatabase() {
   QSqlQuery query;
   query.prepare("DELETE FROM EMPLOYE WHERE ID_EMPLOYE = :id");
   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur de suppression : " << query.lastError();
       return false;
   }
   return true;
}


bool employees::modifier(int id) {
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("flexiverse");
   db.setUserName("raif");
   db.setPassword("esprit18");

   if (!db.open()) {
       qDebug() << "Erreur de connexion à la base de données : " << db.lastError();
       return false;
   }

   QSqlQuery query;
   query.prepare("UPDATE EMPLOYE SET NOM = :nom, PRENOM = :prenom, DATE_EMBAUCHE = :date_embauche, ROLE = :role, SEXE = :sexe, LOGIN = :login, MDP = :mdp, QUESTION_SECURITE = :questionSecurite, REPONSE_SECURITE = :reponseSecurite WHERE ID_EMPLOYE = :id"); // Ajoutez IMAGE = :image
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":date_embauche", date_embauche);
   query.bindValue(":role", role);
   query.bindValue(":sexe", sexe);
   query.bindValue(":login", login);
   query.bindValue(":mdp", mdp);
   query.bindValue(":questionSecurite", questionSecurite); // Nouvelle colonne questionSecurite
    query.bindValue(":reponseSecurite", reponseSecurite);

   query.bindValue(":id", id);
   if(!query.exec()) {
       qDebug() << "Erreur : " << query.lastError();
       return false;
   }

   return true;
}

void employees::displayTable(QTableWidget *table, bool test) {
Connection c;


if (test){
   QSqlDatabase::database().transaction();
   QSqlQuery Query_Get_Data(c.get_db());
   Query_Get_Data.prepare("SELECT * FROM EMPLOYE");

   if (Query_Get_Data.exec()) {
       int currentRow = 0;

           table->setRowCount(10);
           qDebug() <<Query_Get_Data.size();


       while (Query_Get_Data.next()) {
               table->setRowCount(currentRow+1);

               QTableWidgetItem *item0 = new QTableWidgetItem(Query_Get_Data.value("ID_EMPLOYE").toString());
              QTableWidgetItem *item2 = new QTableWidgetItem(Query_Get_Data.value("NOM").toString());
              QTableWidgetItem *item3 = new QTableWidgetItem(Query_Get_Data.value("PRENOM").toString());
               QTableWidgetItem *item4 = new QTableWidgetItem(Query_Get_Data.value("DATE_EMBAUCHE").toString());
                QTableWidgetItem *item5 = new QTableWidgetItem(Query_Get_Data.value("ROLE").toString());
             QTableWidgetItem *item6 = new QTableWidgetItem(Query_Get_Data.value("SEXE").toString());
              QTableWidgetItem *item7 = new QTableWidgetItem(Query_Get_Data.value("LOGIN").toString());
              QTableWidgetItem *item8 = new QTableWidgetItem(Query_Get_Data.value("MDP").toString());
              QTableWidgetItem *item9 = new QTableWidgetItem(Query_Get_Data.value("QUESTION_SECURITE").toString());
               QTableWidgetItem *item10 = new QTableWidgetItem(Query_Get_Data.value("REPONSE_SECURITE").toString());



                table->setItem(currentRow, 0, item0);
                table->setItem(currentRow, 1, item2);
               table->setItem(currentRow, 2, item3);
                table->setItem(currentRow, 3, item4);
                table->setItem(currentRow, 4, item5);
               table->setItem(currentRow, 5, item6);
              table->setItem(currentRow, 6, item7);
              table->setItem(currentRow, 7, item8);
              table->setItem(currentRow, 8, item9);
              table->setItem(currentRow, 9, item10);



               currentRow++;
               qDebug() << "Nombre de lignes récupérées : " << currentRow;
           }
       }

   QSqlDatabase::database().commit();

}

}

// Définissez un message personnalisé pour détecter les clics sur l'icône de notification
#define WM_ICON_NOTIFY (WM_USER + 1)
employees employees;
void employees::showNotification(const std::wstring& title, const std::wstring& message) {
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



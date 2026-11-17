#ifndef EMPLOYEES_H
#define EMPLOYEES_H


#include <QString>
#include <QSqlQuery>
#include <QDate>
#include "QSqlQueryModel"
#include <QLCDNumber>
#include"QDebug"
#include<QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidget>


class employees
{

public:
    employees();
    employees(QString nom, QString prenom,QDate date_embauche,QString role,QString sexe,QString login,QString mdp, QString questionSecurite, QString reponseSecurite);

    int getid();
    QString getnom();
    QString getprenom();
    QDate  getdate_embauche();
    QString getrole();
    QString getsexe();
    QString getlogin();
    QString getmdp();
    QString getQuestionSecurite();
    QString getReponseSecurite();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_embauche(QDate);
    void setrole(QString);
    void setsexe(QString);
    void setlogin(QString);
    void setmdp(QString);
    void setQuestionSecurite(QString questionSecurite);
    void setReponseSecurite(QString reponseSecurite);
    bool ajouter();
   bool deleteFromDatabase();
   bool modifier(int id);



   void displayTable(QTableWidget *table, bool test);
void setId(const int &id);
void showNotification(const std::wstring& title, const std::wstring& message);

private:
    int id;
    QString nom,prenom,role,sexe,login,mdp;
    QDate date_embauche;
    QString questionSecurite; // Nouvelle colonne pour la question de sécurité
    QString reponseSecurite; // Nouvelle colonne pour la réponse de sécurité
};
#endif // EMPLOYEES_H

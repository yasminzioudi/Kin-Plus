#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QLCDNumber>
#include"QDebug"
#include<QObject>
#include <QString>
#include <QDate>
#include <QLabel>
#include <QTableWidget>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QByteArray> // Ajoutez cette ligne
#include <QStackedWidget>
#include "connexion.h"


class salle
{

public:
    salle();
    salle(QString nom,int capacite,QString location);

    QString getnom();
    QString getlocation();
    int getcapacite();

    void setnom(QString);
    void setlocation(QString);
    void setcapacite(int);
    bool ajouter();
   bool deleteFromDatabase();
   bool modifier(int id);


   void displayTable(QTableWidget *table, bool test);

void setId(const int &id);
void showNotification(const std::wstring& title, const std::wstring& message);


private:
    int id;
    QString nom, location;
    int capacite;

};
#endif // SALLE_H

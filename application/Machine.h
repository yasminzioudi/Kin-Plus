#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QLCDNumber>
#include "QDebug"
#include <QObject>
#include <QImage>
#include <QPixmap>
#include "connexion.h"
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




class machine
{

public:
    machine();
    machine(QByteArray  image, QString nom, QString description, QString etat);

    QString getimage();
    QString getnom();
    QString getdescription();
    QString getetat();

    void setId(int id);
    void setnom(QString);
    void setdescription(QString);
    void setetat(QString);
    void setImage(QByteArray  image);

    bool ajouter();
   bool deleteFromDatabase();
   bool modifier(int id, QByteArray imageData);
   //bool modifier(int id);
   void displayTable(QTableWidget *table, bool test);
   void showNotification(const std::wstring& title, const std::wstring& message);




private:
    QString nom, description,etat;
    QByteArray  image;
    int id;

};
#endif // MACHINE_H

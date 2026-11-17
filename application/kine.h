#ifndef KINE_H
#define KINE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
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
class kine
{
    private:
    QString nom,prenom,sexe,date_n,specialite,cv;
    int tel;
    int id;
    public:
    kine();
    kine(QString nom,QString prenom,QString sexe,int tel,QString date_n,QByteArray image,QString specialite,QString cv);
    bool ajouter_kine();
    bool deleteFromDatabase();
    void setId(int id);
    QByteArray image;
    bool modifier(int id,  QByteArray imageData);
    void afficher_kine();
    void displayTable(QTableWidget *table, bool test);
    void showNotification(const std::wstring& title, const std::wstring& message);

};
#endif // KINE_H

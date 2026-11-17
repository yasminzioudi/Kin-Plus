#ifndef SEANCE_H
#define SEANCE_H

#include <QString>
#include <QSqlQuery>
#include "QSqlQueryModel"
#include <QLCDNumber>
#include "QDebug"
#include <QObject>
#include <QDate>

#include <QObject>
#include <QSqlDatabase>
#include <QTableWidget>


class seance
{
public:
        seance();
        seance(QString heure_debut, QString heure_fin,QString type,QDate date_s);



        QString getheure_debut();
        QString getheure_fin();
        QString gettype();
        QDate getdate_s();

        void setheure_debut(QString);
        void setheure_fin(QString);
        void settype(QString);
        void setdate_s(QDate);

        bool ajouter();
       bool deleteFromDatabase();
       bool modifier(int id);



    void setId(const int &id);

    void affichertab(QTableWidget *table, bool test);

    void setEtat(const QString &etat);
    QString getEtat() const;
    bool modifierEtat(int id, const QString &etat);


    void showNotification(const std::wstring& title, const std::wstring& message);



private:
    int id;
    QString type, heure_debut, heure_fin;
    QDate date_s;
    QString etat;


};

#endif // SEANCE_H

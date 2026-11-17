#ifndef PATIENT_H
#define PATIENT_H
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
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QDragEnterEvent>
#include <QDropEvent>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QCamera>
#include <QCameraImageCapture>
#include <QTimer>
class Patient
{
public:
    Patient();
    Patient(QString prenom, QString nom, int telephone, QString dos_med, QString sexe, QDate naissance, QByteArray image); // Ajoutez QByteArray image

     bool ajouter();
     bool deleteFromDatabase();
    bool modifier(int id,  QByteArray imageData);
   void updateStats(QLabel *label, QStackedWidget *stackedWidget);
    void displayTable(QTableWidget *table, bool test);

QString performFaceAnalysis(const QImage &image);

    void setId(int id);
    void setprenom(QString);
    void setnom(QString);
    void settelephone(int);
    void setdos_med(QString);
    void setsexe(QString);
    void setnaissance(QDate);
    void setlocation(QString);
    void setImage(QByteArray image);
    QByteArray getImage() const;
    void showNotification(const std::wstring& title, const std::wstring& message);

private:
    int id;
    QString prenom;
    QString nom;
    int telephone;
    QString dos_med;
    QString sexe;
    QDate naissance;
    QByteArray image; // Ajoutez cette ligne
};

#endif // PATIENT_H



#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "patient.h"
#include "Machine.h"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QMap>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QBuffer>
#include <QByteArray>
#include <QFileInfo>
#include <QPainter>

#include <QtNetwork>





#include <QMainWindow>
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <QUrl>
#include <QSystemTrayIcon>

#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include <QMediaPlayer>

#include <QTextEdit>
#include "ui_CertificateDialog.h"

//salma
#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QSequentialAnimationGroup>
#include <QTableWidgetItem>

#include <QNetworkAccessManager>

struct Position {
    int x;
    int y;
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int getCurrentIndex(QStackedWidget* widget);
    ~MainWindow();
    QByteArray imageData;
    void showWelcomeMessage(const QString& username);

 public slots :
    void verifierNom(const QString &text);
         void verifierPrenom(const QString &text);
         void onLoginSuccessful(const QString& username);



private slots:

    void on_list_b_clicked();

     void on_b_Patients_clicked();


    void on_b_kines_clicked();

    void on_ajout_clicked();




    void on_bm_Patients_clicked();

    void on_statistiques_clicked();
    void on_b_Seances_clicked();

    void on_b_Salles_clicked();
    void on_b_Employes_clicked();

    void on_b_Machines_clicked();

    void on_bm_Employes_clicked();

    void on_bm_Kines_clicked();

    void on_bm_Seances_clicked();

    void on_bm_Machines_clicked();

    void on_bm_Salles_clicked();






    


    void on_pushButton_26_clicked();

    void on_pushButton_35_clicked();

    void on_s_v_clicked();

   void deleteRow_pat();
   void updateRow_pat();
   void validateUpdate_pat();


   void deleteRow_salle();
   void updateRow_salle();
   void validateUpdate_salle();


   void deleteRow_seance();
   void updateRow_seance();
   void validateUpdate_seance();



   void deleteRow_employe();
   void updateRow_employe();
   void validateUpdate_employe();



   void deleteRow_machine();
   void updateRow_machine();
   void validateUpdate_machine();

   void deleteRow_kine();
    void updateRow_kine();
   void validateUpdate_kine();







   void showAllRowsEmploye();
    void filterRowsEmploye(const QString& searchText);
    void searchTableEmploye();

    void showAllRowsSalle();
     void filterRowsSalle(const QString& searchText1);
     void searchTableSalle();

     void showAllRowsSeance();
     void filterRowsSeance(const QString& searchText1);
     void searchTableSeance();


     void showAllRowsMachine();
     void filterRowsMachine(const QString& searchText1);
     void searchTableMachine();

     //Recherche Patient
     void showAllRowsPatient();
     void filterRowsPatient(const QString& searchText1);
     void searchTablePatient();



     void showAllRowsKine();
     void filterRowsKine(const QString& searchText1);
     void searchTableKine();




     void on_pushButton_32_clicked();

     void on_valider_pat_clicked();


     QByteArray on_pushButton_29_clicked();
     QByteArray on_pushButton_18_clicked();


     void on_button_valider_ajout_kine_clicked();
     bool isNomExists(const QString &nom);



     bool salleExisteDeja(const QString& nom, int capacite, const QString& location);



     void on_pdf_machine_clicked();
     void on_pdf_salle_clicked();
     void on_pdf_seance_clicked();
     void on_pdf_employe_clicked();
     void on_pdf_kine_clicked();
     void on_pdf_patient_clicked();

     void sort_table_salle();
     void sort_table_machine();
     void sort_table_patient();
     void sort_table_employe();
     void sort_table_seance();
     void sort_table_kine();

     QByteArray on_add_img_pat_clicked();

     void checkInput();




     QTableWidget* getTablePatient();
    // void updateCalendarAndEventDetails();



     bool verifyEmailExists(const QString& emailAddress);

     void generateQRCode();



     void sendTextRequest(QLabel *textResponseLabel);
     void sendImageRequest(QLabel *imageResponseLabel);



     void onMessageSent();








     void handleTranslationResponse(QNetworkReply *reply, QLabel* textResponseLabel);
     QNetworkRequest createRequest(const QUrl &url);






     void sendEmail(const QString& emailAddress, const QString& message);






     void on_google_traduction_clicked();

     void on_sendd_clicked();

     bool faceVerification(const QString& photo1Path, const QString& photo2Path);
     void captureAndSavePhoto();


     void on_pushButton_3_clicked();
     void on_historique_salle_clicked();
     void on_historique_patient_2_clicked();
     void on_historique_kine_clicked();
     void on_historique_employe_clicked();
     void on_historique_seance_clicked();
     void on_historique_machine_clicked();
void on_b_certif_clicked();

     void sendRequest_45();
     QString processWeatherData(const QByteArray &data);







     //////////////////////////////////
     void saveCertificateData();


     void on_detection_visg_clicked();

     void on_screenshot_b_clicked();
     ////////////////////////////////////////////////////////////////////










     void on_screenshot_seance_clicked();

     void on_screenshot_kine_clicked();

     void on_screenshot_machine_clicked();

     void on_screenshot_employe_clicked();

     void on_screenshot_salle_clicked();


     void checkSeanceTime();
     void modifierEtat(int idSeance, const QString& etat);
     void exportTableToCSV_seance();
     void exportTableToCSV_machine();
     void exportTableToCSV_salle();
     void exportTableToCSV_employe();
     void exportTableToCSV_patient();
     void exportTableToCSV_kine();

     void notification_liste();
     void envoyerSMS(const QString &destinataire, const QString &message);


     void replyFinished(QNetworkReply *reply);

     void send_email_request();

     void sendRequest(const QString &url, QLabel *resultLabel);


     QString getCurrentUserRole(const QString& login);

     void restartAnimation();
     void startAnimation();
     void on_news_clicked();

private:
    Ui::MainWindow *ui;
    bool cnx;
    QString lastClickedButton; // Variable pour stocker le nom du dernier bouton cliqué
      Ui::CertificateDialog *certUi;
Patient patient;
int id_patient;
int currentRow_patient;

int id_salle;
int currentRow_salle;


int id_seance;
int currentRow_seance;

int id_employe;
int currentRow_employe;


int id_machine;
int currentRow_machine;

int id_kine;
int currentRow_kine;


int id_pat;
QString m_message;
    QString m_recipient;
    QString url;
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QByteArray responseData;


    QLabel *chatbotInfoLabel;

QString m_content;
QString m_responseContent; // Variable pour stocker la réponse reçue







   QString recipientLineEdit;
   QString messageLineEdit;



   QNetworkAccessManager *networkManager;
   QString originmessage;
       QString translatemessage;

       QLineEdit *lineEdit;
       QLabel *textResponseLabel;



       ////////////////////////////////////
       QTimer *restartTimer; // Déclaration du QTimer pour redémarrer l'animation
           QPropertyAnimation *animation; // D
           QNetworkRequest request;
           void handleNetworkData();
           QLabel *tickerLabel;




};

#endif // MAINWINDOW_H

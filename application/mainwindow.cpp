#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Salle.h"
#include "Seance.h"
#include "Employe.h"
#include "Machine.h"
#include "kine.h"
#include "buttondelegate.h"
#include <QDebug>
#include <QStackedWidget>
#include <QMap>
#include <QFile>
#include <QString>
#include <QApplication>
#include <QCheckBox>
#include <QMessageBox>
#include <QTableWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QComboBox>
#include <QPrinter>
#include <QTextDocument>
#include <QtCharts>
#include <QPieSeries>
#include <QRegExp>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QChartView>
#include <QLineSeries>
#include <QDesktopServices>
#include <QUrl>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QGraphicsView>
#include <QPdfWriter>
#include <QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
#include <QTime>
#include <QItemSelectionModel>
#include <QTableWidgetItem>
#include <QCoreApplication>
#include <QUrl>
#include <QIntValidator>
#include <QDateEdit>
#include <QLineSeries>
#include <QTabWidget>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include <QStatusBar>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <cstdlib>
#include <QByteArray>
#include <QPixmap>
#include <QtNetwork>
#include <QVariantMap>
#include <QFile>
#include <QDir>
#include <QMediaPlayer>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtMultimedia/QCamera>
#include <QCameraImageCapture>
#include <QNetworkAccessManager>
#include<QCamera>
#include <QTimer>
#include <QCameraViewfinderSettings>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "loadscreen.h" // Utilisez le bon nom de fichier d'en-tête
#include "ui_mainwindowLoad.h"
#include "ui_CertificateDialog.h"

#include <QCryptographicHash>
#include "logindialog.h"
Connection c;
bool test=c.createconnect();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->icon_name_widget->show();
    ui->icon_only_widget->hide();
    // Créez un QTimer pour vérifier le temps de la séance toutes les 1 minute (60000 millisecondes)
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(checkSeanceTime()));
            timer->start(100000); // Lancez le timer







    QFile file(":/style/style.qss");
    if(file.open(QFile::ReadOnly)) {
       QString styleSheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(styleSheet);
    } else {
       qWarning() << "Impossible d'ouvrir le fichier .qss";
    }
    QTableWidget *table_seance = findChild<QTableWidget*>("table_seance");

    ui->table_seance->setColumnWidth(6, 200);

    if (table_seance) {

    for (int row = 0; row < table_seance->rowCount(); ++row) {

        QPushButton *button1 = new QPushButton;
        QPushButton *button2 = new QPushButton;
        QPushButton *button3 = new QPushButton;


        QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
        QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
        QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/sms.png");


        button1->setIcon(icon1);
        button2->setIcon(icon2);
        button3->setIcon(icon3);


        button1->setIconSize(QSize(30, 30));
        button2->setIconSize(QSize(30, 30));
        button3->setIconSize(QSize(30, 30));


        button1->setFixedSize(40, 40);
        button2->setFixedSize(40, 40);
        button3->setFixedSize(40, 40);

        button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                       "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                       "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                            // Création de la case à cocher
                                QCheckBox *checkBox = new QCheckBox;
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



                QHBoxLayout *layout2 = new QHBoxLayout;
        layout2->addWidget(button1);
        layout2->addWidget(button2);
        layout2->addWidget(button3);
        layout2->setContentsMargins(0, 0, 0, 0);
        layout2->setSpacing(0);

    QHBoxLayout *layoutc = new QHBoxLayout;
    layoutc->addWidget(checkBox);
    layoutc->setContentsMargins(30, 0, 0, 0);
    layoutc->setSpacing(0);
    QWidget *widgetc = new QWidget;
    widgetc->setLayout(layoutc);

        table_seance->setCellWidget(row, 5, widgetc);
    ////////////////////////////////////////////////////////////////////////////////////////////////
        QWidget *widget2 = new QWidget;
        widget2->setLayout(layout2);


        table_seance->setCellWidget(row, 6, widget2);
    }
    }


     connect(ui->b_Patients, &QPushButton::clicked, this, &MainWindow::on_b_Patients_clicked);
     connect(ui->bm_Patients, &QPushButton::clicked, this, &MainWindow::on_bm_Patients_clicked);
    connect(ui->list_b, &QPushButton::clicked, this, &MainWindow::on_list_b_clicked);
    connect(ui->ajout, &QPushButton::clicked, this, &MainWindow:: on_ajout_clicked);
    connect(ui->statistique_salle_2, &QPushButton::clicked, this, &MainWindow::on_statistiques_clicked);
    connect(ui->b_kines, &QPushButton::clicked, this, &MainWindow::on_b_kines_clicked);
    connect(ui->b_Seances, &QPushButton::clicked, this, &MainWindow::on_b_Seances_clicked);
    connect(ui->b_Machines, &QPushButton::clicked, this, &MainWindow::on_b_Machines_clicked);
    connect(ui->b_Salles, &QPushButton::clicked, this, &MainWindow::on_b_Salles_clicked);
    connect(ui->b_Employes, &QPushButton::clicked, this, &MainWindow::on_b_Employes_clicked);
    connect(ui->pushButton_34, &QPushButton::clicked, this, &MainWindow::searchTableEmploye);
    connect(ui->pushButton_555, &QPushButton::clicked, this, &MainWindow::searchTableSalle);
    connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::searchTableSeance);
    connect(ui->pushButton_28, &QPushButton::clicked, this, &MainWindow::searchTableMachine);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::searchTablePatient);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::searchTableKine);
    connect(ui->pushButton_39, &QPushButton::clicked, this, &MainWindow::sort_table_salle);
    connect(ui->pushButton_27, &QPushButton::clicked, this, &MainWindow::sort_table_machine);
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::sort_table_patient);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::sort_table_kine);
    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::sort_table_seance);
    connect(ui->pushButton_33, &QPushButton::clicked, this, &MainWindow::sort_table_employe);
    connect(ui->weather_button, &QPushButton::clicked, this, &MainWindow::sendRequest_45);
    connect(ui->LineEdit_prenom_pat, &QLineEdit::textChanged, this, &MainWindow::checkInput);
    connect(ui->LineEdit_nom_pat, &QLineEdit::textChanged, this, &MainWindow::checkInput);
    connect(ui->LineEdit_num_pat, &QLineEdit::textChanged, this, &MainWindow::checkInput);
    connect(ui->LineEdit_doc_pat, &QLineEdit::textChanged, this, &MainWindow::checkInput);
    connect(ui->excel_sceance, &QPushButton::clicked, this, &MainWindow::exportTableToCSV_seance);
    connect(ui->excel_patient, &QPushButton::clicked, this, &MainWindow::exportTableToCSV_patient);
    connect(ui->excel_kine, &QPushButton::clicked, this, &MainWindow::exportTableToCSV_kine);
    connect(ui->excel_employe, &QPushButton::clicked, this, &MainWindow::exportTableToCSV_employe);
    connect(ui->excel_salle, &QPushButton::clicked, this, &MainWindow::exportTableToCSV_salle);
    connect(ui->excel_machine, &QPushButton::clicked, this, &MainWindow::exportTableToCSV_machine);
    connect(ui->nom_kine_3, SIGNAL(textChanged(QString)), this, SLOT(verifierNom(QString)));
    connect(ui->prenom_kine_3, SIGNAL(textChanged(QString)), this, SLOT(verifierPrenom(QString)));



















 ui->table_patient->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);






}

MainWindow::~MainWindow()
{
    delete ui;
}

QString lastClickedButton;


void MainWindow::on_b_Patients_clicked()
{

if (!ui->bm_Patients->isEnabled()) {
        QMessageBox::warning(this, "Avertissement", "Vous n'êtes pas autorisé à accéder à cette fonctionnalité.");
    }
else{
    lastClickedButton = "Patients";
    ui->stackedWidget->setCurrentIndex(1);
    Patient patient;
    QTableWidget *table_patient = ui->table_patient;
    patient.displayTable(table_patient, cnx);
    QTableWidget *tableWidget = findChild<QTableWidget*>("table_patient");
    ui->table_patient->setColumnWidth(8, 200);
                    if (tableWidget) {

                        for (int row = 0; row < tableWidget->rowCount(); ++row) {

                            QPushButton *button1 = new QPushButton;
                            connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_pat()));
                            QPushButton *button2 = new QPushButton;
                             connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_pat()));


                            QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                            QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");



                            button1->setIcon(icon1);
                            button2->setIcon(icon2);

                            button1->setIconSize(QSize(30, 30));
                            button2->setIconSize(QSize(30, 30));


                            button1->setFixedSize(40, 40);
                            button2->setFixedSize(40, 40);

                            button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                    button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");


                            QHBoxLayout *layout = new QHBoxLayout;
                            layout->addWidget(button1);
                            layout->addWidget(button2);

                            layout->setContentsMargins(0, 0, 0, 0);
                            layout->setSpacing(0);


                            QWidget *widget = new QWidget;
                            widget->setLayout(layout);


                            tableWidget->setCellWidget(row, 8, widget);
                        }


    }


}

}

























 void MainWindow::on_b_kines_clicked()
 {
     if (!ui->bm_Kines->isEnabled()) {
             QMessageBox::warning(this, "Avertissement", "Vous n'êtes pas autorisé à accéder à cette fonctionnalité.");
         }
     else{
    lastClickedButton = "kines";
     ui->stackedWidget->setCurrentIndex(2);
     kine kine;
     QTableWidget *table_kine = ui->table_kine;
     kine.displayTable(table_kine, cnx);
     QTableWidget *tableWidget = findChild<QTableWidget*>("table_kine");
     ui->table_kine->setColumnWidth(8, 200);
                     if (tableWidget) {

                         for (int row = 0; row < tableWidget->rowCount(); ++row) {

                             QPushButton *button1 = new QPushButton;
                             connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_kine()));
                             QPushButton *button2 = new QPushButton;
                              connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_kine()));


                             QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                             QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");



                             button1->setIcon(icon1);
                             button2->setIcon(icon2);

                             button1->setIconSize(QSize(30, 30));
                             button2->setIconSize(QSize(30, 30));


                             button1->setFixedSize(40, 40);
                             button2->setFixedSize(40, 40);

                             button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                     button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");


                             QHBoxLayout *layout = new QHBoxLayout;
                             layout->addWidget(button1);
                             layout->addWidget(button2);


                             layout->setContentsMargins(0, 0, 0, 0);
                             layout->setSpacing(0);


                             QWidget *widget = new QWidget;
                             widget->setLayout(layout);


                             tableWidget->setCellWidget(row, 9, widget);
                         }
                     }
 }
}


 void MainWindow::on_b_Seances_clicked()
 {
     if (!ui->bm_Seances->isEnabled()) {
             QMessageBox::warning(this, "Avertissement", "Vous n'êtes pas autorisé à accéder à cette fonctionnalité.");
         }
     else{
     lastClickedButton = "seance";
     ui->stackedWidget->setCurrentIndex(6);

     QSqlDatabase::database().transaction();
     QSqlQuery Query_Get_Data(c.get_db());
     Query_Get_Data.prepare("SELECT * FROM SEANCE");

                if (Query_Get_Data.exec()) {
                    int currentRow = 0;
                    ui->table_seance->setRowCount(10);

                    while (Query_Get_Data.next()) {
                        QTableWidgetItem *it = new QTableWidgetItem(Query_Get_Data.value("ID_SEANCE").toString());
                        QTableWidgetItem *it1 = new QTableWidgetItem(Query_Get_Data.value("DATE_S").toString());
                        QTableWidgetItem *it2 = new QTableWidgetItem(Query_Get_Data.value("HEURE_DEBUT").toString());
                        QTableWidgetItem *it5 = new QTableWidgetItem(Query_Get_Data.value("HEURE_FIN").toString());
                        QTableWidgetItem *it6 = new QTableWidgetItem(Query_Get_Data.value("TYPE").toString());

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

                        QHBoxLayout *layoutc = new QHBoxLayout;
                        layoutc->addWidget(checkBox);
                        layoutc->setContentsMargins(0, 0, 0, 0);
                        layoutc->setSpacing(0);
                        QWidget *widgetc = new QWidget;
                        widgetc->setLayout(layoutc);

                        ui->table_seance->setItem(currentRow, 0, it);
                        ui->table_seance->setItem(currentRow, 1, it1);
                        ui->table_seance->setItem(currentRow, 2, it2);
                        ui->table_seance->setItem(currentRow, 3, it5);
                        ui->table_seance->setItem(currentRow, 4, it6);
                        ui->table_seance->setCellWidget(currentRow, 5, widgetc);

                        currentRow++;
                    }
                }
                QSqlDatabase::database().commit();

                // Ajustement de la largeur de la colonne contenant les boutons
                ui->table_seance->setColumnWidth(6, 200);


                // Réinitialisation des boutons dans la colonne des actions
                for (int row = 0; row < ui->table_seance->rowCount(); ++row) {
                    QPushButton *button1 = new QPushButton;
                    connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_seance()));
                    QPushButton *button2 = new QPushButton;
                    connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_seance()));
                    QPushButton *button3 = new QPushButton;
                    connect(button3, SIGNAL(clicked()), this, SLOT(notification_liste()));



                    QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                    QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
                    QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/sms.png");

                    button1->setIcon(icon1);
                    button2->setIcon(icon2);
                    button3->setIcon(icon3);

                    button1->setIconSize(QSize(30, 30));
                    button2->setIconSize(QSize(30, 30));
                    button3->setIconSize(QSize(30, 30));

                    button1->setFixedSize(40, 40);
                    button2->setFixedSize(40, 40);
                    button3->setFixedSize(40, 40);

                    button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                    button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                    button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                    QHBoxLayout *layout = new QHBoxLayout;
                    layout->addWidget(button1);
                    layout->addWidget(button2);
                    layout->addWidget(button3);
                    layout->setContentsMargins(0, 0, 0, 0);
                    layout->setSpacing(0);

                    QWidget *widget = new QWidget;
                    widget->setLayout(layout);

                    ui->table_seance->setCellWidget(row, 6, widget);
                }
            }
 }



 void MainWindow::on_b_Salles_clicked()
 {
     if (!ui->bm_Salles->isEnabled()) {
            QMessageBox::warning(this, "Avertissement", "Vous n'êtes pas autorisé à accéder à cette fonctionnalité.");
        }
     else{
     lastClickedButton = "salle";
     ui->stackedWidget->setCurrentIndex(12);
     salle salle;
     QTableWidget *table_salle = ui->table_salle;
     salle.displayTable(table_salle, cnx);
     QTableWidget *tableWidget = findChild<QTableWidget*>("table_salle");
     ui->table_salle->setColumnWidth(4, 200);
                     if (tableWidget) {

                         for (int row = 0; row < tableWidget->rowCount(); ++row) {

                             QPushButton *button1 = new QPushButton;
                             connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_salle()));
                             QPushButton *button2 = new QPushButton;
                              connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_salle()));
                              QPushButton *button3 = new QPushButton;
                              connect(button3, SIGNAL(clicked()), this, SLOT(send_email_request()));



                             QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                             QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
                             QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/mail.png");




                             button1->setIcon(icon1);
                             button2->setIcon(icon2);
                             button3->setIcon(icon3);



                             button1->setIconSize(QSize(30, 30));
                             button2->setIconSize(QSize(30, 30));
                             button3->setIconSize(QSize(30, 30));


                             button1->setFixedSize(40, 40);
                             button2->setFixedSize(40, 40);
                             button3->setFixedSize(40, 40);

                             button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                     button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                                     button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                             QHBoxLayout *layout = new QHBoxLayout;
                             layout->addWidget(button1);
                             layout->addWidget(button2);
                             layout->addWidget(button3);


                             layout->setContentsMargins(0, 0, 0, 0);
                             layout->setSpacing(0);


                             QWidget *widget = new QWidget;
                             widget->setLayout(layout);


                             tableWidget->setCellWidget(row, 4, widget);
                         }
                     }
}
 }

 void MainWindow::on_b_Employes_clicked()
 {
     if (!ui->bm_Employes->isEnabled()) {
             QMessageBox::warning(this, "Avertissement", "Vous n'êtes pas autorisé à accéder à cette fonctionnalité.");
         }
     else{
     lastClickedButton = "employe";
     ui->stackedWidget->setCurrentIndex(15);
     employees employe;
     QTableWidget *table_employe = ui->table_employe;
     employe.displayTable(table_employe, cnx);
     QTableWidget *tableWidget = findChild<QTableWidget*>("table_employe");
     ui->table_employe->setColumnWidth(10, 200);
                     if (tableWidget) {

                         for (int row = 0; row < tableWidget->rowCount(); ++row) {

                             QPushButton *button1 = new QPushButton;
                             connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_employe()));
                             QPushButton *button2 = new QPushButton;
                              connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_employe()));


                             QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                             QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");



                             button1->setIcon(icon1);
                             button2->setIcon(icon2);


                             button1->setIconSize(QSize(30, 30));
                             button2->setIconSize(QSize(30, 30));


                             button1->setFixedSize(40, 40);
                             button2->setFixedSize(40, 40);

                             button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                     button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");


                             QHBoxLayout *layout = new QHBoxLayout;
                             layout->addWidget(button1);
                             layout->addWidget(button2);

                             layout->setContentsMargins(0, 0, 0, 0);
                             layout->setSpacing(0);


                             QWidget *widget = new QWidget;
                             widget->setLayout(layout);


                             tableWidget->setCellWidget(row, 10, widget);
                         }
                     }
 }
 }

 void MainWindow::on_b_Machines_clicked()
 {
     if (!ui->bm_Machines->isEnabled()) {
            QMessageBox::warning(this, "Avertissement", "Vous n'êtes pas autorisé à accéder à cette fonctionnalité.");
        }
     else{
     lastClickedButton = "machine";
     ui->stackedWidget->setCurrentIndex(9);
     machine machine;
     QTableWidget *table_machine = ui->table_machine;
     machine.displayTable(table_machine, cnx);
     QTableWidget *tableWidget = findChild<QTableWidget*>("table_machine");
     ui->table_machine->setColumnWidth(8, 200);
                     if (tableWidget) {

                         for (int row = 0; row < tableWidget->rowCount(); ++row) {

                             QPushButton *button1 = new QPushButton;
                             connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_machine()));
                             QPushButton *button2 = new QPushButton;
                              connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_machine()));
                              QPushButton *button3 = new QPushButton;
                               connect(button3, SIGNAL(clicked()), this, SLOT(generateQRCode()));


                             QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                             QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
                             QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/qr-code.png");




                             button1->setIcon(icon1);
                             button2->setIcon(icon2);
                             button3->setIcon(icon3);


                             button1->setIconSize(QSize(30, 30));
                             button2->setIconSize(QSize(30, 30));
                             button3->setIconSize(QSize(30, 30));




                             button1->setFixedSize(40, 40);
                             button2->setFixedSize(40, 40);
                             button3->setFixedSize(40, 40);


                             button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                             button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                             button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                            "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                             QHBoxLayout *layout = new QHBoxLayout;
                             layout->addWidget(button1);
                             layout->addWidget(button2);
                             layout->addWidget(button3);


                             layout->setContentsMargins(0, 0, 0, 0);
                             layout->setSpacing(0);


                             QWidget *widget = new QWidget;
                             widget->setLayout(layout);


                             tableWidget->setCellWidget(row, 5, widget);
                         }
                     }
 }
 }



void MainWindow::on_list_b_clicked()
{

    if (lastClickedButton == "Patients")
        {

    ui->stackedWidget->setCurrentIndex(1);
    Patient patient;
    QTableWidget *table_patient = ui->table_patient;
    patient.displayTable(table_patient, cnx);
    QTableWidget *tableWidget = findChild<QTableWidget*>("table_patient");
    ui->table_patient->setColumnWidth(8, 200);
                    if (tableWidget) {

                        for (int row = 0; row < tableWidget->rowCount(); ++row) {

                            QPushButton *button1 = new QPushButton;
                            connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_pat()));
                            QPushButton *button2 = new QPushButton;
                             connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_pat()));


                            QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                            QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");



                            button1->setIcon(icon1);
                            button2->setIcon(icon2);

                            button1->setIconSize(QSize(30, 30));
                            button2->setIconSize(QSize(30, 30));


                            button1->setFixedSize(40, 40);
                            button2->setFixedSize(40, 40);

                            button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                    button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                           "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                            QHBoxLayout *layout = new QHBoxLayout;
                            layout->addWidget(button1);
                            layout->addWidget(button2);

                            layout->setContentsMargins(0, 0, 0, 0);
                            layout->setSpacing(0);


                            QWidget *widget = new QWidget;
                            widget->setLayout(layout);


                            tableWidget->setCellWidget(row, 8, widget);
                        }


    }
                    qDebug()<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
            }
    if(lastClickedButton=="kines")
    {
        ui->stackedWidget->setCurrentIndex(2);
        kine kine;
        QTableWidget *table_kine = ui->table_kine;
        kine.displayTable(table_kine, cnx);
        QTableWidget *tableWidget = findChild<QTableWidget*>("table_kine");
        ui->table_kine->setColumnWidth(8, 200);
                        if (tableWidget) {

                            for (int row = 0; row < tableWidget->rowCount(); ++row) {

                                QPushButton *button1 = new QPushButton;
                                connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_kine()));
                                QPushButton *button2 = new QPushButton;
                                 connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_kine()));


                                QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                                QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");



                                button1->setIcon(icon1);
                                button2->setIcon(icon2);

                                button1->setIconSize(QSize(30, 30));
                                button2->setIconSize(QSize(30, 30));


                                button1->setFixedSize(40, 40);
                                button2->setFixedSize(40, 40);

                                button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                        button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                                QHBoxLayout *layout = new QHBoxLayout;
                                layout->addWidget(button1);
                                layout->addWidget(button2);

                                layout->setContentsMargins(0, 0, 0, 0);
                                layout->setSpacing(0);


                                QWidget *widget = new QWidget;
                                widget->setLayout(layout);


                                tableWidget->setCellWidget(row, 9, widget);
                            }


        }
    }

    if (lastClickedButton == "seance") {
        ui->stackedWidget->setCurrentIndex(6);
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("flexiverse");
        db.setUserName("raif");
        db.setPassword(QString::fromUtf8(qgetenv("DB_PASSWORD")));

        if (db.open()) {
            qDebug() << "Connexion établie";
            QSqlDatabase::database().transaction();
            QSqlQuery Query_Get_Data(db);
            Query_Get_Data.prepare("SELECT * FROM SEANCE");

            if (Query_Get_Data.exec()) {
                int currentRow = 0;
                ui->table_seance->setRowCount(10);

                while (Query_Get_Data.next()) {
                    QTableWidgetItem *it = new QTableWidgetItem(Query_Get_Data.value("ID_SEANCE").toString());
                    QTableWidgetItem *it1 = new QTableWidgetItem(Query_Get_Data.value("DATE_S").toString());
                    QTableWidgetItem *it2 = new QTableWidgetItem(Query_Get_Data.value("HEURE_DEBUT").toString());
                    QTableWidgetItem *it5 = new QTableWidgetItem(Query_Get_Data.value("HEURE_FIN").toString());
                    QTableWidgetItem *it6 = new QTableWidgetItem(Query_Get_Data.value("TYPE").toString());

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

                    QHBoxLayout *layoutc = new QHBoxLayout;
                    layoutc->addWidget(checkBox);
                    layoutc->setContentsMargins(0, 0, 0, 0);
                    layoutc->setSpacing(0);
                    QWidget *widgetc = new QWidget;
                    widgetc->setLayout(layoutc);

                    ui->table_seance->setItem(currentRow, 0, it);
                    ui->table_seance->setItem(currentRow, 1, it1);
                    ui->table_seance->setItem(currentRow, 2, it2);
                    ui->table_seance->setItem(currentRow, 3, it5);
                    ui->table_seance->setItem(currentRow, 4, it6);
                    ui->table_seance->setCellWidget(currentRow, 5, widgetc);

                    currentRow++;
                }
            }
            QSqlDatabase::database().commit();

            // Ajustement de la largeur de la colonne contenant les boutons
            ui->table_seance->setColumnWidth(6, 200);

            // Réinitialisation des boutons dans la colonne des actions
            for (int row = 0; row < ui->table_seance->rowCount(); ++row) {
                QPushButton *button1 = new QPushButton;
                connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_seance()));
                QPushButton *button2 = new QPushButton;
                connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_seance()));
                QPushButton *button3 = new QPushButton;
                connect(button3, SIGNAL(clicked()), this, SLOT(notification_liste()));


                QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
                QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/sms.png");

                button1->setIcon(icon1);
                button2->setIcon(icon2);
                button3->setIcon(icon3);

                button1->setIconSize(QSize(30, 30));
                button2->setIconSize(QSize(30, 30));
                button3->setIconSize(QSize(30, 30));

                button1->setFixedSize(40, 40);
                button2->setFixedSize(40, 40);
                button3->setFixedSize(40, 40);

                button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                       "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                       "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                       "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                QHBoxLayout *layout = new QHBoxLayout;
                layout->addWidget(button1);
                layout->addWidget(button2);
                layout->addWidget(button3);
                layout->setContentsMargins(0, 0, 0, 0);
                layout->setSpacing(0);

                QWidget *widget = new QWidget;
                widget->setLayout(layout);

                ui->table_seance->setCellWidget(row, 6, widget);
            }
        }
    }

    if(lastClickedButton=="machine")
    {
        ui->stackedWidget->setCurrentIndex(9);
        machine machine;
        QTableWidget *table_machine = ui->table_machine;
        machine.displayTable(table_machine, cnx);
        QTableWidget *tableWidget = findChild<QTableWidget*>("table_machine");
        ui->table_machine->setColumnWidth(5, 200);
                        if (tableWidget) {

                            for (int row = 0; row < tableWidget->rowCount(); ++row) {

                                QPushButton *button1 = new QPushButton;
                                connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_machine()));
                                QPushButton *button2 = new QPushButton;
                                 connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_machine()));
                                 QPushButton *button3 = new QPushButton;
                                  connect(button3, SIGNAL(clicked()), this, SLOT(generateQRCode()));


                                QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                                QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
                                QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/qr-code.png");




                                button1->setIcon(icon1);
                                button2->setIcon(icon2);
                                button3->setIcon(icon3);


                                button1->setIconSize(QSize(30, 30));
                                button2->setIconSize(QSize(30, 30));


                                button1->setFixedSize(40, 40);
                                button2->setFixedSize(40, 40);
                                button3->setFixedSize(40, 40);


                                button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                        button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                                        button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                                QHBoxLayout *layout = new QHBoxLayout;
                                layout->addWidget(button1);
                                layout->addWidget(button2);
                                layout->addWidget(button3);


                                layout->setContentsMargins(0, 0, 0, 0);
                                layout->setSpacing(0);


                                QWidget *widget = new QWidget;
                                widget->setLayout(layout);


                                tableWidget->setCellWidget(row, 5, widget);
                            }


        }
    }
    if(lastClickedButton=="salle")
    {
        ui->stackedWidget->setCurrentIndex(12);
        salle salle;
        QTableWidget *table_salle = ui->table_salle;
        salle.displayTable(table_salle, cnx);
        QTableWidget *tableWidget = findChild<QTableWidget*>("table_salle");
        ui->table_salle->setColumnWidth(4, 200);
                        if (tableWidget) {

                            for (int row = 0; row < tableWidget->rowCount(); ++row) {

                                QPushButton *button1 = new QPushButton;
                                connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_salle()));
                                QPushButton *button2 = new QPushButton;
                                 connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_salle()));
                                 QPushButton *button3 = new QPushButton;
                                  connect(button3, SIGNAL(clicked()), this, SLOT(send_email_request()));


                                QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                                QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");
                                QIcon icon3(":/icon_tabN/ressource/icon_n/icon_tabN/mail.png");



                                button1->setIcon(icon1);
                                button2->setIcon(icon2);
                                button3->setIcon(icon3);


                                button1->setIconSize(QSize(30, 30));
                                button2->setIconSize(QSize(30, 30));
                                button3->setIconSize(QSize(30, 30));



                                button1->setFixedSize(40, 40);
                                button2->setFixedSize(40, 40);
                                button3->setFixedSize(40, 40);


                                button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                        button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");

                                        button3->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                                QHBoxLayout *layout = new QHBoxLayout;
                                layout->addWidget(button1);
                                layout->addWidget(button2);
                                layout->addWidget(button3);


                                layout->setContentsMargins(0, 0, 0, 0);
                                layout->setSpacing(0);


                                QWidget *widget = new QWidget;
                                widget->setLayout(layout);


                                tableWidget->setCellWidget(row, 4, widget);
                            }


        }
    }
    if(lastClickedButton=="employe")
    {
        ui->stackedWidget->setCurrentIndex(15);
        employees employe;
        QTableWidget *table_employe = ui->table_employe;
        employe.displayTable(table_employe, cnx);
        QTableWidget *tableWidget = findChild<QTableWidget*>("table_employe");
        ui->table_salle->setColumnWidth(10, 200);
                        if (tableWidget) {

                            for (int row = 0; row < tableWidget->rowCount(); ++row) {

                                QPushButton *button1 = new QPushButton;
                                connect(button1, SIGNAL(clicked()), this, SLOT(deleteRow_employe()));
                                QPushButton *button2 = new QPushButton;
                                 connect(button2, SIGNAL(clicked()), this, SLOT(updateRow_employe()));


                                QIcon icon1(":/icon_tabN/ressource/icon_n/icon_tabN/delete.png");
                                QIcon icon2(":/icon_tabN/ressource/icon_n/icon_tabN/update.png");



                                button1->setIcon(icon1);
                                button2->setIcon(icon2);

                                button1->setIconSize(QSize(30, 30));
                                button2->setIconSize(QSize(30, 30));


                                button1->setFixedSize(40, 40);
                                button2->setFixedSize(40, 40);

                                button1->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");
                                        button2->setStyleSheet("QPushButton { border: 2px solid transparent; border-radius: 8px; }"
                                                               "QPushButton:hover { background-color: #F0F0F0; border-color: #C0C0C0; }");



                                QHBoxLayout *layout = new QHBoxLayout;
                                layout->addWidget(button1);
                                layout->addWidget(button2);

                                layout->setContentsMargins(0, 0, 0, 0);
                                layout->setSpacing(0);


                                QWidget *widget = new QWidget;
                                widget->setLayout(layout);


                                tableWidget->setCellWidget(row, 10, widget);
                            }


        }
    }
    }






void MainWindow::on_ajout_clicked()
{
    if (lastClickedButton == "Patients")
       {

            ui->stackedWidget->setCurrentIndex(0);
        }

    if (lastClickedButton == "kines")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }

    if(lastClickedButton=="seance")
     {
        ui->stackedWidget->setCurrentIndex(7);
    }

    if(lastClickedButton=="machine")
    {
        ui->stackedWidget->setCurrentIndex(10);
    }

    if(lastClickedButton=="salle")
    {
        ui->stackedWidget->setCurrentIndex(13);
    }

    if(lastClickedButton=="employe")
    {
        ui->stackedWidget->setCurrentIndex(16);
    }


}





void MainWindow::on_statistiques_clicked()
{
    if (lastClickedButton == "Patients")
    {
        if(cnx)
        {
            QSqlQuery hommeQuery(c.get_db());
            hommeQuery.prepare("SELECT * FROM TABLE_PATIENT WHERE SEXE = 'Homme' ");
            hommeQuery.exec();
            int nb_homme=0;
            while(hommeQuery.next())
            {
                nb_homme++;
            }
            qDebug() <<nb_homme++;
            QSqlQuery femmeQuery(c.get_db());
            femmeQuery.prepare("SELECT * FROM TABLE_PATIENT WHERE SEXE = 'Femme' ");
            femmeQuery.exec();
            int nb_femme=0;
            while(femmeQuery.next())
            {
                nb_femme++;
            }
            qDebug() <<nb_femme;
            QPieSeries *pieSeries = new QPieSeries();
            QPieSlice *sliceHommes = pieSeries->append("Hommes", nb_homme);
            QPieSlice *sliceFemmes = pieSeries->append("Femmes", nb_femme);
            sliceHommes->setColor(QColor(31, 149, 239));
            sliceFemmes->setColor(Qt::red);
            QChart *chart = new QChart();
            chart->addSeries(pieSeries);


            sliceHommes->setExploded(true);

              sliceHommes->setLabelVisible(true);

              sliceFemmes->setExploded(true);

                sliceFemmes->setLabelVisible(true);

            chart->setTitle("Répartition Hommes / Femmes");
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            ui->stackedWidget->insertWidget(5, chartView);
            ui->stackedWidget->setCurrentIndex(5);

            // Ajout de l'animation
             QVariantAnimation *animation = new QVariantAnimation();
            animation->setStartValue(0.0);
            animation->setEndValue(1.0);
            animation->setDuration(100); // Durée de l'animation en millisecondes

            connect(animation, &QVariantAnimation::valueChanged, [=](const QVariant &value) {
                sliceHommes->setExploded(value.toReal());
                sliceFemmes->setExploded(value.toReal());
            }); animation->start(QAbstractAnimation::DeleteWhenStopped);

            // Ajout de l'animation
          QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
            chartView->setGraphicsEffect(effect);

            QPropertyAnimation *opacityAnimation = new QPropertyAnimation(effect, "opacity");
            opacityAnimation->setDuration(2000); // Durée de l'animation en millisecondes
            opacityAnimation->setStartValue(0.0);
            opacityAnimation->setEndValue(1.0);
            opacityAnimation->start(QAbstractAnimation::DeleteWhenStopped);



        }
    }

    if(lastClickedButton=="kines"){
        ui->stackedWidget->setCurrentIndex(4);
        QString roleQuery = "SELECT SPECIALITE, COUNT(*) FROM KINE GROUP BY SPECIALITE";
                    QSqlQuery roleCountQuery(roleQuery);
                    QMap<QString, int> roleCounts;
                    int totalEmployees = 0;
                    while (roleCountQuery.next())
                    {
                        QString role = roleCountQuery.value(0).toString();
                        int count = roleCountQuery.value(1).toInt();
                        roleCounts.insert(role, count);
                        totalEmployees += count;
                    }
                    QPieSeries *roleSeries = new QPieSeries();
                    for (auto it = roleCounts.begin(); it != roleCounts.end(); ++it)
                    {
                        QString role = it.key();
                        int count = it.value();
                        double percentage = (count * 100.0) / totalEmployees;
                        roleSeries->append(role + " (" + QString::number(count) + ", " + QString::number(percentage, 'f', 2) + "%)", percentage);
                    }
                    QChart *roleChart = new QChart();
                    roleChart->addSeries(roleSeries);
                    roleChart->setTitle("Kine specialite Distribution");
                    roleChart->setAnimationOptions(QChart::SeriesAnimations);
                    QChartView *roleChartView = new QChartView(roleChart);
                    roleChartView->setRenderHint(QPainter::Antialiasing);
                    QString sexeQuery = "SELECT SEXE, COUNT(*) FROM KINE GROUP BY SEXE";
                    QSqlQuery sexeCountQuery(sexeQuery);
                    QMap<QString, int> sexeCounts;
                    int totalSexes = 0;
                    while (sexeCountQuery.next())
                    {
                        QString sexe = sexeCountQuery.value(0).toString();
                        int count = sexeCountQuery.value(1).toInt();
                        sexeCounts.insert(sexe, count);
                        totalSexes += count;
                    }
                    QBarSet *sexeSet = new QBarSet("Sexe Distribution");
                    QStringList categories;
                    QBarSeries *sexeSeries = new QBarSeries();
                    for (auto it = sexeCounts.begin(); it != sexeCounts.end(); ++it)
                    {
                        QString sexe = it.key();
                        int count = it.value();
                        double percentage = (count * 100.0) / totalSexes;
                        *sexeSet << percentage;
                        categories << sexe + " (" + QString::number(count) + ", " + QString::number(percentage, 'f', 2) + "%)";
                    }
                    sexeSeries->append(sexeSet);
                    QChart *sexeChart = new QChart();
                    sexeChart->addSeries(sexeSeries);
                    sexeChart->setTitle("Kine Sexe Distribution");
                    sexeChart->setAnimationOptions(QChart::SeriesAnimations);
                    QBarCategoryAxis *axis = new QBarCategoryAxis();
                    axis->append(categories);
                    sexeChart->createDefaultAxes();
                    sexeChart->setAxisX(axis, sexeSeries);
                    sexeChart->legend()->setVisible(false);
                    QChartView *sexeChartView = new QChartView(sexeChart);
                    sexeChartView->setRenderHint(QPainter::Antialiasing);

                    QHBoxLayout *layout = new QHBoxLayout();
                        layout->addWidget(roleChartView);
                        layout->addWidget(sexeChartView);

                       QWidget *currentPageWidget = ui->stackedWidget->widget(4);
                       if (currentPageWidget->layout()) {
                           delete currentPageWidget->layout();
                       }
                        currentPageWidget->setLayout(layout);
 }

    if (lastClickedButton == "seance") {
            bool test = c.createconnect();
            if (test) {
                // Statistiques sur la répartition valide / non valide
                QSqlQuery ValideQuery(c.get_db());
                ValideQuery.prepare("SELECT COUNT(*) FROM SEANCE WHERE ETAT = 'validee'");
                ValideQuery.exec();
                ValideQuery.next();
                int nb_valide = ValideQuery.value(0).toInt();

                QSqlQuery NonValideQuery(c.get_db());
                NonValideQuery.prepare("SELECT COUNT(*) FROM SEANCE WHERE ETAT = 'non validee'");
                NonValideQuery.exec();
                NonValideQuery.next();
                int nb_non_valide = NonValideQuery.value(0).toInt();

                QPieSeries *valideNonValideSeries = new QPieSeries();
                valideNonValideSeries->append("Valide", nb_valide);
                valideNonValideSeries->append("Non Valide", nb_non_valide);

                QChart *valideNonValideChart = new QChart();
                valideNonValideChart->addSeries(valideNonValideSeries);
                valideNonValideChart->setTitle("Répartition Valide/Non Valide");
                QChartView *valideNonValideChartView = new QChartView(valideNonValideChart);
                valideNonValideChartView->setRenderHint(QPainter::Antialiasing);

                // Statistiques sur la répartition par type de séance en graphique en barre
                QSqlQuery typeQuery(c.get_db());
                typeQuery.prepare("SELECT TYPE, COUNT(*) FROM SEANCE GROUP BY TYPE");
                typeQuery.exec();

                QBarSeries *typeSeries = new QBarSeries();

                while (typeQuery.next()) {
                    QString type = typeQuery.value(0).toString();
                    int count = typeQuery.value(1).toInt();
                    QBarSet *barSet = new QBarSet(type);
                    *barSet << count;
                    typeSeries->append(barSet);
                }

                QChart *typeChart = new QChart();
                typeChart->addSeries(typeSeries);
                typeChart->setTitle("Répartition par Type de Séance");
                typeChart->createDefaultAxes();
                typeChart->legend()->setVisible(true);
                typeChart->legend()->setAlignment(Qt::AlignBottom);

                QChartView *typeChartView = new QChartView(typeChart);
                typeChartView->setRenderHint(QPainter::Antialiasing);

                // Ajouter les deux graphiques côte à côte
                QHBoxLayout *layout = new QHBoxLayout();
                layout->addWidget(valideNonValideChartView);
                layout->addWidget(typeChartView);

                QWidget *widget = new QWidget();
                widget->setLayout(layout);

                ui->stackedWidget->insertWidget(8, widget);
                ui->stackedWidget->setCurrentIndex(8);
            }
        }
    if(lastClickedButton=="machine")
    {

        ui->stackedWidget->setCurrentIndex(11);
        QString roleQuery = "SELECT ETAT, COUNT(*) FROM MACHINE GROUP BY ETAT";
                    QSqlQuery roleCountQuery(roleQuery);
                    QMap<QString, int> roleCounts;
                    int totalEmployees = 0;
                    while (roleCountQuery.next())
                    {
                        QString role = roleCountQuery.value(0).toString();
                        int count = roleCountQuery.value(1).toInt();
                        roleCounts.insert(role, count);
                        totalEmployees += count;
                    }
                    QPieSeries *roleSeries = new QPieSeries();
                    for (auto it = roleCounts.begin(); it != roleCounts.end(); ++it)
                    {
                        QString role = it.key();
                        int count = it.value();
                        double percentage = (count * 100.0) / totalEmployees;
                        roleSeries->append(role + " (" + QString::number(count) + ", " + QString::number(percentage, 'f', 2) + "%)", percentage);
                    }
                    QChart *roleChart = new QChart();
                    roleChart->addSeries(roleSeries);
                    roleChart->setTitle("Machine Etat Distribution");
                    roleChart->setAnimationOptions(QChart::SeriesAnimations);
                    QChartView *roleChartView = new QChartView(roleChart);
                    roleChartView->setRenderHint(QPainter::Antialiasing);
                    QString sexeQuery = "SELECT ETAT, COUNT(*) FROM MACHINE GROUP BY ETAT";
                    QSqlQuery sexeCountQuery(sexeQuery);
                    QMap<QString, int> sexeCounts;
                    int totalSexes = 0;
                    while (sexeCountQuery.next())
                    {
                        QString sexe = sexeCountQuery.value(0).toString();
                        int count = sexeCountQuery.value(1).toInt();
                        sexeCounts.insert(sexe, count);
                        totalSexes += count;
                    }
                    QBarSet *sexeSet = new QBarSet("Machine Distribution");
                    QStringList categories;
                    QBarSeries *sexeSeries = new QBarSeries();
                    for (auto it = sexeCounts.begin(); it != sexeCounts.end(); ++it)
                    {
                        QString sexe = it.key();
                        int count = it.value();
                        double percentage = (count * 100.0) / totalSexes;
                        *sexeSet << percentage;
                        categories << sexe + " (" + QString::number(count) + ", " + QString::number(percentage, 'f', 2) + "%)";
                    }
                    sexeSeries->append(sexeSet);
                    QChart *sexeChart = new QChart();
                    sexeChart->addSeries(sexeSeries);
                    sexeChart->setTitle("Machine Etat Distribution");
                    sexeChart->setAnimationOptions(QChart::SeriesAnimations);
                    QBarCategoryAxis *axis = new QBarCategoryAxis();
                    axis->append(categories);
                    sexeChart->createDefaultAxes();
                    sexeChart->setAxisX(axis, sexeSeries);
                    sexeChart->legend()->setVisible(false);
                    QChartView *sexeChartView = new QChartView(sexeChart);
                    sexeChartView->setRenderHint(QPainter::Antialiasing);

                    QHBoxLayout *layout = new QHBoxLayout();
                        layout->addWidget(roleChartView);
                        layout->addWidget(sexeChartView);

                       QWidget *currentPageWidget = ui->stackedWidget->widget(11);
                       if (currentPageWidget->layout()) {
                           delete currentPageWidget->layout();
                       }
                        currentPageWidget->setLayout(layout);
    }

    if(lastClickedButton=="salle")
    {
        ui->stackedWidget->setCurrentIndex(14);
        QString roleQuery = "SELECT LOCATION, COUNT(*) FROM SALLE GROUP BY LOCATION";
                    QSqlQuery roleCountQuery(roleQuery);
                    QMap<QString, int> roleCounts;
                    int totalEmployees = 0;
                    while (roleCountQuery.next())
                    {
                        QString role = roleCountQuery.value(0).toString();
                        int count = roleCountQuery.value(1).toInt();
                        roleCounts.insert(role, count);
                        totalEmployees += count;
                    }
                    QPieSeries *roleSeries = new QPieSeries();
                    for (auto it = roleCounts.begin(); it != roleCounts.end(); ++it)
                    {
                        QString role = it.key();
                        int count = it.value();
                        double percentage = (count * 100.0) / totalEmployees;
                        roleSeries->append(role + " (" + QString::number(count) + ", " + QString::number(percentage, 'f', 2) + "%)", percentage);
                    }
                    QChart *roleChart = new QChart();
                    roleChart->addSeries(roleSeries);
                    roleChart->setTitle("Salle localisation Distribution");
                    roleChart->setAnimationOptions(QChart::SeriesAnimations);
                    QChartView *roleChartView = new QChartView(roleChart);
                    roleChartView->setRenderHint(QPainter::Antialiasing);
                    QString sexeQuery = "SELECT LOCATION, COUNT(*) FROM SALLE GROUP BY LOCATION";
                    QSqlQuery sexeCountQuery(sexeQuery);
                    QMap<QString, int> sexeCounts;
                    int totalSexes = 0;
                    while (sexeCountQuery.next())
                    {
                        QString sexe = sexeCountQuery.value(0).toString();
                        int count = sexeCountQuery.value(1).toInt();
                        sexeCounts.insert(sexe, count);
                        totalSexes += count;
                    }
                    QBarSet *sexeSet = new QBarSet("Location Distribution");
                    QStringList categories;
                    QBarSeries *sexeSeries = new QBarSeries();
                    for (auto it = sexeCounts.begin(); it != sexeCounts.end(); ++it)
                    {
                        QString sexe = it.key();
                        int count = it.value();
                        double percentage = (count * 100.0) / totalSexes;
                        *sexeSet << percentage;
                        categories << sexe + " (" + QString::number(count) + ", " + QString::number(percentage, 'f', 2) + "%)";
                    }
                    sexeSeries->append(sexeSet);
                    QChart *sexeChart = new QChart();
                    sexeChart->addSeries(sexeSeries);
                    sexeChart->setTitle("Salle localisation Distribution");
                    sexeChart->setAnimationOptions(QChart::SeriesAnimations);
                    QBarCategoryAxis *axis = new QBarCategoryAxis();
                    axis->append(categories);
                    sexeChart->createDefaultAxes();
                    sexeChart->setAxisX(axis, sexeSeries);
                    sexeChart->legend()->setVisible(false);
                    QChartView *sexeChartView = new QChartView(sexeChart);
                    sexeChartView->setRenderHint(QPainter::Antialiasing);

                    QHBoxLayout *layout = new QHBoxLayout();
                        layout->addWidget(roleChartView);
                        layout->addWidget(sexeChartView);

                       QWidget *currentPageWidget = ui->stackedWidget->widget(14);
                       if (currentPageWidget->layout()) {
                           delete currentPageWidget->layout();
                       }
                        currentPageWidget->setLayout(layout);
    }

    if(lastClickedButton=="employe")
    {
     bool test=c.createconnect();
     if(test)
     {
         QSqlQuery KineQuery(c.get_db());
         KineQuery.prepare("SELECT * FROM EMPLOYE WHERE ROLE = 'Gestion des kinés' ");
         KineQuery.exec();
         int nb_kine=0;
         while(KineQuery.next())
         {
             nb_kine++;

         }
         qDebug() <<nb_kine;
         QSqlQuery SeanceQuery(c.get_db());
         SeanceQuery.prepare("SELECT * FROM EMPLOYE WHERE ROLE = 'Gestion des Séances' ");
         SeanceQuery.exec();
         int nb_seance=0;
         while(SeanceQuery.next())
         {
             nb_seance++;

         }
         qDebug() <<nb_seance;
         QSqlQuery MachineQuery(c.get_db());
         MachineQuery.prepare("SELECT * FROM EMPLOYE WHERE ROLE = 'Gestion des Machines' ");
         MachineQuery.exec();
         int nb_machine=0;
         while(MachineQuery.next())
         {
             nb_machine++;

         }
         qDebug() <<nb_machine;
         QSqlQuery SalleQuery(c.get_db());
         SalleQuery.prepare("SELECT * FROM EMPLOYE WHERE ROLE = 'Gestion des Salles' ");
         SalleQuery.exec();
         int nb_salle=0;
         while(SalleQuery.next())
         {
             nb_salle++;

         }
         qDebug() <<nb_salle;
         QSqlQuery PatientQuery(c.get_db());
         PatientQuery.prepare("SELECT * FROM EMPLOYE WHERE ROLE = 'Gestion des patients' ");
         PatientQuery.exec();
         int nb_patient=0;
         while(PatientQuery.next())
         {
             nb_patient++;

         }
         qDebug() <<nb_patient;
         QPieSeries *pieSeries = new QPieSeries();
             pieSeries->append("Gestion des patients", nb_patient);
             pieSeries->append("Gestion des Salles", nb_salle);
             pieSeries->append("Gestion des Machines", nb_machine);
             pieSeries->append("Gestion des Séances", nb_seance);
             pieSeries->append("Gestion des kinés", nb_kine);
             QChart *chart = new QChart();
             chart->addSeries(pieSeries);

            chart->setTitle("Répartition Par Gestion");
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            ui->stackedWidget->insertWidget(17, chartView);
         ui->stackedWidget->setCurrentIndex(17);
     }
 }


}










         // boutons sans noms dashbord
void MainWindow::on_bm_Patients_clicked()
{
    lastClickedButton = "Patients";
ui->stackedWidget->setCurrentIndex(1);
}




void MainWindow::on_bm_Employes_clicked()
{
    lastClickedButton = "employe";
     ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_bm_Kines_clicked()
{
    lastClickedButton = "kines";
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_bm_Seances_clicked()
{
    lastClickedButton = "seance";
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_bm_Machines_clicked()
{
    lastClickedButton = "machine";
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_bm_Salles_clicked()
{
    lastClickedButton = "salle";
    ui->stackedWidget->setCurrentIndex(12);
}













    QTableWidget* MainWindow::getTablePatient() {
        return ui->table_patient;
    }















//Tri :














//Trier table salle
void MainWindow::sort_table_salle()
{
    if(ui->comboBox_6->currentText()=="Nom")
    {
        ui->table_salle->sortByColumn(1,Qt::AscendingOrder);
    }
    if(ui->comboBox_6->currentText()=="Location")
    {
        ui->table_salle->sortByColumn(3,Qt::AscendingOrder);
    }
    if(ui->comboBox_6->currentText()=="Capacite")
    {
        ui->table_salle->sortByColumn(2,Qt::AscendingOrder);
    }
    if(ui->comboBox_6->currentText()=="ID")
     {
        int rowCount = ui->table_salle->rowCount();

        // Créez une liste pour stocker les valeurs de la colonne spécifiée
        QVector<int> values;

        // Remplissez la liste avec les valeurs de la colonne spécifiée
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = ui->table_salle->item(row, 0);
            if (item) {
                values.append(item->text().toInt());
            }
        }

        // Déclarez la variable order
        Qt::SortOrder order = Qt::AscendingOrder;  // ou Qt::DescendingOrder selon votre besoin

        // Tri de la liste
        QVector<int> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end(), [order](int a, int b) {
            return (order == Qt::AscendingOrder) ? (a < b) : (a > b);
        });

        // Réorganisez les lignes du tableau selon l'ordre trié
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(sortedValues[row]));
            ui->table_salle->setItem(row, 0, item);
        }

               }
           }
//Trier table machine
void MainWindow::sort_table_machine()
{
    if(ui->comboBox_4->currentText()=="Nom")
    {
        ui->table_machine->sortByColumn(2,Qt::AscendingOrder);
    }
    if(ui->comboBox_4->currentText()=="Description")
    {
        ui->table_machine->sortByColumn(3,Qt::AscendingOrder);
    }
    if(ui->comboBox_4->currentText()=="Etat")
    {
        ui->table_machine->sortByColumn(4,Qt::AscendingOrder);
    }
    if(ui->comboBox_4->currentText()=="ID")
     {
        int rowCount = ui->table_machine->rowCount();

        // Créez une liste pour stocker les valeurs de la colonne spécifiée
        QVector<int> values;

        // Remplissez la liste avec les valeurs de la colonne spécifiée
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = ui->table_machine->item(row, 0);
            if (item) {
                values.append(item->text().toInt());
            }
        }

        // Déclarez la variable order
        Qt::SortOrder order = Qt::AscendingOrder;  // ou Qt::DescendingOrder selon votre besoin

        // Tri de la liste
        QVector<int> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end(), [order](int a, int b) {
            return (order == Qt::AscendingOrder) ? (a < b) : (a > b);
        });

        // Réorganisez les lignes du tableau selon l'ordre trié
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(sortedValues[row]));
            ui->table_machine->setItem(row, 0, item);
        }

               }
           }
//Trier table patient
void MainWindow::sort_table_patient()
{
    if(ui->comboBox->currentText()=="Nom")
    {
        ui->table_patient->sortByColumn(3,Qt::AscendingOrder);
    }
    if(ui->comboBox->currentText()=="Prenom")
    {
        ui->table_patient->sortByColumn(2,Qt::AscendingOrder);
    }
    if(ui->comboBox->currentText()=="Naissance")
    {
        ui->table_patient->sortByColumn(4,Qt::AscendingOrder);
    }
    if(ui->comboBox->currentText()=="Telephone")
    {
        ui->table_patient->sortByColumn(5,Qt::AscendingOrder);
    }
    if(ui->comboBox->currentText()=="Sexe")
    {
        ui->table_patient->sortByColumn(6,Qt::AscendingOrder);
    }
    if(ui->comboBox->currentText()=="Dos_Med")
    {
        ui->table_patient->sortByColumn(7,Qt::AscendingOrder);
    }
    if(ui->comboBox->currentText()=="ID")
     {
        int rowCount = ui->table_patient->rowCount();

        // Créez une liste pour stocker les valeurs de la colonne spécifiée
        QVector<int> values;

        // Remplissez la liste avec les valeurs de la colonne spécifiée
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = ui->table_patient->item(row, 0);
            if (item) {
                values.append(item->text().toInt());
            }
        }

        // Déclarez la variable order
        Qt::SortOrder order = Qt::AscendingOrder;  // ou Qt::DescendingOrder selon votre besoin

        // Tri de la liste
        QVector<int> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end(), [order](int a, int b) {
            return (order == Qt::AscendingOrder) ? (a < b) : (a > b);
        });

        // Réorganisez les lignes du tableau selon l'ordre trié
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(sortedValues[row]));
            ui->table_patient->setItem(row, 0, item);
        }

               }
           }
//Trier table kine
void MainWindow::sort_table_kine()
{
    if(ui->comboBox_2->currentText()=="Nom")
    {
        ui->table_kine->sortByColumn(3,Qt::AscendingOrder);
    }
    if(ui->comboBox_2->currentText()=="Prenom")
    {
        ui->table_kine->sortByColumn(2,Qt::AscendingOrder);
    }
    if(ui->comboBox_2->currentText()=="Naissance")
    {
        ui->table_kine->sortByColumn(4,Qt::AscendingOrder);
    }
    if(ui->comboBox_2->currentText()=="Telephone")
    {
        ui->table_kine->sortByColumn(5,Qt::AscendingOrder);
    }
    if(ui->comboBox_2->currentText()=="Sexe")
    {
        ui->table_kine->sortByColumn(6,Qt::AscendingOrder);
    }
    if(ui->comboBox_2->currentText()=="Cv")
    {
        ui->table_kine->sortByColumn(7,Qt::AscendingOrder);
    }
    if(ui->comboBox_2->currentText()=="ID")
     {
        int rowCount = ui->table_kine->rowCount();

        // Créez une liste pour stocker les valeurs de la colonne spécifiée
        QVector<int> values;

        // Remplissez la liste avec les valeurs de la colonne spécifiée
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = ui->table_kine->item(row, 0);
            if (item) {
                values.append(item->text().toInt());
            }
        }

        // Déclarez la variable order
        Qt::SortOrder order = Qt::AscendingOrder;  // ou Qt::DescendingOrder selon votre besoin

        // Tri de la liste
        QVector<int> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end(), [order](int a, int b) {
            return (order == Qt::AscendingOrder) ? (a < b) : (a > b);
        });

        // Réorganisez les lignes du tableau selon l'ordre trié
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(sortedValues[row]));
            ui->table_kine->setItem(row, 0, item);
        }

               }
           }
//Trier la table seance
void MainWindow::sort_table_seance()
{
    if(ui->comboBox_3->currentText()=="Date")
    {
        ui->table_seance->sortByColumn(1,Qt::AscendingOrder);
    }
    if(ui->comboBox_3->currentText()=="Heure_d")
    {
        ui->table_seance->sortByColumn(2,Qt::AscendingOrder);
    }
    if(ui->comboBox_3->currentText()=="Heure_fin")
    {
        ui->table_seance->sortByColumn(3,Qt::AscendingOrder);
    }
    if(ui->comboBox_3->currentText()=="Type")
    {
        ui->table_seance->sortByColumn(4,Qt::AscendingOrder);
    }
    if(ui->comboBox_3->currentText()=="ID")
     {
        int rowCount = ui->table_seance->rowCount();

        // Créez une liste pour stocker les valeurs de la colonne spécifiée
        QVector<int> values;

        // Remplissez la liste avec les valeurs de la colonne spécifiée
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = ui->table_seance->item(row, 0);
            if (item) {
                values.append(item->text().toInt());
            }
        }

        // Déclarez la variable order
        Qt::SortOrder order = Qt::AscendingOrder;  // ou Qt::DescendingOrder selon votre besoin

        // Tri de la liste
        QVector<int> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end(), [order](int a, int b) {
            return (order == Qt::AscendingOrder) ? (a < b) : (a > b);
        });

        // Réorganisez les lignes du tableau selon l'ordre trié
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(sortedValues[row]));
            ui->table_seance->setItem(row, 0, item);
        }

               }
           }
//Trier la table employe
void MainWindow::sort_table_employe()
{
    if(ui->comboBox_5->currentText()=="Nom")
    {
        ui->table_employe->sortByColumn(2,Qt::AscendingOrder);
    }
    if(ui->comboBox_5->currentText()=="Prenom")
    {
        ui->table_employe->sortByColumn(1,Qt::AscendingOrder);
    }
    if(ui->comboBox_5->currentText()=="Date_embauche")
    {
        ui->table_employe->sortByColumn(3,Qt::AscendingOrder);
    }
    if(ui->comboBox_5->currentText()=="Role")
    {
        ui->table_employe->sortByColumn(4,Qt::AscendingOrder);
    }
    if(ui->comboBox_5->currentText()=="Sexe")
    {
        ui->table_employe->sortByColumn(5,Qt::AscendingOrder);
    }
    if(ui->comboBox_5->currentText()=="Login")
    {
        ui->table_employe->sortByColumn(6,Qt::AscendingOrder);
    }
    if(ui->comboBox_5->currentText()=="ID")
     {
        int rowCount = ui->table_employe->rowCount();

        // Créez une liste pour stocker les valeurs de la colonne spécifiée
        QVector<int> values;

        // Remplissez la liste avec les valeurs de la colonne spécifiée
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = ui->table_employe->item(row, 0);
            if (item) {
                values.append(item->text().toInt());
            }
        }

        // Déclarez la variable order
        Qt::SortOrder order = Qt::AscendingOrder;  // ou Qt::DescendingOrder selon votre besoin

        // Tri de la liste
        QVector<int> sortedValues = values;
        std::sort(sortedValues.begin(), sortedValues.end(), [order](int a, int b) {
            return (order == Qt::AscendingOrder) ? (a < b) : (a > b);
        });

        // Réorganisez les lignes du tableau selon l'ordre trié
        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(sortedValues[row]));
            ui->table_employe->setItem(row, 0, item);
        }

               }
           }

















//export to pdf












//export to pdf patient
void MainWindow::on_pdf_patient_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;

        // Configuration de la police et du titre
        QTextBlockFormat titleFormat;
        titleFormat.setAlignment(Qt::AlignHCenter);

        QTextCharFormat titleCharFormat;
        titleCharFormat.setFontPointSize(16);

        // Ajout du titre au document
        QTextCursor cursor(&doc);
        cursor.insertBlock(titleFormat);
        cursor.setCharFormat(titleCharFormat);
        cursor.insertText("Tableau des Patients");
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock();

        QTableWidget *tableWidget = ui->table_patient;
        int rowCount = tableWidget->rowCount();
        int columnCount = tableWidget->columnCount();

        // Insertion du tableau au document
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);

        QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

        // Remplissage du tableau avec les données du QTableWidget //
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                QString text = (item ? item->text() : "");

                // Insertion des données dans les cellules du tableau
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(text);
            }
        }

        // Définition des en-têtes de colonne
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
            QString headerText = (headerItem ? headerItem->text() : "");

            // Insertion des en-têtes dans la première ligne du tableau
            QTextTableCell cell = table->cellAt(0, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(headerText);
        }

        // Configuration de l'imprimante pour exporter le document texte au format PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // Impression du document texte sur l'imprimante
        doc.print(&printer);

        // Affichage d'un message de confirmation
        QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    }
}
//export to pdf seance
void MainWindow::on_pdf_seance_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;

        // Configuration de la police et du titre
        QTextBlockFormat titleFormat;
        titleFormat.setAlignment(Qt::AlignHCenter);

        QTextCharFormat titleCharFormat;
        titleCharFormat.setFontPointSize(16);

        // Ajout du titre au document
        QTextCursor cursor(&doc);
        cursor.insertBlock(titleFormat);
        cursor.setCharFormat(titleCharFormat);
        cursor.insertText("Tableau des Séances");
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock();

        QTableWidget *tableWidget = ui->table_seance;
        int rowCount = tableWidget->rowCount();
        int columnCount = tableWidget->columnCount();

        // Insertion du tableau au document
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);

        QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

        // Remplissage du tableau avec les données du QTableWidget //
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                QString text = (item ? item->text() : "");

                // Insertion des données dans les cellules du tableau
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(text);
            }
        }

        // Définition des en-têtes de colonne
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
            QString headerText = (headerItem ? headerItem->text() : "");

            // Insertion des en-têtes dans la première ligne du tableau
            QTextTableCell cell = table->cellAt(0, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(headerText);
        }

        // Configuration de l'imprimante pour exporter le document texte au format PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // Impression du document texte sur l'imprimante
        doc.print(&printer);

        // Affichage d'un message de confirmation
        QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    }
}
//export to pdf kine
void MainWindow::on_pdf_kine_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;

        // Configuration de la police et du titre
        QTextBlockFormat titleFormat;
        titleFormat.setAlignment(Qt::AlignHCenter);

        QTextCharFormat titleCharFormat;
        titleCharFormat.setFontPointSize(16);

        // Ajout du titre au document
        QTextCursor cursor(&doc);
        cursor.insertBlock(titleFormat);
        cursor.setCharFormat(titleCharFormat);
        cursor.insertText("Tableau des kines");
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock();

        QTableWidget *tableWidget = ui->table_kine;
        int rowCount = tableWidget->rowCount();
        int columnCount = tableWidget->columnCount();

        // Insertion du tableau au document
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);

        QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

        // Remplissage du tableau avec les données du QTableWidget //
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                QString text = (item ? item->text() : "");

                // Insertion des données dans les cellules du tableau
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(text);
            }
        }

        // Définition des en-têtes de colonne
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
            QString headerText = (headerItem ? headerItem->text() : "");

            // Insertion des en-têtes dans la première ligne du tableau
            QTextTableCell cell = table->cellAt(0, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(headerText);
        }

        // Configuration de l'imprimante pour exporter le document texte au format PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // Impression du document texte sur l'imprimante
        doc.print(&printer);

        // Affichage d'un message de confirmation
        QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    }
}
//export to pdf employe
void MainWindow::on_pdf_employe_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;

        // Configuration de la police et du titre
        QTextBlockFormat titleFormat;
        titleFormat.setAlignment(Qt::AlignHCenter);

        QTextCharFormat titleCharFormat;
        titleCharFormat.setFontPointSize(16);

        // Ajout du titre au document
        QTextCursor cursor(&doc);
        cursor.insertBlock(titleFormat);
        cursor.setCharFormat(titleCharFormat);
        cursor.insertText("Tableau des Employe");
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock();

        QTableWidget *tableWidget = ui->table_employe;
        int rowCount = tableWidget->rowCount();
        int columnCount = tableWidget->columnCount();

        // Insertion du tableau au document
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);

        QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

        // Remplissage du tableau avec les données du QTableWidget //
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                QString text = (item ? item->text() : "");

                // Insertion des données dans les cellules du tableau
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(text);
            }
        }

        // Définition des en-têtes de colonne
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
            QString headerText = (headerItem ? headerItem->text() : "");

            // Insertion des en-têtes dans la première ligne du tableau
            QTextTableCell cell = table->cellAt(0, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(headerText);
        }

        // Configuration de l'imprimante pour exporter le document texte au format PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // Impression du document texte sur l'imprimante
        doc.print(&printer);

        // Affichage d'un message de confirmation
        QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    }
}
//export to pdf salle
void MainWindow::on_pdf_salle_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;

        // Configuration de la police et du titre
        QTextBlockFormat titleFormat;
        titleFormat.setAlignment(Qt::AlignHCenter);

        QTextCharFormat titleCharFormat;
        titleCharFormat.setFontPointSize(16);

        // Ajout du titre au document
        QTextCursor cursor(&doc);
        cursor.insertBlock(titleFormat);
        cursor.setCharFormat(titleCharFormat);
        cursor.insertText("Tableau des Salles");
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock();

        QTableWidget *tableWidget = ui->table_salle;
        int rowCount = tableWidget->rowCount();
        int columnCount = tableWidget->columnCount();

        // Insertion du tableau au document
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);

        QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

        // Remplissage du tableau avec les données du QTableWidget //
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                QString text = (item ? item->text() : "");

                // Insertion des données dans les cellules du tableau
                QTextTableCell cell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(text);
            }
        }

        // Définition des en-têtes de colonne
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
            QString headerText = (headerItem ? headerItem->text() : "");

            // Insertion des en-têtes dans la première ligne du tableau
            QTextTableCell cell = table->cellAt(0, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(headerText);
        }

        // Configuration de l'imprimante pour exporter le document texte au format PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // Impression du document texte sur l'imprimante
        doc.print(&printer);

        // Affichage d'un message de confirmation
        QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    }
}
//export to pdf machine
void MainWindow::on_pdf_machine_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (!filename.isEmpty()) {
        QTextDocument doc;

        // Configuration de la police et du titre
        QTextBlockFormat titleFormat;
        titleFormat.setAlignment(Qt::AlignHCenter);

        QTextCharFormat titleCharFormat;
        titleCharFormat.setFontPointSize(16);

        // Ajout du titre au document
        QTextCursor cursor(&doc);
        cursor.insertBlock(titleFormat);
        cursor.setCharFormat(titleCharFormat);
        cursor.insertText("Tableau des Machines");
        cursor.setCharFormat(QTextCharFormat());
        cursor.insertBlock();

        QTableWidget *tableWidget = ui->table_machine;
        int rowCount = tableWidget->rowCount();
        int columnCount = tableWidget->columnCount();

        // Insertion du tableau au document
        QTextTableFormat tableFormat;
        tableFormat.setBorder(1);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setAlignment(Qt::AlignHCenter);

        QTextTable *table = cursor.insertTable(rowCount + 1, columnCount, tableFormat);

        // Iterate through the table and insert data and images
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                QString text = (item ? item->text() : "");

                // Check if the cell contains an image
                if (item && item->data(Qt::UserRole).isValid()) {
                    QImage image = qvariant_cast<QImage>(item->data(Qt::UserRole));

                    // Insert the image into the document
                    QTextImageFormat imageFormat;
                    imageFormat.setWidth(100); // Set the width of the image as per your requirement
                    imageFormat.setHeight(100); // Set the height of the image as per your requirement
                    cursor.insertImage(imageFormat);
                    cursor.movePosition(QTextCursor::Right); // Move the cursor to the next cell
                } else {
                    // Insert data into the cell if it's not an image
                    QTextTableCell cell = table->cellAt(row + 1, col);
                    QTextCursor cellCursor = cell.firstCursorPosition();
                    cellCursor.insertText(text);
                }
            }
        }

        // Définition des en-têtes de colonne
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
            QString headerText = (headerItem ? headerItem->text() : "");

            // Insertion des en-têtes dans la première ligne du tableau
            QTextTableCell cell = table->cellAt(0, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(headerText);
        }

        // Configuration de l'imprimante pour exporter le document texte au format PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // Impression du document texte sur l'imprimante
        doc.print(&printer);

        // Affichage d'un message de confirmation
        QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    }
}


































//Ajout















//Ajouter Salle
void MainWindow::on_s_v_clicked()
{
    QString nom = ui->nomEdit_6->text();
    QString capaciteText = ui->numeroEdit_7->text();
    int capacite = capaciteText.toInt();
    QString location = ui->numeroEdit_150->text();

    // Contrôle de saisie sur le nom (chiffres et lettres, pas de caractères spéciaux)
    QRegExp nomRegex("^[A-Za-z0-9]+$");
    if (!nomRegex.exactMatch(nom))
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"),
                             QObject::tr("Le nom doit contenir uniquement des chiffres et des lettres, sans caractères spéciaux."),
                             QMessageBox::Cancel);
        return;  // Arrêter la fonction en cas d'erreur de saisie
    }

    // Nettoyer la chaîne de capacité pour enlever les espaces non visibles ou autres caractères non numériques
    capaciteText = capaciteText.simplified();

    // Contrôle de saisie sur la capacité (doit être composée de chiffres seulement)
    bool capaciteIsNumber;
     capacite = capaciteText.toInt(&capaciteIsNumber);
    if (!capaciteIsNumber)
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"),
                             QObject::tr("La capacité doit être composée de chiffres seulement."),
                             QMessageBox::Cancel);
        return;  // Arrêter la fonction en cas d'erreur de saisie
    }

    // Contrôle de saisie sur la localisation (chiffres et lettres, pas de caractères spéciaux)
    // Contrôle de saisie sur la localisation (chiffres, lettres, espaces, et caractères spécifiques)
    QRegExp locationRegex("^[A-Za-z0-9éà@è\\s]+$");
    if (!locationRegex.exactMatch(location)) {
        QMessageBox::critical(this, "Erreur", "La localisation doit contenir des chiffres, des lettres, des espaces, et les caractères spéciaux {é, à, @, è}.");
        return;
    }


    // Vérification si la salle existe déjà
    if (salleExisteDeja(nom, capacite, location))
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur d'ajout"),
                             QObject::tr("La salle existe déjà.\n "
                                         "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        return;
    }

    salle s(nom, capacite, location);
    bool test = s.ajouter();

    if (test)
    {
        std::wstring titre = L"ajout de la salle";
            std::wstring message = L"Une nouvelle salle a été ajoutée.";
            s.showNotification(titre, message);
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Ajout avec succès.\n "
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_salle.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                        qDebug() << "Impossible d'ouvrir le fichier.";
                        return;
                    }

                    // Obtenir la date et l'heure actuelles
                    QDateTime currentDateTime = QDateTime::currentDateTime();
                    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                    // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                    QTextStream out(&file);
                    out<< "<font color=\"green\">"  << formattedDateTime << "la salle avec nom : " <<nom<<" et capacite : "<<capacite<<" a ete ajoute"<<endl; // endl ajoute un saut de ligne
                    file.close();

        ui->nomEdit_6->clear();
        ui->numeroEdit_7->clear();
        ui->numeroEdit_150->clear();
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Not Ok"),
                                 QObject::tr("Ajout impossible.\n "
                                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
//Ajouter kine
QByteArray MainWindow::on_pushButton_29_clicked()
{
    // Sélectionnez le fichier image
        QString imagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), QCoreApplication::applicationDirPath(), tr("PNG Files (*.PNG)"));

        QPixmap image(imagePath);
        QPixmap circularImage(image.size());
        circularImage.fill(Qt::transparent);

        if (!image.isNull()) {
            QPainter painter(&circularImage);
            QPainterPath path;
            path.addEllipse(image.rect());

            painter.setClipPath(path);
            painter.drawPixmap(0, 0, image);

            ui->label_imageP_2->setPixmap(circularImage.scaled(ui->label_imageP_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Failed to load image: " << imagePath;
        }

        QBuffer imageBufferData;
        if (imageBufferData.open(QIODevice::ReadWrite)) {
            circularImage.save(&imageBufferData, "PNG");
        }
        imageData= imageBufferData.buffer().toBase64();
        QFileInfo fileInfo(imagePath);
        QString imageName = fileInfo.fileName();

        qDebug() << "Size of QByteArray: " << imageData.size();

        return imageData;

}
void MainWindow::on_button_valider_ajout_kine_clicked()
{
    QString nom = ui->nom_kine->text();
    QString prenom = ui->prenom_kine->text();
    QString tel = ui->numero_kine->text();
    QString date_n = ui->date_kine->date().toString();
    int tel_ = tel.toUInt();
    QString sexe = ui->sexe_kine->currentText();
    QString specialite=ui->comboBox_7->currentText();
    QString cv=ui->cv_kine->text();


    QByteArray image = imageData;

    // Validate nom (only letters and specified characters)
    QRegExp nomRegex("^[a-zA-ZéàçèÉÀÇÈ]+$");
    if (!nomRegex.exactMatch(nom)) {
        QMessageBox::critical(this, "Erreur", "Nom invalide. Veuillez saisir uniquement des lettres et les caractères {é, à, ç, è}.");
        return;
    }

    // Validate prenom (only letters and specified characters)
    QRegExp prenomRegex("^[a-zA-ZéàçèÉÀÇÈ]+$");
    if (!prenomRegex.exactMatch(prenom)) {
        QMessageBox::critical(this, "Erreur", "Prénom invalide. Veuillez saisir uniquement des lettres et les caractères {é, à, ç, è}.");
        return;
    }

    // Validate telephone (8 digits)
    QRegExp telephoneRegex("^\\d{8}$");
    if (!telephoneRegex.exactMatch(tel)) {
        QMessageBox::critical(this, "Erreur", "Numéro invalide. Veuillez saisir 8 chiffres.");
        return;
    }

    // Validate date de naissance (not exceeding today's date)
    QDate currentDate = QDate::currentDate();
    QDate inputDate = ui->date_kine->date();
    if (inputDate > currentDate) {
        QMessageBox::critical(this, "Erreur", "La date de naissance ne peut pas dépasser la date d'aujourd'hui.");
        return;
    }


    kine k(nom,prenom,sexe,tel_,date_n,image,specialite,cv);
    bool test = k.ajouter_kine();
    if (test)
    {
        std::wstring titre = L"ajout de la kiné";
            std::wstring message = L"Un nouveau kiné a été ajouté (e).";
            k.showNotification(titre, message);

        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("l'ajout est effectué\n"
                                             "click cancel to exit . "), QMessageBox::Cancel);


        QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_kine.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                        qDebug() << "Impossible d'ouvrir le fichier.";
                        return;
                    }

                    // Obtenir la date et l'heure actuelles
                    QDateTime currentDateTime = QDateTime::currentDateTime();
                    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                    // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                    QTextStream out(&file);
                    out<< "<font color=\"green\">"  << formattedDateTime << "le kine avec nom : " <<nom<<" et prenom : "<<prenom<<" a ete ajoute"<<endl; // endl ajoute un saut de ligne
                    file.close();

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                 QObject::tr("connection failed.\n "
                                             "click cancel to exit . "), QMessageBox::Cancel);
    }

    ui->table_kine->viewport()->update();
    ui->label_imageP_2->clear();
    ui->nom_kine->clear();
    ui->prenom_kine->clear();
    ui->numero_kine->clear();
    ui->cv_kine->clear();
}
//Ajouter Machine
QByteArray MainWindow::on_pushButton_18_clicked()
{

    QString imagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), QCoreApplication::applicationDirPath(), tr("PNG Files (*.PNG)"));

    QPixmap image(imagePath);
    QPixmap circularImage(image.size());
    circularImage.fill(Qt::transparent);

    if (!image.isNull()) {
        QPainter painter(&circularImage);
        QPainterPath path;
        path.addEllipse(image.rect());

        painter.setClipPath(path);
        painter.drawPixmap(0, 0, image);

        ui->label_imageM->setPixmap(circularImage.scaled(ui->label_imageM->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Failed to load image: " << imagePath;
    }

    QBuffer imageBufferData;
    if (imageBufferData.open(QIODevice::ReadWrite)) {
        circularImage.save(&imageBufferData, "PNG");
    }
    imageData = imageBufferData.buffer().toBase64();
    QFileInfo fileInfo(imagePath);
    QString imageName = fileInfo.fileName();

    qDebug() << "Size of QByteArray: " << imageData.size();

    return imageData;
}
void MainWindow::on_pushButton_32_clicked() {
    QByteArray image = imageData;  // Assuming imageData is declared and initialized elsewhere
    qDebug() << imageData;

    QString nom = ui->numeroEdit_10->text();
    QString description = ui->numeroEdit_6->text();
    QString etat;

    if (ui->radioButton->isChecked()) {
        etat = ui->radioButton->text();
    } else if (ui->radioButton_2->isChecked()) {
        etat = ui->radioButton_2->text();
    }

    // Vérification du champ image
    if (image.isEmpty()) {
        qDebug() << "Image data is empty";
        QMessageBox::critical(this, "Erreur", "L'image ne peut pas être vide.");
        return;
    }

    // Vérification du nom
    QRegExp nomRegExp("^[a-zA-Zéçà@è]+$");
    if (nom.isEmpty() || !nomRegExp.exactMatch(nom)) {
        QMessageBox::critical(this, "Erreur", "Le nom doit être une chaîne de caractères incluant é, ç, à, @, è et ne peut pas être vide.");
        return;
    }

    // Vérification de la longueur de la description
    if (description.length() > 100) {
        QMessageBox::critical(this, "Erreur", "La description ne doit pas dépasser 100 caractères.");
        return;
    }

    // Vérification de l'état
    if (etat.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "L'état ne peut pas être vide.");
        return;
    }

    // Vérification de l'unicité du nom dans le tableau d'affichage
    if (isNomExists(nom)) {
        QMessageBox::critical(this, "Erreur", "Le nom doit être unique dans le tableau d'affichage.");
        return;
    }

    machine machine(image, nom, description, etat);

    // Si l'ajout est réussi
    if (machine.ajouter()) {
        std::wstring titre = L"ajout de la machine";
            std::wstring message = L"Une nouvelle machine a été ajoutée.";
            machine.showNotification(titre, message);
        QMessageBox::information(this, "Succès", "Les données du patient ont été ajoutées avec succès.");
        QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_machine.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                        qDebug() << "Impossible d'ouvrir le fichier.";
                        return;
                    }

                    // Obtenir la date et l'heure actuelles
                    QDateTime currentDateTime = QDateTime::currentDateTime();
                    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                    // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                    QTextStream out(&file);
                    out<< "<font color=\"green\">"  << formattedDateTime << "la machine avec nom : " <<nom<<" et etat : "<<etat<<" a ete ajoute"<<endl; // endl ajoute un saut de ligne
                    file.close();

                    // Réinitialiser les champs
                    ui->numeroEdit_10->clear();
                    ui->numeroEdit_6->clear();
                    ui->label_imageM->clear();

                    ui->radioButton->setChecked(false);
                    ui->radioButton_2->setChecked(false);


    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de l'ajout des données du patient.");
    }
}
//Ajouter Patient
QByteArray MainWindow::on_add_img_pat_clicked()
{
  QString imagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), QCoreApplication::applicationDirPath(), tr("PNG Files (*.PNG)"));

  QPixmap image(imagePath);
  QPixmap circularImage(image.size());
  circularImage.fill(Qt::transparent);

  if (!image.isNull()) {
      QPainter painter(&circularImage);
      QPainterPath path;
      path.addEllipse(image.rect());

      painter.setClipPath(path);
      painter.drawPixmap(0, 0, image);

      ui->label_imageP->setPixmap(circularImage.scaled(ui->label_imageP->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  } else {
      qDebug() << "Failed to load image: " << imagePath;
  }

  QBuffer imageBufferData;
  if (imageBufferData.open(QIODevice::ReadWrite)) {
      circularImage.save(&imageBufferData, "PNG");
  }
  imageData = imageBufferData.buffer().toBase64();
  QFileInfo fileInfo(imagePath);
  QString imageName = fileInfo.fileName();

  qDebug() << "Size of QByteArray: " << imageData.size();

  return imageData;
}



void MainWindow::on_valider_pat_clicked()
{
   QString prenom = ui->LineEdit_prenom_pat->text();
   QString nom = ui->LineEdit_nom_pat->text();
   QString telephone_str = ui->LineEdit_num_pat->text();
       int telephone = telephone_str.toInt();

   QString dos_med = ui->LineEdit_doc_pat->text();
   QString sexe = ui->comboBox_sexe_pat->currentText();
   QDate naissance = ui->dateEdit_N_pat->date();

   QRegExp rx("^[a-zA-Z ]+$");
   QRegExp rx_num("\\d+");

  if(!rx.exactMatch(prenom)) {
       QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres.");
       return;
   }
  if(!rx.exactMatch(nom)) {
       QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres.");
       return;
   }
      if(telephone_str.length() != 8) {
          QMessageBox::critical(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
          return;
      }
   if(prenom.isEmpty() || nom.isEmpty() || dos_med.isEmpty() || sexe.isEmpty()) {
           QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
           return;
       }
   QByteArray image =imageData;
   qDebug() << imageData;
   Patient patient(prenom, nom, telephone, dos_med, sexe, naissance, image);

   if (patient.ajouter()) {
       std::wstring titre = L"ajout de la patient";
           std::wstring message = L"Un nouveau patient a été ajouté.";
           patient.showNotification(titre, message);
       QMessageBox::information(this, "Succès", "Les données du patient ont été ajoutées avec succès.");

       ui->LineEdit_prenom_pat->clear();
       ui->LineEdit_nom_pat->clear();
       ui->LineEdit_num_pat->clear();
       ui->LineEdit_doc_pat->clear();
       ui->label_imageP->clear();
   } else {
       QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de l'ajout des données du patient.");
   }
}
void MainWindow::checkInput() {
    QString prenom = ui->LineEdit_prenom_pat->text().trimmed();
    QString nom = ui->LineEdit_nom_pat->text().trimmed();
    QString telephone_str = ui->LineEdit_num_pat->text();

    QRegExp rx("^[a-zA-Z ]+$");
    QRegExp rx_num("\\d+");
 if(!prenom.isEmpty()){
   if(!rx.exactMatch(prenom)) {
        QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres.");
         ui->LineEdit_prenom_pat->clear();
        return;
    }}
if (!nom.isEmpty()){
     if(!rx.exactMatch(nom)) {
        QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres.");
        return;
        ui->LineEdit_nom_pat->clear();
    }}

   if(!telephone_str.isEmpty()){
  if(!rx_num.exactMatch(telephone_str)) {
        QMessageBox::critical(this, "Erreur", "Le numéro de téléphone ne doit contenir que des chiffres.");
       ui->LineEdit_num_pat->clear();
        return;
    }  }

}
void MainWindow::validateUpdate_pat() {

   QString prenom = ui->LineEdit_prenom_pat->text();
   QString nom = ui->LineEdit_nom_pat->text();
   QString telephone_str = ui->LineEdit_num_pat->text();
       int telephone = telephone_str.toInt();
   QString dos_med = ui->LineEdit_doc_pat->text();
   QString sexe = ui->comboBox_sexe_pat->currentText();
   QDate naissance = ui->dateEdit_N_pat->date();

QByteArray image2 =imageData;
  /*if (image2.isEmpty()) {
          qDebug() << "Image data is empty";
          return;
      }*/
    QRegExp rx_num("\\d+");
    if(!telephone_str.isEmpty()){
       if(!rx_num.exactMatch(telephone_str)) {
          QMessageBox::critical(this, "Erreur", "Le numéro de téléphone ne doit contenir que des chiffres.");

          return;
      } }

  QRegExp rx("[a-zA-Z]+");
  if(!prenom.isEmpty()){
    if(!rx.exactMatch(prenom)) {
         QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres.");
         return;
     }}
 if (!nom.isEmpty()){
      if(!rx.exactMatch(nom)) {
         QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres.");
         return;
     }}
   if(prenom.isEmpty() || nom.isEmpty() || dos_med.isEmpty() || sexe.isEmpty()) {
       QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
     return;
   }
   if(telephone_str.length() != 8) {
       QMessageBox::critical(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
       return;
   }

   Patient patient(prenom, nom, telephone, dos_med, sexe, naissance, image2);

   bool modificationResult=patient.modifier(id_patient,image2);

   if (modificationResult) {
       std::wstring titre = L"Modification de la patient";
           std::wstring message = L"Un nouveau patient a été ajouté.";
           patient.showNotification(titre, message);
       QMessageBox::information(this, "Succès", "Les données du patient ont été modifiées avec succès.");

       ui->LineEdit_prenom_pat->clear();
       ui->LineEdit_nom_pat->clear();
       ui->LineEdit_num_pat->clear();
       ui->LineEdit_doc_pat->clear();
       ui->label_imageP->clear();

   } else {
       QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la modification des données du patient.");
   }


}
//Ajout Séance
void MainWindow::on_pushButton_26_clicked() {
    QString heure_debut = ui->H_D_seance->text();
    QString heure_fin = ui->H_F_seance->text();
    QString type = ui->type_seance->text();
    QDate date_s = ui->date_exercice_seance->date();

    // Contrôle de saisie sur la date (ne doit pas dépasser la date d'aujourd'hui)
    if (date_s > QDate::currentDate()) {
        QMessageBox::critical(this, "Erreur", "La date ne doit pas dépasser la date d'aujourd'hui.");
        return;
    }

    // Contrôle de saisie sur l'heure (format heure:minute)
    QRegExp heureRegExp("^[0-2]?[0-9]:[0-5][0-9]$");
    if (!heureRegExp.exactMatch(heure_debut) || !heureRegExp.exactMatch(heure_fin)) {
        QMessageBox::critical(this, "Erreur", "L'heure doit être au format heure:minute (ex. 08:30).");
        return;
    }

    // Vérifier si les champs sont vides
        if(heure_debut.isEmpty() || heure_fin.isEmpty() || type.isEmpty()) {
            QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
            return; // Arrêter l'exécution de la fonction
        }

        // Vérifier si le champ "type" contient uniquement des lettres
        QRegularExpression regex("^[a-zA-Z]+$");
        if (!regex.match(type).hasMatch()) {
            QMessageBox::warning(this, "Format incorrect", "Le champ 'type' doit contenir uniquement des lettres.");
            return; // Arrêter l'exécution de la fonction
        }

    // Contrôle de saisie sur l'ordre des heures (heure début doit être avant heure fin)
    QTime time_debut = QTime::fromString(heure_debut, "hh:mm");
    QTime time_fin = QTime::fromString(heure_fin, "hh:mm");
    if (time_debut >= time_fin) {
        QMessageBox::critical(this, "Erreur", "L'heure de début doit être avant l'heure de fin.");
        return;
    }

    seance seance(heure_debut, heure_fin, type, date_s);
    seance.setEtat("non validée");
    bool test = seance.ajouter();

    if (test) {
        std::wstring titre = L"ajout de la séance";
            std::wstring message = L"Une nouvelle séance a été ajoutée.";
            seance.showNotification(titre, message);
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Ajout avec succès.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_seance.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                        qDebug() << "Impossible d'ouvrir le fichier.";
                        return;
                    }

                    // Obtenir la date et l'heure actuelles
                    QDateTime currentDateTime = QDateTime::currentDateTime();
                    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                    // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                    QTextStream out(&file);
                    out<< "<font color=\"green\">"  << formattedDateTime << "la séance avec heure début : " <<heure_debut<<" et heure fin : "<<heure_fin<<" a ete ajoute"<<endl; // endl ajoute un saut de ligne
                    file.close();

        // Réinitialiser les champs
        ui->H_D_seance->clear();
        ui->H_F_seance->clear();
        ui->type_seance->clear();
        ui->date_exercice_seance->setDate(QDate::currentDate());
    } else {
        QMessageBox::information(nullptr, QObject::tr("Not Ok"),
                                 QObject::tr("Ajout impossible.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}//Ajout Employe
void MainWindow::on_pushButton_35_clicked() {
    QString nom = ui->nom_kine_3->text();
    QString prenom = ui->prenom_kine_3->text();
    QDate date_embauche = ui->date_kine_3->date();
    QString role = ui->sexe_kine_4->currentText();
    QString sexe = ui->sexe_kine_3->currentText();
    QString login = ui->cv_kine_2->text();
    QString mdp = ui->cv_kine_45->text();
    QString questionSecurite = ui->questionSecuriteComboBox->currentText();
    QString reponseSecurite = ui->reponseSecuriteLineEdit->text();




    // Contrôle de saisie sur la date d'embauche (ne doit pas dépasser la date d'aujourd'hui)
    if (date_embauche > QDate::currentDate()) {
        QMessageBox::critical(this, "Erreur", "La date d'embauche ne peut pas dépasser la date d'aujourd'hui.");
        return;
    }

    // Contrôle de saisie sur le login

    // Contrôle de saisie sur le mot de passe
    // (Vous devrez définir des critères spécifiques pour ce qui est considéré comme un mot de passe fort)
    // Exemple : Au moins 8 caractères avec au moins une majuscule, une minuscule, un chiffre et un caractère spécial
    QRegExp mdpRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%*?&#]{8,}$");
    if (!mdpRegex.exactMatch(mdp)) {
        QMessageBox::critical(this, "Erreur", "Le mot de passe doit être fort, contenant au moins 8 caractères avec au moins une majuscule, une minuscule, un chiffre et un caractère spécial.");
        return;
    }
    QByteArray hashedPassword = QCryptographicHash::hash(mdp.toUtf8(), QCryptographicHash::Sha256).toHex();
        QString hashedPasswordString = QString(hashedPassword);


    employees e(nom, prenom, date_embauche, role, sexe, login, hashedPasswordString, questionSecurite ,reponseSecurite);
    bool test = e.ajouter();

    if (test) {
        std::wstring titre = L"ajout de l'employé";
            std::wstring message = L"Un nouveau employé a été ajoutée.";
            e.showNotification(titre, message);
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Ajout avec succès.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_seance.txt");
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                        qDebug() << "Impossible d'ouvrir le fichier.";
                        return;
                    }

                    // Obtenir la date et l'heure actuelles
                    QDateTime currentDateTime = QDateTime::currentDateTime();
                    QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                    // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                    QTextStream out(&file);
                    out<< "<font color=\"green\">"  << formattedDateTime << "l'employé avec un nom : " <<nom<<" et un prénom : "<<prenom<<" a ete ajoute"<<endl; // endl ajoute un saut de ligne
                    file.close();

        // Réinitialiser les champs
        ui->nom_kine_3->clear();
        ui->prenom_kine_3->clear();
        ui->cv_kine_45->clear();
        ui->cv_kine_2->clear();
        ui->reponseSecuriteLineEdit->clear();
    } else {
        QMessageBox::information(nullptr, QObject::tr("Not Ok"),
                                 QObject::tr("Ajout impossible.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}


//update







//Update Salle
// Fonction pour vérifier si la salle existe déjà
bool MainWindow::salleExisteDeja(const QString& nom, int capacite, const QString& location)
{
    // Mettez ici le code pour vérifier si la salle existe déjà dans votre base de données
    // Vous pouvez utiliser une requête SQL SELECT pour vérifier l'existence de la salle avec les mêmes attributs

    // Exemple (à adapter selon votre structure de base de données)
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SALLE WHERE NOM = :nom AND CAPACITY = :capacite AND LOCATION = :location");
    query.bindValue(":nom", nom);
    query.bindValue(":capacite", capacite);
    query.bindValue(":location", location);

    if (query.exec() && query.next())
    {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false; // En cas d'erreur ou si la salle n'existe pas
}
void MainWindow::updateRow_salle() {
       QPushButton* buttonSender1 = qobject_cast<QPushButton*>(sender());
       if(buttonSender1) {
 qDebug() << "Button sender found.";
           for(int i = 0; i < ui->table_salle->rowCount(); i++) {
               if(ui->table_salle->cellWidget(i, 4) == buttonSender1->parentWidget()) {
                    id_salle = ui->table_salle->item(i, 0)->text().toInt();
                   currentRow_salle = i;
qDebug() <<currentRow_salle;

                   salle salle;
                   salle.setId(id_salle);
             qDebug() <<id_salle;

                   QString nom = ui->table_salle->item(i, 1)->text();
                   int capacite = ui->table_salle->item(i, 2)->text().toInt();
                   QString location = ui->table_salle->item(i, 3)->text();


                   ui->nomEdit_6->setText(nom);
                   ui->numeroEdit_7->setText(QString::number(capacite));
                   ui->numeroEdit_150->setText(location);

                   ui->stackedWidget->setCurrentIndex(13);

                   connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(validateUpdate_salle()));
                                      break;

               }
           }
       }
   }
void MainWindow::validateUpdate_salle() {
    QString nom = ui->nomEdit_6->text();
    QString capaciteText = ui->numeroEdit_7->text();
    int capacite = capaciteText.toInt();

    QString location = ui->numeroEdit_150->text();

    // Contrôle de saisie (omis pour des raisons de concision, ajoutez-le si nécessaire)

    // Vérifier si la salle existe déjà avec les nouvelles valeurs
    if (salleExisteDeja(nom, capacite, location))
    {
        QMessageBox::critical(this, "Erreur", "La salle existe déjà.\n "
                                              "Cliquez sur Annuler pour quitter.", QMessageBox::Cancel);
        return;
    }


    // Contrôle de saisie sur le nom (chiffres ou lettres, pas de caractères spéciaux)
    QRegExp nomRegex("^[A-Za-z0-9]+$");
    if (!nomRegex.exactMatch(nom)) {
        QMessageBox::critical(this, "Erreur", "Le nom doit contenir uniquement des chiffres ou des lettres, sans caractères spéciaux.");
        return;
    }

    // Nettoyer la chaîne de capacité pour enlever les espaces non visibles ou autres caractères non numériques
    capaciteText = capaciteText.simplified();
    bool capaciteIsNumber;
     capacite = capaciteText.toInt(&capaciteIsNumber);
    if (!capaciteIsNumber) {
        QMessageBox::critical(this, "Erreur", "La capacité doit être composée de chiffres seulement.");
        return;
    }

    // Contrôle de saisie sur la localisation (chiffres, lettres, espaces, et caractères spécifiques)
    QRegExp locationRegex("^[A-Za-z0-9éà@è\\s]+$");
    if (!locationRegex.exactMatch(location)) {
        QMessageBox::critical(this, "Erreur", "La localisation doit contenir des chiffres, des lettres, des espaces, et les caractères spéciaux {é, à, @, è}.");
        return;
    }


    // Si toutes les validations sont réussies, procéder à la modification
    salle salle(nom, capacite, location);
    salle.modifier(id_salle);
    if (salle.modifier(id_salle)) {
        std::wstring titre = L"Modification de la salle";
            std::wstring message = L"Une salle a été modifiée.";
            salle.showNotification(titre, message);
        QMessageBox::information(this, "Succès", "Les données de la salle ont été modifiées avec succès.");
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_salle.txt");
                         if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                             qDebug() << "Impossible d'ouvrir le fichier.";
                             return;
                         }

                         // Obtenir la date et l'heure actuelles
                         QDateTime currentDateTime = QDateTime::currentDateTime();
                         QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                         // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                         QTextStream out(&file);
                         out << "<font color=\"#FFA500\">" << formattedDateTime << "salle numero "<<id_salle<<" is updated"<<endl; // endl ajoute un saut de ligne
                         file.close();

    ui->nomEdit_6->clear();
    //ui->numeroEdit_7->clear();
    ui->numeroEdit_150->clear();
}
            else{
            QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la modification des données de la salle.");

}
}



//Update Machine
void MainWindow::updateRow_machine() {
    QPushButton* buttonSender1 = qobject_cast<QPushButton*>(sender());
    if (buttonSender1) {
        qDebug() << "Button sender found.";
        for (int i = 0; i < ui->table_machine->rowCount(); i++) {
            if (ui->table_machine->cellWidget(i, 5) == buttonSender1->parentWidget()) {
                id_machine = ui->table_machine->item(i, 0)->text().toInt();
                currentRow_machine = i;
                qDebug() << currentRow_machine;

                machine m;
                m.setId(id_machine);
                qDebug() << id_machine;

                QString nom = ui->table_machine->item(i, 2)->text();
                QString description = ui->table_machine->item(i, 3)->text();

                // Assuming the column 4 contains a radio box and you want its text
                QString etat = ui->table_machine->item(i, 4)->text();
                QLabel *imageLabel = qobject_cast<QLabel*>(ui->table_machine->cellWidget(i, 1));
                                             QPixmap image = *imageLabel->pixmap();
                 ui->label_imageM->setPixmap(image.scaled(ui->label_imageM->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

                ui->numeroEdit_10->setText(nom);
                ui->numeroEdit_6->setText(nom);


                if (etat == ui->radioButton->text()) {
                    ui->radioButton->setChecked(true);
                    ui->radioButton_2->setChecked(false);
                } else if (etat == ui->radioButton_2->text()) {
                    ui->radioButton->setChecked(false);
                    ui->radioButton_2->setChecked(true);
                }

                ui->stackedWidget->setCurrentIndex(10);

                connect(ui->update_machines, SIGNAL(clicked()), this, SLOT(validateUpdate_machine()));
                break;
            }
        }
    }
}
void MainWindow::validateUpdate_machine() {
    QString nom = ui->numeroEdit_10->text();
    QString description = ui->numeroEdit_6->text();
    QString etat;

    if (ui->radioButton->isChecked()) {
        etat = ui->radioButton->text();
    } else if (ui->radioButton_2->isChecked()) {
        etat = ui->radioButton_2->text();
    } else {
        QMessageBox::critical(this, "Erreur", "Veuillez sélectionner un état.");
        return;
    }

    QByteArray image2 = imageData;
    if (image2.isEmpty()) {
        qDebug() << "Image data is empty";
        return;
    }

    // Vérification du nom
    QRegExp nomRegExp("^[a-zA-Zéçà@è]+$");
    if (nom.isEmpty() || !nomRegExp.exactMatch(nom)) {
        QMessageBox::critical(this, "Erreur", "Le nom doit être une chaîne de caractères incluant é, ç, à, @, è et ne peut pas être vide.");
        return;
    }

    // Vérification de la longueur de la description
    if (description.length() > 100) {
        QMessageBox::critical(this, "Erreur", "La description ne doit pas dépasser 100 caractères.");
        return;
    }

    // Vérification de l'état
    if (etat.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "L'état ne peut pas être vide.");
        return;
    }

    // Vérification de l'unicité du nom dans le tableau d'affichage
    // Assurez-vous d'ajuster cette vérification en fonction de votre structure de données
    if (isNomExists(nom)) {
        QMessageBox::critical(this, "Erreur", "Le nom doit être unique dans le tableau d'affichage.");
        return;
    }

    // Tous les contrôles de saisie sont passés, vous pouvez maintenant effectuer la modification
    machine m(image2, nom, description, etat);
    m.modifier(id_machine, image2);
    if (m.modifier(id_machine,image2)) {
        std::wstring titre = L"Modification de la machine";
            std::wstring message = L"Une machine a été modifiée.";
            m.showNotification(titre, message);

        QMessageBox::information(this, "Succès", "Les données du machine ont été modifiées avec succès.");
        QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_machine.txt");
                             if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                 qDebug() << "Impossible d'ouvrir le fichier.";
                                 return;
                             }

                             // Obtenir la date et l'heure actuelles
                             QDateTime currentDateTime = QDateTime::currentDateTime();
                             QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                             // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                             QTextStream out(&file);
                             out << "<font color=\"#FFA500\">" << formattedDateTime << "machine numero "<<id_machine<<" is updated"<<endl; // endl ajoute un saut de ligne
                             file.close();

        // Réinitialiser les champs
        ui->numeroEdit_10->clear();
        ui->numeroEdit_6->clear();
        ui->label_imageM->clear();

        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la modification des données du machine.");
    }




}
bool MainWindow::isNomExists(const QString &nom) {
    // Supposons que vous avez une liste de noms existants dans une structure de données
    static QSet<QString> nomsExistants;

    // Vérifiez si le nom existe déjà
    if (nomsExistants.contains(nom)) {
        return true; // Le nom existe déjà
    } else {
        // Ajoutez le nouveau nom à la liste
        nomsExistants.insert(nom);
        return false; // Le nom est unique
    }
}
//update kine
void MainWindow::updateRow_kine() {

    QPushButton* buttonSender1 = qobject_cast<QPushButton*>(sender());
    if(buttonSender1) {
qDebug() << "Button sender found.";
        for(int i = 0; i < ui->table_kine->rowCount(); i++) {
            if(ui->table_kine->cellWidget(i, 9) == buttonSender1->parentWidget()) {
                 id_kine = ui->table_kine->item(i, 0)->text().toInt();
                currentRow_kine = i;
qDebug() <<currentRow_kine;

                kine kine;
                kine.setId(id_kine);
          qDebug() <<id_kine;
                     QString prenom = ui->table_kine->item(i, 2)->text();
                     QString nom = ui->table_kine->item(i, 3)->text();
                     QDate naissance = QDate::fromString(ui->table_kine->item(i, 4)->text(), "dd/MM/yyyy");
                     QString specialite=ui->table_kine->item(i,7)->text();
                     QString cv=ui->table_kine->item(i,8)->text();

                     int telephone = ui->table_kine->item(i, 5)->text().toInt();
                     QString sexe = ui->table_kine->item(i, 6)->text();

                     QLabel *imageLabel = qobject_cast<QLabel*>(ui->table_kine->cellWidget(i, 1));
                                 QPixmap image = *imageLabel->pixmap();


                                 ui->label_imageP_2->setPixmap(image.scaled(ui->label_imageP_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));


                     ui->prenom_kine->setText(prenom);
                     ui->nom_kine->setText(nom);
                     ui->numero_kine->setText(QString::number(telephone));
                     ui->cv_kine->setText(cv);

                     ui->sexe_kine->setCurrentText(sexe);
                     ui->comboBox_7->setCurrentText(specialite);
                     ui->date_kine->setDate(naissance);

                     ui->stackedWidget->setCurrentIndex(3);


                     connect(ui->update_kines, SIGNAL(clicked()), this, SLOT(validateUpdate_kine()));



                 }
             }
         }
}
void MainWindow::validateUpdate_kine() {

     QString prenom = ui->prenom_kine->text();
     QString nom = ui->nom_kine->text();
     int telephone = ui->numero_kine->text().toInt();
     QString cv=ui->cv_kine->text();

     QString sexe = ui->sexe_kine->currentText();
     QString specialite=ui->comboBox_7->currentText();
     QString naissance = ui->date_kine->date().toString();

QByteArray image2 =imageData;
    if (image2.isEmpty()) {
            qDebug() << "Image data is empty";
            return;
        }

     if(prenom.isEmpty() || nom.isEmpty() ||  sexe.isEmpty() || specialite.isEmpty() || cv.isEmpty() ) {
         QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
         return;
     }


     kine k(nom,prenom,sexe,telephone,naissance,image2,specialite,cv);

     k.modifier(id_kine,image2);
     if (k.modifier(id_kine,image2)) {
         std::wstring titre = L"Modification de la kiné";
             std::wstring message = L"Un kiné a été modifié (e).";
             k.showNotification(titre, message);
             QMessageBox::information(this, "Succès", "Les données du kiné ont été modifiées avec succès.");

     QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_kine.txt");
                          if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                              qDebug() << "Impossible d'ouvrir le fichier.";
                              return;
                          }

                          // Obtenir la date et l'heure actuelles
                          QDateTime currentDateTime = QDateTime::currentDateTime();
                          QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                          // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                          QTextStream out(&file);
                          out << "<font color=\"#FFA500\">" << formattedDateTime << "kine numero "<<id_kine<<" is updated"<<endl; // endl ajoute un saut de ligne
                          file.close();
     ui->prenom_kine->clear();
     ui->nom_kine->clear();
     ui->numero_kine->clear();
     ui->cv_kine->clear();

     ui->label_imageP_2->clear();
}
     else{
         QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la modification des données du kiné.");
     }
 }
//update patient
void MainWindow::updateRow_pat() {
       QPushButton* buttonSender1 = qobject_cast<QPushButton*>(sender());
       if(buttonSender1) {
 qDebug() << "Button sender found.";
           for(int i = 0; i < ui->table_patient->rowCount(); i++) {
               if(ui->table_patient->cellWidget(i, 8) == buttonSender1->parentWidget()) {
                    id_patient = ui->table_patient->item(i, 0)->text().toInt();
                   currentRow_patient = i;
qDebug() <<currentRow_patient;

                   Patient patient;
                   patient.setId(id_patient);
             qDebug() <<id_patient;

                   QString prenom = ui->table_patient->item(i, 2)->text();
                   QString nom = ui->table_patient->item(i, 3)->text();
                   QDate naissance = QDate::fromString(ui->table_patient->item(i, 4)->text(), "dd/MM/yyyy");

                   int telephone = ui->table_patient->item(i, 5)->text().toInt();
                   QString sexe = ui->table_patient->item(i, 6)->text();
                   QString dos_med = ui->table_patient->item(i, 7)->text();
                   QLabel *imageLabel = qobject_cast<QLabel*>(ui->table_patient->cellWidget(i, 1));
                               QPixmap image = *imageLabel->pixmap();


                               ui->label_imageP->setPixmap(image.scaled(ui->label_imageP->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));


                   ui->LineEdit_prenom_pat->setText(prenom);
                   ui->LineEdit_nom_pat->setText(nom);
                   ui->LineEdit_num_pat->setText(QString::number(telephone));
                   ui->LineEdit_doc_pat->setText(dos_med);
                   ui->comboBox_sexe_pat->setCurrentText(sexe);
                   ui->dateEdit_N_pat->setDate(naissance);

                   ui->stackedWidget->setCurrentIndex(0);

                   connect(ui->update_patient, SIGNAL(clicked()), this, SLOT(validateUpdate_pat()));
                                      break;

               }
           }
       }
   }

//Update Employe
void MainWindow::updateRow_employe() {
       QPushButton* buttonSender1 = qobject_cast<QPushButton*>(sender());
       if(buttonSender1) {
 qDebug() << "Button sender found.";
           for(int i = 0; i < ui->table_employe->rowCount(); i++) {
               if(ui->table_employe->cellWidget(i, 10) == buttonSender1->parentWidget()) {
                    id_employe = ui->table_employe->item(i, 0)->text().toInt();
                   currentRow_employe = i;
qDebug() <<currentRow_employe;

                   employees employe;
                   employe.setId(id_employe);
             qDebug() <<id_employe;

                   QString nom = ui->table_employe->item(i, 1)->text();
                   QString prenom = ui->table_employe->item(i, 2)->text();
                   QDate date_embauche = QDate::fromString(ui->table_employe->item(i, 3)->text(), "dd/MM/yyyy");

                   QString role = ui->table_employe->item(i, 4)->text();
                   QString sexe = ui->table_employe->item(i, 5)->text();
                   QString login = ui->table_employe->item(i, 6)->text();
                   //QString mdp = ui->table_employe->item(i, 7)->text();
                   QString questionSecurite = ui->table_employe->item(i, 8)->text();
                   QString reponseSecurite = ui->table_employe->item(i, 9)->text();



                   ui->nom_kine_3->setText(nom);
                   ui->prenom_kine_3->setText(prenom);
                   ui->date_exercice_seance->setDate(date_embauche);
                   ui->sexe_kine_4->setCurrentText(role);
                   ui->sexe_kine_3->setCurrentText(sexe);
                   ui->cv_kine_2->setText(login);

                   ui->cv_kine_45->clear();

                   ui->questionSecuriteComboBox->setCurrentText(questionSecurite);
                   ui->reponseSecuriteLineEdit->setText(reponseSecurite);


                   ui->stackedWidget->setCurrentIndex(16);

                   connect(ui->update_employ, SIGNAL(clicked()), this, SLOT(validateUpdate_employe()));
                                      break;

               }
           }
       }
   }
void MainWindow::validateUpdate_employe() {
    QString nom = ui->nom_kine_3->text();
    QString prenom = ui->prenom_kine_3->text();
    QDate date_embauche = ui->date_exercice_seance->date();
    QString role = ui->sexe_kine_4->currentText();
    QString sexe = ui->sexe_kine_3->currentText();
    QString login = ui->cv_kine_2->text();
    QString mdp = ui->cv_kine_45->text();
    QString questionSecurite = ui->questionSecuriteComboBox->currentText();
    QString reponseSecurite = ui->reponseSecuriteLineEdit->text();



    // Contrôle de saisie sur le nom et le prénom
    QRegExp nomPrenomRegex("^[a-zA-Zéçàè]+$");
    if (!nomPrenomRegex.exactMatch(nom) || !nomPrenomRegex.exactMatch(prenom)) {
        QMessageBox::critical(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres et les caractères spéciaux {é, ç, à, è}.");
        return;
    }

    // Contrôle de saisie sur la date d'embauche (ne doit pas dépasser la date d'aujourd'hui)
    if (date_embauche > QDate::currentDate()) {
        QMessageBox::critical(this, "Erreur", "La date d'embauche ne peut pas dépasser la date d'aujourd'hui.");
        return;
    }

    // Contrôle de saisie sur le login
    QRegExp loginRegex("^[a-zA-Z]+\\.[a-zA-Z]+@(yahoo|youtube|outlook|hotmail|esprit|gmail)\\.(com|fr|tn)$");
    if (!loginRegex.exactMatch(login)) {
        QMessageBox::critical(this, "Erreur", "Le login doit être de la forme nom.prenom@(yahoo/youtube/outlook/hotmail/esprit/gmail).com/fr/tn");
        return;
    }

    // Contrôle de saisie sur le mot de passe
    // (Vous devrez définir des critères spécifiques pour ce qui est considéré comme un mot de passe fort)
    // Exemple : Au moins 8 caractères avec au moins une majuscule, une minuscule, un chiffre et un caractère spécial
    QRegExp mdpRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%*?&#]{8,}$");
    if (!mdpRegex.exactMatch(mdp)) {
        QMessageBox::critical(this, "Erreur", "Le mot de passe doit être fort, contenant au moins 8 caractères avec au moins une majuscule, une minuscule, un chiffre et un caractère spécial.");
        return;
    }
    QByteArray hashedPassword = QCryptographicHash::hash(mdp.toUtf8(), QCryptographicHash::Sha256).toHex();
        QString hashedPasswordString = QString(hashedPassword);


    employees employe(nom, prenom, date_embauche, role, sexe, login,hashedPasswordString, questionSecurite, reponseSecurite );
    employe.modifier(id_employe);

    // Réinitialiser les champs
    ui->nom_kine_3->clear();
    ui->prenom_kine_3->clear();
    ui->cv_kine_2->clear();
    ui->cv_kine_45->clear();
    ui->reponseSecuriteLineEdit->clear();

}

//Update Seance
void MainWindow::updateRow_seance() {
    QPushButton* buttonSender1 = qobject_cast<QPushButton*>(sender());
    if(buttonSender1) {
qDebug() << "Button sender found.";
        for(int i = 0; i < ui->table_seance->rowCount(); i++) {
            if(ui->table_seance->cellWidget(i, 6) == buttonSender1->parentWidget()) {
                 id_seance = ui->table_seance->item(i, 0)->text().toInt();
                currentRow_seance = i;
qDebug() <<currentRow_seance;

                seance seance;
                seance.setId(id_seance);
          qDebug() <<id_seance;

                QDate date_s = QDate::fromString(ui->table_seance->item(i, 1)->text(), "dd/MM/yyyy");
                QString heure_debut = ui->table_seance->item(i, 2)->text();
                QString heure_fin = ui->table_seance->item(i, 3)->text();
                QString type = ui->table_seance->item(i, 4)->text();



                ui->date_exercice_seance->setDate(date_s);
                ui->H_D_seance->setText(heure_debut);
                ui->H_F_seance->setText(heure_fin);
                ui->type_seance->setText(type);

                 ui->stackedWidget->setCurrentIndex(7);

                connect(ui->update_seance, SIGNAL(clicked()), this, SLOT(validateUpdate_seance()));
                                   break;

            }
        }
    }
}

void MainWindow::validateUpdate_seance() {
 // Récupérer l'état actuel du checkbox de la ligne en cours
 QCheckBox *checkBox = nullptr;
 QWidget *widget = ui->table_seance->cellWidget(currentRow_seance, 5);
 if (widget) {
     checkBox = widget->findChild<QCheckBox *>();
 }

 if (!checkBox) {
     qDebug() << "Erreur: CheckBox non trouvée.";
     return;
 }

 // Récupérer l'état actuel de la séance en fonction de l'état du checkbox
 QString etat = checkBox->isChecked() ? "validee" : "non validee";

 // Ensuite, vous pouvez mettre à jour l'état de la séance dans la base de données
 seance uneSeance; // Créez une instance de la classe seance
 uneSeance.modifierEtat(id_seance, etat); // Assurez-vous que cette méthode est correctement implémentée dans votre classe seance

 // Effectuez d'autres opérations nécessaires
 QDate date_s = ui->date_exercice_seance->date();
 QString heure_debut = ui->H_D_seance->text();
 QString heure_fin = ui->H_F_seance->text();
 QString type = ui->type_seance->text();

 // Contrôle de saisie sur la date (ne doit pas dépasser la date d'aujourd'hui)
 if (date_s > QDate::currentDate()) {
     QMessageBox::critical(this, "Erreur", "La date ne doit pas dépasser la date d'aujourd'hui.");
     return;
 }

 // Contrôle de saisie sur l'heure (format heure:minute)
 QRegExp heureRegExp("^[0-2]?[0-9]:[0-5][0-9]$");
 if (!heureRegExp.exactMatch(heure_debut) || !heureRegExp.exactMatch(heure_fin)) {
     QMessageBox::critical(this, "Erreur", "L'heure doit être au format heure:minute (ex. 08:30).");
     return;
 }

 // Contrôle de saisie sur l'ordre des heures (heure début doit être avant heure fin)
 QTime time_debut = QTime::fromString(heure_debut, "hh:mm");
 QTime time_fin = QTime::fromString(heure_fin, "hh:mm");
 if (time_debut >= time_fin) {
     QMessageBox::critical(this, "Erreur", "L'heure de début doit être avant l'heure de fin.");
     return;
 }

 // Vérifier d'autres conditions de validation si nécessaire

 if (heure_debut.isEmpty() || heure_fin.isEmpty() || type.isEmpty()) {
     QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs.");
     return;
 }

 seance seance(heure_debut, heure_fin, type, date_s);

 seance.modifier(id_seance);
 if (seance.modifier(id_seance)) {
     std::wstring titre = L"Modification de la séance";
         std::wstring message = L"Une séance a été modifiée.";
         seance.showNotification(titre, message);
         QMessageBox::information(this, "Succès", "Les données de la séance ont été modifiées avec succès.");
 // Réinitialiser les champs
 ui->date_exercice_seance->clear();
 ui->H_D_seance->clear();
 ui->H_F_seance->clear();
 ui->type_seance->clear();
}
 else{
     QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la modification des données du la séance.");
 }
 }






































//Delete












//Delete Patient
void MainWindow::deleteRow_pat() {
       QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
       if(buttonSender) {
           for(int i = 0; i < ui->table_patient->rowCount(); i++) {
               if(ui->table_patient->cellWidget(i, 8) == buttonSender->parentWidget()) {

                  int id = ui->table_patient->item(i, 0)->text().toInt();


                   Patient patient;
                   patient.setId(id);


                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce patient?",
                                                   QMessageBox::Yes|QMessageBox::No);
                   if (reply == QMessageBox::Yes) {

                       if(patient.deleteFromDatabase()) {

                           ui->table_patient->removeRow(i);
                           std::wstring titre = L"suppression de la patient";
                               std::wstring message = L"Un nouveau patient a été supprimé (e).";
                               patient.showNotification(titre, message);

                           QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_patient.txt");
                                                if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                                    qDebug() << "Impossible d'ouvrir le fichier.";
                                                    return;
                                                }

                                                // Obtenir la date et l'heure actuelles
                                                QDateTime currentDateTime = QDateTime::currentDateTime();
                                                QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                                                // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                                                QTextStream out(&file);
                                                out << "<font color=\"red\">" << formattedDateTime << "patient numero "<<id_patient<<" is deleted"<<endl; // endl ajoute un saut de ligne
                                                file.close();
                       }
                   }
                   break;
               }
           }
       }
   }
//Delete Salle
void MainWindow::deleteRow_salle() {
       QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
       if(buttonSender) {
           for(int i = 0; i < ui->table_salle->rowCount(); i++) {
               if(ui->table_salle->cellWidget(i, 4) == buttonSender->parentWidget()) {

                  int id = ui->table_salle->item(i, 0)->text().toInt();


                   salle salle;
                   salle.setId(id);


                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette salle?",
                                                   QMessageBox::Yes|QMessageBox::No);
                   if (reply == QMessageBox::Yes) {

                       if(salle.deleteFromDatabase()) {



                           ui->table_salle->removeRow(i);
                           std::wstring titre = L"suppression de la salle";
                               std::wstring message = L"Une nouvelle salle a été supprimé (e).";
                               salle.showNotification(titre, message);

                           QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_salle.txt");
                                                if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                                    qDebug() << "Impossible d'ouvrir le fichier.";
                                                    return;
                                                }

                                                // Obtenir la date et l'heure actuelles
                                                QDateTime currentDateTime = QDateTime::currentDateTime();
                                                QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                                                // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                                                QTextStream out(&file);
                                                out << "<font color=\"red\">" << formattedDateTime << "salle numero "<<id_salle<<" is deleted"<<endl; // endl ajoute un saut de ligne
                                                file.close();
                       }
                   }
                   break;
               }
           }
       }
   }
//Delete Seance
void MainWindow::deleteRow_seance() {
       QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
       if(buttonSender) {
           for(int i = 0; i < ui->table_seance->rowCount(); i++) {
               if(ui->table_seance->cellWidget(i, 6) == buttonSender->parentWidget()) {

                  int id = ui->table_seance->item(i, 0)->text().toInt();


                   seance seance;
                   seance.setId(id);


                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette seance?",
                                                   QMessageBox::Yes|QMessageBox::No);
                   if (reply == QMessageBox::Yes) {

                       if(seance.deleteFromDatabase()) {

                           ui->table_seance->removeRow(i);
                           std::wstring titre = L"suppression de la séance";
                               std::wstring message = L"Une nouvelle séance a été supprimée.";
                               seance.showNotification(titre, message);

                           QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_seance.txt");
                                                if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                                    qDebug() << "Impossible d'ouvrir le fichier.";
                                                    return;
                                                }

                                                // Obtenir la date et l'heure actuelles
                                                QDateTime currentDateTime = QDateTime::currentDateTime();
                                                QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                                                // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                                                QTextStream out(&file);
                                                out << "<font color=\"red\">" << formattedDateTime << "seance numero "<<id_seance<<" is deleted"<<endl; // endl ajoute un saut de ligne
                                                file.close();
                       }
                   }
                   break;
               }
           }
       }
   }
//Delete Employe
void MainWindow::deleteRow_employe() {
       QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
       if(buttonSender) {
           for(int i = 0; i < ui->table_employe->rowCount(); i++) {
               if(ui->table_employe->cellWidget(i, 10) == buttonSender->parentWidget()) {

                  int id = ui->table_employe->item(i, 0)->text().toInt();


                   employees employe;
                   employe.setId(id);


                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cet employé?",
                                                   QMessageBox::Yes|QMessageBox::No);
                   if (reply == QMessageBox::Yes) {

                       if(employe.deleteFromDatabase()) {

                           ui->table_employe->removeRow(i);
                           std::wstring titre = L"suppression de l'employé";
                               std::wstring message = L"Un nouveau employé a été supprimé (e).";
                               employe.showNotification(titre, message);

                           QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_employe.txt");
                                                if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                                    qDebug() << "Impossible d'ouvrir le fichier.";
                                                    return;
                                                }

                                                // Obtenir la date et l'heure actuelles
                                                QDateTime currentDateTime = QDateTime::currentDateTime();
                                                QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                                                // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                                                QTextStream out(&file);
                                                out << "<font color=\"red\">" << formattedDateTime << "employe numero "<<id_employe<<" is deleted"<<endl; // endl ajoute un saut de ligne
                                                file.close();
                       }
                   }
                   break;
               }
           }
       }
   }
//Delete Kine
void MainWindow::deleteRow_kine() {
       QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
       if(buttonSender) {
           for(int i = 0; i < ui->table_kine->rowCount(); i++) {
               if(ui->table_kine->cellWidget(i, 9) == buttonSender->parentWidget()) {

                  int id = ui->table_kine->item(i, 0)->text().toInt();


                   kine kine;
                   kine.setId(id);


                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette kine?",
                                                   QMessageBox::Yes|QMessageBox::No);
                   if (reply == QMessageBox::Yes) {

                       if(kine.deleteFromDatabase()) {

                           ui->table_kine->removeRow(i);
                           std::wstring titre = L"suppression de kiné";
                               std::wstring message = L"Un nouveau kiné a été supprimé (e).";
                               kine.showNotification(titre, message);
                           QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_kine.txt");
                                                if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                                    qDebug() << "Impossible d'ouvrir le fichier.";
                                                    return;
                                                }

                                                // Obtenir la date et l'heure actuelles
                                                QDateTime currentDateTime = QDateTime::currentDateTime();
                                                QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                                                // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                                                QTextStream out(&file);
                                                out << "<font color=\"red\">" << formattedDateTime << "kine numero "<<id_kine<<" is deleted"<<endl; // endl ajoute un saut de ligne
                                                file.close();
                       }
                   }
                   break;
               }
           }
       }
   }
//Delete Machine:
void MainWindow::deleteRow_machine() {
   QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
   if(buttonSender) {
       for(int i = 0; i < ui->table_machine->rowCount(); i++) {
           if(ui->table_machine->cellWidget(i, 5) == buttonSender->parentWidget()) {

                id_machine = ui->table_machine->item(i, 0)->text().toInt();


               machine machine;
               machine.setId(id_machine);


               QMessageBox::StandardButton reply;
               reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette machine?",
                                               QMessageBox::Yes|QMessageBox::No);
               if (reply == QMessageBox::Yes) {

                   if(machine.deleteFromDatabase()) {

                       ui->table_machine->removeRow(i);
                       std::wstring titre = L"suppression de la machine";
                           std::wstring message = L"Une nouvelle machine a été supprimé (e).";
                           machine.showNotification(titre, message);
                       QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_machine.txt");
                                            if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                                                qDebug() << "Impossible d'ouvrir le fichier.";
                                                return;
                                            }

                                            // Obtenir la date et l'heure actuelles
                                            QDateTime currentDateTime = QDateTime::currentDateTime();
                                            QString formattedDateTime = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

                                            // Écrire la date et l'heure actuelles suivies du texte dans le fichier
                                            QTextStream out(&file);
                                            out << "<font color=\"red\">" << formattedDateTime << "machine numero "<<id_machine<<" is deleted"<<endl; // endl ajoute un saut de ligne
                                            file.close();
                   }
               }
               break;
           }
       }
   }
}





























//Recherche





















//Recherche Employe
void MainWindow::showAllRowsEmploye() {
        // Affichez toutes les lignes en rétablissant la visibilité
        int rowCount = ui->table_employe->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->table_employe->setRowHidden(row, false);
        }

    }
void MainWindow::filterRowsEmploye(const QString& searchText) {
        // Filtrer les lignes en fonction du texte de recherche
        int rowCount = ui->table_employe->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            bool matchFound = false;
            for (int col = 0; col < ui->table_employe->columnCount(); ++col) {
                QTableWidgetItem* item = ui->table_employe->item(row, col);
                if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                    matchFound = true;
                    break;
                }
            }
            ui->table_employe->setRowHidden(row, !matchFound);
        }
    }
void MainWindow::searchTableEmploye()
{
    QString searchText = ui->lineEdit_5->text().trimmed(); // Obtenez le texte de la QLineEdit

            if (searchText.isEmpty()) {
                // Si le texte est vide, affichez toutes les lignes
                showAllRowsEmploye();
            } else {
                // Sinon, filtrez les lignes en fonction du texte de recherche
                filterRowsEmploye(searchText);
            }
        }
//Recherche Machine:
void MainWindow::showAllRowsMachine() {
        // Affichez toutes les lignes en rétablissant la visibilité
        int rowCount = ui->table_machine->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->table_machine->setRowHidden(row, false);
        }

    }
void MainWindow::filterRowsMachine(const QString& searchText1) {
        // Filtrer les lignes en fonction du texte de recherche
        int rowCount = ui->table_machine->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            bool matchFound = false;
            for (int col = 0; col < ui->table_machine->columnCount(); ++col) {
                QTableWidgetItem* item = ui->table_machine->item(row, col);
                if (item && item->text().contains(searchText1, Qt::CaseInsensitive)) {
                    matchFound = true;
                    break;
                }
            }
            ui->table_machine->setRowHidden(row, !matchFound);
        }
    }
void MainWindow::searchTableMachine()
{
    QString searchText2 = ui->lineEdit_4->text().trimmed(); // Obtenez le texte de la QLineEdit

            if (searchText2.isEmpty()) {
                // Si le texte est vide, affichez toutes les lignes
                showAllRowsMachine();
            } else {
                // Sinon, filtrez les lignes en fonction du texte de recherche
                filterRowsMachine(searchText2);
            }
}
//Recherche Salle
void MainWindow::showAllRowsSalle() {
        // Affichez toutes les lignes en rétablissant la visibilité
        int rowCount = ui->table_salle->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->table_salle->setRowHidden(row, false);
        }

    }
void MainWindow::filterRowsSalle(const QString& searchText1) {
        // Filtrer les lignes en fonction du texte de recherche
        int rowCount = ui->table_salle->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            bool matchFound = false;
            for (int col = 0; col < ui->table_salle->columnCount(); ++col) {
                QTableWidgetItem* item = ui->table_salle->item(row, col);
                if (item && item->text().contains(searchText1, Qt::CaseInsensitive)) {
                    matchFound = true;
                    break;
                }
            }
            ui->table_salle->setRowHidden(row, !matchFound);
        }
    }
void MainWindow::searchTableSalle()
{
    QString searchText1 = ui->lineEdit_7->text().trimmed(); // Obtenez le texte de la QLineEdit

            if (searchText1.isEmpty()) {
                // Si le texte est vide, affichez toutes les lignes
                showAllRowsSalle();
            } else {
                // Sinon, filtrez les lignes en fonction du texte de recherche
                filterRowsSalle(searchText1);
            }
}
//Recherche Séance
void MainWindow::showAllRowsSeance() {
        // Affichez toutes les lignes en rétablissant la visibilité
        int rowCount = ui->table_seance->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->table_seance->setRowHidden(row, false);
        }

    }
void MainWindow::filterRowsSeance(const QString& searchText1) {
        // Filtrer les lignes en fonction du texte de recherche
        int rowCount = ui->table_seance->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            bool matchFound = false;
            for (int col = 0; col < ui->table_seance->columnCount(); ++col) {
                QTableWidgetItem* item = ui->table_seance->item(row, col);
                if (item && item->text().contains(searchText1, Qt::CaseInsensitive)) {
                    matchFound = true;
                    break;
                }
            }
            ui->table_seance->setRowHidden(row, !matchFound);
        }
    }
void MainWindow::searchTableSeance()
{
    QString searchText2 = ui->recherche_tab_seance->text().trimmed(); // Obtenez le texte de la QLineEdit

            if (searchText2.isEmpty()) {
                // Si le texte est vide, affichez toutes les lignes
                showAllRowsSeance();
            } else {
                // Sinon, filtrez les lignes en fonction du texte de recherche
                filterRowsSeance(searchText2);
            }
}
//Recherche Patient
void MainWindow::showAllRowsPatient() {
        // Affichez toutes les lignes en rétablissant la visibilité
        int rowCount = ui->table_patient->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->table_patient->setRowHidden(row, false);
        }

    }
void MainWindow::filterRowsPatient(const QString& searchText1) {
        // Filtrer les lignes en fonction du texte de recherche
        int rowCount = ui->table_patient->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            bool matchFound = false;
            for (int col = 0; col < ui->table_patient->columnCount(); ++col) {
                QTableWidgetItem* item = ui->table_patient->item(row, col);
                if (item && item->text().contains(searchText1, Qt::CaseInsensitive)) {
                    matchFound = true;
                    break;
                }
            }
            ui->table_patient->setRowHidden(row, !matchFound);
        }
    }
void MainWindow::searchTablePatient()
{
    QString searchText2 = ui->lineEdit->text().trimmed(); // Obtenez le texte de la QLineEdit

            if (searchText2.isEmpty()) {
                // Si le texte est vide, affichez toutes les lignes
                showAllRowsPatient();
            } else {
                // Sinon, filtrez les lignes en fonction du texte de recherche
                filterRowsPatient(searchText2);
            }
}
//Recherche Patient
void MainWindow::showAllRowsKine() {
        // Affichez toutes les lignes en rétablissant la visibilité
        int rowCount = ui->table_kine->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->table_kine->setRowHidden(row, false);
        }

    }
void MainWindow::filterRowsKine(const QString& searchText1) {
        // Filtrer les lignes en fonction du texte de recherche
        int rowCount = ui->table_kine->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            bool matchFound = false;
            for (int col = 0; col < ui->table_kine->columnCount(); ++col) {
                QTableWidgetItem* item = ui->table_kine->item(row, col);
                if (item && item->text().contains(searchText1, Qt::CaseInsensitive)) {
                    matchFound = true;
                    break;
                }
            }
            ui->table_kine->setRowHidden(row, !matchFound);
        }
    }
void MainWindow::searchTableKine()
{
    QString searchText2 = ui->lineEdit_2->text().trimmed(); // Obtenez le texte de la QLineEdit

            if (searchText2.isEmpty()) {
                // Si le texte est vide, affichez toutes les lignes
                showAllRowsKine();
            } else {
                // Sinon, filtrez les lignes en fonction du texte de recherche
                filterRowsKine(searchText2);
            }
}

//metier
/*void MainWindow::updateCalendarAndEventDetails() {
  // Clear existing date text formats in the calendar
    ui->calendar_event->setDateTextFormat(QDate(), QTextCharFormat());

    // Create a QSqlQuery to fetch the DATE_DEBUT values from the database
    QSqlQuery calendarQuery("SELECT DATE_S FROM SEANCE");

    QList<QDate> dateDebuts;
    // Iterate through the query results
    while (calendarQuery.next()) {
        // Extract the DATE_DEBUT value from the query
        QDate dateDebut = calendarQuery.value(1).toDate();
        dateDebuts.append(dateDebut);

        // Set the color for the date in the calendar
        QTextCharFormat format;
        format.setBackground(Qt::green); // Set background color to green
        ui->calendar_event->setDateTextFormat(dateDebut, format);
    }
}*/






void MainWindow::verifierNom(const QString &text) {
    if (text.contains(QRegExp("[0-9]"))) {
        QMessageBox::warning(this, "Erreur", "Le nom ne peut contenir que des lettres.");
        // Effacer le texte du champ de saisie ou prendre une autre action nécessaire
        ui->nom_kine_3->clear();
    }
}
void MainWindow::verifierPrenom(const QString &text) {
    if (text.contains(QRegExp("[0-9]"))) {
        QMessageBox::warning(this, "Erreur", "Le prénom ne peut contenir que des lettres.");
        // Effacer le texte du champ de saisie ou prendre une autre action nécessaire
        ui->prenom_kine_3->clear();
    }
}






bool MainWindow::verifyEmailExists(const QString& emailAddress)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE LOGIN = :email");
    query.bindValue(":email", emailAddress);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
    return false;
}

void MainWindow::sendEmail(const QString& emailAddress, const QString& message)
{


    QJsonObject payload;
    payload["sendto"] = emailAddress;
    payload["name"] = "Raif Guizani";
    payload["replyTo"] = "raifguizani10@gmail.com";
    payload["ishtml"] = false;
    payload["title"] = "Test";
    payload["body"] = message;
    QJsonDocument doc(payload);
    QByteArray postData = doc.toJson();
    QUrl url("https://mail-sender-api1.p.rapidapi.com/");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
    request.setRawHeader("X-RapidAPI-Host", "mail-sender-api1.p.rapidapi.com");

    QNetworkReply *reply = manager.post(request, postData);
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            qDebug() << "Email sent. Response:" << responseData;
        } else {
            qDebug() << "Error sending email:" << reply->errorString();
        }
        reply->deleteLater();
    });
}



void MainWindow::send_email_request()
{
    // Récupérer le bouton qui a été cliqué
    QPushButton* buttonSender2 = qobject_cast<QPushButton*>(sender());
    if (buttonSender2) {
        // Récupérer la ligne correspondante au bouton cliqué
        int row = ui->table_salle->indexAt(buttonSender2->pos()).row();
        if (row >= 0 && row < ui->table_salle->rowCount()) {
            // Récupérer les informations de la salle de la ligne sélectionnée
            QString nomSalle = ui->table_salle->item(row, 1)->text();
            QString capaciteSalle = ui->table_salle->item(row, 2)->text();
            QString locationSalle = ui->table_salle->item(row, 3)->text();

            // Créer et configurer le QDialog
            QDialog *dialog = new QDialog(this);
            dialog->setWindowTitle("Send Email");
            dialog->resize(800, 600);

            // Appliquer le style CSS au QDialog
            dialog->setStyleSheet(
                "background-color: #f2f2f2; /* Fond gris clair */"
                "color: #333333; /* Texte noir */"
                "font-family: Arial, sans-serif;"
            );

            // Créer les widgets nécessaires
            QLabel *emailLabel = new QLabel("Email:", dialog);
            QLineEdit *emailLineEdit = new QLineEdit(dialog);
            QLabel *salleInfoLabel = new QLabel("Informations de la salle:", dialog);
            QLabel *salleDetailsLabel = new QLabel(dialog); // Label pour afficher les détails de la salle

            // Formater les informations de la salle
            QString salleDetails = "Nom de la salle : " + nomSalle + "<br>"
                                   "Capacité de la salle : " + capaciteSalle + "<br>"
                                   "Location de la salle : " + locationSalle;

            salleDetailsLabel->setText(salleDetails);
            salleDetailsLabel->setWordWrap(true); // Permettre le retour à la ligne automatique

            QPushButton *sendButton = new QPushButton("Send", dialog);

            // Disposer les widgets dans une mise en page
            QVBoxLayout *layout = new QVBoxLayout(dialog);
            layout->addWidget(emailLabel);
            layout->addWidget(emailLineEdit);
            layout->addWidget(salleInfoLabel);
            layout->addWidget(salleDetailsLabel);
            layout->addWidget(sendButton);

            sendButton->setStyleSheet(
                "QPushButton {"
                    "background-color: #4CAF50;"
                    "border: none;"
                    "color: white;"
                    "padding: 15px 32px;"
                    "text-align: center;"
                    "text-decoration: none;"
                    "display: inline-block;"
                    "font-size: 16px;"
                    "margin: 4px 2px;"
                    "cursor: pointer;"
                "}"
                "QPushButton:hover {"
                    "background-color: #45a049;"
                "}"
            );

            // Connecter le clic du bouton Send à la fonction d'envoi d'email
            connect(sendButton, &QPushButton::clicked, [=]() {
                QString emailAddress = emailLineEdit->text();

                if (verifyEmailExists(emailAddress)) {
                    // Envoyer les détails de la salle par e-mail
                    sendEmail(emailAddress, salleDetails);
                    // Afficher une confirmation à l'utilisateur
                    QMessageBox::information(this, "Confirmation", "Email envoyé avec succès !");
                    // Fermer la fenêtre QDialog après avoir envoyé l'email
                    dialog->close();



                    // Enregistrer l'email et la date d'envoi dans un fichier texte
                    QString fileName = "C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/email.txt";
                    QFile file(fileName);
                    if (file.open(QIODevice::Append | QIODevice::Text)) {
                        QTextStream out(&file);
                        QString currentDate = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
                        out << "Email: " << emailAddress << ", Date: " << currentDate << "\n";
                        file.close();
                        // Ouvrir une boîte de dialogue de sélection de fichier
                            QString filePath = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QDir::homePath(), "Text Files (*.txt)");

                            if (!filePath.isEmpty()) {
                                // Lire le contenu du fichier
                                QFile file(filePath);
                                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                                    QTextStream in(&file);
                                    QString fileContent = in.readAll();
                                    file.close();

                                    // Créer et configurer le QDialog
                                    QDialog *fileDialog = new QDialog(this);
                                    fileDialog->setWindowTitle("Contenu du fichier");
                                    fileDialog->resize(800, 600);

                                    // Créer un QLabel pour afficher le contenu du fichier
                                    QLabel *fileLabel = new QLabel(fileContent, fileDialog);
                                    fileLabel->setWordWrap(true);
                                    fileLabel->setStyleSheet("color: blue;"); // Définir la couleur de l'écriture en bleu

                                    // Disposer le QLabel dans une mise en page
                                    QVBoxLayout *layout = new QVBoxLayout(fileDialog);
                                    layout->addWidget(fileLabel);

                                    // Afficher le QDialog
                                    fileDialog->exec();
                                } else {
                                    QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier.");
                                }
                            }
                    }
                } else {
                    // Afficher un message d'erreur si l'e-mail n'existe pas
                    QMessageBox::warning(this, "Erreur", "L'e-mail n'existe pas !");
                }
            });

            // Afficher le QDialog
            dialog->exec();
        }
    }
}


/*void MainWindow::generateQRCode()
{
    QPushButton* buttonSender2 = qobject_cast<QPushButton*>(sender());
    if(buttonSender2) {
        for(int i = 0; i < ui->table_machine->rowCount(); i++) {
            if(ui->table_machine->cellWidget(i, 5) == buttonSender2->parentWidget()) {

               int id = ui->table_machine->item(i, 0)->text().toInt();

               // Récupérer les données de la machine à partir de la base de données
               QSqlDatabase db = QSqlDatabase::database("myconnection"); // Utilisez le nom de connexion correct
               QSqlQuery query(db);
               query.prepare("SELECT NOM, DESCRIPTION, ETAT FROM MACHINE WHERE ID_MACHINE = :id");
               query.bindValue(":id", id);
               if (!query.exec()) {
                   qDebug() << "Erreur lors de la récupération des données de la machine :" << query.lastError().text();
                   return;
               }

               // Récupérer les données de la première (et unique) ligne résultante
               if (query.next()) {
                   QString nom = query.value(0).toString();
                   QString description = query.value(1).toString();
                   QString etat = query.value(2).toString();

                   // Combinez les données dans une seule chaîne
                   QString dataToEncode = "Nom: " + nom + "\n"
                                          "Description: " + description + "\n"
                                          "État: " + etat;

                   // Afficher les données à encoder
                   qDebug() << "Data to encode:" << dataToEncode;

                   // Créer un objet QZXing pour générer le code QR
                   QZXing *qzxing = new QZXing();

                   // Générer le code QR à partir des données
                   QImage qrImage = qzxing->encodeData(dataToEncode);

                   // Vérifier si le code QR a été généré avec succès
                   if (qrImage.isNull()) {
                       QMessageBox::critical(this, "Erreur", "Impossible de générer le code QR.");
                       return;
                   }

                   // Afficher le code QR généré
                   QMessageBox msgBox;
                   msgBox.setWindowTitle("Code QR généré");
                   msgBox.setText("Voici le code QR généré à partir des données:");
                   msgBox.setIconPixmap(QPixmap::fromImage(qrImage));
                   msgBox.exec();
               } else {
                   qDebug() << "Aucune machine trouvée avec l'identifiant:" << id;
               }

               // Sortir de la boucle une fois que le bouton correspondant à la ligne est trouvé
               break;
            }
        }
    }
}
*/

void MainWindow::onMessageSent()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "SMS envoyé avec succès. Réponse: " << responseData;
    } else {
        qDebug() << "Erreur lors de l'envoi du SMS: " << reply->errorString();
    }
    reply->deleteLater();
}




void MainWindow::handleTranslationResponse(QNetworkReply *reply, QLabel* textResponseLabel)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        // Convertir la réponse en objet JSON
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

        // Vérifier si l'analyse JSON a réussi
        if (!jsonResponse.isNull() && jsonResponse.isArray()) {
            QJsonArray translations = jsonResponse.array();
            QString translatedText;
            foreach (const QJsonValue &value, translations) {
                QJsonObject translationObject = value.toObject();
                int code = translationObject["code"].toInt();
                if (code == 200) {
                    QString text = translationObject["texts"].toString();
                    QString language = translationObject["tl"].toString();

                    // Découper le texte en lignes de 10 mots maximum
                    QStringList words = text.split(" ");
                    int wordCount = 0;
                    foreach (const QString &word, words) {
                        if (wordCount >= 9) {
                            translatedText += "\n"; // Nouvelle ligne après 10 mots
                            wordCount = 0;
                        }
                        translatedText += word + " ";
                        wordCount++;
                    }
                } else {
                    qDebug() << "Translation failed with code:" << code;
                }
            }

            // Définir le texte traduit dans textResponseLabel
            textResponseLabel->setText(translatedText.trimmed());

        } else {
            qDebug() << "Failed to parse JSON response";
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}


void MainWindow::on_google_traduction_clicked()
{
    // Créer et configurer le QDialog
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Google Traduction");
    dialog->resize(800, 600);

    // Appliquer le style CSS au QDialog
    dialog->setStyleSheet(
        "background-color: #f2f2f2; /* Fond gris clair */"
        "color: #333333; /* Texte noir */"
        "font-family: Arial, sans-serif;"
    );

    // Créer les widgets nécessaires
    QLabel *label = new QLabel("Message:", dialog);
    QLineEdit *lineEdit = new QLineEdit(dialog);
    QComboBox *comboBox = new QComboBox(dialog);
    QLabel *translatedLabel = new QLabel("Translated Text:", dialog);
    QLabel *label_reponse = new QLabel(dialog);
    QPushButton *translateButton = new QPushButton("Translate", dialog);

    // Appliquer le style CSS aux widgets
    label->setStyleSheet("font-size: 16px;");
    lineEdit->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ccc;"
        "border-radius: 4px;"
        "font-size: 16px;"
        "padding: 6px;"
    );
    comboBox->setStyleSheet(
        "font-size: 16px;"
        "padding: 6px;"
    );
    translatedLabel->setStyleSheet("font-size: 16px;");
    label_reponse->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ccc;"
        "border-radius: 4px;"
        "font-size: 16px;"
        "padding: 6px;"
    );
    translateButton->setStyleSheet(
        "QPushButton {"
            "background-color: #4CAF50;"
            "border: none;"
            "color: white;"
            "padding: 15px 32px;"
            "text-align: center;"
            "text-decoration: none;"
            "display: inline-block;"
            "font-size: 16px;"
            "margin: 4px 2px;"
            "cursor: pointer;"
        "}"
        "QPushButton:hover {"
            "background-color: #45a049;"
        "}"
    );

    // Ajouter les options au QComboBox
    comboBox->addItem("en");
    comboBox->addItem("fr");
    comboBox->addItem("ar");
    comboBox->addItem("de");
    comboBox->addItem("ru");
    comboBox->addItem("zh");

    // Disposer les widgets dans une mise en page
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(comboBox);
    layout->addWidget(translatedLabel);
    layout->addWidget(label_reponse);
    layout->addWidget(translateButton);

    // Connecter le clic du bouton Translate à la fonction de traduction
    connect(translateButton, &QPushButton::clicked, [=]() {
        // Récupérer le texte à traduire et la langue sélectionnée
        QString textToTranslate = lineEdit->text();
        QString targetLanguage = comboBox->currentText();

        // Créer la requête et l'envoyer
        QNetworkAccessManager *manager = new QNetworkAccessManager(dialog);
        QNetworkRequest request = createRequest(QUrl("https://ai-translate.p.rapidapi.com/translates"));
        QJsonObject dataObject;
        dataObject["texts"] = QJsonArray::fromStringList({textToTranslate});
        dataObject["tls"] = QJsonArray::fromStringList({targetLanguage});
        dataObject["sl"] = "auto";
        QJsonDocument doc(dataObject);
        QByteArray jsonData = doc.toJson();

        manager->post(request, jsonData);

        // Connecter la réponse de la requête à la fonction de gestion de la traduction
        connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply) {
            handleTranslationResponse(reply, label_reponse);
            reply->deleteLater();
        });
    });

    // Afficher le QDialog
    dialog->exec();
}


QNetworkRequest MainWindow::createRequest(const QUrl &url)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
    request.setRawHeader("X-RapidAPI-Host", "ai-translate.p.rapidapi.com");
    return request;
}







void MainWindow::on_sendd_clicked()
{
    // Créer et configurer le QDialog
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Send Request");
    dialog->resize(800, 600);

    // Appliquer le style CSS au QDialog
    dialog->setStyleSheet(
        "background-color: #f2f2f2; /* Fond gris clair */"
        "color: #333333; /* Texte noir */"
        "font-family: Arial, sans-serif;"
    );

    // Créer les widgets nécessaires
    QLabel *label = new QLabel("Message:", dialog);
    QLabel *responseTextLabel = new QLabel("Text Response:", dialog);
    QLabel *responseImageLabel = new QLabel("Image Response:", dialog);
    QLineEdit *lineEdit = new QLineEdit(dialog);
    QLabel *textResponseLabel = new QLabel(dialog); // Label pour afficher la réponse texte
    QLabel *imageResponseLabel = new QLabel(dialog); // Label pour afficher la réponse image
    QPushButton *sendButton = new QPushButton("Send", dialog);

    // Appliquer le style CSS aux widgets
    label->setStyleSheet("font-size: 16px;");
    responseTextLabel->setStyleSheet("font-size: 16px;");
    responseImageLabel->setStyleSheet("font-size: 16px;");
    lineEdit->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ccc;"
        "border-radius: 4px;"
        "font-size: 16px;"
        "padding: 6px;"
    );
    textResponseLabel->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ccc;"
        "border-radius: 4px;"
        "font-size: 16px;"
        "padding: 6px;"
    );
    imageResponseLabel->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ccc;"
        "border-radius: 4px;"
        "font-size: 16px;"
        "padding: 6px;"
    );
    sendButton->setStyleSheet(
        "QPushButton {"
            "background-color: #4CAF50;"
            "border: none;"
            "color: white;"
            "padding: 15px 32px;"
            "text-align: center;"
            "text-decoration: none;"
            "display: inline-block;"
            "font-size: 16px;"
            "margin: 4px 2px;"
            "cursor: pointer;"
        "}"
        "QPushButton:hover {"
            "background-color: #45a049;"
        "}"
    );

    // Disposer les widgets dans une mise en page
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(responseTextLabel);
    layout->addWidget(textResponseLabel); // Ajouter le label pour la réponse texte
    layout->addWidget(responseImageLabel);
    layout->addWidget(imageResponseLabel); // Ajouter le label pour la réponse image
    layout->addWidget(sendButton);
    dialog->setLayout(layout);

    // Connecter le clic du bouton Send à la fonction d'envoi de la demande
    connect(sendButton, &QPushButton::clicked, [=]() {
        // Récupérer le message de l'utilisateur
        QString userMessage = lineEdit->text();
        // Définir le message dans m_content (attribut de la classe MainWindow)
        m_content = userMessage;
        // Appeler la fonction sendRequest pour envoyer la demande
        sendTextRequest(textResponseLabel); // Passer les labels pour la réponse texte et image
        sendImageRequest(imageResponseLabel); // Passer les labels pour la réponse texte et image

    });

    // Afficher le QDialog
    dialog->exec();
}

void MainWindow::sendTextRequest(QLabel *textResponseLabel)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://chatgpt-42.p.rapidapi.com/conversationgpt4");

    // Création du payload JSON
    QJsonObject payload;
    QJsonArray messages;
    QJsonObject message;
    message["role"] = "user";
    message["content"] = m_content; // Utiliser la question entrée par l'utilisateur
    messages.append(message);
    payload["messages"] = messages;
    payload["web_access"] = false;
    payload["system_prompt"] = "";
    payload["temperature"] = 0.9;
    payload["top_k"] = 5;
    payload["top_p"] = 0.9;
    payload["max_tokens"] = 256;
    QJsonDocument doc(payload);
    QByteArray postData = doc.toJson();

    // Création de la requête
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
    request.setRawHeader("X-RapidAPI-Host", "chatgpt-42.p.rapidapi.com");

    // Envoi de la requête
    QNetworkReply *reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray responseData = reply->readAll();
            qDebug() << responseData;

            // Convertir la réponse JSON en objet JSON
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
            QJsonObject responseObject = responseDoc.object();

            // Récupérer le message de la réponse
            QString resultMessage = responseObject["result"].toString();

            // Insérer un saut de ligne après chaque 10 mots
            QStringList words = resultMessage.split(' ');
            QString formattedMessage;
            int wordCount = 0;
            for (const QString &word : words) {
                formattedMessage += word + " ";
                wordCount++;
                if (wordCount == 10) {
                    formattedMessage += "\n";
                    wordCount = 0;
                }
            }

            // Afficher le message texte dans le QLabel correspondant
            textResponseLabel->setText(formattedMessage.trimmed());
        }
        else
        {
            qDebug() << "Error:" << reply->errorString();
            // Afficher un message d'erreur en cas d'erreur de réseau
            QMessageBox::critical(this, "Error", "Failed to send text request: " + reply->errorString());
        }
        reply->deleteLater();
    });
}

void MainWindow::sendImageRequest(QLabel *imageResponseLabel)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url("https://chatgpt-42.p.rapidapi.com/texttoimage");

    // Création du payload JSON
    QJsonObject json;
    json["text"] = m_content; // Utiliser le texte entré par l'utilisateur
    QJsonDocument doc(json);
    QByteArray postData = doc.toJson();

    // Création de la requête
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
    request.setRawHeader("X-RapidAPI-Host", "chatgpt-42.p.rapidapi.com");

    // Envoi de la requête
    QNetworkReply *reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray responseData = reply->readAll();

            // Analyser la réponse JSON
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObject = jsonResponse.object();
            QString imageUrl = jsonObject["generated_image"].toString();

            // Télécharger l'image à partir de l'URL
            QNetworkAccessManager *imageManager = new QNetworkAccessManager(this);
            connect(imageManager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *imageReply) {
                if (imageReply->error() == QNetworkReply::NoError) {
                    QByteArray imageData = imageReply->readAll();
                    QPixmap originalPixmap;
                    originalPixmap.loadFromData(imageData);

                    // Redimensionner l'image
                    QPixmap scaledPixmap = originalPixmap.scaled(500, 500, Qt::KeepAspectRatio);

                    // Afficher l'image dans le QLabel correspondant
                    imageResponseLabel->setPixmap(scaledPixmap);
                } else {
                    qDebug() << "Erreur lors du téléchargement de l'image :" << imageReply->errorString();
                }
                imageReply->deleteLater();
            });

            imageManager->get(QNetworkRequest(QUrl(imageUrl)));
        }
        else
        {
            qDebug() << "Erreur de réseau :" << reply->errorString();
            // Afficher un message d'erreur en cas d'erreur de réseau
            QMessageBox::critical(this, "Error", "Failed to send image request: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
















bool MainWindow::faceVerification(const QString& photo1Path, const QString& photo2Path) {
    QString messageverif;
    url = "https://face-verification2.p.rapidapi.com/faceverification";


    // Construct the request
    QNetworkRequest request(url);
    request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
    request.setRawHeader("X-RapidAPI-Host", "face-verification2.p.rapidapi.com");
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("multipart/form-data; boundary=boundary"));

    // Construct the payload
    QByteArray postData;
    QFile photo1File(photo1Path);
    QFile photo2File(photo2Path);

    if (photo1File.open(QIODevice::ReadOnly) && photo2File.open(QIODevice::ReadOnly)) {
        postData.append("--boundary\r\n");
        postData.append(QString("Content-Disposition: form-data; name=\"photo1\"; filename=\"%1\"\r\n").arg(photo1Path));
        postData.append("Content-Type: image/jpeg\r\n\r\n");
        postData.append(photo1File.readAll());
        postData.append("\r\n");
        postData.append("--boundary\r\n");
        postData.append(QString("Content-Disposition: form-data; name=\"photo2\"; filename=\"%1\"\r\n").arg(photo2Path));
        postData.append("Content-Type: image/jpeg\r\n\r\n");
        postData.append(photo2File.readAll());
        postData.append("\r\n");
        postData.append("--boundary--\r\n");

        // Send the POST request
        reply = manager.post(request, postData);

        // Event loop to wait for reply finished
        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        // Handle the response
        if (reply->error() == QNetworkReply::NoError) {
            responseData = reply->readAll();
            qDebug() << responseData;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                        if (!jsonDoc.isNull()) {
                            QJsonObject jsonObj = jsonDoc.object();
                            if (jsonObj.contains("data") && jsonObj["data"].isObject()) {
                                QJsonObject dataObj = jsonObj["data"].toObject();
                                if (dataObj.contains("resultMessage") && dataObj["resultMessage"].isString()) {
                                    QString resultMessage = dataObj["resultMessage"].toString();
                                    qDebug() << "Result Message:" << resultMessage;
                                    messageverif=resultMessage;


                                }
                            }
                        }
            // Process the response data here
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

        // Clean up
        reply->deleteLater();
        photo1File.close();
        photo2File.close();
    } else {
        qDebug() << "Error opening photo files";
    }
    if(messageverif=="The two faces belong to the same person. ")
     {
        return true;
    }
    else
    {
        return false;
    }
}
void MainWindow::captureAndSavePhoto() {
    QString nv_path;

    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
dialog->resize(1000,1000);
    // Créer et configurer la caméra
    QCamera *camera = new QCamera(dialog);
    QCameraViewfinder *viewfinder = new QCameraViewfinder(dialog);
    camera->setViewfinder(viewfinder);

    // Créer QCameraImageCapture pour capturer des images
    QCameraImageCapture *imageCapture = new QCameraImageCapture(camera, dialog);
    QString path = "C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/temporaire.jpg";
    nv_path=path;
    // Connecter le signal imageCaptured au slot pour enregistrer l'image
    connect(imageCapture, &QCameraImageCapture::imageCaptured, [=](int id, const QImage& image) {

        image.save(path); // Enregistre l'image dans un fichier


    });
    QPushButton *captureButton = new QPushButton("Capture", dialog);
    connect(captureButton, &QPushButton::clicked, [=]() {
        // Capturer une image
        imageCapture->capture();
    });
    layout->addWidget(captureButton);
    QPushButton *button = new QPushButton("Declencher_reconnaissance", dialog);
    connect(button, &QPushButton::clicked, [=] {
    bool testout1=false;
    int compte;
    if(test)
   {
       qDebug() << "Connexion établie";
       QSqlDatabase::database().transaction();
       QSqlQuery querym(c.get_db());
       int num_ligne=1;

       querym.prepare("SELECT * FROM KINE");
       if(querym.exec())
       {
           while(querym.next() && testout1==false)
           {
               QByteArray imageData = querym.value("IMAGE").toByteArray();

               QPixmap image;
               image.loadFromData(QByteArray::fromBase64(imageData), "PNG");

               QPixmap circularImage(image.size());
               circularImage.fill(Qt::transparent);
               QPainter painter(&circularImage);
               QPainterPath path;
               path.addEllipse(image.rect());
               painter.setClipPath(path);
               painter.drawPixmap(0, 0, image);
               QString fileName = QString("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/image_%1.jpg").arg(num_ligne); // Nom de fichier unique basé sur l'index de ligne
               circularImage.save(fileName);
               bool nv_test=faceVerification(fileName,nv_path);
               if(nv_test==true)
               {
                   testout1=true;
               }
               else
               {
                   num_ligne++;
                   compte=num_ligne;
               }
           }
           QSqlDatabase::database().commit();
       }


   }
    if(testout1==true)
    {
    if(test)
    {
        qDebug() << "Connexion établie";
        QSqlDatabase::database().transaction();
        QSqlQuery querym1(c.get_db());
        qDebug() << "Connexion établie";
        querym1.prepare("SELECT * FROM (SELECT t.*, ROWNUM AS rn FROM KINE t) WHERE rn = :x");
        querym1.bindValue(":x", compte);
        if(querym1.exec())
        {
            while(querym1.next())
            {
                QByteArray imageData = querym1.value("IMAGE").toByteArray();

                QPixmap image;
                image.loadFromData(QByteArray::fromBase64(imageData), "PNG");

                QPixmap circularImage(image.size());
                circularImage.fill(Qt::transparent);
                QPainter painter(&circularImage);
                QPainterPath path;
                path.addEllipse(image.rect());
                painter.setClipPath(path);
                painter.drawPixmap(0, 0, image);


                QLabel *imageLabel = new QLabel(dialog);
                imageLabel->setPixmap(circularImage.scaled(300,300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                layout->addWidget(imageLabel);
                imageLabel->show();
                qDebug()<<"personne detectée";
                QString nom=querym1.value("NOM").toString()+" "+querym1.value("PRENOM").toString();
                QString sexe=querym1.value("SEXE").toString();
                QString Specialite=querym1.value("SPECIALITE").toString();
                QString telephone=querym1.value("TEL").toString();
                QString date=querym1.value("DATE_N").toString();

                QTextEdit *textEdit = new QTextEdit(dialog);

                // Insérer deux lignes de texte dans QTextEdit
                textEdit->insertPlainText("personne detectée \n" + nom+"\n"+sexe+"\n"+Specialite+"\n"+telephone+"\n"+date);
                layout->addWidget(textEdit);
            }
            QSqlDatabase::database().commit();
        }


    }
    }
    else
    {
        qDebug()<<"personne non detectée";
    }
});


    // Ajouter le viewfinder au layout du dialogue
    layout->addWidget(viewfinder);
    layout->addWidget(button);

    // Commencer la capture vidéo
    camera->start();

    // Afficher le dialogue
    dialog->exec();

    // Arrêter la caméra lorsque le dialogue est fermé
    camera->stop();
}


void MainWindow::on_pushButton_3_clicked()
{
    captureAndSavePhoto();

}















void MainWindow::on_historique_salle_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
     QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_salle.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();

}
void MainWindow::on_historique_employe_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
     QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_employe.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();

}
void MainWindow::on_historique_seance_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
     QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_seance.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();

}
void MainWindow::on_historique_machine_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
     QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_machine.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();

}
void MainWindow::on_historique_patient_2_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
     QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_patient.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();

}
void MainWindow::on_historique_kine_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->resize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
     QTextEdit *textEdit = new QTextEdit(dialog);

    // Ouvrir le fichier en lecture seule
    QFile file("C:/Users/LENOVO/OneDrive/Bureau/application 2 mars/application/Historique_kine.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Lire le contenu du fichier ligne par ligne et l'ajouter à QTextEdit
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = "evenement : "+in.readLine();
            textEdit->append(line);
        }
        // Fermer le fichier
        file.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        qDebug() << "Erreur lors de l'ouverture du fichier.";
    }
    layout->addWidget(textEdit);
    dialog->exec();

}


void MainWindow::sendRequest_45()
{
    QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Weather Information");
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        dialog->resize(800, 600);


        QLabel *countryLabel = new QLabel("Enter country:", dialog);
        QLineEdit *countryLineEdit = new QLineEdit(dialog);
        layout->addWidget(countryLabel);
        layout->addWidget(countryLineEdit);

        QLabel *weatherInfoLabel = new QLabel(dialog);
        weatherInfoLabel->setWordWrap(true);
        layout->addWidget(weatherInfoLabel);



        QPushButton *submitButton = new QPushButton("Get Weather", dialog);
        layout->addWidget(submitButton);

        dialog->setLayout(layout);
        // Créez une feuille de style CSS pour vos widgets
        QString styleSheet = "QLabel {"
                             "    font-size: 14px;"
                             "    color: #333333;" // Couleur du texte
                             "}"

                             "QLineEdit {"
                             "    font-size: 14px;"
                             "    padding: 5px;" // Ajout de marge intérieure pour l'apparence
                             "    border: 1px solid #999999;" // Bordure autour du champ de texte
                             "    border-radius: 3px;" // Coins arrondis
                             "}";

        // Appliquer la feuille de style CSS à vos widgets
        countryLabel->setStyleSheet(styleSheet);
        countryLineEdit->setStyleSheet(styleSheet);
        submitButton->setStyleSheet(
            "QPushButton {"
                "background-color: #4CAF50;"
                "border: none;"
                "color: white;"
                "padding: 15px 32px;"
                "text-align: center;"
                "text-decoration: none;"
                "display: inline-block;"
                "font-size: 16px;"
                "margin: 4px 2px;"
                "cursor: pointer;"
            "}"
            "QPushButton:hover {"
                "background-color: #45a049;"
            "}"
        );


        connect(submitButton, &QPushButton::clicked, [=]() {
            QString country = countryLineEdit->text();
            if (country.isEmpty()) {
                QMessageBox::warning(dialog, "Error", "Please enter a country.");
                return;
            }

            QString url = "https://open-weather13.p.rapidapi.com/city/" + country;

            QNetworkRequest request;
            request.setUrl(QUrl(url));
            request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
            request.setRawHeader("X-RapidAPI-Host", "open-weather13.p.rapidapi.com");

            QNetworkReply *reply = manager.get(request);

            connect(reply, &QNetworkReply::finished, [=]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QByteArray responseData = reply->readAll();

                    QString weatherInfo = processWeatherData(responseData);
                    weatherInfoLabel->setText(weatherInfo);
                } else {
                    QMessageBox::warning(dialog, "Error", "Error fetching weather data: " + reply->errorString());
                }
                reply->deleteLater();
            });
        });

        dialog->exec();
    }

QString MainWindow::processWeatherData(const QByteArray &data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();

        QString weatherInfo;

        // Créer un style CSS pour le QLineEdit
        QString lineEditStyle = "QLineEdit {"
                                    "background-color: white;"
                                    "border: 1px solid #ccc;"
                                    "border-radius: 4px;"
                                    "font-size: 16px;"
                                    "padding: 6px;"
                                "}";

        // Appliquer le style CSS au QLineEdit
        QLineEdit *lineEdit = new QLineEdit;
        lineEdit->setStyleSheet(lineEditStyle);

        // Créer un style CSS pour la QLabel
        QString labelStyle = "QLabel {"
                                "font-size: 16px;"
                                "color: #333333;"
                            "}";

        // Appliquer le style CSS à la QLabel
        QLabel *label = new QLabel;
        label->setStyleSheet(labelStyle);

        // Récupérer les informations météorologiques pertinentes et les ajouter à weatherInfo
        if (jsonObj.contains("weather") && jsonObj["weather"].isArray()) {
            QJsonArray weatherArray = jsonObj["weather"].toArray();
            if (!weatherArray.isEmpty()) {
                QJsonObject weatherObj = weatherArray.at(0).toObject();
                QString weatherMain = weatherObj["main"].toString();
                QString weatherDescription = weatherObj["description"].toString();
                weatherInfo += "Weather: " + weatherMain + " (" + weatherDescription + ")\n";
            }
        }

        if (jsonObj.contains("main")) {
            QJsonObject mainObj = jsonObj["main"].toObject();
            double tempFahrenheit = mainObj["temp"].toDouble();
            double tempCelsius = (tempFahrenheit - 32) * 5 / 9; // Conversion de Fahrenheit à Celsius
            double feelsLikeFahrenheit = mainObj["feels_like"].toDouble();
            double feelsLikeCelsius = (feelsLikeFahrenheit - 32) * 5 / 9; // Conversion de Fahrenheit à Celsius
            double pressure = mainObj["pressure"].toDouble();
            double humidity = mainObj["humidity"].toDouble();
            weatherInfo += QString("Temperature: %1°C\nFeels like: %2°C\nPressure: %3 hPa\nHumidity: %4%\n")
                               .arg(tempCelsius).arg(feelsLikeCelsius).arg(pressure).arg(humidity);
        }

        if (jsonObj.contains("wind")) {
            QJsonObject windObj = jsonObj["wind"].toObject();
            double windSpeed = windObj["speed"].toDouble();
            double windDirection = windObj["deg"].toDouble();
            weatherInfo += QString("Wind Speed: %1 m/s\nWind Direction: %2°\n").arg(windSpeed).arg(windDirection);
        }

        if (jsonObj.contains("clouds")) {
            QJsonObject cloudsObj = jsonObj["clouds"].toObject();
            double clouds = cloudsObj["all"].toDouble();
            weatherInfo += QString("Cloud Cover: %1%\n").arg(clouds);
        }

        // Ajoutez ici d'autres informations météorologiques nécessaires en extrayant les données de jsonObj

        // Définir le texte et le style pour la QLabel et le QLineEdit
        label->setText("Message:");
        lineEdit->setPlaceholderText("Entrez le pays ici");

        return weatherInfo;
    }
    return "No weather information available.";
}




void MainWindow::on_detection_visg_clicked()

{

    QDialog *dialog = new QDialog;
    dialog->setWindowTitle("Face Emotion Recognition");
    dialog->resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(dialog);


    QCamera *camera = new QCamera;

    QCameraViewfinder *viewfinder = new QCameraViewfinder;
    camera->setViewfinder(viewfinder);


    layout->addWidget(viewfinder);


    camera->start();


    QTextEdit *textEdit = new QTextEdit;
    layout->addWidget(textEdit);


    QPushButton *scanButton = new QPushButton("Scan");
    layout->addWidget(scanButton);


    scanButton->setStyleSheet(
        "QPushButton {"
            "background-color: #4CAF50;"
            "border: none;"
            "color: white;"
            "padding: 15px 32px;"
            "text-align: center;"
            "text-decoration: none;"
            "display: inline-block;"
            "font-size: 16px;"
            "margin: 4px 2px;"
            "cursor: pointer;"
        "}"
        "QPushButton:hover {"
            "background-color: #45a049;"
        "}"
    );


    QCameraImageCapture *imageCapture = new QCameraImageCapture(camera);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);


    QObject::connect(imageCapture, &QCameraImageCapture::imageCaptured, [=](int id, const QImage &preview) {

        QString response = patient.performFaceAnalysis(preview);

        textEdit->setText(response);
    });


    QObject::connect(scanButton, &QPushButton::clicked, [=]() {

        imageCapture->capture();
    });


    dialog->exec();
    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
    blurEffect->setBlurRadius(20);

    dialog->setGraphicsEffect(blurEffect);

    camera->stop();


    delete camera;
}


void MainWindow::on_b_certif_clicked()
{
    QDialog *dialog = new QDialog(this);
        certUi = new Ui::CertificateDialog(); // Create an instance of the class Ui::CertificateDialog
        dialog->setWindowFlags( Qt::FramelessWindowHint);

        // Setup the user interface
        certUi->setupUi(dialog);

        // Connect the "accepted" signal of the QDialog to the slot "saveCertificateData"
        connect(dialog, &QDialog::accepted, this, &MainWindow::saveCertificateData);

        // Show the dialog
        dialog->exec();
}

void MainWindow::saveCertificateData(){

// Check if the image loaded successfully
QPixmap certificatImage(":/icon_tabN/ressource/icon_n/icon_tabN/certif22.png");
if (certificatImage.isNull()) {
    qDebug() << "Failed to load image.";
    return;
}
int fontId = QFontDatabase::addApplicationFont(":/icon_tabN/ressource/icon_n/icon_tabN/yearlong/Yearlong_DEMO.ttf");

if (fontId != -1) {
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    if (!fontFamilies.isEmpty()) {
        QFont customFont(fontFamilies.at(0), 84); // Set font size
        QPainter painter(&certificatImage);
        if (painter.isActive()) {

            painter.setPen(Qt::black);

            // Set custom font
            painter.setFont(customFont);

                QString nom = certUi->LineEdit_prenom_certif->text();
                    QString prenom = certUi->LineEdit_nom_certif->text();
                    QString date = certUi->dateEdit_certif->text();
                    QString jours = certUi->spinBox_certif->text();
qDebug()<<nom;
qDebug()<<prenom;
qDebug()<<date;
            painter.drawText(1650, 837, nom);
            painter.drawText(1650, 1126, prenom);
            painter.drawText(1920, 1500, jours);
            painter.drawText(1685, 1790, date);
            // End painting
            painter.end();


            QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
            QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/certificat_modifie.png";
            certificatImage.save(filePath);

            qDebug() << "Image saved to: " << filePath;

            // Optionally, display the modified image
            // ui->labelCertificat->setPixmap(certificatImage);
        } else {
            qDebug() << "Painter is not active.";
        }
    } else {
        qDebug() << "Failed to load custom font family.";
    }
} else {
    qDebug() << "Failed to load custom font.";
}
}
void MainWindow::on_screenshot_b_clicked()
{

    QPixmap screenshot = this->grab();


    QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/screenshot_patient.png";


    screenshot.save(filePath, "PNG");
}

void MainWindow::on_screenshot_seance_clicked()
{
    QPixmap screenshot = this->grab();


    QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/screenshot_seance.png";


    screenshot.save(filePath, "PNG");
}

void MainWindow::on_screenshot_kine_clicked()
{
    QPixmap screenshot = this->grab();


    QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/screenshot_kine.png";


    screenshot.save(filePath, "PNG");
}


void MainWindow::on_screenshot_machine_clicked()
{
    QPixmap screenshot = this->grab();


    QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/screenshot_machine.png";


    screenshot.save(filePath, "PNG");
}

void MainWindow::on_screenshot_employe_clicked()
{
    QPixmap screenshot = this->grab();


    QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/screenshot_employe.png";


    screenshot.save(filePath, "PNG");
}


void MainWindow::on_screenshot_salle_clicked()
{
    QPixmap screens = this->grab();


    QString filePath = "C:/Users/LENOVO/OneDrive/Bureau/screenshot_salle.png";


    screens.save(filePath, "PNG");
}




void MainWindow::modifierEtat(int idSeance, const QString& etat) {
    QSqlQuery query;
    query.prepare("UPDATE SEANCE SET ETAT = :etat WHERE ID_SEANCE = :id");
    query.bindValue(":etat", etat);
    query.bindValue(":id", idSeance);
    if (query.exec()) {
        qDebug() << "État de la séance modifié avec succès.";
    } else {
        qWarning() << "Erreur lors de la modification de l'état de la séance:" << query.lastError().text();
    }
}


void MainWindow::checkSeanceTime() {
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Parcourez toutes les séances dans votre base de données
    QSqlQuery query("SELECT * FROM SEANCE");
    while (query.next()) {
        QDateTime seanceDateTime = query.value("DATE_S").toDateTime();
        QTime heureDebut = query.value("HEURE_DEBUT").toTime();
        QTime heureFin = query.value("HEURE_FIN").toTime();

        // Vérifiez si la séance est en cours ou terminée
        if (currentDateTime.date() == seanceDateTime.date()) {
            if (currentDateTime.time() >= heureDebut && currentDateTime.time() <= heureFin) {
                // La séance est en cours
                continue;
            } else if (currentDateTime.time() > heureFin) {
                // La séance est terminée, affichez un message
                QString typeSeance = query.value("TYPE").toString();
                QMessageBox msgBox;
                msgBox.setWindowTitle("Séance Terminée");
                msgBox.setText(QString("La séance de type %1 du %2 à %3 est terminée. Cette séance est-elle validée ?")
                                    .arg(typeSeance)
                                    .arg(seanceDateTime.toString("hh:mm"))
                                    .arg(heureFin.toString("hh:mm")));
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                int choice = msgBox.exec();

                // Mettez à jour l'état de la séance en fonction du choix de l'utilisateur
                if (choice == QMessageBox::Yes) {
                    // Valider la séance (set checkbox to checked)
                    modifierEtat(query.value("ID_SEANCE").toInt(), "validee");
                } else {
                    // Ne pas valider la séance (set checkbox to unchecked)
                    modifierEtat(query.value("ID_SEANCE").toInt(), "non validee");
                }
            }
        }
    }
}


//excel
void MainWindow::exportTableToCSV_seance() {
    // Obtenez le nom de fichier à partir d'une boîte de dialogue de fichier
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier CSV"), "", tr("Fichiers CSV (*.csv)"));

    // Vérifiez si l'utilisateur a annulé la boîte de dialogue
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Gérer l'échec de l'ouverture du fichier
        return;
    }

    QTextStream out(&file);

    // Parcourez chaque ligne du tableau et écrivez les données dans le fichier CSV
    for (int row = 0; row < ui->table_seance->rowCount(); ++row) {
        for (int col = 0; col < ui->table_seance->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_seance->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < ui->table_seance->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
}

void MainWindow::exportTableToCSV_kine() {
    // Obtenez le nom de fichier à partir d'une boîte de dialogue de fichier
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier CSV"), "", tr("Fichiers CSV (*.csv)"));

    // Vérifiez si l'utilisateur a annulé la boîte de dialogue
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Gérer l'échec de l'ouverture du fichier
        return;
    }

    QTextStream out(&file);

    // Parcourez chaque ligne du tableau et écrivez les données dans le fichier CSV
    for (int row = 0; row < ui->table_kine->rowCount(); ++row) {
        for (int col = 0; col < ui->table_kine->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_kine->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < ui->table_kine->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
}
void MainWindow::exportTableToCSV_employe() {
    // Obtenez le nom de fichier à partir d'une boîte de dialogue de fichier
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier CSV"), "", tr("Fichiers CSV (*.csv)"));

    // Vérifiez si l'utilisateur a annulé la boîte de dialogue
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Gérer l'échec de l'ouverture du fichier
        return;
    }

    QTextStream out(&file);

    // Parcourez chaque ligne du tableau et écrivez les données dans le fichier CSV
    for (int row = 0; row < ui->table_employe->rowCount(); ++row) {
        for (int col = 0; col < ui->table_employe->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_employe->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < ui->table_employe->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
}
void MainWindow::exportTableToCSV_patient() {
    // Obtenez le nom de fichier à partir d'une boîte de dialogue de fichier
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier CSV"), "", tr("Fichiers CSV (*.csv)"));

    // Vérifiez si l'utilisateur a annulé la boîte de dialogue
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Gérer l'échec de l'ouverture du fichier
        return;
    }

    QTextStream out(&file);

    // Parcourez chaque ligne du tableau et écrivez les données dans le fichier CSV
    for (int row = 0; row < ui->table_patient->rowCount(); ++row) {
        for (int col = 0; col < ui->table_patient->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_patient->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < ui->table_patient->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
}
void MainWindow::exportTableToCSV_salle() {
    // Obtenez le nom de fichier à partir d'une boîte de dialogue de fichier
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier CSV"), "", tr("Fichiers CSV (*.csv)"));

    // Vérifiez si l'utilisateur a annulé la boîte de dialogue
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Gérer l'échec de l'ouverture du fichier
        return;
    }

    QTextStream out(&file);

    // Parcourez chaque ligne du tableau et écrivez les données dans le fichier CSV
    for (int row = 0; row < ui->table_salle->rowCount(); ++row) {
        for (int col = 0; col < ui->table_salle->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_salle->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < ui->table_salle->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
}
void MainWindow::exportTableToCSV_machine() {
    // Obtenez le nom de fichier à partir d'une boîte de dialogue de fichier
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier CSV"), "", tr("Fichiers CSV (*.csv)"));

    // Vérifiez si l'utilisateur a annulé la boîte de dialogue
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Gérer l'échec de l'ouverture du fichier
        return;
    }

    QTextStream out(&file);

    // Parcourez chaque ligne du tableau et écrivez les données dans le fichier CSV
    for (int row = 0; row < ui->table_machine->rowCount(); ++row) {
        for (int col = 0; col < ui->table_machine->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table_machine->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < ui->table_machine->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
}
/*
void MainWindow::envoyerSMS(const QString &destinataire, const QString &message)
{
    // SID et auth token de Twilio
    QString sid = QString::fromUtf8(qgetenv("TWILIO_SID"));
    QString authToken = QString::fromUtf8(qgetenv("TWILIO_TOKEN"));

    // Construire l'URL de l'API Twilio
    QString url = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";

    // Créer la requête HTTP
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(sid).arg(authToken).toUtf8()).toBase64());

    // Construire les données de la requête
    QByteArray postData;
    postData.append("To=" + destinataire.toUtf8());
    postData.append("&From=+14432750319");
    postData.append("&Body=" + message.toUtf8());

    // Créer le gestionnaire de réseau
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
    connect(networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);

    // Envoyer la requête
    QNetworkReply *reply = networkAccessManager->post(request, postData);

    // Attendre la réponse
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Libérer la mémoire
    reply->deleteLater();


}


void MainWindow::replyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        // Afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'envoi du SMS : " + reply->errorString());
    }
    else
    {
        // Afficher un message de succès
        QMessageBox::information(this, "Envoi SMS", "Le SMS a été envoyé avec succès.");
    }
    // Libérer la mémoire
    reply->deleteLater();
}



void MainWindow::on_sendSms_clicked()
{
    QString destinataire = "+21629681046"; // Numéro de téléphone du destinataire
    QString message = "hello"; // Message à envoyer

    envoyerSMS(destinataire, message);
}*/
void MainWindow::envoyerSMS(const QString &destinataire, const QString &message)
{
    // SID et auth token de Twilio
    QString sid = QString::fromUtf8(qgetenv("TWILIO_SID"));
    QString authToken = QString::fromUtf8(qgetenv("TWILIO_TOKEN"));

    // Construire l'URL de l'API Twilio
    QString url = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";

    // Créer la requête HTTP
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(sid).arg(authToken).toUtf8()).toBase64());

    // Construire les données de la requête
    QByteArray postData;
    postData.append("To=" + destinataire.toUtf8());
    postData.append("&From=+12563968443");
    postData.append("&Body=" + message.toUtf8());

    // Créer le gestionnaire de réseau
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
    connect(networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);

    // Envoyer la requête
    QNetworkReply *reply = networkAccessManager->post(request, postData);

    // Attendre la réponse
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Libérer la mémoire
    reply->deleteLater();


}


void MainWindow::replyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        // Afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de l'envoi du SMS : " + reply->errorString());
    }
    else
    {
        // Afficher un message de succès
        QMessageBox::information(this, "Envoi SMS", "Le SMS a été envoyé avec succès.");
    }
    // Libérer la mémoire
    reply->deleteLater();
}



void MainWindow::notification_liste()
{
    QString destinataire = "+21658133596"; // Numéro de téléphone du destinataire
    QString message = "La séance est validé"; // Message à envoyer

    envoyerSMS(destinataire, message);
}




QString MainWindow::getCurrentUserRole(const QString& login) {
    QString role; // Variable pour stocker le rôle récupéré

    // Connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flexiverse");
    db.setUserName("raif");
    db.setPassword(QString::fromUtf8(qgetenv("DB_PASSWORD")));

    // Vérifier si la connexion est établie
    if (!db.open()) {
        qDebug() << "Erreur lors de la connexion à la base de données:" << db.lastError().text();
        return role; // Retourner une chaîne vide si la connexion a échoué
    }

    qDebug() << "Connexion à la base de données établie";

    // Exemple de requête SQL pour récupérer le rôle de l'utilisateur depuis la table EMPLOYE
    QSqlQuery query;
    query.prepare("SELECT ROLE FROM EMPLOYE WHERE LOGIN = :login"); // Adaptation de la requête selon votre structure de base de données
    query.bindValue(":login", login);

    // Exécuter la requête et récupérer le résultat
    if (query.exec() && query.next()) {
        role = query.value(0).toString();
        qDebug() << "Rôle de l'utilisateur" << login << " :" << role; // Afficher le rôle récupéré
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:" << query.lastError().text();
    }

    // Fermer la connexion à la base de données
    db.close();
    qDebug() << "Connexion à la base de données fermée";

    return role;
}



void MainWindow::onLoginSuccessful(const QString& username) {
    qDebug() << "Login successful for user:" << username;
    QString role = getCurrentUserRole(username);

    qDebug() << "Role retrieved from database:" << role; // Ajoutez ce message de débogage

    if (role.isEmpty()) {
        // Si le rôle est vide ou non valide, affichez un message d'erreur et déconnectez l'utilisateur.
        QMessageBox::critical(this, "Erreur", "Le rôle de cet utilisateur n'est pas valide.");
        return;
    }

    // Désactiver les boutons d'accès en fonction du rôle de l'utilisateur
    qDebug() << "Disabling buttons based on role:";

    if (role != "Gestion des patients") {
        qDebug() << "Disabling bm_Patients button";
        ui->bm_Patients->setEnabled(false);
    }

    if (role != "Gestion des kines") {
        qDebug() << "Disabling bm_Kines button";
        ui->bm_Kines->setEnabled(false);
    }

    if (role != "Gestion des Seances") {
        qDebug() << "Disabling bm_Seances button";
        ui->bm_Seances->setEnabled(false);
    }

    if (role != "Gestion des Machines") {
        qDebug() << "Disabling bm_Machines button";
        ui->bm_Machines->setEnabled(false);
    }

    if (role != "Gestion des Salles") {
        qDebug() << "Disabling bm_Salles button";
        ui->bm_Salles->setEnabled(false);
    }

    // Afficher la page principale après avoir configuré les autorisations
    this->show();
}






void MainWindow::showWelcomeMessage(const QString &username) {
    QMessageBox::information(this, "Bienvenue", "Connecté en tant que : " + username);
}



void MainWindow::on_news_clicked()
{
    // Créer un gestionnaire d'accès réseau
    networkManager = new QNetworkAccessManager(this);

    // Construire l'URL avec les paramètres nécessaires
    QUrl url("https://google-news13.p.rapidapi.com/health?lr=en-US");
    QUrlQuery query;
    query.addQueryItem("lr", "en-US");
    url.setQuery(query);

    // Créer la requête HTTP
    request = QNetworkRequest(url);

    // Ajouter les en-têtes requis
    request.setRawHeader("X-RapidAPI-Key", qgetenv("RAPIDAPI_KEY"));
    request.setRawHeader("X-RapidAPI-Host", "google-news13.p.rapidapi.com");

    // Effectuer la requête
    reply = networkManager->get(request);

    // Connecter le signal de fin de requête à une fonction pour traiter la réponse
    connect(reply, &QNetworkReply::finished, this, &MainWindow::handleNetworkData);
}


void MainWindow::handleNetworkData()
{
    ui->label_77->hide();
    if (reply->error() == QNetworkReply::NoError) {
        // Récupérer les données de réponse
        QByteArray responseData = reply->readAll();

        // Convertir la réponse JSON en objet QVariant
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QVariantMap result = jsonDoc.toVariant().toMap();

        // Vérifier si la réponse contient la clé "items"
        if (result.contains("items")) {
            QVariantList items = result["items"].toList();
            QString displayText;

            // Parcourir chaque élément dans "items" et concaténer les extraits
            for (const QVariant &item : items) {
                QVariantMap itemMap = item.toMap();
                QString snippet = itemMap["snippet"].toString();
                displayText += snippet + "   |   ";
            }

            // Créer un QDialog pour afficher le texte défilant
            QDialog *dialog = new QDialog(this);
            dialog->setWindowTitle("Contenu");

            QLabel *label = new QLabel(dialog);
            label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            label->setText(displayText);

            // Définir la couleur de fond et la couleur du texte
            label->setStyleSheet("background-color: rgb(31, 149, 239); color: black;");

            // Définir la taille de police du texte
            QFont font = label->font();
            font.setPointSize(14); // Modifier la taille de police selon vos besoins
            label->setFont(font);

            // Ajuster la taille du QLabel en fonction de la taille du texte
            label->adjustSize();

            // Déplacer le QDialog à la position désirée
            int desiredX = 220; // Modifier selon vos besoins
            int desiredY = 960; // Modifier selon vos besoins
            dialog->move(desiredX, desiredY);

            // Masquer la barre de titre du QDialog
            dialog->setWindowFlags(dialog->windowFlags() | Qt::FramelessWindowHint);

            // Créer une animation pour faire défiler le texte
            QPropertyAnimation *animation = new QPropertyAnimation(label, "pos", dialog);
            animation->setDuration(298000); // ajustez la durée selon vos besoins
            animation->setStartValue(QPoint(dialog->width(), 0));
            animation->setEndValue(QPoint(-label->width(), 0));

            // Connecter le signal de fin de l'animation pour fermer le QDialog
            connect(animation, &QPropertyAnimation::finished, dialog, &QDialog::accept);

            // Démarrer l'animation
            animation->start();

            // Afficher le QDialog
            dialog->exec();
        }
    } else {
        // En cas d'erreur lors de la requête
        qDebug() << "Erreur de requête: " << reply->errorString();
    }
    // Libérer la mémoire utilisée par la réponse
    reply->deleteLater();
    ui->label_77->show();
}

void MainWindow::startAnimation()
{
    // Calculer la largeur totale du texte
    int textWidth = tickerLabel->fontMetrics().width(tickerLabel->text());

    // Créer une animation pour faire défiler le texte de droite à gauche
    animation = new QPropertyAnimation(tickerLabel, "pos", this);
    animation->setDuration(280000);
    animation->setStartValue(QPoint(width(), height() - tickerLabel->height()));
    animation->setEndValue(QPoint(-textWidth, height() - tickerLabel->height()));
    connect(animation, &QPropertyAnimation::finished, this, &MainWindow::restartAnimation);

    // Démarrer l'animation
    animation->start();
}

void MainWindow::restartAnimation()
{
    // Déplacer le QLabel à droite de la fenêtre pour redémarrer l'animation
    tickerLabel->move(width(), height() - tickerLabel->height());

    // Redémarrer le QTimer pour redémarrer l'animation
    restartTimer->start(3000); // Démarre l'animation après 3 secondes
}









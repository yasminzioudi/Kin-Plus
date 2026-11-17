#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"
#include "oublimotdepassedialog.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <string>
#include <QCryptographicHash>


#include <QtNetwork>

logindialog::logindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    ui->setupUi(this);
    this->setWindowTitle("FlexiVerse");

    QString styleSheet = "QProgressBar {"
                             "border: 2px solid grey;"
                             "border-radius: 5px;"
                             "background-color: white;"
                             "}"
                             "QProgressBar::chunk {"
                             "background-color: #3498db;" // Couleur bleue
                             "width: 20px;" // Largeur de chaque segment de progression
                             "}";
        ui->progressBar->setStyleSheet(styleSheet);
     ui->progressBar->hide();
    // Masquer le texte du champ de mot de passe
        ui->passLineEdit->setEchoMode(QLineEdit::Password);
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &logindialog::updateProgress);
}

logindialog::~logindialog()
{
    delete ui;

}
QString logindialog::getUsername() const {
    return ui->loginLineEdit->text(); // Renvoie le texte du champ de saisie de login
}


void logindialog::on_pushButton_clicked()
{
    // Afficher la barre de progression
    ui->progressBar->show();
    ui->progressBar->setMaximum(100);

    // Commencer l'animation de la barre de progression
    ui->progressBar->setValue(20);
    timer->start(50); // Changez l'intervalle selon vos besoins

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flexiverse"); // Remplacez "localhost" par le nom de votre serveur
    db.setUserName("raif"); // Remplacez "test" par votre nom d'utilisateur
    db.setPassword("esprit18"); // Remplacez "test" par votre mot de passe

    // Ouvrez la connexion
    if (!db.open()) {
        QMessageBox::critical(this, "Erreur de connexion", "Impossible de se connecter à la base de données : " + db.lastError().text());
        // Arrêter le timer et cacher la barre de progression en cas d'erreur
        timer->stop();
        ui->progressBar->hide();
        return;
    }
    QByteArray hashedPassword = QCryptographicHash::hash(ui->passLineEdit->text().toUtf8(), QCryptographicHash::Sha256).toHex();
        QString hashedPasswordString = QString(hashedPassword);

    // Préparez la requête SQL
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE LOGIN = :login AND MDP = :mdp");
    query.bindValue(":login", ui->loginLineEdit->text());
    query.bindValue(":mdp", hashedPasswordString);


    // Exécutez la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur de requête", "La requête a échoué : " + query.lastError().text());
        // Arrêter le timer et cacher la barre de progression en cas d'erreur
        timer->stop();
        ui->progressBar->hide();
        return;
    }


    // Vérifiez le résultat
    if (query.next() && query.value(0).toInt() > 0) {
        emit loginSuccessful(ui->loginLineEdit->text()); // Émettre le signal loginSuccessful avec le nom d'utilisateur
        // Les informations de connexion sont correctes
        // modifyPassword(ui->loginLineEdit->text(), ui->newPasswordLineEdit->text());
        accept();
    } else {
        // Les informations de connexion sont incorrectes
        QMessageBox::warning(this, "Erreur de connexion", "Nom d'utilisateur ou mot de passe incorrect.");
    }

    // Arrêter le timer une fois que le traitement est terminé
    timer->stop();
}

void logindialog::updateProgress()
{
    // Incrémenter la valeur de la barre de progression
    int value = ui->progressBar->value();
    value += 1; // Augmentez la valeur selon vos besoins
    ui->progressBar->setValue(value);
}



void logindialog::on_oubliMotDePasse_clicked()
{
    QString username = ui->loginLineEdit->text();

       // Afficher la boîte de dialogue de récupération de mot de passe (oublimotde passe dialog)
       OubliMotDePasseDialog oublimotdePasseDialog;
       oublimotdePasseDialog.setLogin(username); // Passer le nom d'utilisateur à la boîte de dialogue de récupération de mot de passe
       oublimotdePasseDialog.exec();

}

#include "oublimotdepassedialog.h"
#include "ui_oublimotdepassedialog.h"
#include "oublimotdepasseinputdialog.h"
#include <QSqlDatabase> // Ajout de cette ligne
#include <QSqlQuery> // Ajout de cette ligne
#include <QDebug> // Ajout de cette ligne
#include <QSqlError>
#include <QAbstractButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QCryptographicHash>


OubliMotDePasseDialog::OubliMotDePasseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OubliMotDePasseDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("mot de passe ooublier");
    connect(ui->buttonBox, &QDialogButtonBox::clicked, this, &OubliMotDePasseDialog::on_buttonBox_clicked);

}

OubliMotDePasseDialog::~OubliMotDePasseDialog()
{
    delete ui;
}


QString OubliMotDePasseDialog::recupererQuestionSecurite(const QString &login)
{
    QString questionSecurite;

    // Ouvrir la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flexiverse");
    db.setUserName("raif");
    db.setPassword("esprit18");

    // Vérifier si la connexion à la base de données a été établie avec succès
    if (db.open()) {
        // Préparer la requête SQL pour récupérer la question de sécurité en fonction du login
        QSqlQuery query;
        query.prepare("SELECT QUESTION_SECURITE FROM EMPLOYE WHERE LOGIN = :login");
        query.bindValue(":login", login);

        // Exécuter la requête SQL
        if (query.exec()) {
            // Vérifier si des résultats sont retournés
            if (query.next()) {
                // Récupérer la question de sécurité depuis le résultat de la requête
                questionSecurite = query.value(0).toString();
            } else {
                // Aucune question de sécurité trouvée pour ce login
                qDebug() << "Aucune question de sécurité trouvée pour le login :" << login;
            }
        } else {
            // Erreur lors de l'exécution de la requête SQL
            qDebug() << "Erreur lors de l'exécution de la requête SQL pour récupérer la question de sécurité :" << query.lastError().text();
        }
    } else {
        // La connexion à la base de données n'a pas pu être établie
        qDebug() << "La connexion à la base de données n'a pas pu être établie.";
    }

    return questionSecurite;
}

void OubliMotDePasseDialog::setLogin(const QString &username)
{
    ui->lineEdit_2->setText(username); // Définir le nom d'utilisateur dans le lineEdit correspondant

    // Récupérer la question de sécurité associée à ce login
    QString questionSecurite = recupererQuestionSecurite(username);

    // Afficher la question de sécurité dans le QLabel (ou tout autre widget)
    ui->lineEditQuestionSecurite->setText(questionSecurite); // Assurez-vous que labelQuestionSecurite est le nom de votre QLabel

}
QString OubliMotDePasseDialog::recupererReponseSecurite(const QString &login)
{
    QString reponseSecurite;

    // Ouvrir la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flexiverse");
    db.setUserName("raif");
    db.setPassword("esprit18");

    // Vérifier si la connexion à la base de données a été établie avec succès
    if (db.open()) {

        // Préparer la requête SQL pour récupérer la réponse de sécurité en fonction du login
        QSqlQuery query;
        query.prepare("SELECT REPONSE_SECURITE FROM EMPLOYE WHERE LOGIN = :login");
        query.bindValue(":login", login);

        // Exécuter la requête SQL
        if (query.exec()) {
            // Vérifier si des résultats sont retournés
            if (query.next()) {
                // Récupérer la réponse de sécurité depuis le résultat de la requête
                reponseSecurite = query.value(0).toString();
            } else {
                // Aucune réponse de sécurité trouvée pour ce login
                qDebug() << "Aucune réponse de sécurité trouvée pour le login :" << login;
            }
        } else {
            // Erreur lors de l'exécution de la requête SQL
            qDebug() << "Erreur lors de l'exécution de la requête SQL pour récupérer la réponse de sécurité :" << query.lastError().text();
        }
    } else {
        // La connexion à la base de données n'a pas pu être établie
        qDebug() << "La connexion à la base de données n'a pas pu être établie.";
    }

    return reponseSecurite;
}


bool OubliMotDePasseDialog::verifierReponseSecurite(const QString &login, const QString &reponseUtilisateur)
{
    // Récupérer la réponse de sécurité associée au login depuis la base de données
    QString reponseBD = recupererReponseSecurite(login);

    // Comparer la réponse saisie par l'utilisateur avec la réponse de sécurité de la base de données
    return (reponseUtilisateur == reponseBD);
}
bool OubliMotDePasseDialog::mettreAJourMotDePasse(const QString &login, const QString &nouveauMotDePasse)
{
    // Ouvrir la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flexiverse");
    db.setUserName("raif");
    db.setPassword("esprit18");

    // Vérifier si la connexion à la base de données a été établie avec succès
    if (db.open()) {
        // Préparer la requête SQL pour mettre à jour le mot de passe
        QByteArray hashedPassword = QCryptographicHash::hash(nouveauMotDePasse.toUtf8(), QCryptographicHash::Sha256).toHex();
                QString hashedPasswordString = QString(hashedPassword);
        QSqlQuery query;
        query.prepare("UPDATE EMPLOYE SET MDP = :nouveauMotDePasse WHERE LOGIN = :login");
        query.bindValue(":nouveauMotDePasse", hashedPasswordString);
        query.bindValue(":login", login);

        // Exécuter la requête SQL
        if (query.exec()) {
            // La mise à jour du mot de passe a réussi
            return true;
        } else {
            // La mise à jour du mot de passe a échoué
            qDebug() << "Erreur lors de la mise à jour du mot de passe :" << query.lastError().text();
            return false;
        }
    } else {
        // La connexion à la base de données a échoué
        qDebug() << "La connexion à la base de données a échoué.";
        return false;
    }
}


// Début de la définition de la fonction on_buttonBox_clicked
void OubliMotDePasseDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->buttonBox->buttonRole(button) == QDialogButtonBox::AcceptRole) {
        QString login = ui->lineEdit_2->text();
        QString reponseUtilisateur = ui->lineEdit->text();

        if (verifierReponseSecurite(login, reponseUtilisateur)) {
            bool motDePasseAccepte = false;
            OubliMotDePasseInputDialog dialog;
            connect(&dialog, &OubliMotDePasseInputDialog::validerNouveauMotDePasse, this, [&](const QString &nouveauMotDePasse) {
                qDebug() << "Signal validerNouveauMotDePasse émis";
                QRegExp mdpRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%*?&#]{8,}$");

                if (!mdpRegex.exactMatch(nouveauMotDePasse)) {
                    QMessageBox::critical(&dialog, "Erreur", "Le mot de passe doit être fort, contenant au moins 8 caractères avec au moins une majuscule, une minuscule, un chiffre et un caractère spécial.");
                } else {
                    if (mettreAJourMotDePasse(login, nouveauMotDePasse)) {
                        QMessageBox::information(&dialog, "Succès", "Votre mot de passe a été réinitialisé avec succès !");
                        motDePasseAccepte = true;
                        dialog.accept();
                    } else {
                        QMessageBox::critical(&dialog, "Erreur", "Impossible de réinitialiser votre mot de passe. Veuillez réessayer plus tard.");
                    }
                }
            });

            while (!motDePasseAccepte) {

                //dialog.disconnect();


                if(dialog.exec() == QDialog::Accepted && motDePasseAccepte) {
                    dialog.close();
                }
            }
        } else {
            QMessageBox::warning(this, "Erreur", "Réponse de sécurité incorrecte.");
        }
    }
}

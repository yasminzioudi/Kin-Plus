#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include "loadscreen.h"
#include "logindialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Connection c;
    MainWindow w;
    w.setWindowTitle("FlexiVerse");

    bool test = c.createconnect();

    qDebug() << "OpenSSL build version:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "OpenSSL supported:" << QSslSocket::supportsSsl();
    if (QSslSocket::supportsSsl()) {
        qDebug() << "OpenSSL runtime version:" << QSslSocket::sslLibraryVersionString();
    } else {
        qDebug() << "OpenSSL not found";
    }

    LoadScreen loadScreen;
    loadScreen.show();

    // Afficher la fenêtre de connexion après un délai de 7 secondes
    QTimer::singleShot(7000, [&loadScreen, &w, test]() {
        loadScreen.close(); // Fermer la fenêtre de chargement

        if (test) {
            logindialog loginDialog;
            if (loginDialog.exec() == QDialog::Accepted) {
                QString username = loginDialog.getUsername();
                if (!username.isEmpty()) {
                    w.onLoginSuccessful(username);
                    w.show();
                    w.showWelcomeMessage(username);
                } else {
                    // Gestion des erreurs si le nom d'utilisateur est vide
                }
            } else {
                // L'utilisateur a annulé la connexion
            }
        } else {
            // La connexion à la base de données a échoué
            QMessageBox::information(nullptr, QObject::tr("Database is not open"),
                                     QObject::tr("Connection failed.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
    });

    return a.exec();
}

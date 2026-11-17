#include "connexion.h"
#include <QMessageBox>
Connection::Connection()
{




}
bool Connection::createconnect() {
bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("flexiverse"); // Remplacez "localhost" par le nom de votre serveur
db.setUserName("dhia"); // Remplacez "test" par votre nom d'utilisateur
db.setPassword("dhia"); // Remplacez "test" par votre mot de passe
if(db.open())
        test= true;



        return test;
    }
QSqlDatabase Connection::get_db()
{
    return db;
}


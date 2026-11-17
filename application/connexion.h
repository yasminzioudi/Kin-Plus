#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class Connection
{
public :
    Connection();
    bool createconnect();
    QSqlDatabase get_db();
    // Définissez un message personnalisé pour détecter les clics sur l'icône de notification
#define WM_ICON_NOTIFY (WM_USER + 1)

private:
QSqlDatabase db;




};























#endif // CONNEXION_H

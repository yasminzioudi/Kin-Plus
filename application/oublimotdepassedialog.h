#ifndef OUBLIMOTDEPASSEDIALOG_H
#define OUBLIMOTDEPASSEDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class OubliMotDePasseDialog;
}

class OubliMotDePasseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OubliMotDePasseDialog(QWidget *parent = nullptr);
    ~OubliMotDePasseDialog();
     bool mettreAJourMotDePasse(const QString &login, const QString &nouveauMotDePasse);
    void setLogin(const QString &username); // Méthode pour définir le nom d'utilisateur
     QString recupererQuestionSecurite(const QString &login);
     bool verifierReponseSecurite(const QString &login, const QString &reponseUtilisateur);
     QString recupererReponseSecurite(const QString &login);
      void on_buttonBox_clicked(QAbstractButton *button);
private slots:


private:
    Ui::OubliMotDePasseDialog *ui;
};

#endif // OUBLIMOTDEPASSEDIALOG_H

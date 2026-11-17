#ifndef OUBLIMOTDEPASSEINPUTDIALOG_H
#define OUBLIMOTDEPASSEINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class OubliMotDePasseInputDialog;
}

class OubliMotDePasseInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OubliMotDePasseInputDialog(QWidget *parent = nullptr);
    ~OubliMotDePasseInputDialog();
     QString getNouveauMotDePasse() const;
signals:
void validerNouveauMotDePasse(const QString &nouveauMotDePasse); // Déclaration du signal


private slots:
     void on_pushButton_clicked();

private:
    Ui::OubliMotDePasseInputDialog *ui;
};

#endif // OUBLIMOTDEPASSEINPUTDIALOG_H

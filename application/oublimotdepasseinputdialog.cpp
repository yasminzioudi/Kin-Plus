#include "oublimotdepasseinputdialog.h"
#include "ui_oublimotdepasseinputdialog.h"
#include "oublimotdepassedialog.h"
#include "ui_oublimotdepassedialog.h"

OubliMotDePasseInputDialog::OubliMotDePasseInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OubliMotDePasseInputDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &OubliMotDePasseInputDialog::on_pushButton_clicked);
}

OubliMotDePasseInputDialog::~OubliMotDePasseInputDialog()
{
    delete ui;
}
QString OubliMotDePasseInputDialog::getNouveauMotDePasse() const
{
    return ui->lineEdit->text();
}
void OubliMotDePasseInputDialog::on_pushButton_clicked()
{

    // Émettre le signal avec le nouveau mot de passe
    emit validerNouveauMotDePasse(getNouveauMotDePasse());
    close(); // Fermer la boîte de dialogue après avoir cliqué sur "Valider"
}

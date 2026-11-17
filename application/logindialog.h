#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class logindialog;
}

class logindialog : public QDialog
{
    Q_OBJECT

public:
    explicit logindialog(QWidget *parent = nullptr);
    ~logindialog();
       void toggleFullScreen();
       void modifyPassword(const QString &username, const QString &newPassword);
       QString getUsername() const;
signals:
    void loginSuccessful(const QString& login);
private slots:
    void on_pushButton_clicked();
    void updateProgress();

    void on_oubliMotDePasse_clicked();

private:
    Ui::logindialog *ui;
    QTimer *timer;
};

#endif // LOGINDIALOG_H

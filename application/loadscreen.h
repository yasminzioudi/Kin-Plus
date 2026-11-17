#ifndef LOADSCREEN_H
#define LOADSCREEN_H

#include <QMainWindow>
#include "ui_mainwindowLoad.h"
#include <QTimer>
#include <QGraphicsDropShadowEffect>

class LoadScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadScreen(QWidget *parent = nullptr);
    ~LoadScreen();

private:
    Ui::mainwindowLoad *uil;
};

#endif // LOADSCREEN_H

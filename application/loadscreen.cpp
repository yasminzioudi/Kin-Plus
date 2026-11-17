#include "loadscreen.h"

LoadScreen::LoadScreen(QWidget *parent) :
    QMainWindow(parent),
  uil(new Ui::mainwindowLoad)
{
    uil->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
    // Ajouter l'effet d'ombre portée à la fenêtre principale
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(20);
    shadow->setXOffset(0);
    shadow->setYOffset(0);
    shadow->setColor(QColor(0, 0, 0, 60));

    uil->dropShadow->setGraphicsEffect(shadow);
    setWindowFlags(Qt::FramelessWindowHint);

    // Créer un nouveau QTimer
    QTimer *timer = new QTimer(this);

    // Définir la valeur initiale de la barre de progression à 24%
    uil->progressBar_2->setValue(0);

    connect(timer, &QTimer::timeout, this, [this, timer]() {
        int value = uil->progressBar_2->value();

        // Si la valeur est inférieure à 100, l'incrémenter. Sinon, arrêter le timer.
        if(value < 100) {
            uil->progressBar_2->setValue(value + 1);
        } else {
            timer->stop();
             timer->deleteLater();
        }
    });

    // Initialiser le texte de la QLabel
    uil->label_2->setText("<strong>WELCOME</strong> TO APPLICATION");

    // Changer le texte après un certain délai
    QTimer::singleShot(2500, [this]() {
       uil->label_2->setText("<strong>LOADING</strong> DATABASE");
    });

    QTimer::singleShot(4000, [this]() {
       uil->label_2->setText("<strong>LOADING</strong> USER INTERFACE");
    });

    // Démarrer le timer
    timer->start(50); // Démarrer le timer avec une intervalle de 50 ms
}

LoadScreen::~LoadScreen()
{
    delete uil;
}

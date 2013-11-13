#include "screener.h"
#include <QDebug>
#include <QThread>
#include "mainwindow.h"

void Screener::run(){
    MainWindow* mmm = new MainWindow();
    connect(mmm, SIGNAL( finished() ), this, SLOT( sendCrds() ) , Qt::QueuedConnection);
    mmm->show();
}

void Screener::sendCrds(){
    sendCoords();
    emit finished();
    this->terminate();
}

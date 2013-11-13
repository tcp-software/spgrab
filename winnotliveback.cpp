#include "winnotliveback.h"
#include "ui_winnotliveback.h"
#include "window.h"
#include "config.h"
#include <QPainter>
#include <QImage>
#include <QDebug>

QPainter *bckPainter;

WinNotLiveBack::WinNotLiveBack(QWidget *parent) : QMainWindow(parent), ui(new Ui::WinNotLiveBack){
    QString format =  config::getImageFormat();
    QString initialPath = config::getWPath() + "/";
    nlPath = initialPath + "nlive/nlivescreenshot" + "." + format;
    ui->setupUi(this);
}
WinNotLiveBack::~WinNotLiveBack(){
    bckPainter->end();
    delete bckPainter;
    qDebug() << "~WinNotLiveBack";
    delete ui;
}
void WinNotLiveBack::keyPressEvent(QKeyEvent * event ){
    if( event->key() == Qt::Key_Escape ){
        hide();
    }else{
        //qDebug() << "KeyPresed: " << event->key();
    }
}
void WinNotLiveBack::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //bckPainter->drawImage( 0, 0, QImage( nlPath ) );
    bckPainter->drawPixmap(0,0,config::capturedBackQPix.value(0));
    bckPainter->setCompositionMode(QPainter::CompositionMode_Source);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.drawImage( 0, 0, *fullScreen );
}
void WinNotLiveBack::showBack(int width, int height){
    //qDebug() << "Entered into showBack";
    setWindowFlags( Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint );
    resize(width, height);
    //setAttribute( Qt::WA_TranslucentBackground, true );
    move( 0, 0 );

    //showFullScreen();

    fullScreen = new QImage(width, height, QImage::Format_ARGB32);
    bckPainter = new QPainter(fullScreen);
    qDebug() << "Width: " << width << ", Height: " << height;
    show();
}
void WinNotLiveBack::pRepaint(){
    this->repaint();
}

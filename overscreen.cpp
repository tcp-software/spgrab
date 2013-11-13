#include "overscreen.h"

#include <QMoveEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QThread>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>
#include <QDir>
#include <QBitmap>

#include "worker.h"


int startX;
int startY;
int endX;
int endY;
int clickCounter;

bool takeScreenShot;
bool scrDone;
bool firstRelease;

overScreen::overScreen(QWidget *parent) : QWidget(parent){

    this->setMouseTracking(true);

    paint = false;
    takeScreenShot = false;
    scrDone = false;
    firstRelease = true;

    sizeDesktop = QApplication::desktop()->size();

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
    setWindowState(Qt::WindowFullScreen);
    //setAttribute( Qt::WA_TranslucentBackground,true );

    #ifdef Q_WS_WIN
        this->setWindowOpacity(0.1);
        firstRelease = false;
    #endif

    setScreenFullWidhtHeight();

    move( 0, 0 );
    qDebug("Started QWidget");

    resize(fullScrWidth, fullScrHeight);
    setFocusPolicy( Qt::StrongFocus );
}
void overScreen::mousePressEvent(QMouseEvent * event ){
    if ( takeScreenShot == false ){
        this->paint = true;

        startX = event->x();
        startY = event->y();
    }
}
void overScreen::mouseReleaseEvent(QMouseEvent * event ){
    if(firstRelease){
        firstRelease = false;
    } else {
        //if ( takeScreenShot == false ){
            endX = event->x();
            endY = event->y();
            paint = false;
            takeScreenShot = true;
            this->repaint();

            this->hide();
        //}
    }
}
void overScreen::mouseMoveEvent ( QMouseEvent * event ){
    if(paint){
        endX = event->x();
        endY = event->y();

    }
    this->repaint();
}

void overScreen::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.eraseRect( 0, 0, this->width(), this->height() );
    painter.setPen(QColor("#000000"));

    if(takeScreenShot){
        paint = false;
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(getCoordonatesRegion()));
        timer->setSingleShot(true);
        timer->start(100);

         takeScreenShot = false;
    }
    if( paint ) {

        painter.setOpacity(1);
        painter.setBrush(QColor("#860000"));
        painter.drawRect( getMin(startX, endX ), getMin( startY, endY ), abs( startX - endX ), abs( startY - endY ) );
    }

}
void overScreen::getCoordonates(){
    //qDebug("received");
    newScreenShot( );
}

void overScreen::getCoordonatesRegion(){
    newScreenShot( getMin(startX, endX ), getMin( startY, endY ), abs( startX - endX ), abs( startY - endY ) );

}
void overScreen::getCoordonates(int x, int y, int wd, int hd){
    newScreenShot( x, y, wd, hd );
}
int overScreen::getMin(int min1, int min2){
    if( min1 > min2 ){
        return min2;
    } else {
        return min1;
    }
}
void overScreen::setScreenFullWidhtHeight(){

    int scrNum = QApplication::desktop()->screenCount();
    qDebug() << scrNum;
    for (int i=0; i < scrNum; i++){
        if( scrNum > 1 ){

            qDebug() << QApplication::desktop()->screenGeometry(i);

            if( QApplication::desktop()->screenGeometry(i).top() == 0 ) {
                fullScrWidth += QApplication::desktop()->screenGeometry(i).width();
                fullScrHeight = QApplication::desktop()->screenGeometry(i).height();
            } else {
                fullScrWidth = QApplication::desktop()->screenGeometry(i).width();
                fullScrHeight += QApplication::desktop()->screenGeometry(i).height();
            }
        } else {
            fullScrWidth += QApplication::desktop()->screenGeometry(0).width();
            fullScrHeight += QApplication::desktop()->screenGeometry(0).height();        }
    }
    qDebug() << fullScrWidth << fullScrHeight;
}
void overScreen::newScreenShot(){
    hide();
    overScreen::shootScreen();
}
void overScreen::newScreenShot(int x, int y, int wd, int hd){
    hide();
    overScreen::shootScreen( x, y, wd, hd );
}
void overScreen::saveScreenshot(){
    QString format = "png";
    QString initialPath = QDir::currentPath() + "/";
    QString fileName = initialPath + "newscreenshot" + "." + format;

    originalPixmap.save( fileName, format.toAscii() );
    qDebug() << "Should be finished";
    emit finished();
    close();
    //delete this;
    //this->destroy(true, true);
}
void overScreen::shootScreen(){
    originalPixmap = QPixmap(); // clear image for low memory situations on embedded devices.
    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId() );
    show();
    overScreen::saveScreenshot();
}
void overScreen::shootScreen(int x, int y, int wd, int hd){
    originalPixmap = QPixmap(); // clear image for low memory situations on embedded devices.
    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId(), x, y, wd, hd );
    show();
    overScreen::saveScreenshot();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "winnotliveback.h"


#include <QPushButton>
#include <QApplication>
#include <QMoveEvent>
#include <QDebug>
#include <QTimer>
#include <QDir>
#include <QFileDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QThread>
#include <QDateTime>
#include <QClipboard>
#include <QPixmap>
#include <QImage>
#include <QUrl>
#include <QDesktopServices>
#include <QCryptographicHash>
#include <QByteArray>
#include <QNetworkInterface>
#include <QDateTime>

#include "config.h"

int startX;
int startY;
int endX;
int endY;
int clickCounter;

bool takeScreenShot;
bool scrDone;
bool paintFullScreen;
bool firstRelease;
QTimer *timer;
QTimer *timerPainterOffset;
QPainter *tmpPainter;
QString textInfo;
QString sizeInfo;
QBrush brush( QColor(161, 35, 35, 255) );
QBrush brushTTBg( QColor(161, 35, 35, 190) );
QBrush brushTTBg2( QColor(255, 255, 255, 220) );
QPen pen ( brush, 1, Qt::SolidLine );

QUrl url;
QDesktopServices *dServ;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    winBck = 0;
    stopPainting = false;
    backWinInited = false;
    sizeInfoS = 120;
    sizeInfoM = 140;
    sizeInfoL = 155;
#ifdef Q_WS_WIN
    sizeInfoS = 100;
    sizeInfoM = 120;
    sizeInfoL = 135;
#endif

    timer = new QTimer(this);
    textInfo = QString("Click and drag mouse to draw a rectangle to screenshot\n or exit by pressing Escape key.");
    sizeInfo = QString("0px X 0px");
    connect(timer, SIGNAL(timeout()), this, SLOT(getCoordonatesRegion()));
    timer->setSingleShot(true);
    ui->setupUi(this);
    this->setMouseTracking(true);

    sizeDesktop = QApplication::desktop()->size();

    setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint );
    setAttribute( Qt::WA_TranslucentBackground, true );

    #ifdef Q_WS_X11
        setAutoFillBackground(false);
        setStyleSheet("background:rgba(0,0,0,1);");
    #endif

    #ifdef Q_WS_WIN
        firstRelease = false;
        setAutoFillBackground(false);
        setStyleSheet("background:rgba(0,0,0,1);");
    #endif
    paintFullScreen = true;
    setScreenFullWidhtHeight();

    move( 0, 0 );

    showFullScreen();
    resize(fullScrWidth, fullScrHeight);

    setFocusPolicy( Qt::StrongFocus );

    ui->centralWidget->setAttribute( Qt::WA_TranslucentBackground, true );
        timm = new QTime;
        timerPainterOffset = new QTimer(this);
        connect(timerPainterOffset, SIGNAL(timeout()), this, SLOT(repainter() ) );
        timerPainterOffset->setSingleShot(false);
        timerPainterOffset->start(200);

    this->hide();
}
void MainWindow::hideEvent(QHideEvent *eve){
    qDebug() << "MainWindow::hideEvent";
    qDebug() << "|_____ backWinInited == " << backWinInited;
    if( backWinInited == true ){
        backWinInited = false;
    }
}
void MainWindow::onShow(){
    fullScreen = new QImage(fullScrWidth, fullScrHeight, QImage::Format_ARGB32);
    tmpPainter = new QPainter(fullScreen);
    startX = 0;
    winBck = 0;
    backWinInited = false;
    startY = 0;
    endX = 0;
    endY = 0;
    paint = false;
    takeScreenShot = false;
    scrDone = false;
    firstRelease = false;
    #ifdef Q_WS_WIN
        firstRelease = false;
    #endif
    setCursor( Qt::CrossCursor );
}
void MainWindow::onShowNLive(){
    fullScreen = new QImage(fullScrWidth, fullScrHeight, QImage::Format_ARGB32);
    tmpPainter = new QPainter(fullScreen);
    startX = 0;
    startY = 0;
    endX = 0;
    endY = 0;
    paint = false;
    takeScreenShot = false;
    scrDone = false;
    firstRelease = false;

    setCursor( Qt::CrossCursor );
    show();

    winBck = new WinNotLiveBack();
    winBck->showBack(fullScrWidth, fullScrHeight);
    raise();
    backWinInited = true;
}
MainWindow::~MainWindow(){
    qDebug() << "Num of BackQPix-es: " << config::capturedBackQPix.values().count();
    delete fullScreen;
    tmpPainter->end();
    delete tmpPainter;
    if( winBck != 0 ){
        winBck->hide();
        winBck->deleteLater();
    }
    qDebug() << "~MainWindow()";

    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event ){
    if( event->key() == Qt::Key_Escape ){
        releaseKeyboard();
        qDebug() << "keyPressEvent: emit canceled()";
        //delete fullScreen;
        tmpPainter->end();
        //delete tmpPainter;

        releaseKeyboard();
        this->deleteLater();
        this->hide();
        emit finished();
    }else{
        qDebug() << "KeyPresed: " << event->key();
    }
}
void MainWindow::mousePressEvent(QMouseEvent * event ){
    if ( takeScreenShot == false ){
        this->paint = true;
        startX = event->x();
        startY = event->y();
        endX = startX;
        endY = startY;
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent * event ){
    releaseKeyboard();
    if(endX == 0 && endY == 0 ){
        hide();
        emit canceled();
    }else{
        if(firstRelease){
            firstRelease = false;
        } else {
            endX = event->x();
            endY = event->y();
            paint = false;
            takeScreenShot = true;
            this->repaint();
            stopPainting = true;
            //this->hide();
        }
    }
}
void MainWindow::mouseMoveEvent ( QMouseEvent * event ){
    if(paint){
        endX = event->x();
        endY = event->y();
    }
    this->repaint();
}
void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    //qDebug() << "fullScreenImage size == " << fullScreen->byteCount();
    if( stopPainting == true ){
        qDebug() << "stopPainting == true";
        painter.end();
        qDebug() << "painter.end();";
        //if( tmpPainter->isActive() ){
            tmpPainter->end();
            qDebug() << "tmpPainter->end();";
        //}
    } else {
        grabKeyboard();
        tmpPainter->setBrush(QColor(0,0,0, 50));
        tmpPainter->fillRect( 0, 0, this->width(), this->height(), QColor(0,0,0,50) );
        tmpPainter->setPen( pen );
        tmpPainter->setFont( QFont( "tahoma", 14 ) );

        sizeInfo = QString::number( abs( startX - endX ) ) + QString("px X ") + QString::number( abs( startY - endY ) ) + "px";

        tmpPainter->fillRect( firstScreenWidth / 3, firstScreenHeight / 4 - 25, firstScreenWidth / 3, 50, brushTTBg );
        tmpPainter->drawText( QRect( 1, 1, firstScreenWidth, firstScreenHeight / 2 ), Qt::AlignCenter, textInfo );

        if( paint ) {
            tmpPainter->setFont( QFont( "tahoma", 10, 120 ) );
            if( sizeInfo.length() <= 11 ){
                tmpPainter->drawRect( getMax( startX, endX ) - 1, getMax( startY, endY ) - 1, sizeInfoS, 20 );
                tmpPainter->fillRect( getMax( startX, endX ), getMax( startY, endY ), sizeInfoS - 1, 19, brushTTBg2 );
            }else if( sizeInfo.length() == 12 || sizeInfo.length() == 13  ){
                tmpPainter->drawRect( getMax( startX, endX ) - 1, getMax( startY, endY ) - 1, sizeInfoM, 20 );
                tmpPainter->fillRect( getMax( startX, endX ), getMax( startY, endY ), sizeInfoM - 1, 19, brushTTBg2 );
            }else{
                tmpPainter->drawRect( getMax( startX, endX ) - 1, getMax( startY, endY ) - 1, sizeInfoL, 20 );
                tmpPainter->fillRect( getMax( startX, endX ), getMax( startY, endY ), sizeInfoL -1 , 19, brushTTBg2 );
            }
            tmpPainter->drawText( QRect( getMax( startX, endX ) + 10, getMax( startY, endY ) + 3, 600, 20 ), Qt::AlignLeft, sizeInfo );
        }
        pen = QPen( QBrush( QColor(255,255,255) ), 1, Qt::SolidLine );
        tmpPainter->setFont( QFont( "tahoma", 14 ) );
        tmpPainter->setPen( pen );
        tmpPainter->drawText( QRect( 0, 0, firstScreenWidth, firstScreenHeight / 2 ), Qt::AlignCenter, textInfo );
        brush = QBrush( QColor( 92, 149, 209 ) );
        pen = QPen(brush, 1, Qt::DashLine );
        pen.setDashOffset( paintOffset );
        tmpPainter->setPen( pen );

        if( nLive == true ){
            // THIS IS CRTL+SHIFT+L
            if(takeScreenShot){
                paint = false;
                getCoordonatesRegion();
                takeScreenShot = false;
            }
        }else{
            // THIS IS CRTL+SHIFT+R
            if(takeScreenShot){
                tmpPainter->setBrush(QColor(0,0,0,0));
                tmpPainter->drawRect( 0, 0, this->width(), this->height() );
                paint = false;

                timer->start(200);
                takeScreenShot = false;
            }
        }
        if( paint ) {
            tmpPainter->setBrush(QColor(0,0,0,0));
            tmpPainter->drawRect( getMin(startX, endX )+1, getMin( startY, endY ), abs( startX - endX )+1, abs( startY - endY ) );
        }
        tmpPainter->setCompositionMode(QPainter::CompositionMode_Source);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.drawImage( 0, 0, *fullScreen );
    }
}
void MainWindow::getCoordonates(){
    newScreenShot( );
}

void MainWindow::repainter(){
    paintOffset = timm->currentTime().msec();
    this->repaint();
}
void MainWindow::attachGrabKeys(){
    this->grabKeyboard();
}

void MainWindow::getCoordonatesRegion(){
    stopPainting = true;
    nLivePost = nLive;
    nLive = false;
    newScreenShot( getMin(startX, endX ), getMin( startY, endY ), abs( startX - endX ), abs( startY - endY ) );
}
void MainWindow::getCoordonates(int x, int y, int wd, int hd){
    newScreenShot( x, y, wd, hd );
}
int MainWindow::getMin(int min1, int min2){
    if( min1 > min2 ){
        return min2;
    } else {
        return min1;
    }
}
int MainWindow::getMax(int min1, int min2){
    if( min1 > min2 ){
        return min1;
    } else {
        return min2;
    }
}
void MainWindow::setScreenFullWidhtHeight(){
    fullScrWidth = config::getFSWidth();
    fullScrHeight = config::getFSHeight();

    firstScreenWidth =  config::getFFSWidth();
    firstScreenHeight = config::getFFSHeight();
}
void MainWindow::newScreenShot(){
    hide();
    MainWindow::shootScreen( 0, 0, fullScrWidth, fullScrHeight );
}

void MainWindow::newScreenShot(bool NLive){
    //hide();
    grabKeyboard();
    nLive = NLive;
    MainWindow::shootScreen( 0, 0, fullScrWidth, fullScrHeight );
}

void MainWindow::newScreenShot(int x, int y, int wd, int hd){
    hide();
    MainWindow::shootScreen( x, y, wd, hd );
}
void MainWindow::saveScreenshot(){
    QString format =  config::getImageFormat();
    QString initialPath = config::getWPath() + "/";

    QDateTime tt2 = QDateTime::currentDateTime();
    QString currTime1;
    QString newName = config::getMacAddress() + QString::number( tt2.toMSecsSinceEpoch() );
    currTime1 = QCryptographicHash::hash( QByteArray::fromRawData( newName.toAscii(), newName.length()), QCryptographicHash::Md5 ).toHex();

    QString fileName = initialPath + currTime1 + "." + format;

    if( nLive == true ){

        onShowNLive();
    } else {
        if( config::StoreToFolderEnabled() ){
            QDateTime tt = QDateTime::currentDateTime();
            QString currTime = tt.toString( "MM-dd-yyyy-hh-mm-ss-zzz" );
            originalPixmap.save( config::getStoringFolder() + "/" + currTime + "." + format , format.toAscii() );

            if( config::getOpenInBrowser() ){
                QString tmpPath = config::getStoringFolder();
                url = QUrl( "file://" + tmpPath + "/" + currTime + "." + format );

                #ifdef Q_WS_WIN
                    tmpPath = config::getStoringFolder().replace(":\\", "://" ).replace('\\', '/');
                    url = QUrl( "file:///" + tmpPath + "/" + currTime + "." + format );
                #endif

                    if( dServ->openUrl(url) ){
                        //qDebug("Picture Downloaded");
                    }
            }
        }
        if( config::getCopyImgToClip() ){
            QClipboard *cb = QApplication::clipboard();
            cb->setPixmap( originalPixmap,
                         QClipboard::Clipboard );
        }

        config::addFile( fileName );
        config::appendQPix( originalPixmap );

        stopPainting = true;
        if( backWinInited == true ){
            backWinInited = false;
            delete winBck;
        }
        qDebug() << "SAVE SS: delete tmpPainter;";
        //delete fullScreen;
        tmpPainter->end();
        //delete tmpPainter;

        releaseKeyboard();
        config::capturedBackQPix.clear();
        emit finished();
        this->deleteLater();
        this->hide();
    }
}
void MainWindow::shootScreen(){
    originalPixmap = QPixmap(); // clear image for low memory situations on embedded devices.
    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId() );
    MainWindow::saveScreenshot();
}
void MainWindow::shootScreen(int x, int y, int wd, int hd){
    if( nLivePost == false ){
        originalPixmap = QPixmap();
        originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId(), x, y, wd, hd );
    } else {
        originalPixmap = QPixmap();
        originalPixmap = config::capturedBackQPix.value( 0 );//config::capturedBackQPix; //QPixmap::fromImage( QImage( nlPath ) );
        originalPixmap = QPixmap(originalPixmap.copy( x, y, wd, hd ) );
    }
    nLivePost = false;
    if( wd > 0 && hd > 0 ){
        MainWindow::saveScreenshot();
    }else{
        qDebug() << "shootScreen: emit canceled()";
        //delete fullScreen;
        tmpPainter->end();
        //delete tmpPainter;

        releaseKeyboard();
        this->deleteLater();
        this->hide();
        emit canceled();
    }
}

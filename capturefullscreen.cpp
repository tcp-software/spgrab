#include "capturefullscreen.h"
#include "config.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QPixmap>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QClipboard>

bool nLive;
captureFullScreen::captureFullScreen(QWidget *parent) : QWidget(parent){
    nLive = false;
}
void captureFullScreen::shootScreen(bool nl){
    nLive = nl;
    QPixmap originalPixmap = QPixmap();

    originalPixmap = QPixmap::grabWindow( QApplication::desktop()->winId(), 0, 0, config::getFSWidth(), config::getFSHeight() );
    saveScreenshot(originalPixmap);
}
void captureFullScreen::saveScreenshot(QPixmap ss){
    if( nLive == false ){
        QString format =  config::getImageFormat();
        QString initialPath = config::getWPath() + "/";

        QDateTime tt2 = QDateTime::currentDateTime();
        QString newName = config::getMacAddress() + QString::number( tt2.toMSecsSinceEpoch() );
        QString currTime1 = config::getCryptedName( newName );

        QString fileName = initialPath + currTime1 + "." + format;

        if( config::StoreToFolderEnabled() ){
            QDateTime tt = QDateTime::currentDateTime();
            QString currTime = tt.toString( "MM-dd-yyyy-hh-mm-ss-zzz" );
            ss.save( config::getStoringFolder() + "/" + currTime + "." + format , format.toAscii() );
        }
        if( config::getCopyImgToClip() ){
            QClipboard *cb = QApplication::clipboard();
            cb->setPixmap( ss, QClipboard::Clipboard );
        }
        config::addFile( fileName );
        config::appendQPix( ss );
    } else {
        config::capturedBackQPix.clear();
        config::capturedBackQPix.insert( 0, ss );
        qDebug() << "Appended to the BACKqPIX";
    }
    emit screenshotTakken();
}

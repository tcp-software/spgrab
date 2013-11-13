#include "config.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QNetworkInterface>
#include <QStringList>
#include <QDateTime>

int config::fullScrWidth;
int config::fullScrHeight;
int config::firstScreenWidth;
int config::firstScreenHeight;
bool config::shortcutEnabled;
bool config::winAboutVisible;
bool config::winHistoryVisible;
bool config::winSettingsVisible;
QHash<int, QPixmap> config::capturedQPixes;
QHash<int, QPixmap> config::capturedBackQPix;

QStringList config::filesForUpload;
bool config::_doLog;

config::config(QObject *parent) : QObject(parent){
    winHistoryVisible = false;
    winSettingsVisible = false;
    winAboutVisible = false;

    setScreenFullWidhtHeight();
}

void config::setScreenFullWidhtHeight(){
    int scrNum = QApplication::desktop()->screenCount();
    int fsw, fsh, ffsw, ffsh;
    QRect scrGeo;
    QList<QRect> rects;
    for (int i=0; i < scrNum; i++){
        scrGeo = QApplication::desktop()->screenGeometry(i);
        if( scrGeo.left() == 0 ){
            rects.prepend(scrGeo);
        } else {
            rects << scrGeo;
        }
    }

    foreach( QRect qrc, rects){
        if( qrc.top() == 0 ){
            fsw = fsw + qrc.width();
            fsh = qrc.height();
        }else{
            fsw = qrc.width();
            fsh = fsh + qrc.height();
        }
        ffsw = qrc.width();
        ffsh = qrc.height();
    }
    fsw = QApplication::desktop()->size().width();
    fsh = QApplication::desktop()->size().height();
    setFSWidth(fsw);
    setFSHeight(fsh);
    setFFSWidth(ffsw);
    setFFSHeight(ffsh);
}
QString config::getMacAddress(){
    foreach( QNetworkInterface interface, QNetworkInterface::allInterfaces() ) {
        // Return only the first non-loopback MAC Address
        if (!(interface.flags() & QNetworkInterface::IsLoopBack))
            return interface.hardwareAddress();
    }
    return QString();
}
QString config::getCryptedWithPath(){
    QDateTime tt2 = QDateTime::currentDateTime();
    QString newName = getMacAddress() + QString::number( tt2.toMSecsSinceEpoch() );
    newName = getCryptedName( newName );
    newName = getWPath() + "/" + newName + "." + imageFormat;
    return newName;
}

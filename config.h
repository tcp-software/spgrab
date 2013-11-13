#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QCryptographicHash>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QIODevice>
#include <QTextStream>
#include <QPixmap>
#include <QHash>
#include <QByteArray>
#include <QBuffer>

class config : public QObject
{
    Q_OBJECT
public:
    explicit config(QObject *parent = 0);
    static void setScreenFullWidhtHeight();
    static int getFSWidth(void){ return fullScrWidth; }
    static int getFSHeight(void){ return fullScrHeight; }
    static int getFFSWidth(void){ return firstScreenWidth; }
    static int getFFSHeight(void){ return firstScreenHeight; }

    static void _LogIt(QString what){
        if( _doLog == true ){
            qDebug() << what;
            QFile fLog( config::getWPath() + "/logger.txt" );
            fLog.open(QIODevice::Append | QIODevice::Text );
            QTextStream out(&fLog);
            out << QString( what + "\n");
            fLog.close();
        }
    }
    static void setDebug(bool isTrue){ _doLog = isTrue; }
    static bool getDebug(void){ return _doLog; }
    static bool _doLog;

    static void setFSWidth(int newVal){fullScrWidth = newVal;}
    static void setFSHeight(int newVal){fullScrHeight = newVal;}
    static void setFFSWidth(int newVal){firstScreenWidth = newVal;}
    static void setFFSHeight(int newVal){firstScreenHeight = newVal;}

    static QString getImageFormat(void){ return imageFormat; }
    static void setImageFormat(QString newVal){ imageFormat = newVal; }

    static QStringList filesForUpload;
    static QString getFirstFile(){
        //qDebug() << "filesForUpload" << filesForUpload;
        if( filesForUpload.length() > 0 ){
            return filesForUpload.at(0);
        }else{
            return "no_files";
        }
    }
    static void addFile(QString filename){ filesForUpload << filename; }
    static void rmFile(QString filename){
        for(int i = 0; i < filesForUpload.length(); i++){
            if( filesForUpload.at(i) == filename ){
                filesForUpload.removeAt(i);
                //filesForUpload.sort();
                break;
            }
        }
    }

    static QString getWPath(void){ return wPath; }
    static void setWPath(QString newVal){ wPath = newVal; }

    static QString getMacAddress();
    static QString getCryptedWithPath();
    static QString getCryptedName(QString value){ return QCryptographicHash::hash( QByteArray::fromRawData( value.toAscii(), value.length()), QCryptographicHash::Md5 ).toHex(); }

    static QString getStoringFolder(void){ return storingFolder; }
    static void setStoringFolder(QString newVal){ storingFolder = newVal; }

    static bool StoreToFolderEnabled(void){ return storeToFolder; }
    static void setStoreFolderEnable(bool newVal){ storeToFolder = newVal; }

    static bool getCopyImgToClip(void){ return copyImgToClip; }
    static void setCopyImgToClip(bool newVal){ copyImgToClip = newVal; }

    static bool getOpenInBrowser(void){ return openInBrowser; }
    static void setOpenInBrowser(bool newVal){ openInBrowser = newVal; }

    static bool isShortcutEnabled(void){ return shortcutEnabled; }
    static void setShortcutEnabled(bool newVal){ shortcutEnabled = newVal; }

    static void appendQPix(QPixmap newQPix){
        capturedQPixes.insert( capturedQPixes.values().count(), newQPix);
        qDebug() << "config: appendQPix: Number of captured images: " << capturedQPixes.values().count();
    }
    static void removeQPix(){
        //qDebug() << "config: capturedQPixes.keys(): " << capturedQPixes.keys();
        capturedQPixes.remove(capturedQPixes.keys().at(0));
        qDebug() << "config: removeQPix: Number of captured images: " << capturedQPixes.values().count();
    }
    static QByteArray getBytesForUpload(QPixmap test){
        QByteArray bytes;
        QBuffer tmpBuffer(&bytes);
        tmpBuffer.open(QIODevice::WriteOnly);
        test.save( &tmpBuffer, config::getImageFormat().toAscii() );
        return bytes;
    }

    static int fullScrWidth;
    static int fullScrHeight;
    static int firstScreenWidth;
    static int firstScreenHeight;
    static QString imageFormat;
    static QString wPath;

    static QString storingFolder;
    static bool storeToFolder;
    static bool copyImgToClip;
    static bool openInBrowser;
    static bool shortcutEnabled;
    static bool logEnabled;

    static bool winHistoryVisible;
    static bool winSettingsVisible;
    static bool winAboutVisible;

    static QHash<int, QPixmap> capturedQPixes;
    static QHash<int, QPixmap> capturedBackQPix;
public slots:
    
};

#endif // CONFIG_H

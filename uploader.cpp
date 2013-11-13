#include "uploader.h"
#include "config.h"
#include <QtCore>
#include <QDebug>
#include <QUrl>
#include <QByteArray>
#include <QPixmap>

Uploader::Uploader(QObject *parent) : QThread(parent)
{
    this->uploadFinished = true;
    this->doUpload = true;
    this->newUploadNeeded = false;
    this->ftpReady = false;
    this->ftpConnecting = false;
    this->currentFileName = "";
}
void Uploader::run(){
    timPostpone = new QTimer(this);
    timPostpone->setSingleShot(false);
    connect( timPostpone, SIGNAL( timeout() ), this, SLOT( goUpload() ) );
    timPostpone->start(500);
}
void Uploader::goUpload(){
    if( this->doUpload ){
        if( this->ftpReady == false && this->ftpConnecting == false ){
            qDebug() <<  "FTPUploader:  ++++++ this->ftpReady = " << this->ftpReady << " ___ this->ftpConnecting = " << this->ftpConnecting;
            timPostpone->stop();
            this->connectOrDisconnect();
        }
        if( this->ftpReady == true && this->uploadFinished == true ){
            this->uploadNext();
        }else if( this->ftpReady == true && this->uploadFinished == false && this->ftp->hasPendingCommands() == false ){
            if( this->ftp->currentCommand() == 0 ){
                //qDebug() << "ftp's currentCommand is 0, aka Nothing to do, but :-)";
                this->uploadFinished = true;
            }
        }
    }else{
        qDebug() <<  "FTPUploader:  ++++++ this->doUpload == FALSE";
        timPostpone->stop();
    }
}

void Uploader::uploadNext(){
    this->uploadFinished = false;
    this->newUploadNeeded = false;
    this->currentFileName = config::getFirstFile();
    if( this->currentFileName != "no_files" ){
        if( !this->currentFileName.contains('\\') && !this->currentFileName.contains('/') ){
            this->currentFileName = config::getWPath() + "/" + this->currentFileName;
        }
        this->tt = QDateTime::currentDateTime();
        QString newName = config::getMacAddress() + QString::number( this->tt.toMSecsSinceEpoch() );
        QString currTime = config::getCryptedName( newName );
        this->clipboardName = this->ftpClipboardURL + currTime + "." + config::getImageFormat();
        if( config::capturedQPixes.size() > 0 ){
            QPixmap currentQPix = config::capturedQPixes.value( config::capturedQPixes.keys().at(0) );
            QByteArray bytesForSending = config::getBytesForUpload( currentQPix );
            if( bytesForSending.length() == 0 ){
                qDebug() << "UploadFile: config::getBytesForUpload( config::capturedQPixes.keys().at(0) ).length == 0 ";
                config::rmFile( this->currentFileName );
                config::removeQPix();
                this->uploadFinished = true;
            } else {
                this->ftp->put( bytesForSending, currTime + "." + config::getImageFormat() );
            }
        }else if( ftp->state() == ftp->Unconnected ){
            timPostpone->stop();
            this->uploadFinished = true;
            qDebug() << "ftp is NOT connected to the host => calling connectOrDisconect()";
            connectOrDisconnect();
        }
    }else{
        //qDebug() << "FTPUploader:  ++++++ uploadNext: No Files for upload";
        this->uploadFinished = true;
    }

}
void Uploader::ftpCommandFinished(int currCommand, bool error){
    if ( this->ftp->currentCommand() == QFtp::ConnectToHost) {
        if ( error ) {
            this->ftpReady = false;
            this->ftpConnecting = false;
            qDebug() << "Command: ConnectToHost: " << this->ftp->error();
            qDebug() << this->ftp->errorString();
            return;
        }
        return;
    }else if ( this->ftp->currentCommand() == QFtp::Put) {
        if (error) {
            this->ftpReady = false;
            this->ftpConnecting = false;
            qDebug() << "ERR: Command: PUT: " << this->ftp->error();
            qDebug() << this->ftp->errorString();
            timPostpone->stop();
            connectOrDisconnect();
            return;
        }
        config::rmFile( this->currentFileName );
        config::removeQPix();

        if ( this->copyURLToClip == true ){
            emit updateClipBoard( this->clipboardName );
        }
        if( config::getFirstFile() == "no_files" || config::capturedQPixes.values().count() == 0 ){
            config::filesForUpload.clear();
            emit showMessage();
        }
        this->uploadFinished = true;
        return;
    } else if( this->ftp->currentCommand() == QFtp::Login ){
        if ( error ){
            this->ftpReady = false;
            this->ftpConnecting = false;
            qDebug() << this->ftp->error();
            qDebug() << this->ftp->errorString();
            return;
        }
        return;
    }else{
        if( error ){
            this->ftpReady = false;
            this->ftpConnecting = false;
            qDebug() << "Error for FTP Command: " << this->ftp->currentCommand();
            qDebug() << this->ftp->error();
            qDebug() << this->ftp->errorString();
            return;
        }
        this->ftpReady = true;
        return;
    }
}
void Uploader::connectOrDisconnect(){
    if( !this->ftpReady ){
        this->ftpConnecting = true;
        this->ftp = new QFtp();
        disconnect( this->ftp );
        connect( this->ftp, SIGNAL(stateChanged(int)), this, SLOT(ftpStateChanged(int)));
        connect( this->ftp, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
        connect( this->ftp, SIGNAL(dataTransferProgress(qint64,qint64)), this, SLOT(updateDataTransferProgress(qint64,qint64)));
        QUrl url( this->ftpHost);
        url.setUserName( this->ftpUser);
        url.setPassword( this->ftpPass);
        this->ftp->connectToHost( url.host(), url.port(21) );
        if (!url.userName().isEmpty()){
            this->ftp->login( QUrl::fromPercentEncoding( url.userName().toLatin1() ), url.password() );
        }else{
            this->ftp->login();
        }
    }
}
void Uploader::ftpStateChanged(int status){
    if( status == 0 ){
        qDebug() << "FTP object is NOT connected to the host." << status;
        if( this->newUploadNeeded == true ){
            this->newUploadNeeded = false;
            this->ftp = 0;
            this->ftpReady = false;
        }else{
            qDebug() << "No New Upload Needed";
        }
    }else if( status == 4 ){
        this->ftpConnecting = false;
        this->ftpReady = true;
        timPostpone->start(500);
    }else{
        qDebug() << "FTP object has NEW Status: " << status;
    }
}
void Uploader::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes){
    if( totalBytes > 0 ){
        emit updateTrayIconProgress( ( int ) readBytes * 100 / totalBytes );
    }else{
        qDebug() << "updateDataTransferProgress: ***********  totalBytes < 0 -------------- ";
        emit updateTrayIconProgress( 100 );
    }
}


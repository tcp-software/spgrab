#ifndef UPLOADER_H
#define UPLOADER_H

#include <QThread>
#include <QNetworkSession>
#include <QFtp>
#include <QDateTime>
#include <QTimer>

class Uploader : public QThread
{
    Q_OBJECT
public:
    explicit Uploader(QObject *parent = 0);

    QString currentPath;
    QString clipboardName;
    bool copyURLToClip;
    bool ftpReady;
    bool ftpConnecting;
    bool doUpload;
    bool newUploadNeeded;
    QString ftpHost;
    QString ftpUser;
    QString ftpPass;
    QString ftpClipboardURL;
    void run();

private:
    QNetworkSession *networkSession;
    QFtp *ftp;
    bool uploadFinished;
    QDateTime tt;
    QString currentFileName;
    void uploadNext();
    void connectOrDisconnect();
    QTimer *timPostpone;

signals:
    void updateTrayIconProgress( int val );
    void updateClipBoard( QString newUrlPath );
    void showMessage();
    
public slots:

private slots:
    void goUpload();
    void ftpStateChanged(int status);
    void ftpCommandFinished(int commandId, bool error);
    void updateDataTransferProgress(qint64 readBytes, qint64 totalBytes);
    
};

#endif // UPLOADER_H

#include <QtGui>
#include <QApplication>

#include <QtCore/QChar>
#include <QtCore/QBuffer>
#include <QtNetwork>
#include <QClipboard>
#include <QSettings>
#include <QShortcut>
#include <QShortcutEvent>
#include <QString>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QTimer>

#include "window.h"
#include "mainwindow.h"
#include "winhistory.h"
#include "winnotliveback.h"
#include "config.h"
#include "capturefullscreen.h"
#include "uploader.h"

#ifdef Q_WS_WIN
    #include "windows.h"
#endif

#ifdef Q_WS_X11
    #include "netwm/netwm.h"
    using namespace netwm;

    #include <X11/Xlib.h>
    #include <QX11Info>
#endif

QString config::wPath;
QString SPGrab::defName;
QString config::imageFormat;
bool config::openInBrowser;
bool config::storeToFolder;
QString config::storingFolder;
bool config::copyImgToClip;
bool withDesc;

bool shortcutFullScreenEnabled;
bool shortcutAreaEnabled;
bool shortcutDescEnabled;
bool shortcutNLiveEnabled;
bool shortcutGrabWindowEnabled;
//WinNotLiveBack *winBck;

int tCounter;
int tCounterAttempt;
QTimer *timPostpone;
QString fileNN;
QString currentFileNN;
QDateTime tt;
QString newName;
QString currTime;
QString moreFiles;
bool uploadInProgress;
Uploader *ftpUplader;

SPGrab::SPGrab(QWidget *parent) : QMainWindow(parent){
    workingDir = QDir( config::getWPath() );
    workingDir.setSorting( QDir::Time );
    historyTitle = "No Title";
    historyDesc = "No Description";
    isMoreFirstTime = true;
    ftpCounter = 0;
    ftp = 0;
    cOrD = 0;
    m_hotkeyFullScreen = 0;
    m_hotkeyArea = 0;
    m_hotkeyAreaDesc = 0;
    m_hotkeyAreaNLive = 0;
    m_hotkeyGrabWindow = 0;
    uploadInProgress = false;

    tCounter = 0;
    tCounterAttempt = 0;

    if( !QSystemTrayIcon::isSystemTrayAvailable() ){
        timPostpone = new QTimer(this);
        timPostpone->setSingleShot(false);
        connect( timPostpone, SIGNAL( timeout() ), this, SLOT( systrayCheck() ) );
    }
    uploadFinished = true;

    config::setWPath("temp");

    config::setStoreFolderEnable( false );
    config::setStoringFolder( "home" );
    config::setImageFormat( "jpg" );

    SPGrab::defName = "newscreenshot_1.jpg";
    config::setCopyImgToClip( false );
    config::setOpenInBrowser( true );
    config::setScreenFullWidhtHeight();

    mHistoryWindow = new winHistory();

    //mMyNewWindow = new MainWindow();
    //connect( mMyNewWindow, SIGNAL( finished() ), this, SLOT( screenShotTakken() ) );

    ftpUplader = new Uploader();
    connect(ftpUplader, SIGNAL(updateTrayIconProgress(int)), this, SLOT(updateTrayIconProgress(int)));
    connect(ftpUplader, SIGNAL(updateClipBoard(QString)), this, SLOT(updateClipBoard(QString)));
    connect(ftpUplader, SIGNAL(showMessage()), this, SLOT(showMessage()));

    checkIniSettingsVersion();
    getSettingsInfo();

    //deleteTempFiles();
    if( !QSystemTrayIcon::isSystemTrayAvailable() ){
        timPostpone->start(2000);
    }else{
        generateUI();
    }
}
void SPGrab::updateClipBoard(QString newUrlPath){
    clipboardName = newUrlPath;
    QClipboard *cb = QApplication::clipboard();
    cb->setText( newUrlPath, QClipboard::Clipboard );
    saveToHistory();
    setIcon(0);
}

#ifdef Q_WS_X11
    void SPGrab::grabActiveWindowX11(){
        netwm::init();
        QPixmap pixelMap;

            Window *wnd = reinterpret_cast<ulong *>(netwm::property(QX11Info::appRootWindow(), NET_ACTIVE_WINDOW, XA_WINDOW));

            if(!wnd){
                pixelMap = QPixmap::grabWindow(QApplication::desktop()->winId());
                exit(1);
            }

            // no dectortions option is select
            /*
            if (conf->getNoDecorX11() == true){
                pixelMap = QPixmap::grabWindow(*wnd);
                return;
            }
            */
            unsigned int d;
            int status;
            int stat;

        //    if (status != 0) {
              Window rt, *children, parent;

            // Find window manager frame
            while (true){
                status = XQueryTree(QX11Info::display(), *wnd, &rt, &parent, &children, &d);
                if (status && (children != None)){
                    XFree((char *) children);
                }

                if (!status || (parent == None) || (parent == rt)){
                    break;
                }

                *wnd = parent;
            }

            XWindowAttributes attr; // window attributes
            stat = XGetWindowAttributes(QX11Info::display(), *wnd, &attr);

            if ((stat == False) || (attr.map_state != IsViewable)){
                qDebug() << "Not window attributes.";
            }

            // get wnd size
            int rx = 0, ry = 0, rw = 0, rh = 0;
            rw = attr.width;
            rh = attr.height;
            rx = attr.x;
            ry = attr.y;

            pixelMap = QPixmap::grabWindow(QApplication::desktop()->winId(), rx, ry, rw, rh);

            XFree(wnd);
            QString filename = config::getCryptedWithPath();
            //pixelMap.save( filename, config::imageFormat.toAscii() );

            config::addFile( filename );
            config::appendQPix(pixelMap);

            if( config::StoreToFolderEnabled() ){
                QDateTime tt = QDateTime::currentDateTime();
                QString currTime = tt.toString( "MM-dd-yyyy-hh-mm-ss-zzz" );
                pixelMap.save( config::getStoringFolder() + "/" + currTime + "." + config::imageFormat , config::imageFormat.toAscii() );
            }
            screenShotTakken();
    }
#endif

#ifdef Q_WS_WIN
    void SPGrab::grabActiveWindow(){

        HWND findWindow = GetForegroundWindow();
        if ( findWindow == NULL ){
            return;
        }
        if ( findWindow == GetDesktopWindow() ){
            return;
        }
        ShowWindow( findWindow, SW_SHOW );
        SetForegroundWindow( findWindow );
        HDC hdcScreen = GetDC( NULL );
        RECT rcWindow;
        GetWindowRect( findWindow, &rcWindow );
        if ( IsZoomed( findWindow ) ){
            if ( QSysInfo::WindowsVersion >= QSysInfo::WV_VISTA ){
              rcWindow.right -= 8;
              rcWindow.left += 8;
              rcWindow.top += 8;
              rcWindow.bottom -= 8;
            }else{
              rcWindow.right += 4;
              rcWindow.left -= 4;
              rcWindow.top += 4;
              rcWindow.bottom -= 4;
            }
        }

        HDC hdcMem = CreateCompatibleDC( hdcScreen );
        HBITMAP hbmCapture = CreateCompatibleBitmap( hdcScreen, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top );
        SelectObject( hdcMem, hbmCapture );

        BitBlt( hdcMem, 0, 0, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top, hdcScreen, rcWindow.left, rcWindow.top, SRCCOPY );

        ReleaseDC( findWindow, hdcMem );
        DeleteDC( hdcMem );

        QPixmap pixelMap = QPixmap::fromWinHBITMAP( hbmCapture );
        DeleteObject( hbmCapture );

        QString filename = config::getCryptedWithPath();

        //pixelMap.save( filename, config::imageFormat.toAscii() );

        config::addFile( filename );
        config::appendQPix(pixelMap);

        if( config::StoreToFolderEnabled() ){
            QDateTime tt = QDateTime::currentDateTime();
            QString currTime = tt.toString( "MM-dd-yyyy-hh-mm-ss-zzz" );
            pixelMap.save( config::getStoringFolder() + "/" + currTime + "." + config::imageFormat , config::imageFormat.toAscii() );
        }
        screenShotTakken();

    }
#endif

void SPGrab::deleteTempFiles(){
    QDir directory(config::getWPath());
    QStringList filesList = directory.entryList( QStringList() << "*." + config::getImageFormat(), QDir::Files);
    QString fileName;
    foreach(fileName, filesList){
        if(!directory.remove(fileName))
            qDebug() << "Not removed file: " << fileName;
    }
    qDebug() << "Temp.files.deleted";
}

void SPGrab::checkIniSettingsVersion(){
    bool tmpTester = false;
    QDir *dDir = new QDir( QDir::homePath () );
    if( !dDir->exists(dDir->absolutePath() + "/.SPGrabInit") ){
        qDebug() << "Made temp folder";
        dDir->mkdir(".SPGrabInit");
    }
    QString workingPath = QDir::homePath() + "/.SPGrabInit";
    config::setWPath(workingPath);
    if( QFile::exists(workingPath + "/settings.ini") ){
        QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);
        settings.beginGroup("General");
            tmpTester = ( settings.value("firstTestera22").toString() == "true" ) ? true : false;
        settings.endGroup();

        if ( tmpTester == false ){
            QFile *iniFile = new QFile( config::getWPath() + "/settings.ini" );

            if(iniFile->open(QIODevice::ReadWrite)){
                iniFile->close();
            }
            iniFile->remove();
            delete iniFile;
        }
    }else{
        qDebug() << "settings.ini does not exists.";
    }

}
void SPGrab::setFTPInfo(QString host, QString user, QString pass, QString url){
    ftpHost = host;
    ftpUser = user;
    ftpPass = pass;
    ftpClipboardURL = url;
}
void SPGrab::ftpStateChanged(int status){
    qDebug() << "ftpStateChanged() to: " << status;
    if( status == 0 ){
        qDebug() << "FTP object is NOT connected to the host." << status;
        ftp = 0;
        uploadFinished = true;
        uploadFinished2 = true;
    }
}

void SPGrab::connectOrDisconnect(){
    if( ftp == 0 || ftp->state() == ftp->Unconnected ){
        cOrD++;
        qDebug() << "connectOrDisconnect: Entered into connectOrDisconnect: " << cOrD;
        ftp = new QFtp();

        disconnect(ftp);
        connect(ftp, SIGNAL(stateChanged(int)), this, SLOT(ftpStateChanged(int)));

        connect(ftp, SIGNAL(commandFinished(int,bool)),
                this, SLOT(ftpCommandFinished(int,bool)));
        connect(ftp, SIGNAL(commandStarted(int)),
                this, SLOT(ftpCommandStarted(int)));
        connect(ftp, SIGNAL(dataTransferProgress(qint64,qint64)),
                this, SLOT(updateDataTransferProgress(qint64,qint64)));
        QUrl url(ftpHost);

        url.setUserName(ftpUser);
        url.setPassword(ftpPass);
        ftp->connectToHost(url.host(), url.port(21));

        if (!url.userName().isEmpty()){
            ftp->login(QUrl::fromPercentEncoding(url.userName().toLatin1()), url.password());
        }else{
            ftp->login();
        }
        //ftp->cd(url.path());
        /*
        if( file->isOpen() ){
            file->close();
            delete file;
        }
        deleteTempFiles();
        */
    }else{
        uploadFile();
        //screenShotTakken();
    }
}

void SPGrab::uploadFile( QString fileN ){
    /*
    if( ftp == 0 ){
        qDebug() << "uploadFile: FTP is 0 at uploadFile";
        qDebug() << "uploadFile: connectOrDisconnect";
        connectOrDisconnect();
    }else{
        if( ftp->state() == 0 ){
            connectOrDisconnect();
        }else{
            if( !ftp->hasPendingCommands() ){
                qDebug() << "FTP is NOT 0 and HAS NO PendingCommands";
                if( uploadFinished ){
                    qDebug() << "UploadFile: uploadFinished == true";
                    uploadFinished = false;
                    if ( fileN.trimmed().length() == 0 || fileN == defName ){
                        //qDebug() << "UploadFile: fileN == defName";
                        fileNN = IsMoreForUpload();
                    }else{
                        //qDebug() << "UploadFile: fileN != defName";
                        fileNN = fileN;
                    }
                    if( fileNN != "no_files" ){
                        if( !fileNN.contains('\\') && !fileNN.contains('/') ){
                            fileNN = config::getWPath() + "/" + fileNN;
                        }
                        tt = QDateTime::currentDateTime();
                        newName = config::getMacAddress() + QString::number( tt.toMSecsSinceEpoch() );
                        currTime = config::getCryptedName( newName );

                        clipboardName = ftpClipboardURL + currTime + "." + config::getImageFormat();
                        if( ftp->state() != ftp->Unconnected && config::capturedQPixes.size() > 0 ){
                            //int curQPixIndex = config::capturedQPixes.keys().at(0);
                            QByteArray bytesForSending = config::getBytesForUpload( QPixmap( config::capturedQPixes.value( config::capturedQPixes.keys().at(0) ) ) );
                            if( bytesForSending.length() == 0 ){
                                qDebug() << "UploadFile: config::getBytesForUpload( config::capturedQPixes.keys().at(0) ).length == 0 ";
                            } else {
                                ftp->put( bytesForSending, currTime + "." + config::getImageFormat() );
                            }
                        }else if( ftp->state() == ftp->Unconnected ){
                            qDebug() << "ftp is NOT connected to the host => calling connectOrDisconect()";
                            connectOrDisconnect();
                        }
                    }
                }else{
                    qDebug() << "UploadFile: uploadFinished == false AND no PENDING commands";
                    qDebug() << "Images in waiting list: " << config::capturedQPixes.values().count();
                    //uploadFinished = true;
                    //uploadFile();
                }

            }
        }
    }
    */
}

void SPGrab::cancelDownload(){
    ftp->abort();
    if (file->exists()) {
        file->close();
        file->remove();
    }
    delete file;
}
void SPGrab::ftpDone(bool isDone){
    //if( isDone ){
        //ftp->close();
    //}
}
void SPGrab::ftpCommandStarted(int commandId){
    if (ftp->currentCommand() == QFtp::Put) {
        currentFileNN = fileNN;
    }
}

void SPGrab::ftpCommandFinished(int, bool error){
    if (ftp->currentCommand() == QFtp::ConnectToHost) {
        if ( error ) {
            qDebug() << "Command: ConnectToHost: " << ftp->error();
            qDebug() << ftp->errorString();
            ftpCounter++;
            QMessageBox msgBox;
            msgBox.setText("Please check/correct your FTP account info.");
            msgBox.exec();
            ssSettings();
            return;
        }
        qDebug() << "************* Entered into ftpCommandFinished: ConnectToHost";
        ftpCounter = 0;
        return;
    }else if (ftp->currentCommand() == QFtp::Put) {

        setIcon(0);
        if (error) {
            qDebug() << "ERR: Command: PUT: " << ftp->error();
            qDebug() << ftp->errorString();
            //file->close();
            //delete file;
            ftpCounter++;
            connectOrDisconnect();

            if( config::isShortcutEnabled() == true ){
                shortcutEnabled = true;
            }
            return;
        }

        qDebug() << "************* Entered into ftpCommandFinished: ftpPut";

        ftpCounter = 0;

        if ( copyURLToClip ){
            QClipboard *cb = QApplication::clipboard();
            cb->setText( clipboardName,
                     QClipboard::Clipboard );
        }

        saveToHistory();

        config::removeQPix();
        config::rmFile(fileNN);

        currentFileNN = currentFileNN.replace('/', '\\');
        moreFiles = IsMoreForUpload();
        if( moreFiles != "no_files" ){
            uploadFile();
        } else {
            showMessage();
        }

        if( config::filesForUpload.length() < 50  ){
            if( config::isShortcutEnabled() == true ){
                shortcutEnabled = true;
            }
        }
    } else if( ftp->currentCommand() == QFtp::Login ){
        if ( error ){
            /*
            if( ftp->error() == 4 ){
                connectOrDisconnect();
                return;
            }
            */
            qDebug() << ftp->error();
            qDebug() << ftp->errorString();
            ftpCounter++;
            QMessageBox msgBox;
            msgBox.setText("Please check/correct your FTP account info.");
            msgBox.exec();
            return;
        }
        qDebug() << "************* Entered into ftpCommandFinished: Login";
        uploadFinished = true;

        //screenShotTakken();
        uploadFile();
    }else{
        if( error ){
            qDebug() << "Error for FTP Command: " << ftp->currentCommand();
            qDebug() << ftp->error();
            qDebug() << ftp->errorString();
            uploadFinished = true;
            ftpCounter++;
            return;
        }
        qDebug() << "************* Entered into ftpCommandFinished: ELSE" << ftp->currentCommand();
        ftpCounter = 0;
        //uploadFinished = true;
        //up_loadFile();

        //*******   screenShotTakken();

        return;
    }
}
QString SPGrab::IsMoreForUpload(){
    QString result = "";
    result = config::getFirstFile();
    return result;
}
void SPGrab::saveToHistory(){
    if( withDesc ){
        historyTitle = QInputDialog::getText(0, "Screenshot with Description","Title:");
        historyDesc = QInputDialog::getText(0, "Screenshot with Description","Description:");
        withDesc = false;
    }
    QSettings settings( config::getWPath() + "/history.ini", QSettings::IniFormat);

    settings.beginGroup("history");
        int size = settings.value("itemscount").toInt();
        QString headd = "uploaded" + QString::number(size);
        settings.setValue("itemscount", QString::number(size+1) );
    settings.endGroup();

    QDateTime tt = QDateTime::currentDateTime();
    QString currTime =  tt.toString( "MMM-dd-yyyy hh:mm:ss" );

    settings.beginGroup(headd);
        settings.setValue("title", historyTitle );
        settings.setValue("desc",  historyDesc );
        settings.setValue("date", currTime );
        settings.setValue("url", clipboardName );
    settings.endGroup();

}
void SPGrab::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes){
    if( totalBytes > 0 ){
        updateTrayIconProgress( ( int ) readBytes * 100 / totalBytes );
    }else{
        qDebug() << "updateDataTransferProgress: ***********  totalBytes < 0 -------------- ";
        uploadFinished = true;
    }
}

void SPGrab::updateTrayIconProgress( int val ){

    QPixmap normalPixmap( ":/images/spgrab.png" );
    QPixmap disabledPixmap( normalPixmap.size() );

    disabledPixmap.fill( Qt::transparent );

    QPainter p( &disabledPixmap );

    p.setBackgroundMode( Qt::TransparentMode );
    p.setBackground( QBrush(Qt::transparent ) );
    p.eraseRect( normalPixmap.rect() );

    p.setOpacity( 0.8 );
    p.drawPixmap( 0, 0, normalPixmap );

    p.setOpacity( 1 );
    p.setBrush( QColor( 134, 0, 0 ) );
    p.drawRect(0, normalPixmap.height() / 2 , normalPixmap.width() * val / 100, normalPixmap.height() / 4 );

    p.end();

    QIcon icon;
    icon.addPixmap(disabledPixmap, QIcon::Disabled, QIcon::On);
    trayIcon->setIcon(icon);
    if( val >= 100 ){
        uploadFinished = true;
        uploadFinished2 = true;
    }
}
void SPGrab::setVisible(bool visible){
    minimizeAction->setEnabled(visible);
    maximizeAction->setEnabled(!isMaximized());
    restoreAction->setEnabled(isMaximized() || !visible);
}

void SPGrab::closeEvent(QCloseEvent *event){
    if (trayIcon->isVisible()) {
        hide();
        event->ignore();
    }
}

void SPGrab::setIcon(int index){
    QIcon icon = iconComboBox->itemIcon(0);

    trayIcon->setIcon(icon);
    setWindowIcon(icon);

    trayIcon->setToolTip(iconComboBox->itemText(0));
}

void SPGrab::iconActivated(QSystemTrayIcon::ActivationReason reason){
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    default:
        break;
    }
}

void SPGrab::showMessage(){
    uploadFinished = true;
    uploadFinished2 = true;
    QString respond = "";
    if( config::StoreToFolderEnabled() ){
        respond +="Screenshot is saved into: \n" + config::getStoringFolder() + ", \n";
    }
    if( uploadImgs == true){
        respond +="Screenshot has been uploaded, \n";
    }
    if( copyURLToClip == true ){
        respond +="URL of uploaded Screenshot is saved in clipboard, \n";
    }
    if( config::getCopyImgToClip() == true ){
        respond +="Screenshot image is saved in clipboard, \n";
    }
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(
            typeComboBox->itemData(typeComboBox->currentIndex()).toInt());
    trayIcon->showMessage("Screenshot taken", respond, icon,
                          durationSpinBox->value() * 2000);

        if( config::openInBrowser && clipboardName.trimmed().length() > 0 ){
            QUrl url2 = QUrl( clipboardName );
            QDesktopServices *dServ2;
                if( dServ2->openUrl(url2) ){
                    qDebug("Picture Downloaded");
                }
        }
}

void SPGrab::showMessage(QString msgTitle, QString msgText){
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(
    typeComboBox->itemData(typeComboBox->currentIndex()).toInt());
    trayIcon->showMessage(msgTitle, msgText, icon,
                          durationSpinBox->value() * 2000);
}
void SPGrab::messageClicked(){
    /*
    QMessageBox::information(0, tr("Systray"),
                             tr("Sorry, I already gave what help I could.\n"
                                "Maybe you should try asking a human?"));
    */
}
void SPGrab::getCoordinates(){
    MainWindow w;
    w.newScreenShot();
}
void SPGrab::disableShortcuts(){
    shortcutEnabled = false;
    if( m_hotkeyFullScreen != 0 ){
        m_hotkeyFullScreen->setEnabled(false);
        disconnect( m_hotkeyFullScreen, SIGNAL( activated() ) );
    }
    if( m_hotkeyArea != 0 ){
        m_hotkeyArea->setEnabled(false);
        disconnect( m_hotkeyArea, SIGNAL( activated() ) );
    }
    if( m_hotkeyAreaDesc != 0 ){
        m_hotkeyAreaDesc->setEnabled(false);
        disconnect( m_hotkeyAreaDesc, SIGNAL( activated() ) );
    }
    if( m_hotkeyAreaNLive != 0 ){
        m_hotkeyAreaNLive->setEnabled(false);
        disconnect( m_hotkeyAreaNLive, SIGNAL( activated() ) );
    }
    if( m_hotkeyGrabWindow != 0 ){
        m_hotkeyGrabWindow->setEnabled(false);
        disconnect( m_hotkeyGrabWindow, SIGNAL( activated() ) );
    }

}

void SPGrab::setShortcuts(){
    //qDebug() << "shortcutEnabled is:" << shortcutEnabled;
    if( shortcutEnabled ){
        if( shortcutFullScreen == "" ){
            shortcutFullScreen = "CTRL+SHIFT+F";
        }

        if( shortcutArea == "" ){
            shortcutArea = "CTRL+SHIFT+L";
        }

        if( shortcutDesc == "" ){
            shortcutDesc = "CTRL+SHIFT+D";
        }

        if( shortcutAreaNLive == "" ){
            shortcutAreaNLive = "CTRL+SHIFT+R";
        }

        if( shortcutGrab == "" ){
            shortcutGrab = "CTRL+SHIFT+A";
        }

        if( shortcutFullScreenEnabled ){
            m_hotkeyFullScreen = new QxtGlobalShortcut( QKeySequence( shortcutFullScreen ), this);
            m_hotkeyFullScreen->setEnabled(true);

            connect( m_hotkeyFullScreen, SIGNAL(activated()),
                this, SLOT(ssFull()), Qt::QueuedConnection );
        }

        if( shortcutNLiveEnabled ){
            m_hotkeyArea = new QxtGlobalShortcut( QKeySequence( shortcutAreaNLive ), this);
            m_hotkeyArea->setEnabled(true);

            connect( m_hotkeyArea, SIGNAL(activated()),
                    this, SLOT(ssRegionNLive()), Qt::QueuedConnection );
        }

        if( shortcutDescEnabled ){
            m_hotkeyAreaDesc = new QxtGlobalShortcut( QKeySequence( shortcutDesc ), this);
            m_hotkeyAreaDesc->setEnabled(true);

            connect( m_hotkeyAreaDesc, SIGNAL(activated()),
                    this, SLOT(ssRegionDesc()), Qt::QueuedConnection );
        }
        if( shortcutAreaEnabled ){

            m_hotkeyAreaNLive = new QxtGlobalShortcut( QKeySequence( shortcutArea ), this);
            m_hotkeyAreaNLive->setEnabled(true);

            connect( m_hotkeyAreaNLive, SIGNAL(activated()),
                    this, SLOT(ssRegion()), Qt::QueuedConnection );
        }
        if( shortcutGrabWindowEnabled ){

            m_hotkeyGrabWindow = new QxtGlobalShortcut( QKeySequence( shortcutGrab ), this);
            m_hotkeyGrabWindow->setEnabled(true);

            connect( m_hotkeyGrabWindow, SIGNAL(activated()),
                    this, SLOT(ssGrabWindow()), Qt::QueuedConnection );
        }


    }else{
        if( m_hotkeyAreaDesc != 0 ){
            m_hotkeyFullScreen->setEnabled( false );
            m_hotkeyArea->setEnabled( false );
            m_hotkeyAreaDesc->setEnabled( false );
            m_hotkeyGrabWindow->setEnabled( false );
        }
    }

}
void SPGrab::ssFull(){
    qDebug() << "****** ssFull: shortcutEnabled = " << shortcutEnabled;
    if( shortcutEnabled ){
        shortcutEnabled = false;
        captureFullScreen *cfs = new captureFullScreen();
        cfs->shootScreen(false);
        delete cfs;
        screenShotTakken();
    }
}
void SPGrab::ssRegion(){
    qDebug() << "****** ssRegion: shortcutEnabled = " << shortcutEnabled;
    if( shortcutEnabled ){
        shortcutEnabled = false;

        //delete mMyNewWindow;
        MainWindow *mMyNewWindow = new MainWindow();
        connect( mMyNewWindow, SIGNAL( finished() ), this, SLOT( screenShotTakken() ) );
        connect( mMyNewWindow, SIGNAL( canceled() ), this, SLOT( screenShotTakingCanceled() ) );

        mMyNewWindow->nLive = false;
        mMyNewWindow->nLivePost = false;
        mMyNewWindow->stopPainting = false;

        mMyNewWindow->show();
        mMyNewWindow->onShow();
    }
}
void SPGrab::ssRegionNLive(){
    qDebug() << "****** ssRegionNLive: shortcutEnabled = " << shortcutEnabled;
    if( shortcutEnabled ){
        shortcutEnabled = false;

        captureFullScreen *cfs = new captureFullScreen();
        cfs->shootScreen(true);
        delete cfs;
        qDebug() << "After delete cfs";
        MainWindow *mMyNewWindow = new MainWindow();
        connect( mMyNewWindow, SIGNAL( finished() ), this, SLOT( screenShotTakken() ) );
        connect( mMyNewWindow, SIGNAL( canceled() ), this, SLOT( screenShotTakingCanceled() ) );

        mMyNewWindow->nLivePost = false;
        mMyNewWindow->stopPainting = false;
        //CAPTURE THE SCREEN AS IT IS AND KEEP IT IN THE SPECIAL IMAGE
        mMyNewWindow->newScreenShot(true);
    }
}
void SPGrab::ssGrabWindow(){
    qDebug() << "****** ssGrabWindow: shortcutEnabled = " << shortcutEnabled;
    if( shortcutEnabled ){
        shortcutEnabled = false;
#ifdef Q_WS_WIN
        grabActiveWindow();
#endif

#ifdef Q_WS_X11
        grabActiveWindowX11();
#endif

    }
}

void SPGrab::ssRegionDesc(){
    if( shortcutEnabled ){
        shortcutEnabled = false;
        MainWindow *mMyNewWindow = new MainWindow();
        connect( mMyNewWindow, SIGNAL( finished() ), this, SLOT( screenShotTakken() ) );
        connect( mMyNewWindow, SIGNAL( canceled() ), this, SLOT( screenShotTakingCanceled() ) );


        mMyNewWindow->nLive = false;
        mMyNewWindow->nLivePost = false;
        mMyNewWindow->stopPainting = false;
        withDesc = true;
        mMyNewWindow->show();
        mMyNewWindow->onShow();
        //delete mMyNewWindow;
    }
}
void SPGrab::ssAboutMe(){
    if( !config::winAboutVisible ){
        config::winAboutVisible = true;
        mWinAbout = new winAboutProgram();
        mWinAbout->show();
    }else{
#ifdef Q_WS_WIN
        mWinAbout->activateWindow();
#endif
#ifdef Q_WS_X11
        mWinAbout->raise();
#endif
    }
}
void SPGrab::ssSettings(){
    if( !config::winSettingsVisible ){
        config::winSettingsVisible = true;
        ftpCounter = 0;
        disableShortcuts();
        mSettingsWindow = new winSettings();
        connect( mSettingsWindow, SIGNAL( dataSaved() ), this, SLOT( getSettingsInfo() ) );
        connect( mSettingsWindow, SIGNAL( canceled() ), this, SLOT( winSettingsClosed() ) );
        mSettingsWindow->show();
    }else{
#ifdef Q_WS_WIN
        mSettingsWindow->activateWindow();
#endif
#ifdef Q_WS_X11
        mSettingsWindow->raise();
#endif
    }
}
void SPGrab::firstTime(){
    ftpCounter = 0;
    mSettingsWindow = new winSettings();
    connect( mSettingsWindow, SIGNAL( dataSaved() ), this, SLOT( getSettingsInfo() ) );
    connect( mSettingsWindow, SIGNAL( canceled() ), this, SLOT( winSettingsClosed() ) );
    mSettingsWindow->show();
}

void SPGrab::ssHistory(){
    if( !mHistoryWindow->isVisible() ){
        mHistoryWindow = new winHistory();
        mHistoryWindow->show();
    }else{
#ifdef Q_WS_WIN
        mHistoryWindow->activateWindow();
#endif
#ifdef Q_WS_X11
        mHistoryWindow->raise();
#endif
    }
}
void SPGrab::winSettingsClosed(){
    //qDebug() << "winSettings is hidden";
    getSettingsInfo();
}
void SPGrab::getSettingsInfo(){
    ftpCounter = 0;
    uploadFinished = true;
    if( !QFile::exists( config::getWPath() + "/settings.ini" ) ){
        config::setShortcutEnabled(true);
        QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);

        settings.beginGroup("shortcuts");
            settings.setValue("enablekeys", "true" );
            settings.setValue("enablekeysFS", "true" );
            settings.setValue("enablekeysAS", "true" );
            settings.setValue("enablekeysADS", "true" );
            settings.setValue("enablekeysNL", "true" );
            settings.setValue("enablekeysGW", "true" );
            settings.setValue("fullscreen", "CTRL+SHIFT+F" );
            settings.setValue("area", "CTRL+SHIFT+L" );
            settings.setValue("areanl", "CTRL+SHIFT+R" );
            settings.setValue("desc", "CTRL+SHIFT+D" );
            settings.setValue("grabwindow", "CTRL+SHIFT+A" );
        settings.endGroup();

        settings.beginGroup("Server");
            settings.setValue("uploadto", "2" );
            settings.setValue("uploadimgs", "false" );
        settings.endGroup();

        settings.beginGroup("General");
            settings.setValue("firstTestera22", "true" );
            settings.setValue("autostart", "false" );
            settings.setValue("storetofolder",  "false" );
            settings.setValue("storingfolder",  "");
            settings.setValue("copyimgtoclipboard", "false" );
            settings.setValue("copyurltoclipboard", "false" );
            settings.setValue("imgformat", "png" );
        settings.endGroup();

        settings.beginGroup("General");
            settings.setValue("firstrun", "false" );
        settings.endGroup();
        config::setDebug(false);
        getSettingsInfo();
    }else{
        QSettings settings( config::getWPath() + "/settings.ini", QSettings::IniFormat);
        settings.beginGroup("Server");
            uploadImgs = ( settings.value("uploadimgs").toString() == "true" ) ? true : false;
            if( uploadImgs ){
                ftpHost = settings.value("host").toString().replace("\r\n","").replace("\n","");
                ftpUser = settings.value("username").toString().replace("\r\n","").replace("\n","");
                ftpPass = settings.value("pass").toString().replace("\r\n","").replace("\n","");
                ftpClipboardURL = settings.value("url").toString().replace("\r\n","").replace("\n","");

                ftpUplader->ftpHost = ftpHost;
                ftpUplader->ftpUser = ftpUser;
                ftpUplader->ftpPass = ftpPass;
                ftpUplader->ftpClipboardURL = ftpClipboardURL;
            }else{
                ftpUplader->doUpload  = false;
            }
        settings.endGroup();

        settings.beginGroup("General");
            config::setCopyImgToClip( ( settings.value("copyimgtoclipboard").toString() == "true" ) ? true : false );
            copyURLToClip = ( settings.value("copyurltoclipboard").toString() == "true" ) ? true : false;
            config::setStoreFolderEnable( ( settings.value("storetofolder").toString() == "true" ) ? true : false );
            config::setStoringFolder( settings.value("storingfolder").toString() );
            config::setImageFormat( settings.value("imgformat").toString()  );
            config::setOpenInBrowser( ( settings.value("openinbrowser").toString() == "true" ) ? true : false );
            config::setDebug( ( settings.value("debug").toString() == "true" ) ? true : false );
        settings.endGroup();

        settings.beginGroup("shortcuts");
            if( settings.value("enablekeys").toString() == "true" ){
                shortcutEnabled = true;
                config::setShortcutEnabled(true);
            }else{
                shortcutEnabled = false;
                config::setShortcutEnabled(false);
            }

            shortcutFullScreenEnabled = ( ( settings.value("enablekeysFS") == "true" ) ? true : false );
            shortcutAreaEnabled = ( ( settings.value("enablekeysAS") == "true" ) ? true : false );
            shortcutNLiveEnabled = ( ( settings.value("enablekeysNL") == "true" ) ? true : false );
            shortcutGrabWindowEnabled = ( ( settings.value("enablekeysGW") == "true" ) ? true : false );
            shortcutDescEnabled = ( ( settings.value("enablekeysADS") == "true" ) ? true : false );

            shortcutFullScreen = settings.value("fullscreen").toString();
            shortcutArea = settings.value("area").toString();
            shortcutAreaNLive = settings.value("areanl").toString();
            shortcutDesc = settings.value("desc").toString();
            shortcutGrab = settings.value("grabwindow").toString();

        settings.endGroup();
        if ( uploadImgs ){
            if ( ftpHost == "" || ftpUser == "" ){
                QMessageBox msgBox;
                msgBox.setText("If You are using SP Grab for the first time \n You need to setup your FTP account info.");
                msgBox.exec();
                firstTime();
            }else{
                ftpUplader->copyURLToClip = copyURLToClip;
                ftpUplader->run();
            }
        } else {
            copyURLToClip = false;
            ftpUplader->doUpload = false;
        }
        setShortcuts();
    }
}
void SPGrab::screenShotTakingCanceled(){
    shortcutEnabled = true;
}

void SPGrab::screenShotTakken(){
    shortcutEnabled = true;
    //delete mMyNewWindow->fullScreen;
    //mMyNewWindow->disconnect(this);
    //if( mMyNewWindow ){
    //    delete mMyNewWindow;
    //    mMyNewWindow = NULL;
    //}
    qDebug() << "screenShotTakken : mMyWindow deleted";
    if( uploadImgs == true ){
        ftpUplader->newUploadNeeded == true;
    }else{
        if( config::isShortcutEnabled() == true ){
            shortcutEnabled = true;
        }
        qDebug() << "uploadImgs => false";
        setIcon(0);
        showMessage();
    }
}
void SPGrab::systrayCheck(){
    if( QSystemTrayIcon::isSystemTrayAvailable() ){
             timPostpone->stop();
             qDebug() << " ******* * ** * * It's TIME ;-)";
             generateUI();
    }else{
        qDebug() << "Not yet :-), tCounter=" << tCounter;
        tCounter++;
    }
}
void SPGrab::generateUI(){

    createIconGroupBox();
    createMessageGroupBox();

    iconLabel->setMinimumWidth(durationLabel->sizeHint().width());

    createActions();
    createTrayIcon();

    connect(showMessageButton, SIGNAL(clicked()), this, SLOT(showMessage()));
    connect(showIconCheckBox, SIGNAL(toggled(bool)), trayIcon, SLOT(setVisible(bool)));
    connect(iconComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setIcon(int)));
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(iconGroupBox);
    mainLayout->addWidget(messageGroupBox);
    //setLayout(mainLayout);

    iconComboBox->setCurrentIndex(1);
    trayIcon->show();

    setWindowTitle(tr("SPGrab"));
    resize(400, 300);
    QIcon icon = iconComboBox->itemIcon(0);

    progressDialog = new QProgressDialog(this);
    progressDialog->setCancelButton(0);
    progressDialog->setWindowIcon(icon);
    progressDialog->setVisible(false);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        networkSession->open();
    }
}
void SPGrab::createIconGroupBox(){
    iconGroupBox = new QGroupBox(tr("Tray Icon"));

    iconLabel = new QLabel("Icon:");

    iconComboBox = new QComboBox;
    iconComboBox->addItem(QIcon(":/images/spgrab.png"), tr("ShiftPlanning SPGrab"));

    showIconCheckBox = new QCheckBox(tr("Show icon"));
    showIconCheckBox->setChecked(true);

    QHBoxLayout *iconLayout = new QHBoxLayout;
    iconLayout->addWidget(iconLabel);
    iconLayout->addWidget(iconComboBox);
    iconLayout->addStretch();
    iconLayout->addWidget(showIconCheckBox);
    iconGroupBox->setLayout(iconLayout);
}

void SPGrab::createMessageGroupBox()
{
    messageGroupBox = new QGroupBox(tr("Balloon Message"));

    typeLabel = new QLabel(tr("Type:"));

    typeComboBox = new QComboBox;
    typeComboBox->addItem(tr("None"), QSystemTrayIcon::NoIcon);
    typeComboBox->addItem(style()->standardIcon(
            QStyle::SP_MessageBoxInformation), tr("Information"),
            QSystemTrayIcon::Information);
    typeComboBox->addItem(style()->standardIcon(
            QStyle::SP_MessageBoxWarning), tr("Warning"),
            QSystemTrayIcon::Warning);
    typeComboBox->addItem(style()->standardIcon(
            QStyle::SP_MessageBoxCritical), tr("Critical"),
            QSystemTrayIcon::Critical);
    typeComboBox->setCurrentIndex(1);

    durationLabel = new QLabel(tr("Duration:"));

    durationSpinBox = new QSpinBox;
    durationSpinBox->setRange(5, 60);
    durationSpinBox->setSuffix(" s");
    durationSpinBox->setValue(15);

    durationWarningLabel = new QLabel(tr("(some systems might ignore this "
                                         "hint)"));
    durationWarningLabel->setIndent(10);

    titleLabel = new QLabel(tr("Title:"));

    titleEdit = new QLineEdit(tr("Cannot connect to network"));

    bodyLabel = new QLabel(tr("Body:"));

    bodyEdit = new QTextEdit;
    bodyEdit->setPlainText(tr("Don't believe me. Honestly, I don't have a "
                              "clue.\nClick this balloon for details."));

    showMessageButton = new QPushButton(tr("Show Message"));
    showMessageButton->setDefault(true);

    QGridLayout *messageLayout = new QGridLayout;
    messageLayout->addWidget(typeLabel, 0, 0);
    messageLayout->addWidget(typeComboBox, 0, 1, 1, 2);
    messageLayout->addWidget(durationLabel, 1, 0);
    messageLayout->addWidget(durationSpinBox, 1, 1);
    messageLayout->addWidget(durationWarningLabel, 1, 2, 1, 3);
    messageLayout->addWidget(titleLabel, 2, 0);
    messageLayout->addWidget(titleEdit, 2, 1, 1, 4);
    messageLayout->addWidget(bodyLabel, 3, 0);
    messageLayout->addWidget(bodyEdit, 3, 1, 2, 4);
    messageLayout->addWidget(showMessageButton, 5, 4);
    messageLayout->setColumnStretch(3, 1);
    messageLayout->setRowStretch(4, 1);
    messageGroupBox->setLayout(messageLayout);
}

void SPGrab::createActions()
{

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    screenShotFull = new QAction(tr("Screenshoot - &Full"), this);
    connect(screenShotFull, SIGNAL( triggered() ), this, SLOT( ssFull() ) );

    wSettings = new QAction(tr("&Settings"), this);
    connect(wSettings, SIGNAL( triggered() ), this, SLOT( ssSettings() ) );

    wHistory = new QAction(tr("&History"), this);
    connect(wHistory, SIGNAL( triggered() ), this, SLOT( ssHistory()) );

    screenShotRegion = new QAction(tr("Screenshoot - &Live"), this);
    connect(screenShotRegion, SIGNAL( triggered() ), this, SLOT( ssRegion()) );

    screenShotRegionNLive = new QAction(tr("Screenshoot - &Region"), this);
    connect(screenShotRegionNLive, SIGNAL( triggered() ), this, SLOT( ssRegionNLive()) );

    screenGrabWindow = new QAction(tr("Screenshoot - Active Window"), this);
    connect(screenGrabWindow, SIGNAL( triggered() ), this, SLOT( ssGrabWindow() ) );

    screenShotRegionDesc = new QAction(tr("Screenshoot - Region with &Description"), this);
    connect(screenShotRegionDesc, SIGNAL( triggered() ), this, SLOT( ssRegionDesc()) );

    aboutProgram = new QAction(tr("A&bout SPGrab"), this);
    connect(aboutProgram, SIGNAL( triggered() ), this, SLOT( ssAboutMe()) );

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void SPGrab::createTrayIcon()
{
    trayIconMenu = new QMenu(this);

    trayIconMenu->addAction(screenShotFull);
    trayIconMenu->addAction(screenShotRegionNLive);
    trayIconMenu->addAction(screenShotRegion);
    trayIconMenu->addAction(screenGrabWindow);
    trayIconMenu->addAction(screenShotRegionDesc);
    trayIconMenu->addSeparator();

    trayIconMenu->addAction(wSettings);
    trayIconMenu->addAction(wHistory);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(aboutProgram);
    trayIconMenu->addSeparator();

    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

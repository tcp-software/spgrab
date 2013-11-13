#ifndef WINDOW_H
 #define WINDOW_H

#include <QSystemTrayIcon>
#include <QDialog>
#include <QHash>
#include <QTreeWidgetItem>
#include <QShortcut>
#include <QMainWindow>
#include <QTimer>
#include <QDir>
#include <shortcut/3rdparty/qxt/src/core/qxtglobal.h>

#include "mainwindow.h"
#include "winsettings.h"
#include "winhistory.h"
#include "winaboutprogram.h"
#include "config.h"

#include "shortcut/3rdparty/qxt/include/QxtGui/QxtGlobalShortcut"

    class QAction;
    class QCheckBox;
    class QComboBox;
    class QGroupBox;
    class QLabel;
    class QLineEdit;
    class QMenu;
    class QPushButton;
    class QSpinBox;
    class QTextEdit;
    class QProgressDialog;

    class QFile;
    class QFtp;
    class QUrlInfo;
    class QNetworkSession;
    class QClipboard;
    class QString;

class SPGrab : public QMainWindow
 {
     Q_OBJECT

    public:
        SPGrab(QWidget *parent = 0);
        MainWindow *mMyNewWindow;
        winAboutProgram *mWinAbout;
        void setVisible(bool visible);
        void setFTPInfo(QString host, QString user, QString pass, QString url);
        void saveToHistory();
#ifdef Q_WS_WIN
        void grabActiveWindow();
#endif
#ifdef Q_WS_X11
        void grabActiveWindowX11();
#endif
        QxtGlobalShortcut *m_hotkeyFullScreen;
        QxtGlobalShortcut *m_hotkeyArea;
        QxtGlobalShortcut *m_hotkeyAreaDesc;
        QxtGlobalShortcut *m_hotkeyAreaNLive;
        QxtGlobalShortcut *m_hotkeyGrabWindow;

        static QString defName;

        int ftpCounter;
        bool uploadFinished;
        QString troubleFile;
        bool uploadFinished2;
        void generateUI();

    public slots:
        void getCoordinates( );
        void setShortcuts();
        void disableShortcuts();
        void systrayCheck();

    protected:
        void closeEvent(QCloseEvent *event);

    private slots:
        void setIcon(int index);
        void iconActivated(QSystemTrayIcon::ActivationReason reason);
        void showMessage();
        void showMessage(QString msgTitle, QString msgText);
        void messageClicked();
        void ssFull();
        void ssRegion();
        void ssRegionNLive();
        void ssRegionDesc();
        void ssGrabWindow();
        void ssAboutMe();
        void ssHistory();
        void ssSettings();
        void firstTime();
        void screenShotTakken();
        void screenShotTakingCanceled();
        void getSettingsInfo();
        void checkIniSettingsVersion();
        void winSettingsClosed();

        void connectOrDisconnect();
        void uploadFile( QString fileN = defName );
        void cancelDownload();
        void ftpStateChanged(int status);

        void ftpCommandFinished(int commandId, bool error);
        void ftpCommandStarted(int commandId);

        void ftpDone(bool);
        void updateDataTransferProgress(qint64 readBytes,
                                        qint64 totalBytes);
        void updateTrayIconProgress( int val );
        void updateClipBoard(QString newUrlPath);

    private:
        void deleteTempFiles();
        void createIconGroupBox();
        void createMessageGroupBox();
        void createActions();
        void createTrayIcon();
        int imgCounter;

        QString IsMoreForUpload();
        bool isMoreFirstTime;

        QGroupBox *iconGroupBox;
        QLabel *iconLabel;
        QComboBox *iconComboBox;
        QCheckBox *showIconCheckBox;

        QGroupBox *messageGroupBox;
        QLabel *typeLabel;
        QLabel *durationLabel;
        QLabel *durationWarningLabel;
        QLabel *titleLabel;
        QLabel *bodyLabel;
        QComboBox *typeComboBox;
        QSpinBox *durationSpinBox;
        QLineEdit *titleEdit;
        QTextEdit *bodyEdit;
        QPushButton *showMessageButton;

        QAction *screenShotRegion;
        QAction *screenShotRegionNLive;
        QAction *screenShotRegionDesc;
        QAction *screenShotFull;
        QAction *screenGrabWindow;
        //QAction *checkUpload;
        QAction *wSettings;
        QAction *wHistory;
        QAction *aboutProgram;

        QAction *minimizeAction;
        QAction *maximizeAction;
        QAction *restoreAction;
        QAction *quitAction;

        QSystemTrayIcon *trayIcon;
        QMenu *trayIconMenu;
        winSettings *mSettingsWindow;
        winHistory *mHistoryWindow;

        QProgressDialog *progressDialog;
        QHash<QString, bool> isDirectory;

        QNetworkSession *networkSession;
        QFtp *ftp;
        QFile *file;
        QDir workingDir;
        QString currentPath;
        QString clipboardName;

        bool uploadImgs;
        bool copyURLToClip;
        QString ftpHost;
        QString ftpUser;
        QString ftpPass;
        QString ftpClipboardURL;

        bool shortcutEnabled;
        QString shortcutFullScreen;
        QString shortcutArea;
        QString shortcutAreaNLive;
        QString shortcutDesc;
        QString shortcutGrab;

        QString historyTitle;
        QString historyDesc;
        int cOrD;
 };

 #endif

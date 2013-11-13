/********************************************************************************
** Form generated from reading UI file 'winsettings.ui'
**
** Created: Sat 5. Jan 17:22:53 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINSETTINGS_H
#define UI_WINSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winSettings
{
public:
    QWidget *centralwidget;
    QPushButton *btnSaveData;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *cmbImageFormats;
    QCheckBox *chkToFolder;
    QCheckBox *chkAutoStart;
    QFrame *line;
    QLineEdit *txtStoreFolder;
    QPushButton *btnBrowseFolder;
    QFrame *line_2;
    QLabel *label_22;
    QCheckBox *chkOpenInBrowser;
    QCheckBox *chkToClipboard;
    QCheckBox *chkImgToClipboard;
    QWidget *tab_2;
    QPushButton *btnTest;
    QGroupBox *groupBox;
    QRadioButton *optSPGrab;
    QRadioButton *optCustomFtp;
    QRadioButton *optNone;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtUploadedURL;
    QLabel *label_3;
    QLineEdit *txtFtpUsername;
    QLineEdit *txtFtpPassword;
    QLineEdit *txtHost;
    QLabel *label_4;
    QWidget *tab_3;
    QLabel *label_6;
    QPushButton *btnShortcutDesc;
    QCheckBox *chkDisableSKeys;
    QCheckBox *chkKeyADS;
    QCheckBox *chkKeyFS;
    QPushButton *btnShortcutArea;
    QLabel *label_7;
    QPushButton *btnResetFull;
    QPushButton *btnResetDesc;
    QCheckBox *chkKeyAS;
    QLabel *label_5;
    QPushButton *btnResetRegion;
    QPushButton *btnShortcutFull;
    QPushButton *btnResetRegionLive;
    QPushButton *btnShortcutAreaLive;
    QLabel *label_8;
    QCheckBox *chkKeyLive;
    QLabel *label_9;
    QPushButton *btnShortcutGrabWindow;
    QPushButton *btnResetGrabWindow;
    QCheckBox *chkKeyGW;

    void setupUi(QMainWindow *winSettings)
    {
        if (winSettings->objectName().isEmpty())
            winSettings->setObjectName(QString::fromUtf8("winSettings"));
        winSettings->setWindowModality(Qt::WindowModal);
        winSettings->resize(515, 360);
        winSettings->setMinimumSize(QSize(515, 360));
        winSettings->setMaximumSize(QSize(515, 360));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/spgrab.ico"), QSize(), QIcon::Normal, QIcon::Off);
        winSettings->setWindowIcon(icon);
        centralwidget = new QWidget(winSettings);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnSaveData = new QPushButton(centralwidget);
        btnSaveData->setObjectName(QString::fromUtf8("btnSaveData"));
        btnSaveData->setGeometry(QRect(380, 320, 131, 31));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 501, 301));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        cmbImageFormats = new QComboBox(tab);
        cmbImageFormats->setObjectName(QString::fromUtf8("cmbImageFormats"));
        cmbImageFormats->setGeometry(QRect(160, 230, 91, 21));
        chkToFolder = new QCheckBox(tab);
        chkToFolder->setObjectName(QString::fromUtf8("chkToFolder"));
        chkToFolder->setGeometry(QRect(10, 140, 291, 21));
        chkAutoStart = new QCheckBox(tab);
        chkAutoStart->setObjectName(QString::fromUtf8("chkAutoStart"));
        chkAutoStart->setGeometry(QRect(10, 20, 251, 21));
        chkAutoStart->setChecked(true);
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 501, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        txtStoreFolder = new QLineEdit(tab);
        txtStoreFolder->setObjectName(QString::fromUtf8("txtStoreFolder"));
        txtStoreFolder->setEnabled(false);
        txtStoreFolder->setGeometry(QRect(30, 160, 341, 22));
        btnBrowseFolder = new QPushButton(tab);
        btnBrowseFolder->setObjectName(QString::fromUtf8("btnBrowseFolder"));
        btnBrowseFolder->setEnabled(false);
        btnBrowseFolder->setGeometry(QRect(380, 160, 91, 23));
        line_2 = new QFrame(tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 120, 501, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 220, 141, 31));
        chkOpenInBrowser = new QCheckBox(tab);
        chkOpenInBrowser->setObjectName(QString::fromUtf8("chkOpenInBrowser"));
        chkOpenInBrowser->setGeometry(QRect(10, 90, 291, 21));
        chkToClipboard = new QCheckBox(tab);
        chkToClipboard->setObjectName(QString::fromUtf8("chkToClipboard"));
        chkToClipboard->setGeometry(QRect(10, 60, 261, 21));
        chkToClipboard->setChecked(true);
        chkImgToClipboard = new QCheckBox(tab);
        chkImgToClipboard->setObjectName(QString::fromUtf8("chkImgToClipboard"));
        chkImgToClipboard->setGeometry(QRect(10, 190, 281, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        btnTest = new QPushButton(tab_2);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));
        btnTest->setGeometry(QRect(310, 240, 141, 23));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 481, 61));
        optSPGrab = new QRadioButton(groupBox);
        optSPGrab->setObjectName(QString::fromUtf8("optSPGrab"));
        optSPGrab->setGeometry(QRect(32, 20, 101, 21));
        optSPGrab->setChecked(true);
        optCustomFtp = new QRadioButton(groupBox);
        optCustomFtp->setObjectName(QString::fromUtf8("optCustomFtp"));
        optCustomFtp->setGeometry(QRect(200, 20, 111, 21));
        optNone = new QRadioButton(groupBox);
        optNone->setObjectName(QString::fromUtf8("optNone"));
        optNone->setGeometry(QRect(410, 20, 71, 21));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 111, 20));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 120, 111, 31));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        txtUploadedURL = new QLineEdit(tab_2);
        txtUploadedURL->setObjectName(QString::fromUtf8("txtUploadedURL"));
        txtUploadedURL->setGeometry(QRect(140, 210, 331, 21));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 111, 31));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        txtFtpUsername = new QLineEdit(tab_2);
        txtFtpUsername->setObjectName(QString::fromUtf8("txtFtpUsername"));
        txtFtpUsername->setGeometry(QRect(140, 130, 331, 21));
        txtFtpPassword = new QLineEdit(tab_2);
        txtFtpPassword->setObjectName(QString::fromUtf8("txtFtpPassword"));
        txtFtpPassword->setGeometry(QRect(140, 170, 331, 21));
        txtHost = new QLineEdit(tab_2);
        txtHost->setObjectName(QString::fromUtf8("txtHost"));
        txtHost->setGeometry(QRect(140, 90, 331, 21));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 200, 61, 31));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 40, 141, 31));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnShortcutDesc = new QPushButton(tab_3);
        btnShortcutDesc->setObjectName(QString::fromUtf8("btnShortcutDesc"));
        btnShortcutDesc->setGeometry(QRect(250, 110, 141, 21));
        chkDisableSKeys = new QCheckBox(tab_3);
        chkDisableSKeys->setObjectName(QString::fromUtf8("chkDisableSKeys"));
        chkDisableSKeys->setGeometry(QRect(10, 180, 191, 16));
        chkKeyADS = new QCheckBox(tab_3);
        chkKeyADS->setObjectName(QString::fromUtf8("chkKeyADS"));
        chkKeyADS->setGeometry(QRect(10, 100, 71, 31));
        chkKeyFS = new QCheckBox(tab_3);
        chkKeyFS->setObjectName(QString::fromUtf8("chkKeyFS"));
        chkKeyFS->setGeometry(QRect(10, 10, 71, 31));
        btnShortcutArea = new QPushButton(tab_3);
        btnShortcutArea->setObjectName(QString::fromUtf8("btnShortcutArea"));
        btnShortcutArea->setGeometry(QRect(250, 50, 141, 21));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 100, 151, 31));
        QFont font;
        font.setPointSize(8);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnResetFull = new QPushButton(tab_3);
        btnResetFull->setObjectName(QString::fromUtf8("btnResetFull"));
        btnResetFull->setGeometry(QRect(400, 20, 81, 21));
        btnResetDesc = new QPushButton(tab_3);
        btnResetDesc->setObjectName(QString::fromUtf8("btnResetDesc"));
        btnResetDesc->setGeometry(QRect(400, 110, 81, 21));
        chkKeyAS = new QCheckBox(tab_3);
        chkKeyAS->setObjectName(QString::fromUtf8("chkKeyAS"));
        chkKeyAS->setGeometry(QRect(10, 40, 71, 31));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 10, 151, 31));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnResetRegion = new QPushButton(tab_3);
        btnResetRegion->setObjectName(QString::fromUtf8("btnResetRegion"));
        btnResetRegion->setGeometry(QRect(400, 50, 81, 21));
        btnShortcutFull = new QPushButton(tab_3);
        btnShortcutFull->setObjectName(QString::fromUtf8("btnShortcutFull"));
        btnShortcutFull->setGeometry(QRect(250, 20, 141, 21));
        btnResetRegionLive = new QPushButton(tab_3);
        btnResetRegionLive->setObjectName(QString::fromUtf8("btnResetRegionLive"));
        btnResetRegionLive->setGeometry(QRect(400, 80, 81, 21));
        btnShortcutAreaLive = new QPushButton(tab_3);
        btnShortcutAreaLive->setObjectName(QString::fromUtf8("btnShortcutAreaLive"));
        btnShortcutAreaLive->setGeometry(QRect(250, 80, 141, 21));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 70, 151, 31));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        chkKeyLive = new QCheckBox(tab_3);
        chkKeyLive->setObjectName(QString::fromUtf8("chkKeyLive"));
        chkKeyLive->setGeometry(QRect(10, 70, 71, 31));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(90, 130, 151, 31));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnShortcutGrabWindow = new QPushButton(tab_3);
        btnShortcutGrabWindow->setObjectName(QString::fromUtf8("btnShortcutGrabWindow"));
        btnShortcutGrabWindow->setGeometry(QRect(250, 140, 141, 21));
        btnResetGrabWindow = new QPushButton(tab_3);
        btnResetGrabWindow->setObjectName(QString::fromUtf8("btnResetGrabWindow"));
        btnResetGrabWindow->setGeometry(QRect(400, 140, 81, 21));
        chkKeyGW = new QCheckBox(tab_3);
        chkKeyGW->setObjectName(QString::fromUtf8("chkKeyGW"));
        chkKeyGW->setGeometry(QRect(10, 130, 71, 31));
        tabWidget->addTab(tab_3, QString());
        winSettings->setCentralWidget(centralwidget);

        retranslateUi(winSettings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(winSettings);
    } // setupUi

    void retranslateUi(QMainWindow *winSettings)
    {
        winSettings->setWindowTitle(QApplication::translate("winSettings", "Preferences", 0, QApplication::UnicodeUTF8));
        btnSaveData->setText(QApplication::translate("winSettings", "Save", 0, QApplication::UnicodeUTF8));
        chkToFolder->setText(QApplication::translate("winSettings", "Store image to folder:", 0, QApplication::UnicodeUTF8));
        chkAutoStart->setText(QApplication::translate("winSettings", "Run SPGrab on startup", 0, QApplication::UnicodeUTF8));
        btnBrowseFolder->setText(QApplication::translate("winSettings", "Browse", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("winSettings", "Screenshot format:", 0, QApplication::UnicodeUTF8));
        chkOpenInBrowser->setText(QApplication::translate("winSettings", "Open in browser", 0, QApplication::UnicodeUTF8));
        chkToClipboard->setText(QApplication::translate("winSettings", "Copy URL to clipboard", 0, QApplication::UnicodeUTF8));
        chkImgToClipboard->setText(QApplication::translate("winSettings", "Copy image to clipboard", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("winSettings", "General", 0, QApplication::UnicodeUTF8));
        btnTest->setText(QApplication::translate("winSettings", "Test connection", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("winSettings", "Upload to:", 0, QApplication::UnicodeUTF8));
        optSPGrab->setText(QApplication::translate("winSettings", "SPGrab", 0, QApplication::UnicodeUTF8));
        optCustomFtp->setText(QApplication::translate("winSettings", "Custom FTP", 0, QApplication::UnicodeUTF8));
        optNone->setText(QApplication::translate("winSettings", "None", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("winSettings", "FTP Host URL", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("winSettings", "FTP Username", 0, QApplication::UnicodeUTF8));
        txtUploadedURL->setInputMask(QString());
        txtUploadedURL->setText(QString());
        txtUploadedURL->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("winSettings", "FTP Password", 0, QApplication::UnicodeUTF8));
        txtFtpPassword->setInputMask(QString());
        txtFtpPassword->setText(QString());
        txtFtpPassword->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        txtHost->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("winSettings", "URL", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("winSettings", "Account", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("winSettings", "Area Shortcut Key", 0, QApplication::UnicodeUTF8));
        btnShortcutDesc->setText(QString());
        chkDisableSKeys->setText(QApplication::translate("winSettings", "Disable shortcut keys", 0, QApplication::UnicodeUTF8));
        chkKeyADS->setText(QApplication::translate("winSettings", "Enable", 0, QApplication::UnicodeUTF8));
        chkKeyFS->setText(QApplication::translate("winSettings", "Enable", 0, QApplication::UnicodeUTF8));
        btnShortcutArea->setText(QString());
        label_7->setText(QApplication::translate("winSettings", "Area + Desc Key", 0, QApplication::UnicodeUTF8));
        btnResetFull->setText(QApplication::translate("winSettings", "Reset", 0, QApplication::UnicodeUTF8));
        btnResetDesc->setText(QApplication::translate("winSettings", "Reset", 0, QApplication::UnicodeUTF8));
        chkKeyAS->setText(QApplication::translate("winSettings", "Enable", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("winSettings", "FullScreen Key", 0, QApplication::UnicodeUTF8));
        btnResetRegion->setText(QApplication::translate("winSettings", "Reset", 0, QApplication::UnicodeUTF8));
        btnShortcutFull->setText(QString());
        btnResetRegionLive->setText(QApplication::translate("winSettings", "Reset", 0, QApplication::UnicodeUTF8));
        btnShortcutAreaLive->setText(QString());
        label_8->setText(QApplication::translate("winSettings", "Area Live Key", 0, QApplication::UnicodeUTF8));
        chkKeyLive->setText(QApplication::translate("winSettings", "Enable", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("winSettings", "Window Grabing Key", 0, QApplication::UnicodeUTF8));
        btnShortcutGrabWindow->setText(QString());
        btnResetGrabWindow->setText(QApplication::translate("winSettings", "Reset", 0, QApplication::UnicodeUTF8));
        chkKeyGW->setText(QApplication::translate("winSettings", "Enable", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("winSettings", "Key Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winSettings: public Ui_winSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSETTINGS_H

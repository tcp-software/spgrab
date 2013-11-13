/********************************************************************************
** Form generated from reading UI file 'winaboutapp.ui'
**
** Created: Tue Jul 3 15:58:57 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINABOUTAPP_H
#define UI_WINABOUTAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winaboutapp
{
public:
    QWidget *centralwidget;
    QLabel *lblLogo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *winaboutapp)
    {
        if (winaboutapp->objectName().isEmpty())
            winaboutapp->setObjectName(QString::fromUtf8("winaboutapp"));
        winaboutapp->resize(358, 249);
        winaboutapp->setMaximumSize(QSize(478, 278));
        winaboutapp->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        winaboutapp->setWindowIcon(icon);
        winaboutapp->setWindowOpacity(1);
        winaboutapp->setAutoFillBackground(false);
        centralwidget = new QWidget(winaboutapp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lblLogo = new QLabel(centralwidget);
        lblLogo->setObjectName(QString::fromUtf8("lblLogo"));
        lblLogo->setGeometry(QRect(40, 10, 111, 91));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/biglogo.png")));
        lblLogo->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 171, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Trebuchet MS"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 60, 81, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Trebuchet MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 110, 351, 101));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        winaboutapp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(winaboutapp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 358, 20));
        winaboutapp->setMenuBar(menubar);
        statusbar = new QStatusBar(winaboutapp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        winaboutapp->setStatusBar(statusbar);

        retranslateUi(winaboutapp);

        QMetaObject::connectSlotsByName(winaboutapp);
    } // setupUi

    void retranslateUi(QMainWindow *winaboutapp)
    {
        winaboutapp->setWindowTitle(QApplication::translate("winaboutapp", "About SP Grab", 0, QApplication::UnicodeUTF8));
        lblLogo->setText(QString());
        label->setText(QApplication::translate("winaboutapp", "SPGrab", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("winaboutapp", " v2.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("winaboutapp", "<html><head/><body>\n"
"SPGrab is designed by ShiftPlanning,<br>\n"
"Online Employee Scheduling Software Company.<br><br>\n"
"Go to <a href=\"http://www.shiftplanning.com\">http://www.shiftplanning.com</a><br>\n"
"for more information about the<br>\n"
"ShiftPlanning Software\n"
"\n"
"</body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winaboutapp: public Ui_winaboutapp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINABOUTAPP_H

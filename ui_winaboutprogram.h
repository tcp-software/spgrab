/********************************************************************************
** Form generated from reading UI file 'winaboutprogram.ui'
**
** Created: Sat 5. Jan 17:22:53 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINABOUTPROGRAM_H
#define UI_WINABOUTPROGRAM_H

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

class Ui_winAboutProgram
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *lblLogo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *winAboutProgram)
    {
        if (winAboutProgram->objectName().isEmpty())
            winAboutProgram->setObjectName(QString::fromUtf8("winAboutProgram"));
        winAboutProgram->resize(372, 270);
        winAboutProgram->setMinimumSize(QSize(372, 270));
        winAboutProgram->setMaximumSize(QSize(372, 270));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/spgrab.ico"), QSize(), QIcon::Normal, QIcon::Off);
        winAboutProgram->setWindowIcon(icon);
        centralwidget = new QWidget(winAboutProgram);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 20, 171, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Trebuchet MS"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 351, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Trebuchet MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 60, 81, 16));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblLogo = new QLabel(centralwidget);
        lblLogo->setObjectName(QString::fromUtf8("lblLogo"));
        lblLogo->setGeometry(QRect(50, 10, 111, 91));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/spgrab.png")));
        lblLogo->setScaledContents(true);
        winAboutProgram->setCentralWidget(centralwidget);
        menubar = new QMenuBar(winAboutProgram);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 372, 21));
        winAboutProgram->setMenuBar(menubar);
        statusbar = new QStatusBar(winAboutProgram);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        winAboutProgram->setStatusBar(statusbar);

        retranslateUi(winAboutProgram);

        QMetaObject::connectSlotsByName(winAboutProgram);
    } // setupUi

    void retranslateUi(QMainWindow *winAboutProgram)
    {
        winAboutProgram->setWindowTitle(QApplication::translate("winAboutProgram", "About SPGrab", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("winAboutProgram", "SPGrab", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("winAboutProgram", "<html><head/><body>\n"
"SPGrab is designed by ShiftPlanning,<br>\n"
"Online Employee Scheduling Software Company.<br><br>\n"
"Go to <a href=\"http://www.shiftplanning.com\">http://www.shiftplanning.com</a><br>\n"
"for more information about the<br>\n"
"ShiftPlanning Software\n"
"\n"
"</body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("winAboutProgram", " v2.0", 0, QApplication::UnicodeUTF8));
        lblLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class winAboutProgram: public Ui_winAboutProgram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINABOUTPROGRAM_H

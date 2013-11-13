/********************************************************************************
** Form generated from reading UI file 'winhistory.ui'
**
** Created: Sat 5. Jan 17:22:53 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINHISTORY_H
#define UI_WINHISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winHistory
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableWidget *tblHistory;
    QGroupBox *groupBox;
    QLineEdit *txtSearch;
    QLabel *label;
    QPushButton *btnClearAll;
    QLineEdit *txtUrl;
    QLabel *label_2;
    QPushButton *btnToClipboard;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *winHistory)
    {
        if (winHistory->objectName().isEmpty())
            winHistory->setObjectName(QString::fromUtf8("winHistory"));
        winHistory->resize(1133, 619);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/spgrab.ico"), QSize(), QIcon::Normal, QIcon::Off);
        winHistory->setWindowIcon(icon);
        centralwidget = new QWidget(winHistory);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tblHistory = new QTableWidget(centralwidget);
        if (tblHistory->columnCount() < 4)
            tblHistory->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblHistory->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblHistory->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblHistory->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblHistory->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tblHistory->rowCount() < 1)
            tblHistory->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblHistory->setVerticalHeaderItem(0, __qtablewidgetitem4);
        tblHistory->setObjectName(QString::fromUtf8("tblHistory"));
        tblHistory->setMaximumSize(QSize(16777215, 16777215));
        tblHistory->setSortingEnabled(true);
        tblHistory->setRowCount(1);
        tblHistory->horizontalHeader()->setStretchLastSection(true);
        tblHistory->verticalHeader()->setMinimumSectionSize(17);
        tblHistory->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblHistory->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tblHistory, 3, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 74));
        groupBox->setBaseSize(QSize(0, 0));
        txtSearch = new QLineEdit(groupBox);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));
        txtSearch->setGeometry(QRect(110, 10, 641, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 21));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnClearAll = new QPushButton(groupBox);
        btnClearAll->setObjectName(QString::fromUtf8("btnClearAll"));
        btnClearAll->setGeometry(QRect(960, 10, 141, 23));
        txtUrl = new QLineEdit(groupBox);
        txtUrl->setObjectName(QString::fromUtf8("txtUrl"));
        txtUrl->setGeometry(QRect(110, 40, 641, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 81, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btnToClipboard = new QPushButton(groupBox);
        btnToClipboard->setObjectName(QString::fromUtf8("btnToClipboard"));
        btnToClipboard->setGeometry(QRect(764, 40, 81, 23));

        gridLayout->addWidget(groupBox, 2, 1, 1, 1);

        winHistory->setCentralWidget(centralwidget);
        menubar = new QMenuBar(winHistory);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1133, 21));
        winHistory->setMenuBar(menubar);
        statusbar = new QStatusBar(winHistory);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        winHistory->setStatusBar(statusbar);

        retranslateUi(winHistory);

        QMetaObject::connectSlotsByName(winHistory);
    } // setupUi

    void retranslateUi(QMainWindow *winHistory)
    {
        winHistory->setWindowTitle(QApplication::translate("winHistory", "ShiftPlanning Grabber - History", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tblHistory->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("winHistory", "Title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tblHistory->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("winHistory", "Desc", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tblHistory->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("winHistory", "Taken on", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tblHistory->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("winHistory", "URL", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("winHistory", "Search: ", 0, QApplication::UnicodeUTF8));
        btnClearAll->setText(QApplication::translate("winHistory", "Delete All History", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("winHistory", "Selected URL:", 0, QApplication::UnicodeUTF8));
        btnToClipboard->setText(QApplication::translate("winHistory", "to clipboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winHistory: public Ui_winHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINHISTORY_H

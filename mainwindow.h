#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>
#include <QLabel>
#include <QApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPixmap>
#include <QPen>
#include <QTimer>
#include <QImage>
#include "winnotliveback.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);

        WinNotLiveBack *winBck;
        bool backWinInited;
        bool stopPainting;
        void newScreenShot();
        void newScreenShot(bool NLive);
        void newScreenShot(int x, int y, int wd, int hd);
        void saveScreenshot();
        QString getMacAddress();
        void shootScreen();
        void shootScreen(int x, int y, int wd, int hd);
        void onShow();
        void onShowNLive();
        void paintEvent(QPaintEvent*);

        void keyPressEvent(QKeyEvent*);
        void mousePressEvent(QMouseEvent*);
        void mouseReleaseEvent(QMouseEvent*);
        void mouseMoveEvent(QMouseEvent*);
        void hideEvent(QHideEvent *eve);
        void MainWindowTest();
        QImage *fullScreen;

        int getMin(int, int);
        int getMax(int, int);
        QTimer *timer;
        bool instanceExist;
        bool nLive;
        bool nLivePost;
        int fullScrWidth;
        int fullScrHeight;
        int firstScreenWidth;
        int firstScreenHeight;

        void setScreenFullWidhtHeight();

        ~MainWindow();

    private:
        Ui::MainWindow *ui;

        QSize sizeDesktop;
        QPixmap originalPixmap;
        bool paint;
        QRect selectRect;

        QPoint selStartPoint;
        QPoint selEndPoint;
        int paintOffset;
        QTime *timm;
        QString nlPath;
        int sizeInfoS;
        int sizeInfoM;
        int sizeInfoL;


    protected slots:
        void getCoordonates( );
        void getCoordonatesRegion( );
        void repainter( );
        void getCoordonates( int, int, int, int );
        void attachGrabKeys();
signals:
        void finished();
        void canceled();



};

#endif // MAINWINDOW_H

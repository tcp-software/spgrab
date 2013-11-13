#ifndef OVERSCREEN_H
#define OVERSCREEN_H

#include <QWidget>
#include <QMouseEvent>
#include <QPixmap>
#include "worker.h"

class overScreen : public QWidget
{
    Q_OBJECT
    public:
        explicit overScreen(QWidget *parent = 0);

        void newScreenShot();
        void newScreenShot(int x, int y, int wd, int hd);
        void saveScreenshot();
        void shootScreen();
        void shootScreen(int x, int y, int wd, int hd);


        int getMin(int, int);
        Worker *thr;

        int fullScrWidth;
        int fullScrHeight;

        void setScreenFullWidhtHeight();


    protected:
        void paintEvent(QPaintEvent*);
        void mousePressEvent(QMouseEvent*);
        void mouseReleaseEvent(QMouseEvent*);
        void mouseMoveEvent(QMouseEvent*);

    protected slots:
        void getCoordonates( );
        void getCoordonatesRegion( );
        void getCoordonates( int, int, int, int );


    signals:
        void finished();


    private:

        QSize sizeDesktop;
        QPixmap originalPixmap;
        bool paint;
        QRect selectRect;

        QPoint selStartPoint;
        QPoint selEndPoint;

    
};

#endif // OVERSCREEN_H

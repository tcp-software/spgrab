#ifndef SSWINDOW_H
#define SSWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDesktopWidget>
#include <QLabel>
#include <QApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);

        void newScreenShot();
        void newScreenShot(int x, int y, int wd, int hd);
        void saveScreenshot();
        void shootScreen();
        void shootScreen(int x, int y, int wd, int hd);

        void paintEvent(QPaintEvent*);

        void mousePressEvent(QMouseEvent*);
        void mouseReleaseEvent(QMouseEvent*);
        void mouseMoveEvent(QMouseEvent*);

        int getMin(int, int);

        void setScreenFullWidhtHeight();

    private:
        Ui::MainWindow *ui;
        QSize sizeDesktop;
        QPixmap originalPixmap;

        QRect selectRect;

        QPoint selStartPoint;
        QPoint selEndPoint;
    public slots:
        void getCoordonates( int, int, int, int );

};

#endif // SSWINDOW_H

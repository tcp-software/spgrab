#ifndef WINNOTLIVEBACK_H
#define WINNOTLIVEBACK_H

#include <QWidget>
#include <QPaintEvent>
#include <QImage>
#include <QMainWindow>
#include <QApplication>
#include <QString>

namespace Ui {
class WinNotLiveBack;
}

class WinNotLiveBack : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WinNotLiveBack(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void pRepaint();
    void showBack(int width, int height);    
    void keyPressEvent(QKeyEvent*);
    QImage *fullScreen;
    QString nlPath;
    ~WinNotLiveBack();
    
private:
    Ui::WinNotLiveBack *ui;
};

#endif // WINNOTLIVEBACK_H

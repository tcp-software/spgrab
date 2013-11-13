#ifndef WINABOUTPROGRAM_H
#define WINABOUTPROGRAM_H

#include <QMainWindow>

namespace Ui {
class winAboutProgram;
}

class winAboutProgram : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit winAboutProgram(QWidget *parent = 0);
    void hideEvent(QHideEvent *eve);
    ~winAboutProgram();
    
private:
    Ui::winAboutProgram *ui;
};

#endif // WINABOUTPROGRAM_H

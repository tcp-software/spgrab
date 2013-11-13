#ifndef CAPTUREFULLSCREEN_H
#define CAPTUREFULLSCREEN_H

#include <QWidget>
#include <QSize>
#include <QString>
#include <QPixmap>

class captureFullScreen : public QWidget
{
    Q_OBJECT
public:
    explicit captureFullScreen(QWidget *parent = 0);
    void shootScreen(bool nl);
private:
    void saveScreenshot(QPixmap ss);

    
signals:
    void screenshotTakken();
public slots:
    
};

#endif // CAPTUREFULLSCREEN_H

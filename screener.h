#ifndef SCREENER_H
#define SCREENER_H

#include <QObject>
#include <QThread>

class Screener : public QThread{
    Q_OBJECT

protected:
    void run();

public slots:
    void sendCrds( );

signals:
    void sendCoords( );
};

#endif // SCREENER_H

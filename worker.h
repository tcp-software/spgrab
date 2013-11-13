#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QThread {
    Q_OBJECT

protected:
    void run();

public slots:
    void sendCrds( );
    void sendCrds( int, int, int, int );

signals:
    void sendCoords( );
    void sendCoords( int, int, int, int );
};

#endif // WORKER_H

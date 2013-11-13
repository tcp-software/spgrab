#include "worker.h"
#include <QDebug>
#include <QThread>
#include <QMutex>

int tmp;
QMutex sleepMutex;

void Worker::run(){

}

void Worker::sendCrds(){

    sleepMutex.lock();
    tmp = 0;

    while( !sleepMutex.tryLock(100) ){

        if( tmp > 0 ){
            sendCoords();
            sleepMutex.unlock();
            emit finished();
        }
        tmp++;
    }
    sleepMutex.unlock();
}
void Worker::sendCrds(int x, int y, int wd, int hd){

    sleepMutex.lock();
    tmp = 0;

    while( !sleepMutex.tryLock(1000) ){

        if( tmp > 0 ){
            sendCoords(x, y, wd, hd);
            emit finished();
            sleepMutex.unlock();
        }
        tmp++;
    }
    sleepMutex.unlock();


}



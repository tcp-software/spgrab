#include <QtGui>

#include "window.h"

int main(int argc, char *argv[]){

    Q_INIT_RESOURCE( systray );
    QApplication app( argc, argv );
    SPGrab window;
    window.raise();
    QApplication::setQuitOnLastWindowClosed(false);

    return app.exec();
}

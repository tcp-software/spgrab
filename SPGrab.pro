#-------------------------------------------------
#
# Project created by QtCreator 2012-06-13T12:16:31
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPGrab
TEMPLATE = app

CONFIG  += qxt
RC_FILE = myapp.rc
CONFIG += static
static {
    CONFIG += static
    DEFINES += STATIC
    message("Static build.")
}


QXT     += core gui

SOURCES += main.cpp\
        window.cpp \
    mainwindow.cpp \
    winsettings.cpp \
    winhistory.cpp \
    shortcut/3rdparty/qxt/src/core/qxtglobal.cpp \
    shortcut/3rdparty/qxt/src/gui/qxtglobalshortcut.cpp \
    winaboutprogram.cpp \
    winnotliveback.cpp \
    capturefullscreen.cpp \
    config.cpp \
    uploader.cpp


win32 {
    QMAKE_LFLAGS += -static -static-libgcc -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc
    CONFIG += win32
    SOURCES +=      shortcut/3rdparty/qxt/src/gui/qxtglobalshortcut_win.cpp
}
linux-g++ {
    CONFIG += x11
    SOURCES +=      shortcut/3rdparty/qxt/src/gui/qxtglobalshortcut_x11.cpp \
                    netwm/netwm.cpp
}
macx {
    SOURCES +=      shortcut/3rdparty/qxt/src/gui/qxtglobalshortcut_mac.cpp
}

HEADERS  += window.h \
    mainwindow.h \
    winsettings.h \
    winhistory.h \
    shortcut/3rdparty/qxt/include/QxtGui/QxtGlobalShortcut \
    shortcut/3rdparty/qxt/src/core/qxtglobal.h \
    shortcut/3rdparty/qxt/src/gui/qxtglobalshortcut_p.h \
    shortcut/3rdparty/qxt/src/gui/qxtglobalshortcut.h \
    winaboutprogram.h \
    winnotliveback.h \
    capturefullscreen.h \
    config.h \
    uploader.h

linux-g++ {
    HEADERS += netwm/netwm.h
}
FORMS    += \
    mainwindow.ui \
    winsettings.ui \
    winhistory.ui \
    winaboutprogram.ui \
    winnotliveback.ui

OTHER_FILES += \
    myapp.rc \
    images/spgrab.png \
    images/spgrab.ico


RESOURCES += \
    systray.qrc \


/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created: Tue Jan 29 12:21:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SPGrab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      25,    7,    7,    7, 0x0a,
      40,    7,    7,    7, 0x0a,
      59,    7,    7,    7, 0x0a,
      80,   74,    7,    7, 0x08,
     100,   93,    7,    7, 0x08,
     149,    7,    7,    7, 0x08,
     180,  163,    7,    7, 0x08,
     209,    7,    7,    7, 0x08,
     226,    7,    7,    7, 0x08,
     235,    7,    7,    7, 0x08,
     246,    7,    7,    7, 0x08,
     262,    7,    7,    7, 0x08,
     277,    7,    7,    7, 0x08,
     292,    7,    7,    7, 0x08,
     304,    7,    7,    7, 0x08,
     316,    7,    7,    7, 0x08,
     329,    7,    7,    7, 0x08,
     341,    7,    7,    7, 0x08,
     360,    7,    7,    7, 0x08,
     387,    7,    7,    7, 0x08,
     405,    7,    7,    7, 0x08,
     431,    7,    7,    7, 0x08,
     451,    7,    7,    7, 0x08,
     479,  473,    7,    7, 0x08,
     499,    7,    7,    7, 0x28,
     512,    7,    7,    7, 0x08,
     536,  529,    7,    7, 0x08,
     573,  557,    7,    7, 0x08,
     612,  602,    7,    7, 0x08,
     635,    7,    7,    7, 0x08,
     670,  649,    7,    7, 0x08,
     716,  712,    7,    7, 0x08,
     755,  744,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SPGrab[] = {
    "SPGrab\0\0getCoordinates()\0setShortcuts()\0"
    "disableShortcuts()\0systrayCheck()\0"
    "index\0setIcon(int)\0reason\0"
    "iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "showMessage()\0msgTitle,msgText\0"
    "showMessage(QString,QString)\0"
    "messageClicked()\0ssFull()\0ssRegion()\0"
    "ssRegionNLive()\0ssRegionDesc()\0"
    "ssGrabWindow()\0ssAboutMe()\0ssHistory()\0"
    "ssSettings()\0firstTime()\0screenShotTakken()\0"
    "screenShotTakingCanceled()\0getSettingsInfo()\0"
    "checkIniSettingsVersion()\0winSettingsClosed()\0"
    "connectOrDisconnect()\0fileN\0"
    "uploadFile(QString)\0uploadFile()\0"
    "cancelDownload()\0status\0ftpStateChanged(int)\0"
    "commandId,error\0ftpCommandFinished(int,bool)\0"
    "commandId\0ftpCommandStarted(int)\0"
    "ftpDone(bool)\0readBytes,totalBytes\0"
    "updateDataTransferProgress(qint64,qint64)\0"
    "val\0updateTrayIconProgress(int)\0"
    "newUrlPath\0updateClipBoard(QString)\0"
};

void SPGrab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SPGrab *_t = static_cast<SPGrab *>(_o);
        switch (_id) {
        case 0: _t->getCoordinates(); break;
        case 1: _t->setShortcuts(); break;
        case 2: _t->disableShortcuts(); break;
        case 3: _t->systrayCheck(); break;
        case 4: _t->setIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 6: _t->showMessage(); break;
        case 7: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->messageClicked(); break;
        case 9: _t->ssFull(); break;
        case 10: _t->ssRegion(); break;
        case 11: _t->ssRegionNLive(); break;
        case 12: _t->ssRegionDesc(); break;
        case 13: _t->ssGrabWindow(); break;
        case 14: _t->ssAboutMe(); break;
        case 15: _t->ssHistory(); break;
        case 16: _t->ssSettings(); break;
        case 17: _t->firstTime(); break;
        case 18: _t->screenShotTakken(); break;
        case 19: _t->screenShotTakingCanceled(); break;
        case 20: _t->getSettingsInfo(); break;
        case 21: _t->checkIniSettingsVersion(); break;
        case 22: _t->winSettingsClosed(); break;
        case 23: _t->connectOrDisconnect(); break;
        case 24: _t->uploadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->uploadFile(); break;
        case 26: _t->cancelDownload(); break;
        case 27: _t->ftpStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 29: _t->ftpCommandStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->ftpDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->updateDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 32: _t->updateTrayIconProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->updateClipBoard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SPGrab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SPGrab::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SPGrab,
      qt_meta_data_SPGrab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SPGrab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SPGrab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SPGrab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SPGrab))
        return static_cast<void*>(const_cast< SPGrab*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SPGrab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

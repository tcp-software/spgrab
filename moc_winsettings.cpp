/****************************************************************************
** Meta object code from reading C++ file 'winsettings.h'
**
** Created: Fri Dec 7 17:37:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "winsettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_winSettings[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      25,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   12,   12,   12, 0x08,
      57,   12,   12,   12, 0x08,
      82,   12,   12,   12, 0x08,
     111,   12,   12,   12, 0x08,
     140,   12,   12,   12, 0x08,
     169,  162,   12,   12, 0x08,
     198,   12,   12,   12, 0x08,
     227,   12,   12,   12, 0x08,
     256,   12,   12,   12, 0x08,
     282,   12,   12,   12, 0x08,
     310,   12,   12,   12, 0x08,
     344,  336,   12,   12, 0x08,
     373,  336,   12,   12, 0x08,
     405,  336,   12,   12, 0x08,
     440,  336,   12,   12, 0x08,
     467,  336,   12,   12, 0x08,
     497,  336,   12,   12, 0x08,
     522,  336,   12,   12, 0x08,
     555,   12,   12,   12, 0x08,
     576,   12,   12,   12, 0x08,
     599,   12,   12,   12, 0x08,
     625,   12,   12,   12, 0x08,
     658,   12,   12,   12, 0x08,
     690,   12,   12,   12, 0x08,
     725,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_winSettings[] = {
    "winSettings\0\0dataSaved()\0canceled()\0"
    "on_btnLoad_clicked()\0on_btnSaveData_clicked()\0"
    "on_btnShortcutArea_clicked()\0"
    "on_btnShortcutFull_clicked()\0"
    "connectOrDisconnect()\0,error\0"
    "ftpCommandFinished(int,bool)\0"
    "on_btnShortcutDesc_clicked()\0"
    "on_btnBrowseFolder_clicked()\0"
    "on_btnResetFull_clicked()\0"
    "on_btnResetRegion_clicked()\0"
    "on_btnResetDesc_clicked()\0checked\0"
    "on_chkToFolder_toggled(bool)\0"
    "on_chkToClipboard_toggled(bool)\0"
    "on_chkImgToClipboard_toggled(bool)\0"
    "on_optSPGrab_toggled(bool)\0"
    "on_optCustomFtp_toggled(bool)\0"
    "on_optNone_toggled(bool)\0"
    "on_chkDisableSKeys_toggled(bool)\0"
    "on_btnTest_clicked()\0on_optSPGrab_clicked()\0"
    "on_optCustomFtp_clicked()\0"
    "on_btnShortcutAreaLive_clicked()\0"
    "on_btnResetRegionLive_clicked()\0"
    "on_btnShortcutGrabWindow_clicked()\0"
    "on_btnResetGrabWindow_clicked()\0"
};

void winSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        winSettings *_t = static_cast<winSettings *>(_o);
        switch (_id) {
        case 0: _t->dataSaved(); break;
        case 1: _t->canceled(); break;
        case 2: _t->on_btnLoad_clicked(); break;
        case 3: _t->on_btnSaveData_clicked(); break;
        case 4: _t->on_btnShortcutArea_clicked(); break;
        case 5: _t->on_btnShortcutFull_clicked(); break;
        case 6: _t->connectOrDisconnect(); break;
        case 7: _t->ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->on_btnShortcutDesc_clicked(); break;
        case 9: _t->on_btnBrowseFolder_clicked(); break;
        case 10: _t->on_btnResetFull_clicked(); break;
        case 11: _t->on_btnResetRegion_clicked(); break;
        case 12: _t->on_btnResetDesc_clicked(); break;
        case 13: _t->on_chkToFolder_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_chkToClipboard_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_chkImgToClipboard_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_optSPGrab_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_optCustomFtp_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_optNone_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_chkDisableSKeys_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_btnTest_clicked(); break;
        case 21: _t->on_optSPGrab_clicked(); break;
        case 22: _t->on_optCustomFtp_clicked(); break;
        case 23: _t->on_btnShortcutAreaLive_clicked(); break;
        case 24: _t->on_btnResetRegionLive_clicked(); break;
        case 25: _t->on_btnShortcutGrabWindow_clicked(); break;
        case 26: _t->on_btnResetGrabWindow_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData winSettings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject winSettings::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_winSettings,
      qt_meta_data_winSettings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &winSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *winSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *winSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_winSettings))
        return static_cast<void*>(const_cast< winSettings*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int winSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void winSettings::dataSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void winSettings::canceled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

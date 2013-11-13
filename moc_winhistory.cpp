/****************************************************************************
** Meta object code from reading C++ file 'winhistory.h'
**
** Created: Fri Dec 7 17:37:53 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "winhistory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winhistory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_winHistory[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x08,
      47,   42,   11,   11, 0x08,
      92,   81,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     158,  152,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_winHistory[] = {
    "winHistory\0\0hotkeyPressed()\0refreshList()\0"
    "arg1\0on_txtSearch_textChanged(QString)\0"
    "row,column\0on_tblHistory_cellClicked(int,int)\0"
    "on_btnClearAll_clicked()\0index\0"
    "on_tblHistory_activated(QModelIndex)\0"
    "on_btnToClipboard_clicked()\0"
};

void winHistory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        winHistory *_t = static_cast<winHistory *>(_o);
        switch (_id) {
        case 0: _t->hotkeyPressed(); break;
        case 1: _t->refreshList(); break;
        case 2: _t->on_txtSearch_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_tblHistory_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_btnClearAll_clicked(); break;
        case 5: _t->on_tblHistory_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_btnToClipboard_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData winHistory::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject winHistory::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_winHistory,
      qt_meta_data_winHistory, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &winHistory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *winHistory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *winHistory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_winHistory))
        return static_cast<void*>(const_cast< winHistory*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int winHistory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

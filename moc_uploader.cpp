/****************************************************************************
** Meta object code from reading C++ file 'uploader.h'
**
** Created: Fri Jan 18 14:34:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "uploader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uploader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Uploader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,
      53,   42,    9,    9, 0x05,
      78,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,    9,    9,    9, 0x08,
     110,  103,    9,    9, 0x08,
     147,  131,    9,    9, 0x08,
     197,  176,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Uploader[] = {
    "Uploader\0\0val\0updateTrayIconProgress(int)\0"
    "newUrlPath\0updateClipBoard(QString)\0"
    "showMessage()\0goUpload()\0status\0"
    "ftpStateChanged(int)\0commandId,error\0"
    "ftpCommandFinished(int,bool)\0"
    "readBytes,totalBytes\0"
    "updateDataTransferProgress(qint64,qint64)\0"
};

void Uploader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Uploader *_t = static_cast<Uploader *>(_o);
        switch (_id) {
        case 0: _t->updateTrayIconProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateClipBoard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->showMessage(); break;
        case 3: _t->goUpload(); break;
        case 4: _t->ftpStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->updateDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Uploader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Uploader::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Uploader,
      qt_meta_data_Uploader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Uploader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Uploader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Uploader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uploader))
        return static_cast<void*>(const_cast< Uploader*>(this));
    return QThread::qt_metacast(_clname);
}

int Uploader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Uploader::updateTrayIconProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Uploader::updateClipBoard(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Uploader::showMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

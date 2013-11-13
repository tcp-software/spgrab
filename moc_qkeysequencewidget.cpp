/****************************************************************************
** Meta object code from reading C++ file 'qkeysequencewidget.h'
**
** Created: Mon Jun 18 18:06:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qkeysequencewidget/src/qkeysequencewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qkeysequencewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QKeySequenceWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       4,   69, // properties
       1,   81, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   20,   19,   19, 0x05,
      57,   20,   19,   19, 0x05,
      91,   19,   19,   19, 0x05,
     112,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     130,   19,   19,   19, 0x08,
     150,  146,   19,   19, 0x0a,
     179,   19,   19,   19, 0x0a,
     203,  198,   19,   19, 0x0a,
     229,  224,   19,   19, 0x0a,
     260,  255,   19,   19, 0x0a,
     316,   19,   19,   19, 0x0a,

 // properties: name, type, flags
     350,  337, 0x4c095103,
     398,  362, 0x0009500b,
     418,  410, 0x0a095103,
     433,  427, 0x45095103,

 // enums: name, flags, count, data
     449, 0x1,    3,   85,

 // enum data: key, value
     465, uint(QKeySequenceWidget::NoShow),
     472, uint(QKeySequenceWidget::ShowLeft),
     481, uint(QKeySequenceWidget::ShowRight),

       0        // eod
};

static const char qt_meta_stringdata_QKeySequenceWidget[] = {
    "QKeySequenceWidget\0\0seq\0"
    "keySequenceChanged(QKeySequence)\0"
    "keySequenceAccepted(QKeySequence)\0"
    "keySequenceCleared()\0keyNotSupported()\0"
    "doneRecording()\0key\0setKeySequence(QKeySequence)\0"
    "clearKeySequence()\0text\0setNoneText(QString)\0"
    "icon\0setClearButtonIcon(QIcon)\0show\0"
    "setClearButtonShow(QKeySequenceWidget::ClearButtonShow)\0"
    "captureKeySequence()\0QKeySequence\0"
    "keySequence\0QKeySequenceWidget::ClearButtonShow\0"
    "clearButton\0QString\0noneText\0QIcon\0"
    "clearButtonIcon\0ClearButtonShow\0NoShow\0"
    "ShowLeft\0ShowRight\0"
};

void QKeySequenceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QKeySequenceWidget *_t = static_cast<QKeySequenceWidget *>(_o);
        switch (_id) {
        case 0: _t->keySequenceChanged((*reinterpret_cast< const QKeySequence(*)>(_a[1]))); break;
        case 1: _t->keySequenceAccepted((*reinterpret_cast< const QKeySequence(*)>(_a[1]))); break;
        case 2: _t->keySequenceCleared(); break;
        case 3: _t->keyNotSupported(); break;
        case 4: _t->d_func()->doneRecording(); break;
        case 5: _t->setKeySequence((*reinterpret_cast< const QKeySequence(*)>(_a[1]))); break;
        case 6: _t->clearKeySequence(); break;
        case 7: _t->setNoneText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setClearButtonIcon((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 9: _t->setClearButtonShow((*reinterpret_cast< QKeySequenceWidget::ClearButtonShow(*)>(_a[1]))); break;
        case 10: _t->captureKeySequence(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QKeySequenceWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QKeySequenceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QKeySequenceWidget,
      qt_meta_data_QKeySequenceWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QKeySequenceWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QKeySequenceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QKeySequenceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QKeySequenceWidget))
        return static_cast<void*>(const_cast< QKeySequenceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QKeySequenceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QKeySequence*>(_v) = keySequence(); break;
        case 1: *reinterpret_cast< QKeySequenceWidget::ClearButtonShow*>(_v) = clearButtonShow(); break;
        case 2: *reinterpret_cast< QString*>(_v) = noneText(); break;
        case 3: *reinterpret_cast< QIcon*>(_v) = clearButtonIcon(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setKeySequence(*reinterpret_cast< QKeySequence*>(_v)); break;
        case 1: setClearButtonShow(*reinterpret_cast< QKeySequenceWidget::ClearButtonShow*>(_v)); break;
        case 2: setNoneText(*reinterpret_cast< QString*>(_v)); break;
        case 3: setClearButtonIcon(*reinterpret_cast< QIcon*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QKeySequenceWidget::keySequenceChanged(const QKeySequence & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QKeySequenceWidget::keySequenceAccepted(const QKeySequence & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QKeySequenceWidget::keySequenceCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QKeySequenceWidget::keyNotSupported()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE

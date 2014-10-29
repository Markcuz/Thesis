/****************************************************************************
** Meta object code from reading C++ file 'debuglogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/debuglogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debuglogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DebugLogger_t {
    QByteArrayData data[11];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DebugLogger_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DebugLogger_t qt_meta_stringdata_DebugLogger = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 10),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 3),
QT_MOC_LITERAL(4, 28, 8),
QT_MOC_LITERAL(5, 37, 9),
QT_MOC_LITERAL(6, 47, 6),
QT_MOC_LITERAL(7, 54, 9),
QT_MOC_LITERAL(8, 64, 6),
QT_MOC_LITERAL(9, 71, 7),
QT_MOC_LITERAL(10, 79, 11)
    },
    "DebugLogger\0displayMsg\0\0msg\0debugMsg\0"
    "QtMsgType\0logMsg\0warnLevel\0source\0"
    "newLine\0nameChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DebugLogger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    3,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x0a /* Public */,
       6,    2,   62,    2, 0x0a /* Public */,
       6,    3,   67,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,    7,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    7,    8,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DebugLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DebugLogger *_t = static_cast<DebugLogger *>(_o);
        switch (_id) {
        case 0: _t->displayMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->debugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->logMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->logMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->logMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->newLine(); break;
        case 6: _t->nameChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DebugLogger::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DebugLogger::displayMsg)) {
                *result = 0;
            }
        }
        {
            typedef void (DebugLogger::*_t)(QtMsgType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DebugLogger::debugMsg)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DebugLogger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DebugLogger.data,
      qt_meta_data_DebugLogger,  qt_static_metacall, 0, 0}
};


const QMetaObject *DebugLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DebugLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DebugLogger.stringdata))
        return static_cast<void*>(const_cast< DebugLogger*>(this));
    return QObject::qt_metacast(_clname);
}

int DebugLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DebugLogger::displayMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DebugLogger::debugMsg(QtMsgType _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'engine_port.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/engine_port.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine_port.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_engine_port_t {
    QByteArrayData data[15];
    char stringdata[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_engine_port_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_engine_port_t qt_meta_stringdata_engine_port = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 8),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 9),
QT_MOC_LITERAL(4, 32, 5),
QT_MOC_LITERAL(5, 38, 8),
QT_MOC_LITERAL(6, 47, 8),
QT_MOC_LITERAL(7, 56, 8),
QT_MOC_LITERAL(8, 65, 8),
QT_MOC_LITERAL(9, 74, 4),
QT_MOC_LITERAL(10, 79, 7),
QT_MOC_LITERAL(11, 87, 5),
QT_MOC_LITERAL(12, 93, 5),
QT_MOC_LITERAL(13, 99, 9),
QT_MOC_LITERAL(14, 109, 7)
    },
    "engine_port\0debugMsg\0\0QtMsgType\0ready\0"
    "finished\0checkRun\0checkRPM\0clicking\0"
    "init\0runSimu\0click\0close\0volEffect\0"
    "lowBatt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_engine_port[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   88,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void engine_port::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        engine_port *_t = static_cast<engine_port *>(_o);
        switch (_id) {
        case 0: _t->debugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->ready(); break;
        case 2: _t->finished(); break;
        case 3: _t->checkRun(); break;
        case 4: _t->checkRPM(); break;
        case 5: _t->clicking((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->init(); break;
        case 7: _t->runSimu(); break;
        case 8: _t->click(); break;
        case 9: _t->close(); break;
        case 10: _t->volEffect(); break;
        case 11: _t->lowBatt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtMsgType >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (engine_port::*_t)(QtMsgType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine_port::debugMsg)) {
                *result = 0;
            }
        }
        {
            typedef void (engine_port::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine_port::ready)) {
                *result = 1;
            }
        }
        {
            typedef void (engine_port::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine_port::finished)) {
                *result = 2;
            }
        }
        {
            typedef void (engine_port::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine_port::checkRun)) {
                *result = 3;
            }
        }
        {
            typedef void (engine_port::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine_port::checkRPM)) {
                *result = 4;
            }
        }
        {
            typedef void (engine_port::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine_port::clicking)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject engine_port::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_engine_port.data,
      qt_meta_data_engine_port,  qt_static_metacall, 0, 0}
};


const QMetaObject *engine_port::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *engine_port::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_engine_port.stringdata))
        return static_cast<void*>(const_cast< engine_port*>(this));
    return QObject::qt_metacast(_clname);
}

int engine_port::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void engine_port::debugMsg(QtMsgType _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void engine_port::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void engine_port::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void engine_port::checkRun()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void engine_port::checkRPM()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void engine_port::clicking(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

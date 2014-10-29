/****************************************************************************
** Meta object code from reading C++ file 'logger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/logger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Logger_t {
    QByteArrayData data[25];
    char stringdata[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Logger_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Logger_t qt_meta_stringdata_Logger = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 7),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 8),
QT_MOC_LITERAL(4, 25, 8),
QT_MOC_LITERAL(5, 34, 9),
QT_MOC_LITERAL(6, 44, 9),
QT_MOC_LITERAL(7, 54, 8),
QT_MOC_LITERAL(8, 63, 18),
QT_MOC_LITERAL(9, 82, 12),
QT_MOC_LITERAL(10, 95, 11),
QT_MOC_LITERAL(11, 107, 14),
QT_MOC_LITERAL(12, 122, 12),
QT_MOC_LITERAL(13, 135, 12),
QT_MOC_LITERAL(14, 148, 13),
QT_MOC_LITERAL(15, 162, 11),
QT_MOC_LITERAL(16, 174, 11),
QT_MOC_LITERAL(17, 186, 8),
QT_MOC_LITERAL(18, 195, 6),
QT_MOC_LITERAL(19, 202, 6),
QT_MOC_LITERAL(20, 209, 7),
QT_MOC_LITERAL(21, 217, 11),
QT_MOC_LITERAL(22, 229, 12),
QT_MOC_LITERAL(23, 242, 5),
QT_MOC_LITERAL(24, 248, 6)
    },
    "Logger\0updated\0\0TripData\0debugMsg\0"
    "QtMsgType\0isLogging\0isPaused\0"
    "setDefaultSettings\0startLogging\0"
    "stopLogging\0updatePosition\0PositionData\0"
    "positionData\0updateBattery\0BatteryData\0"
    "batteryData\0updateIO\0IOData\0ioData\0"
    "logData\0nameChanged\0checkDirSize\0char*\0"
    "logDir\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x05,
       4,    3,   82,    2, 0x05,
       6,    1,   89,    2, 0x05,
       7,    1,   92,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,   95,    2, 0x0a,
       9,    0,   96,    2, 0x0a,
      10,    0,   97,    2, 0x0a,
      11,    1,   98,    2, 0x0a,
      14,    1,  101,    2, 0x0a,
      17,    1,  104,    2, 0x0a,
      20,    0,  107,    2, 0x0a,
      21,    0,  108,    2, 0x0a,
      22,    1,  109,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 23,   24,

       0        // eod
};

void Logger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Logger *_t = static_cast<Logger *>(_o);
        switch (_id) {
        case 0: _t->updated((*reinterpret_cast< TripData(*)>(_a[1]))); break;
        case 1: _t->debugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->isLogging((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->isPaused((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setDefaultSettings(); break;
        case 5: _t->startLogging(); break;
        case 6: _t->stopLogging(); break;
        case 7: _t->updatePosition((*reinterpret_cast< PositionData(*)>(_a[1]))); break;
        case 8: _t->updateBattery((*reinterpret_cast< BatteryData(*)>(_a[1]))); break;
        case 9: _t->updateIO((*reinterpret_cast< IOData(*)>(_a[1]))); break;
        case 10: _t->logData(); break;
        case 11: _t->nameChanged(); break;
        case 12: { bool _r = _t->checkDirSize((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Logger::*_t)(TripData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Logger::updated)) {
                *result = 0;
            }
        }
        {
            typedef void (Logger::*_t)(QtMsgType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Logger::debugMsg)) {
                *result = 1;
            }
        }
        {
            typedef void (Logger::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Logger::isLogging)) {
                *result = 2;
            }
        }
        {
            typedef void (Logger::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Logger::isPaused)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Logger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Logger.data,
      qt_meta_data_Logger,  qt_static_metacall, 0, 0}
};


const QMetaObject *Logger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Logger.stringdata))
        return static_cast<void*>(const_cast< Logger*>(this));
    return QObject::qt_metacast(_clname);
}

int Logger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Logger::updated(TripData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Logger::debugMsg(QtMsgType _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Logger::isLogging(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Logger::isPaused(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'battery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/battery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BMS_t {
    QByteArrayData data[17];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_BMS_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_BMS_t qt_meta_stringdata_BMS = {
    {
QT_MOC_LITERAL(0, 0, 3),
QT_MOC_LITERAL(1, 4, 7),
QT_MOC_LITERAL(2, 12, 0),
QT_MOC_LITERAL(3, 13, 11),
QT_MOC_LITERAL(4, 25, 8),
QT_MOC_LITERAL(5, 34, 9),
QT_MOC_LITERAL(6, 44, 5),
QT_MOC_LITERAL(7, 50, 4),
QT_MOC_LITERAL(8, 55, 3),
QT_MOC_LITERAL(9, 59, 18),
QT_MOC_LITERAL(10, 78, 14),
QT_MOC_LITERAL(11, 93, 12),
QT_MOC_LITERAL(12, 106, 18),
QT_MOC_LITERAL(13, 125, 13),
QT_MOC_LITERAL(14, 139, 11),
QT_MOC_LITERAL(15, 151, 8),
QT_MOC_LITERAL(16, 160, 6)
    },
    "BMS\0updated\0\0BatteryData\0debugMsg\0"
    "QtMsgType\0error\0init\0end\0setDefaultSettings\0"
    "displayRawData\0saveCommands\0"
    "parseBatteryString\0batteryString\0"
    "bms_connect\0portName\0update\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BMS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x05,
       4,    3,   77,    2, 0x05,
       6,    1,   84,    2, 0x05,
       6,    1,   87,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    0,   90,    2, 0x0a,
       8,    0,   91,    2, 0x0a,
       9,    0,   92,    2, 0x0a,
      10,    1,   93,    2, 0x0a,
      11,    1,   96,    2, 0x0a,
      12,    1,   99,    2, 0x08,
      14,    1,  102,    2, 0x08,
      16,    0,  105,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool, QMetaType::QString,   13,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Void,

       0        // eod
};

void BMS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BMS *_t = static_cast<BMS *>(_o);
        switch (_id) {
        case 0: _t->updated((*reinterpret_cast< BatteryData(*)>(_a[1]))); break;
        case 1: _t->debugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->error((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->end(); break;
        case 6: _t->setDefaultSettings(); break;
        case 7: _t->displayRawData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->saveCommands((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: { bool _r = _t->parseBatteryString((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->bms_connect((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BMS::*_t)(BatteryData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BMS::updated)) {
                *result = 0;
            }
        }
        {
            typedef void (BMS::*_t)(QtMsgType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BMS::debugMsg)) {
                *result = 1;
            }
        }
        {
            typedef void (BMS::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BMS::error)) {
                *result = 2;
            }
        }
        {
            typedef void (BMS::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BMS::error)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject BMS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BMS.data,
      qt_meta_data_BMS,  qt_static_metacall, 0, 0}
};


const QMetaObject *BMS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BMS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BMS.stringdata))
        return static_cast<void*>(const_cast< BMS*>(this));
    return QObject::qt_metacast(_clname);
}

int BMS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void BMS::updated(BatteryData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BMS::debugMsg(QtMsgType _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BMS::error(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BMS::error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

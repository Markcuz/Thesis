/****************************************************************************
** Meta object code from reading C++ file 'media.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mediaTest/media.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'media.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Media_t {
    QByteArrayData data[14];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Media_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Media_t qt_meta_stringdata_Media = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 4),
QT_MOC_LITERAL(2, 11, 0),
QT_MOC_LITERAL(3, 12, 4),
QT_MOC_LITERAL(4, 17, 5),
QT_MOC_LITERAL(5, 23, 4),
QT_MOC_LITERAL(6, 28, 4),
QT_MOC_LITERAL(7, 33, 4),
QT_MOC_LITERAL(8, 38, 3),
QT_MOC_LITERAL(9, 42, 8),
QT_MOC_LITERAL(10, 51, 6),
QT_MOC_LITERAL(11, 58, 7),
QT_MOC_LITERAL(12, 66, 4),
QT_MOC_LITERAL(13, 71, 5)
    },
    "Media\0init\0\0play\0pause\0stop\0next\0prev\0"
    "add\0pathName\0remove\0shuffle\0read\0write\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Media[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a,
       3,    0,   70,    2, 0x0a,
       4,    0,   71,    2, 0x0a,
       5,    0,   72,    2, 0x0a,
       6,    0,   73,    2, 0x0a,
       7,    0,   74,    2, 0x0a,
       8,    1,   75,    2, 0x0a,
      10,    0,   78,    2, 0x0a,
      11,    0,   79,    2, 0x0a,
      12,    0,   80,    2, 0x08,
      13,    0,   81,    2, 0x08,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Media::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Media *_t = static_cast<Media *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->play(); break;
        case 2: _t->pause(); break;
        case 3: _t->stop(); break;
        case 4: _t->next(); break;
        case 5: _t->prev(); break;
        case 6: _t->add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->remove(); break;
        case 8: _t->shuffle(); break;
        case 9: _t->read(); break;
        case 10: _t->write(); break;
        default: ;
        }
    }
}

const QMetaObject Media::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Media.data,
      qt_meta_data_Media,  qt_static_metacall, 0, 0}
};


const QMetaObject *Media::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Media::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Media.stringdata))
        return static_cast<void*>(const_cast< Media*>(this));
    return QObject::qt_metacast(_clname);
}

int Media::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

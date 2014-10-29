/****************************************************************************
** Meta object code from reading C++ file 'media.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/media.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'media.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Media_t {
    QByteArrayData data[26];
    char stringdata[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Media_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Media_t qt_meta_stringdata_Media = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 9),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 8),
QT_MOC_LITERAL(4, 26, 16),
QT_MOC_LITERAL(5, 43, 11),
QT_MOC_LITERAL(6, 55, 13),
QT_MOC_LITERAL(7, 69, 4),
QT_MOC_LITERAL(8, 74, 4),
QT_MOC_LITERAL(9, 79, 5),
QT_MOC_LITERAL(10, 85, 4),
QT_MOC_LITERAL(11, 90, 4),
QT_MOC_LITERAL(12, 95, 4),
QT_MOC_LITERAL(13, 100, 3),
QT_MOC_LITERAL(14, 104, 8),
QT_MOC_LITERAL(15, 113, 6),
QT_MOC_LITERAL(16, 120, 5),
QT_MOC_LITERAL(17, 126, 9),
QT_MOC_LITERAL(18, 136, 11),
QT_MOC_LITERAL(19, 148, 3),
QT_MOC_LITERAL(20, 152, 9),
QT_MOC_LITERAL(21, 162, 7),
QT_MOC_LITERAL(22, 170, 9),
QT_MOC_LITERAL(23, 180, 5),
QT_MOC_LITERAL(24, 186, 4),
QT_MOC_LITERAL(25, 191, 5)
    },
    "Media\0isPlaying\0\0selected\0mediaListUpdated\0"
    "songChanged\0artistChanged\0init\0play\0"
    "pause\0stop\0next\0prev\0add\0pathName\0"
    "remove\0index\0mediaList\0getSongName\0"
    "raw\0getArtist\0getData\0removeAll\0start\0"
    "read\0write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Media[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       3,    1,  122,    2, 0x06 /* Public */,
       4,    0,  125,    2, 0x06 /* Public */,
       5,    0,  126,    2, 0x06 /* Public */,
       6,    0,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  128,    2, 0x0a /* Public */,
       8,    0,  129,    2, 0x0a /* Public */,
       9,    0,  130,    2, 0x0a /* Public */,
      10,    0,  131,    2, 0x0a /* Public */,
      11,    0,  132,    2, 0x0a /* Public */,
      12,    0,  133,    2, 0x0a /* Public */,
      13,    1,  134,    2, 0x0a /* Public */,
      15,    1,  137,    2, 0x0a /* Public */,
      17,    0,  140,    2, 0x0a /* Public */,
      18,    1,  141,    2, 0x0a /* Public */,
      20,    1,  144,    2, 0x0a /* Public */,
      21,    0,  147,    2, 0x0a /* Public */,
      22,    0,  148,    2, 0x0a /* Public */,
      23,    0,  149,    2, 0x0a /* Public */,
      24,    0,  150,    2, 0x08 /* Private */,
      25,    0,  151,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::QStringList,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::Void,
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
        case 0: _t->isPlaying((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->selected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mediaListUpdated(); break;
        case 3: _t->songChanged(); break;
        case 4: _t->artistChanged(); break;
        case 5: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->play(); break;
        case 7: _t->pause(); break;
        case 8: _t->stop(); break;
        case 9: _t->next(); break;
        case 10: _t->prev(); break;
        case 11: _t->add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: { QStringList _r = _t->mediaList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 14: { QString _r = _t->getSongName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = _t->getArtist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: _t->getData(); break;
        case 17: _t->removeAll(); break;
        case 18: _t->start(); break;
        case 19: _t->read(); break;
        case 20: _t->write(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Media::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Media::isPlaying)) {
                *result = 0;
            }
        }
        {
            typedef void (Media::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Media::selected)) {
                *result = 1;
            }
        }
        {
            typedef void (Media::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Media::mediaListUpdated)) {
                *result = 2;
            }
        }
        {
            typedef void (Media::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Media::songChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (Media::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Media::artistChanged)) {
                *result = 4;
            }
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Media::isPlaying(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Media::selected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Media::mediaListUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Media::songChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Media::artistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE

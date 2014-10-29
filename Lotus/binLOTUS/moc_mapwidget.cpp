/****************************************************************************
** Meta object code from reading C++ file 'mapwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mapwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SlippyMap_t {
    QByteArrayData data[30];
    char stringdata[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SlippyMap_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SlippyMap_t qt_meta_stringdata_SlippyMap = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 7),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 4),
QT_MOC_LITERAL(4, 24, 8),
QT_MOC_LITERAL(5, 33, 9),
QT_MOC_LITERAL(6, 43, 12),
QT_MOC_LITERAL(7, 56, 12),
QT_MOC_LITERAL(8, 69, 18),
QT_MOC_LITERAL(9, 88, 6),
QT_MOC_LITERAL(10, 95, 7),
QT_MOC_LITERAL(11, 103, 7),
QT_MOC_LITERAL(12, 111, 4),
QT_MOC_LITERAL(13, 116, 9),
QT_MOC_LITERAL(14, 126, 3),
QT_MOC_LITERAL(15, 130, 3),
QT_MOC_LITERAL(16, 134, 3),
QT_MOC_LITERAL(17, 138, 5),
QT_MOC_LITERAL(18, 144, 6),
QT_MOC_LITERAL(19, 151, 9),
QT_MOC_LITERAL(20, 161, 1),
QT_MOC_LITERAL(21, 163, 6),
QT_MOC_LITERAL(22, 170, 5),
QT_MOC_LITERAL(23, 176, 6),
QT_MOC_LITERAL(24, 183, 18),
QT_MOC_LITERAL(25, 202, 5),
QT_MOC_LITERAL(26, 208, 5),
QT_MOC_LITERAL(27, 214, 17),
QT_MOC_LITERAL(28, 232, 14),
QT_MOC_LITERAL(29, 247, 5)
    },
    "SlippyMap\0updated\0\0rect\0debugMsg\0"
    "QtMsgType\0loadSettings\0saveSettings\0"
    "setDefaultSettings\0zoomIn\0zoomOut\0"
    "setZoom\0zoom\0setCenter\0lat\0lng\0pan\0"
    "delta\0render\0QPainter*\0p\0resize\0width\0"
    "height\0pixelForCoordinate\0myLat\0myLng\0"
    "handleNetworkData\0QNetworkReply*\0reply\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlippyMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x05,
       4,    3,   87,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   94,    2, 0x0a,
       7,    0,   95,    2, 0x0a,
       8,    0,   96,    2, 0x0a,
       9,    0,   97,    2, 0x0a,
      10,    0,   98,    2, 0x0a,
      11,    1,   99,    2, 0x0a,
      13,    2,  102,    2, 0x0a,
      16,    1,  107,    2, 0x0a,
      18,    2,  110,    2, 0x0a,
      21,    2,  115,    2, 0x0a,
      24,    2,  120,    2, 0x0a,
      27,    1,  125,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QRect,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   14,   15,
    QMetaType::Void, QMetaType::QPoint,   17,
    QMetaType::Void, 0x80000000 | 19, QMetaType::QRect,   20,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,
    QMetaType::QPointF, QMetaType::QReal, QMetaType::QReal,   25,   26,
    QMetaType::Void, 0x80000000 | 28,   29,

       0        // eod
};

void SlippyMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SlippyMap *_t = static_cast<SlippyMap *>(_o);
        switch (_id) {
        case 0: _t->updated((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 1: _t->debugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->loadSettings(); break;
        case 3: _t->saveSettings(); break;
        case 4: _t->setDefaultSettings(); break;
        case 5: _t->zoomIn(); break;
        case 6: _t->zoomOut(); break;
        case 7: _t->setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCenter((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 9: _t->pan((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->render((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2]))); break;
        case 11: _t->resize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: { QPointF _r = _t->pixelForCoordinate((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = _r; }  break;
        case 13: _t->handleNetworkData((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SlippyMap::*_t)(const QRect & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SlippyMap::updated)) {
                *result = 0;
            }
        }
        {
            typedef void (SlippyMap::*_t)(QtMsgType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SlippyMap::debugMsg)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SlippyMap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SlippyMap.data,
      qt_meta_data_SlippyMap,  qt_static_metacall, 0, 0}
};


const QMetaObject *SlippyMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlippyMap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlippyMap.stringdata))
        return static_cast<void*>(const_cast< SlippyMap*>(this));
    return QObject::qt_metacast(_clname);
}

int SlippyMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void SlippyMap::updated(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SlippyMap::debugMsg(QtMsgType _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_MapWidget_t {
    QByteArrayData data[39];
    char stringdata[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MapWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MapWidget_t qt_meta_stringdata_MapWidget = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 8),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 9),
QT_MOC_LITERAL(4, 30, 12),
QT_MOC_LITERAL(5, 43, 12),
QT_MOC_LITERAL(6, 56, 18),
QT_MOC_LITERAL(7, 75, 6),
QT_MOC_LITERAL(8, 82, 7),
QT_MOC_LITERAL(9, 90, 9),
QT_MOC_LITERAL(10, 100, 3),
QT_MOC_LITERAL(11, 104, 3),
QT_MOC_LITERAL(12, 108, 8),
QT_MOC_LITERAL(13, 117, 3),
QT_MOC_LITERAL(14, 121, 11),
QT_MOC_LITERAL(15, 133, 8),
QT_MOC_LITERAL(16, 142, 15),
QT_MOC_LITERAL(17, 158, 11),
QT_MOC_LITERAL(18, 170, 14),
QT_MOC_LITERAL(19, 185, 13),
QT_MOC_LITERAL(20, 199, 16),
QT_MOC_LITERAL(21, 216, 21),
QT_MOC_LITERAL(22, 238, 20),
QT_MOC_LITERAL(23, 259, 10),
QT_MOC_LITERAL(24, 270, 11),
QT_MOC_LITERAL(25, 282, 16),
QT_MOC_LITERAL(26, 299, 18),
QT_MOC_LITERAL(27, 318, 26),
QT_MOC_LITERAL(28, 345, 9),
QT_MOC_LITERAL(29, 355, 9),
QT_MOC_LITERAL(30, 365, 12),
QT_MOC_LITERAL(31, 378, 9),
QT_MOC_LITERAL(32, 388, 1),
QT_MOC_LITERAL(33, 390, 9),
QT_MOC_LITERAL(34, 400, 5),
QT_MOC_LITERAL(35, 406, 15),
QT_MOC_LITERAL(36, 422, 9),
QT_MOC_LITERAL(37, 432, 6),
QT_MOC_LITERAL(38, 439, 3)
    },
    "MapWidget\0debugMsg\0\0QtMsgType\0"
    "loadSettings\0saveSettings\0setDefaultSettings\0"
    "zoomIn\0zoomOut\0setCenter\0lat\0lng\0"
    "setMyPos\0dir\0setCentered\0centered\0"
    "toggleNightMode\0showMyTrack\0myTrackVisible\0"
    "showTestTrack\0testTrackVisible\0"
    "showTestTrackComments\0testTrackCmtsVisible\0"
    "isCentered\0isNightmode\0isVisibleMyTrack\0"
    "isVisibleTestTrack\0isVisibleTestTrackComments\0"
    "loadTrack\0trackFile\0getTrackFile\0"
    "updateMap\0r\0isVisible\0point\0forwardDebugMsg\0"
    "warnLevel\0source\0msg\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  129,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,  136,    2, 0x0a,
       5,    0,  137,    2, 0x0a,
       6,    0,  138,    2, 0x0a,
       7,    0,  139,    2, 0x0a,
       8,    0,  140,    2, 0x0a,
       9,    2,  141,    2, 0x0a,
      12,    3,  146,    2, 0x0a,
      14,    1,  153,    2, 0x0a,
      16,    0,  156,    2, 0x0a,
      17,    1,  157,    2, 0x0a,
      19,    1,  160,    2, 0x0a,
      21,    1,  163,    2, 0x0a,
      23,    0,  166,    2, 0x0a,
      24,    0,  167,    2, 0x0a,
      25,    0,  168,    2, 0x0a,
      26,    0,  169,    2, 0x0a,
      27,    0,  170,    2, 0x0a,
      28,    1,  171,    2, 0x0a,
      30,    0,  174,    2, 0x0a,
      31,    1,  175,    2, 0x08,
      33,    1,  178,    2, 0x08,
      35,    3,  181,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   10,   11,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal,   10,   11,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QRect,   32,
    QMetaType::Bool, QMetaType::QPointF,   34,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,   36,   37,   38,

       0        // eod
};

void MapWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapWidget *_t = static_cast<MapWidget *>(_o);
        switch (_id) {
        case 0: _t->debugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->loadSettings(); break;
        case 2: _t->saveSettings(); break;
        case 3: _t->setDefaultSettings(); break;
        case 4: _t->zoomIn(); break;
        case 5: _t->zoomOut(); break;
        case 6: _t->setCenter((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 7: _t->setMyPos((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 8: _t->setCentered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->toggleNightMode(); break;
        case 10: _t->showMyTrack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->showTestTrack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->showTestTrackComments((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: { bool _r = _t->isCentered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->isNightmode();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->isVisibleMyTrack();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->isVisibleTestTrack();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = _t->isVisibleTestTrackComments();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: _t->loadTrack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: { QString _r = _t->getTrackFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: _t->updateMap((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 21: { bool _r = _t->isVisible((*reinterpret_cast< QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: _t->forwardDebugMsg((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MapWidget::*_t)(QtMsgType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapWidget::debugMsg)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MapWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapWidget.data,
      qt_meta_data_MapWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MapWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MapWidget.stringdata))
        return static_cast<void*>(const_cast< MapWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MapWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MapWidget::debugMsg(QtMsgType _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

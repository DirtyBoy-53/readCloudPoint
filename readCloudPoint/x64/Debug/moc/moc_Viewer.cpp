/****************************************************************************
** Meta object code from reading C++ file 'viewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../viewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VVAssistant_t {
    QByteArrayData data[11];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VVAssistant_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VVAssistant_t qt_meta_stringdata_VVAssistant = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VVAssistant"
QT_MOC_LITERAL(1, 12, 11), // "signalSetXy"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "PointView"
QT_MOC_LITERAL(4, 35, 2), // "pv"
QT_MOC_LITERAL(5, 38, 11), // "slotShotOne"
QT_MOC_LITERAL(6, 50, 7), // "shotOne"
QT_MOC_LITERAL(7, 58, 20), // "slotRidarDataSetting"
QT_MOC_LITERAL(8, 79, 4), // "slot"
QT_MOC_LITERAL(9, 84, 16), // "StructPointData*"
QT_MOC_LITERAL(10, 101, 4) // "data"

    },
    "VVAssistant\0signalSetXy\0\0PointView\0"
    "pv\0slotShotOne\0shotOne\0slotRidarDataSetting\0"
    "slot\0StructPointData*\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VVAssistant[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,
       5,    0,   40,    2, 0x2a /* Public | MethodCloned */,
       7,    2,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,

       0        // eod
};

void VVAssistant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VVAssistant *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSetXy((*reinterpret_cast< PointView(*)>(_a[1]))); break;
        case 1: _t->slotShotOne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotShotOne(); break;
        case 3: _t->slotRidarDataSetting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< StructPointData*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VVAssistant::*)(PointView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VVAssistant::signalSetXy)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VVAssistant::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VVAssistant.data,
    qt_meta_data_VVAssistant,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VVAssistant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VVAssistant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VVAssistant.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VVAssistant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VVAssistant::signalSetXy(PointView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Viewer_t {
    QByteArrayData data[21];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Viewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Viewer_t qt_meta_stringdata_Viewer = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Viewer"
QT_MOC_LITERAL(1, 7, 16), // "updateViewMaster"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "PointView"
QT_MOC_LITERAL(4, 35, 19), // "drawGridAndCircular"
QT_MOC_LITERAL(5, 55, 21), // "convertRgbByIntensity"
QT_MOC_LITERAL(6, 77, 9), // "intensity"
QT_MOC_LITERAL(7, 87, 6), // "float&"
QT_MOC_LITERAL(8, 94, 1), // "r"
QT_MOC_LITERAL(9, 96, 1), // "g"
QT_MOC_LITERAL(10, 98, 1), // "b"
QT_MOC_LITERAL(11, 100, 15), // "set_camera_view"
QT_MOC_LITERAL(12, 116, 9), // "ENUM_VIEW"
QT_MOC_LITERAL(13, 126, 4), // "view"
QT_MOC_LITERAL(14, 131, 19), // "set_projection_mode"
QT_MOC_LITERAL(15, 151, 12), // "Camera::Type"
QT_MOC_LITERAL(16, 164, 5), // "model"
QT_MOC_LITERAL(17, 170, 16), // "set_is_show_grid"
QT_MOC_LITERAL(18, 187, 5), // "state"
QT_MOC_LITERAL(19, 193, 17), // "set_is_show_polar"
QT_MOC_LITERAL(20, 211, 22) // "set_is_show_coordinate"

    },
    "Viewer\0updateViewMaster\0\0PointView\0"
    "drawGridAndCircular\0convertRgbByIntensity\0"
    "intensity\0float&\0r\0g\0b\0set_camera_view\0"
    "ENUM_VIEW\0view\0set_projection_mode\0"
    "Camera::Type\0model\0set_is_show_grid\0"
    "state\0set_is_show_polar\0set_is_show_coordinate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Viewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    4,   58,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,
      14,    1,   70,    2, 0x0a /* Public */,
      17,    1,   73,    2, 0x0a /* Public */,
      19,    1,   76,    2, 0x0a /* Public */,
      20,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void Viewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Viewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateViewMaster((*reinterpret_cast< PointView(*)>(_a[1]))); break;
        case 1: _t->drawGridAndCircular(); break;
        case 2: _t->convertRgbByIntensity((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 3: _t->set_camera_view((*reinterpret_cast< ENUM_VIEW(*)>(_a[1]))); break;
        case 4: _t->set_projection_mode((*reinterpret_cast< Camera::Type(*)>(_a[1]))); break;
        case 5: _t->set_is_show_grid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->set_is_show_polar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->set_is_show_coordinate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Viewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLViewer::staticMetaObject>(),
    qt_meta_stringdata_Viewer.data,
    qt_meta_data_Viewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Viewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Viewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Viewer.stringdata0))
        return static_cast<void*>(this);
    return QGLViewer::qt_metacast(_clname);
}

int Viewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLViewer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

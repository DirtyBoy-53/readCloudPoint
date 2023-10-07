/****************************************************************************
** Meta object code from reading C++ file 'lidarviewerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../lidarviewerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lidarviewerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LidarViewerWidget_t {
    QByteArrayData data[15];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LidarViewerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LidarViewerWidget_t qt_meta_stringdata_LidarViewerWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "LidarViewerWidget"
QT_MOC_LITERAL(1, 18, 19), // "sig_set_camera_view"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "ENUM_VIEW"
QT_MOC_LITERAL(4, 49, 4), // "view"
QT_MOC_LITERAL(5, 54, 23), // "sig_set_projection_mode"
QT_MOC_LITERAL(6, 78, 12), // "Camera::Type"
QT_MOC_LITERAL(7, 91, 5), // "model"
QT_MOC_LITERAL(8, 97, 19), // "sig_set_isShow_grid"
QT_MOC_LITERAL(9, 117, 20), // "sig_set_isShow_polar"
QT_MOC_LITERAL(10, 138, 25), // "sig_set_isShow_coordinate"
QT_MOC_LITERAL(11, 164, 21), // "sig_update_lidar_data"
QT_MOC_LITERAL(12, 186, 9), // "PointView"
QT_MOC_LITERAL(13, 196, 22), // "slot_btn_clicked_tools"
QT_MOC_LITERAL(14, 219, 25) // "slot_btn_clicked_playCtrl"

    },
    "LidarViewerWidget\0sig_set_camera_view\0"
    "\0ENUM_VIEW\0view\0sig_set_projection_mode\0"
    "Camera::Type\0model\0sig_set_isShow_grid\0"
    "sig_set_isShow_polar\0sig_set_isShow_coordinate\0"
    "sig_update_lidar_data\0PointView\0"
    "slot_btn_clicked_tools\0slot_btn_clicked_playCtrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LidarViewerWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       8,    1,   60,    2, 0x06 /* Public */,
       9,    1,   63,    2, 0x06 /* Public */,
      10,    1,   66,    2, 0x06 /* Public */,
      11,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   72,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 12,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LidarViewerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LidarViewerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_set_camera_view((*reinterpret_cast< ENUM_VIEW(*)>(_a[1]))); break;
        case 1: _t->sig_set_projection_mode((*reinterpret_cast< Camera::Type(*)>(_a[1]))); break;
        case 2: _t->sig_set_isShow_grid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sig_set_isShow_polar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->sig_set_isShow_coordinate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sig_update_lidar_data((*reinterpret_cast< PointView(*)>(_a[1]))); break;
        case 6: _t->slot_btn_clicked_tools(); break;
        case 7: _t->slot_btn_clicked_playCtrl(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LidarViewerWidget::*)(ENUM_VIEW );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LidarViewerWidget::sig_set_camera_view)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LidarViewerWidget::*)(Camera::Type );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LidarViewerWidget::sig_set_projection_mode)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LidarViewerWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LidarViewerWidget::sig_set_isShow_grid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LidarViewerWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LidarViewerWidget::sig_set_isShow_polar)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LidarViewerWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LidarViewerWidget::sig_set_isShow_coordinate)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LidarViewerWidget::*)(PointView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LidarViewerWidget::sig_update_lidar_data)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LidarViewerWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LidarViewerWidget.data,
    qt_meta_data_LidarViewerWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LidarViewerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LidarViewerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LidarViewerWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LidarViewerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LidarViewerWidget::sig_set_camera_view(ENUM_VIEW _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LidarViewerWidget::sig_set_projection_mode(Camera::Type _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LidarViewerWidget::sig_set_isShow_grid(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LidarViewerWidget::sig_set_isShow_polar(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LidarViewerWidget::sig_set_isShow_coordinate(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LidarViewerWidget::sig_update_lidar_data(PointView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

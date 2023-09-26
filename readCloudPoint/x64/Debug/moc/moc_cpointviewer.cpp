/****************************************************************************
** Meta object code from reading C++ file 'cpointviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cpointviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cpointviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPointViewer_t {
    QByteArrayData data[15];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPointViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPointViewer_t qt_meta_stringdata_CPointViewer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CPointViewer"
QT_MOC_LITERAL(1, 13, 10), // "onTimerOut"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "mousePressEvent"
QT_MOC_LITERAL(4, 41, 12), // "QMouseEvent*"
QT_MOC_LITERAL(5, 54, 1), // "e"
QT_MOC_LITERAL(6, 56, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(7, 71, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(8, 89, 10), // "wheelEvent"
QT_MOC_LITERAL(9, 100, 12), // "QWheelEvent*"
QT_MOC_LITERAL(10, 113, 13), // "keyPressEvent"
QT_MOC_LITERAL(11, 127, 10), // "QKeyEvent*"
QT_MOC_LITERAL(12, 138, 10), // "leaveEvent"
QT_MOC_LITERAL(13, 149, 7), // "QEvent*"
QT_MOC_LITERAL(14, 157, 10) // "enterEvent"

    },
    "CPointViewer\0onTimerOut\0\0mousePressEvent\0"
    "QMouseEvent*\0e\0mouseMoveEvent\0"
    "mouseReleaseEvent\0wheelEvent\0QWheelEvent*\0"
    "keyPressEvent\0QKeyEvent*\0leaveEvent\0"
    "QEvent*\0enterEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPointViewer[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       7,    1,   61,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,
      12,    1,   70,    2, 0x08 /* Private */,
      14,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 9,    5,
    QMetaType::Void, 0x80000000 | 11,    5,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13,    2,

       0        // eod
};

void CPointViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CPointViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimerOut(); break;
        case 1: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 7: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CPointViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_CPointViewer.data,
    qt_meta_data_CPointViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CPointViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPointViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPointViewer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int CPointViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
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

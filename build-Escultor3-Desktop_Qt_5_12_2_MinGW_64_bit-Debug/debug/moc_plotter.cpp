/****************************************************************************
** Meta object code from reading C++ file 'plotter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Escultor3/plotter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plotter_t {
    QByteArrayData data[16];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plotter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plotter_t qt_meta_stringdata_Plotter = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Plotter"
QT_MOC_LITERAL(1, 8, 5), // "moveX"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "moveY"
QT_MOC_LITERAL(4, 21, 7), // "clickXY"
QT_MOC_LITERAL(5, 29, 10), // "mudaLinhas"
QT_MOC_LITERAL(6, 40, 1), // "l"
QT_MOC_LITERAL(7, 42, 11), // "mudaColunas"
QT_MOC_LITERAL(8, 54, 1), // "c"
QT_MOC_LITERAL(9, 56, 10), // "mudaPlanos"
QT_MOC_LITERAL(10, 67, 1), // "p"
QT_MOC_LITERAL(11, 69, 9), // "olhaPlano"
QT_MOC_LITERAL(12, 79, 6), // "clicou"
QT_MOC_LITERAL(13, 86, 1), // "x"
QT_MOC_LITERAL(14, 88, 1), // "y"
QT_MOC_LITERAL(15, 90, 7) // "mudaCor"

    },
    "Plotter\0moveX\0\0moveY\0clickXY\0mudaLinhas\0"
    "l\0mudaColunas\0c\0mudaPlanos\0p\0olhaPlano\0"
    "clicou\0x\0y\0mudaCor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plotter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    2,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   70,    2, 0x0a /* Public */,
       7,    1,   73,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
      11,    1,   79,    2, 0x0a /* Public */,
      12,    2,   82,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void,

       0        // eod
};

void Plotter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plotter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->moveY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clickXY((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->mudaLinhas((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->mudaColunas((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->mudaPlanos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->olhaPlano((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->clicou((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Plotter::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plotter::moveX)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Plotter::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plotter::moveY)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Plotter::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Plotter::clickXY)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plotter::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Plotter.data,
    qt_meta_data_Plotter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plotter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plotter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plotter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Plotter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Plotter::moveX(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Plotter::moveY(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Plotter::clickXY(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'logicalelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../logicalelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logicalelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogicalElement_t {
    QByteArrayData data[14];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogicalElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogicalElement_t qt_meta_stringdata_LogicalElement = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LogicalElement"
QT_MOC_LITERAL(1, 15, 13), // "connectSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "std::vector<id_t>"
QT_MOC_LITERAL(4, 48, 3), // "ids"
QT_MOC_LITERAL(5, 52, 12), // "coordsSignal"
QT_MOC_LITERAL(6, 65, 3), // "pos"
QT_MOC_LITERAL(7, 69, 8), // "propSlot"
QT_MOC_LITERAL(8, 78, 4), // "name"
QT_MOC_LITERAL(9, 83, 7), // "ionum_t"
QT_MOC_LITERAL(10, 91, 4), // "inum"
QT_MOC_LITERAL(11, 96, 4), // "onum"
QT_MOC_LITERAL(12, 101, 34), // "std::vector<std::vector<value..."
QT_MOC_LITERAL(13, 136, 12) // "output_table"

    },
    "LogicalElement\0connectSignal\0\0"
    "std::vector<id_t>\0ids\0coordsSignal\0"
    "pos\0propSlot\0name\0ionum_t\0inum\0onum\0"
    "std::vector<std::vector<value_t> >\0"
    "output_table"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogicalElement[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    4,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPointF,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 12,    8,   10,   11,   13,

       0        // eod
};

void LogicalElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogicalElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectSignal((*reinterpret_cast< std::vector<id_t>(*)>(_a[1]))); break;
        case 1: _t->coordsSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->propSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ionum_t(*)>(_a[2])),(*reinterpret_cast< ionum_t(*)>(_a[3])),(*reinterpret_cast< std::vector<std::vector<value_t> >(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LogicalElement::*)(std::vector<id_t> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogicalElement::connectSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LogicalElement::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogicalElement::coordsSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LogicalElement::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LogicalElement.data,
    qt_meta_data_LogicalElement,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LogicalElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogicalElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogicalElement.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int LogicalElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LogicalElement::connectSignal(std::vector<id_t> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LogicalElement::coordsSignal(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

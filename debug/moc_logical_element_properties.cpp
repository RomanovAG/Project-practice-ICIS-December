/****************************************************************************
** Meta object code from reading C++ file 'logical_element_properties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../logical_element_properties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logical_element_properties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Logical_Element_Properties_t {
    QByteArrayData data[17];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Logical_Element_Properties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Logical_Element_Properties_t qt_meta_stringdata_Logical_Element_Properties = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Logical_Element_Properties"
QT_MOC_LITERAL(1, 27, 10), // "propSignal"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "name"
QT_MOC_LITERAL(4, 44, 7), // "ionum_t"
QT_MOC_LITERAL(5, 52, 4), // "inum"
QT_MOC_LITERAL(6, 57, 4), // "onum"
QT_MOC_LITERAL(7, 62, 34), // "std::vector<std::vector<value..."
QT_MOC_LITERAL(8, 97, 12), // "output_table"
QT_MOC_LITERAL(9, 110, 9), // "delSignal"
QT_MOC_LITERAL(10, 120, 8), // "propSlot"
QT_MOC_LITERAL(11, 129, 13), // "on_OK_clicked"
QT_MOC_LITERAL(12, 143, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(13, 161, 27), // "on_inputNumBox_valueChanged"
QT_MOC_LITERAL(14, 189, 4), // "arg1"
QT_MOC_LITERAL(15, 194, 28), // "on_outputNumBox_valueChanged"
QT_MOC_LITERAL(16, 223, 20) // "on_delButton_clicked"

    },
    "Logical_Element_Properties\0propSignal\0"
    "\0name\0ionum_t\0inum\0onum\0"
    "std::vector<std::vector<value_t> >\0"
    "output_table\0delSignal\0propSlot\0"
    "on_OK_clicked\0on_Cancel_clicked\0"
    "on_inputNumBox_valueChanged\0arg1\0"
    "on_outputNumBox_valueChanged\0"
    "on_delButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logical_Element_Properties[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       9,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    4,   64,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    1,   75,    2, 0x08 /* Private */,
      15,    1,   78,    2, 0x08 /* Private */,
      16,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 7,    3,    5,    6,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 7,    3,    5,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

       0        // eod
};

void Logical_Element_Properties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Logical_Element_Properties *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->propSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ionum_t(*)>(_a[2])),(*reinterpret_cast< ionum_t(*)>(_a[3])),(*reinterpret_cast< std::vector<std::vector<value_t> >(*)>(_a[4]))); break;
        case 1: _t->delSignal(); break;
        case 2: _t->propSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ionum_t(*)>(_a[2])),(*reinterpret_cast< ionum_t(*)>(_a[3])),(*reinterpret_cast< std::vector<std::vector<value_t> >(*)>(_a[4]))); break;
        case 3: _t->on_OK_clicked(); break;
        case 4: _t->on_Cancel_clicked(); break;
        case 5: _t->on_inputNumBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_outputNumBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_delButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Logical_Element_Properties::*)(QString , ionum_t , ionum_t , std::vector<std::vector<value_t>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logical_Element_Properties::propSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Logical_Element_Properties::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logical_Element_Properties::delSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Logical_Element_Properties::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Logical_Element_Properties.data,
    qt_meta_data_Logical_Element_Properties,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Logical_Element_Properties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logical_Element_Properties::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Logical_Element_Properties.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Logical_Element_Properties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Logical_Element_Properties::propSignal(QString _t1, ionum_t _t2, ionum_t _t3, std::vector<std::vector<value_t>> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Logical_Element_Properties::delSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

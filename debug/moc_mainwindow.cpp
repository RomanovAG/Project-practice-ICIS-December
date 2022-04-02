/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 34), // "on_actionSet_logic_level_trig..."
QT_MOC_LITERAL(4, 69, 17), // "on_addNet_clicked"
QT_MOC_LITERAL(5, 87, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 111, 20), // "on_notButton_clicked"
QT_MOC_LITERAL(7, 132, 20), // "on_andButton_clicked"
QT_MOC_LITERAL(8, 153, 19), // "on_orButton_clicked"
QT_MOC_LITERAL(9, 173, 19), // "on_addInOut_clicked"
QT_MOC_LITERAL(10, 193, 20), // "on_connector_clicked"
QT_MOC_LITERAL(11, 214, 19), // "onLogicLevelChanged"
QT_MOC_LITERAL(12, 234, 7), // "level_t"
QT_MOC_LITERAL(13, 242, 5), // "value"
QT_MOC_LITERAL(14, 248, 11), // "connectSlot"
QT_MOC_LITERAL(15, 260, 17), // "std::vector<id_t>"
QT_MOC_LITERAL(16, 278, 3) // "ids"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_actionSet_logic_level_triggered\0"
    "on_addNet_clicked\0on_pushButton_2_clicked\0"
    "on_notButton_clicked\0on_andButton_clicked\0"
    "on_orButton_clicked\0on_addInOut_clicked\0"
    "on_connector_clicked\0onLogicLevelChanged\0"
    "level_t\0value\0connectSlot\0std::vector<id_t>\0"
    "ids"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_actionSet_logic_level_triggered(); break;
        case 2: _t->on_addNet_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_notButton_clicked(); break;
        case 5: _t->on_andButton_clicked(); break;
        case 6: _t->on_orButton_clicked(); break;
        case 7: _t->on_addInOut_clicked(); break;
        case 8: _t->on_connector_clicked(); break;
        case 9: _t->onLogicLevelChanged((*reinterpret_cast< level_t(*)>(_a[1]))); break;
        case 10: _t->connectSlot((*reinterpret_cast< std::vector<id_t>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

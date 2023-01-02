/****************************************************************************
** Meta object code from reading C++ file 'weapons2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pirate/weapons2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapons2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_weapons2_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_weapons2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_weapons2_t qt_meta_stringdata_weapons2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "weapons2"
QT_MOC_LITERAL(1, 9, 11), // "SIG_Change2"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "SIG_Bomb"
QT_MOC_LITERAL(4, 31, 9), // "SIG_Move2"
QT_MOC_LITERAL(5, 41, 18), // "on_pb_bomb_clicked"
QT_MOC_LITERAL(6, 60, 17), // "on_pb_sur_clicked"
QT_MOC_LITERAL(7, 78, 18) // "on_pb_move_clicked"

    },
    "weapons2\0SIG_Change2\0\0SIG_Bomb\0SIG_Move2\0"
    "on_pb_bomb_clicked\0on_pb_sur_clicked\0"
    "on_pb_move_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_weapons2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void weapons2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        weapons2 *_t = static_cast<weapons2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_Change2(); break;
        case 1: _t->SIG_Bomb(); break;
        case 2: _t->SIG_Move2(); break;
        case 3: _t->on_pb_bomb_clicked(); break;
        case 4: _t->on_pb_sur_clicked(); break;
        case 5: _t->on_pb_move_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (weapons2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&weapons2::SIG_Change2)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (weapons2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&weapons2::SIG_Bomb)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (weapons2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&weapons2::SIG_Move2)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject weapons2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_weapons2.data,
      qt_meta_data_weapons2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *weapons2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *weapons2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_weapons2.stringdata0))
        return static_cast<void*>(const_cast< weapons2*>(this));
    return QDialog::qt_metacast(_clname);
}

int weapons2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void weapons2::SIG_Change2()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void weapons2::SIG_Bomb()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void weapons2::SIG_Move2()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

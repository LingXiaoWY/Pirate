/****************************************************************************
** Meta object code from reading C++ file 'ckernel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pirate/ckernel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ckernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ckernel_t {
    QByteArrayData data[10];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ckernel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ckernel_t qt_meta_stringdata_Ckernel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Ckernel"
QT_MOC_LITERAL(1, 8, 18), // "slot_dealstartplay"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "slot_dealstopplay"
QT_MOC_LITERAL(4, 46, 16), // "slot_dealweapon1"
QT_MOC_LITERAL(5, 63, 16), // "slot_dealweapon2"
QT_MOC_LITERAL(6, 80, 22), // "slot_dealweapon1Change"
QT_MOC_LITERAL(7, 103, 22), // "slot_dealweapon2Change"
QT_MOC_LITERAL(8, 126, 19), // "slot_dealweaponBomb"
QT_MOC_LITERAL(9, 146, 16) // "slot_dealperMove"

    },
    "Ckernel\0slot_dealstartplay\0\0"
    "slot_dealstopplay\0slot_dealweapon1\0"
    "slot_dealweapon2\0slot_dealweapon1Change\0"
    "slot_dealweapon2Change\0slot_dealweaponBomb\0"
    "slot_dealperMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ckernel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Ckernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ckernel *_t = static_cast<Ckernel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_dealstartplay(); break;
        case 1: _t->slot_dealstopplay(); break;
        case 2: _t->slot_dealweapon1(); break;
        case 3: _t->slot_dealweapon2(); break;
        case 4: _t->slot_dealweapon1Change(); break;
        case 5: _t->slot_dealweapon2Change(); break;
        case 6: _t->slot_dealweaponBomb(); break;
        case 7: _t->slot_dealperMove(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Ckernel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ckernel.data,
      qt_meta_data_Ckernel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ckernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ckernel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ckernel.stringdata0))
        return static_cast<void*>(const_cast< Ckernel*>(this));
    return QObject::qt_metacast(_clname);
}

int Ckernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

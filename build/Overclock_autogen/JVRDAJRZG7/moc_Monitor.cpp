/****************************************************************************
** Meta object code from reading C++ file 'Monitor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/HEADERS/Monitor.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Monitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Monitor_t {
    uint offsetsAndSizes[24];
    char stringdata0[8];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[15];
    char stringdata5[9];
    char stringdata6[15];
    char stringdata7[9];
    char stringdata8[15];
    char stringdata9[9];
    char stringdata10[10];
    char stringdata11[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Monitor_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Monitor_t qt_meta_stringdata_Monitor = {
    {
        QT_MOC_LITERAL(0, 7),  // "Monitor"
        QT_MOC_LITERAL(8, 20),  // "updateTemperatureCPU"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 11),  // "temperature"
        QT_MOC_LITERAL(42, 14),  // "updateUsageCPU"
        QT_MOC_LITERAL(57, 8),  // "usagecpu"
        QT_MOC_LITERAL(66, 14),  // "updateUsageRAM"
        QT_MOC_LITERAL(81, 8),  // "usageram"
        QT_MOC_LITERAL(90, 14),  // "updateClockCPU"
        QT_MOC_LITERAL(105, 8),  // "clockcpu"
        QT_MOC_LITERAL(114, 9),  // "getThread"
        QT_MOC_LITERAL(124, 7)   // "Thread*"
    },
    "Monitor",
    "updateTemperatureCPU",
    "",
    "temperature",
    "updateUsageCPU",
    "usagecpu",
    "updateUsageRAM",
    "usageram",
    "updateClockCPU",
    "clockcpu",
    "getThread",
    "Thread*"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Monitor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       6,    1,   50,    2, 0x0a,    5 /* Public */,
       8,    1,   53,    2, 0x0a,    7 /* Public */,
      10,    0,   56,    2, 0x10a,    9 /* Public | MethodIsConst  */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,
    0x80000000 | 11,

       0        // eod
};

Q_CONSTINIT const QMetaObject Monitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Monitor.offsetsAndSizes,
    qt_meta_data_Monitor,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Monitor_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Monitor, std::true_type>,
        // method 'updateTemperatureCPU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updateUsageCPU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updateUsageRAM'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updateClockCPU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'getThread'
        QtPrivate::TypeAndForceComplete<Thread *, std::false_type>
    >,
    nullptr
} };

void Monitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Monitor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTemperatureCPU((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->updateUsageCPU((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->updateUsageRAM((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->updateClockCPU((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: { Thread* _r = _t->getThread();
            if (_a[0]) *reinterpret_cast< Thread**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *Monitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Monitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Monitor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Monitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

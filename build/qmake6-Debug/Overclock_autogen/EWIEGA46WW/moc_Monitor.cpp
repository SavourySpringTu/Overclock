/****************************************************************************
** Meta object code from reading C++ file 'Monitor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Monitor.h"
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
    uint offsetsAndSizes[30];
    char stringdata0[8];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[18];
    char stringdata5[9];
    char stringdata6[29];
    char stringdata7[15];
    char stringdata8[9];
    char stringdata9[19];
    char stringdata10[9];
    char stringdata11[25];
    char stringdata12[6];
    char stringdata13[10];
    char stringdata14[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Monitor_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Monitor_t qt_meta_stringdata_Monitor = {
    {
        QT_MOC_LITERAL(0, 7),  // "Monitor"
        QT_MOC_LITERAL(8, 20),  // "updateTemperatureCPU"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 11),  // "temperature"
        QT_MOC_LITERAL(42, 17),  // "updatePerUsageCPU"
        QT_MOC_LITERAL(60, 8),  // "usagecpu"
        QT_MOC_LITERAL(69, 28),  // "updatePerUsageRAMandUsageRAM"
        QT_MOC_LITERAL(98, 14),  // "vector<double>"
        QT_MOC_LITERAL(113, 8),  // "usageram"
        QT_MOC_LITERAL(122, 18),  // "updateCoreClockCPU"
        QT_MOC_LITERAL(141, 8),  // "clockcpu"
        QT_MOC_LITERAL(150, 24),  // "eventChangeOperationMode"
        QT_MOC_LITERAL(175, 5),  // "index"
        QT_MOC_LITERAL(181, 9),  // "getThread"
        QT_MOC_LITERAL(191, 7)   // "Thread*"
    },
    "Monitor",
    "updateTemperatureCPU",
    "",
    "temperature",
    "updatePerUsageCPU",
    "usagecpu",
    "updatePerUsageRAMandUsageRAM",
    "vector<double>",
    "usageram",
    "updateCoreClockCPU",
    "clockcpu",
    "eventChangeOperationMode",
    "index",
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
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    1,   53,    2, 0x0a,    3 /* Public */,
       6,    1,   56,    2, 0x0a,    5 /* Public */,
       9,    1,   59,    2, 0x0a,    7 /* Public */,
      11,    1,   62,    2, 0x0a,    9 /* Public */,
      13,    0,   65,    2, 0x10a,   11 /* Public | MethodIsConst  */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Int,   12,
    0x80000000 | 14,

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
        // method 'updatePerUsageCPU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'updatePerUsageRAMandUsageRAM'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<double>, std::false_type>,
        // method 'updateCoreClockCPU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'eventChangeOperationMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        case 1: _t->updatePerUsageCPU((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->updatePerUsageRAMandUsageRAM((*reinterpret_cast< std::add_pointer_t<vector<double>>>(_a[1]))); break;
        case 3: _t->updateCoreClockCPU((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->eventChangeOperationMode((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: { Thread* _r = _t->getThread();
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

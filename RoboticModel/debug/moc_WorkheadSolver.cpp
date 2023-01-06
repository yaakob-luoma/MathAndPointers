/****************************************************************************
** Meta object code from reading C++ file 'WorkheadSolver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WorkheadSolver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkheadSolver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkheadSolver_t {
    QByteArrayData data[19];
    char stringdata[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkheadSolver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkheadSolver_t qt_meta_stringdata_WorkheadSolver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WorkheadSolver"
QT_MOC_LITERAL(1, 15, 14), // "masterXChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "masterYChanged"
QT_MOC_LITERAL(4, 46, 13), // "slaveXChanged"
QT_MOC_LITERAL(5, 60, 13), // "slaveYChanged"
QT_MOC_LITERAL(6, 74, 25), // "spottingFBCylinderChanged"
QT_MOC_LITERAL(7, 100, 25), // "spottingSWCylinderChanged"
QT_MOC_LITERAL(8, 126, 24), // "patternFBCylinderChanged"
QT_MOC_LITERAL(9, 151, 24), // "patternSWCylinderChanged"
QT_MOC_LITERAL(10, 176, 5), // "solve"
QT_MOC_LITERAL(11, 182, 7), // "masterX"
QT_MOC_LITERAL(12, 190, 7), // "masterY"
QT_MOC_LITERAL(13, 198, 6), // "slaveX"
QT_MOC_LITERAL(14, 205, 6), // "slaveY"
QT_MOC_LITERAL(15, 212, 18), // "spottingFBCylinder"
QT_MOC_LITERAL(16, 231, 18), // "spottingSWCylinder"
QT_MOC_LITERAL(17, 250, 17), // "patternFBCylinder"
QT_MOC_LITERAL(18, 268, 17) // "patternSWCylinder"

    },
    "WorkheadSolver\0masterXChanged\0\0"
    "masterYChanged\0slaveXChanged\0slaveYChanged\0"
    "spottingFBCylinderChanged\0"
    "spottingSWCylinderChanged\0"
    "patternFBCylinderChanged\0"
    "patternSWCylinderChanged\0solve\0masterX\0"
    "masterY\0slaveX\0slaveY\0spottingFBCylinder\0"
    "spottingSWCylinder\0patternFBCylinder\0"
    "patternSWCylinder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkheadSolver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       8,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,

 // properties: name, type, flags
      11, QMetaType::Double, 0x00495103,
      12, QMetaType::Double, 0x00495103,
      13, QMetaType::Double, 0x00495103,
      14, QMetaType::Double, 0x00495103,
      15, QMetaType::Double, 0x00495103,
      16, QMetaType::Double, 0x00495103,
      17, QMetaType::Double, 0x00495103,
      18, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void WorkheadSolver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkheadSolver *_t = static_cast<WorkheadSolver *>(_o);
        switch (_id) {
        case 0: _t->masterXChanged(); break;
        case 1: _t->masterYChanged(); break;
        case 2: _t->slaveXChanged(); break;
        case 3: _t->slaveYChanged(); break;
        case 4: _t->spottingFBCylinderChanged(); break;
        case 5: _t->spottingSWCylinderChanged(); break;
        case 6: _t->patternFBCylinderChanged(); break;
        case 7: _t->patternSWCylinderChanged(); break;
        case 8: { int _r = _t->solve();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::masterXChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::masterYChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::slaveXChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::slaveYChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::spottingFBCylinderChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::spottingSWCylinderChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::patternFBCylinderChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (WorkheadSolver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkheadSolver::patternSWCylinderChanged)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject WorkheadSolver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WorkheadSolver.data,
      qt_meta_data_WorkheadSolver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkheadSolver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkheadSolver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkheadSolver.stringdata))
        return static_cast<void*>(const_cast< WorkheadSolver*>(this));
    return QObject::qt_metacast(_clname);
}

int WorkheadSolver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = masterX(); break;
        case 1: *reinterpret_cast< double*>(_v) = masterY(); break;
        case 2: *reinterpret_cast< double*>(_v) = slaveX(); break;
        case 3: *reinterpret_cast< double*>(_v) = slaveY(); break;
        case 4: *reinterpret_cast< double*>(_v) = spottingFBCylinder(); break;
        case 5: *reinterpret_cast< double*>(_v) = spottingSWCylinder(); break;
        case 6: *reinterpret_cast< double*>(_v) = patternFBCylinder(); break;
        case 7: *reinterpret_cast< double*>(_v) = patternSWCylinder(); break;
        default: break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMasterX(*reinterpret_cast< double*>(_v)); break;
        case 1: setMasterY(*reinterpret_cast< double*>(_v)); break;
        case 2: setSlaveX(*reinterpret_cast< double*>(_v)); break;
        case 3: setSlaveY(*reinterpret_cast< double*>(_v)); break;
        case 4: setSpottingFBCylinder(*reinterpret_cast< double*>(_v)); break;
        case 5: setSpottingSWCylinder(*reinterpret_cast< double*>(_v)); break;
        case 6: setPatternFBCylinder(*reinterpret_cast< double*>(_v)); break;
        case 7: setPatternSWCylinder(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WorkheadSolver::masterXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void WorkheadSolver::masterYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void WorkheadSolver::slaveXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void WorkheadSolver::slaveYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void WorkheadSolver::spottingFBCylinderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void WorkheadSolver::spottingSWCylinderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void WorkheadSolver::patternFBCylinderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void WorkheadSolver::patternSWCylinderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

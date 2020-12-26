/****************************************************************************
** Meta object code from reading C++ file 'minesweeping.h'
**
** Created: Sun Nov 17 20:18:03 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../minesweeping.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minesweeping.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MineSweeping[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   14,   13,   13, 0x0a,
      58,   13,   13,   13, 0x0a,
      68,   13,   13,   13, 0x0a,
      78,   13,   13,   13, 0x0a,
      90,   13,   13,   13, 0x0a,
     101,   13,   13,   13, 0x0a,
     115,   13,   13,   13, 0x0a,
     126,   13,   13,   13, 0x0a,
     138,   13,   13,   13, 0x0a,
     148,   13,   13,   13, 0x0a,
     157,   13,   13,   13, 0x0a,
     172,   13,   13,   13, 0x0a,
     189,  187,   13,   13, 0x0a,
     211,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MineSweeping[] = {
    "MineSweeping\0\0row,column,type\0"
    "cellClickeSlot(int,int,int)\0newGame()\0"
    "restart()\0showAbout()\0showHelp()\0"
    "showSetting()\0showInfo()\0showStyle()\0"
    "setRank()\0reSize()\0setBombStyle()\0"
    "setCellStyle()\0,\0setHighLight(int,int)\0"
    "showWindow()\0"
};

void MineSweeping::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MineSweeping *_t = static_cast<MineSweeping *>(_o);
        switch (_id) {
        case 0: _t->cellClickeSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->newGame(); break;
        case 2: _t->restart(); break;
        case 3: _t->showAbout(); break;
        case 4: _t->showHelp(); break;
        case 5: _t->showSetting(); break;
        case 6: _t->showInfo(); break;
        case 7: _t->showStyle(); break;
        case 8: _t->setRank(); break;
        case 9: _t->reSize(); break;
        case 10: _t->setBombStyle(); break;
        case 11: _t->setCellStyle(); break;
        case 12: _t->setHighLight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->showWindow(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MineSweeping::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MineSweeping::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MineSweeping,
      qt_meta_data_MineSweeping, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MineSweeping::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MineSweeping::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MineSweeping::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MineSweeping))
        return static_cast<void*>(const_cast< MineSweeping*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MineSweeping::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

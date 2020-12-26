/****************************************************************************
** Meta object code from reading C++ file 'GameSetting.h'
**
** Created: Thu Oct 17 13:16:25 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      23,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   32,   12,   12, 0x08,
      56,   12,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameSetting[] = {
    "GameSetting\0\0setRank()\0resize()\0bShow\0"
    "showCostume(bool)\0setValue()\0setBombs(int)\0"
};

void GameSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameSetting *_t = static_cast<GameSetting *>(_o);
        switch (_id) {
        case 0: _t->setRank(); break;
        case 1: _t->resize(); break;
        case 2: _t->showCostume((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setValue(); break;
        case 4: _t->setBombs((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GameSetting,
      qt_meta_data_GameSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameSetting))
        return static_cast<void*>(const_cast< GameSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int GameSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GameSetting::setRank()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameSetting::resize()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

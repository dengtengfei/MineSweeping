/****************************************************************************
** Meta object code from reading C++ file 'StyleSetting.h'
**
** Created: Sun Nov 17 20:07:20 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StyleSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StyleSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StyleSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   13,   13,   13, 0x08,
      57,   13,   13,   13, 0x08,
      67,   13,   13,   13, 0x08,
      82,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StyleSetting[] = {
    "StyleSetting\0\0emitCellStyle()\0"
    "emitBombStyle()\0setStyle()\0setBomb()\0"
    "setRandom(int)\0confirm()\0"
};

void StyleSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StyleSetting *_t = static_cast<StyleSetting *>(_o);
        switch (_id) {
        case 0: _t->emitCellStyle(); break;
        case 1: _t->emitBombStyle(); break;
        case 2: _t->setStyle(); break;
        case 3: _t->setBomb(); break;
        case 4: _t->setRandom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->confirm(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StyleSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StyleSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StyleSetting,
      qt_meta_data_StyleSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StyleSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StyleSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StyleSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StyleSetting))
        return static_cast<void*>(const_cast< StyleSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int StyleSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void StyleSetting::emitCellStyle()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void StyleSetting::emitBombStyle()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'singleApp.h'
**
** Created: Sun Nov 17 20:07:20 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../singleApp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'singleApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SingleApp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SingleApp[] = {
    "SingleApp\0\0strMsg\0recvMsg(QString)\0"
    "receiveMessage()\0"
};

void SingleApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SingleApp *_t = static_cast<SingleApp *>(_o);
        switch (_id) {
        case 0: _t->recvMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->receiveMessage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SingleApp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SingleApp::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_SingleApp,
      qt_meta_data_SingleApp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SingleApp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SingleApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SingleApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SingleApp))
        return static_cast<void*>(const_cast< SingleApp*>(this));
    return QApplication::qt_metacast(_clname);
}

int SingleApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SingleApp::recvMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

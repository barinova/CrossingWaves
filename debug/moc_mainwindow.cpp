/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed 12. Mar 01:04:33 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     159,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     290,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     352,   11,   11,   11, 0x08,
     384,   11,   11,   11, 0x08,
     414,   11,   11,   11, 0x08,
     443,   11,   11,   11, 0x08,
     480,   11,   11,   11, 0x08,
     516,   11,   11,   11, 0x08,
     543,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_buttonBrowse_M_clicked()\0"
    "on_calculateButton_clicked()\0"
    "on_buttonSaveAll_clicked()\0"
    "on_buttonBrowse_clicked()\0"
    "on_buttonZoomOutHeightsZUC_clicked()\0"
    "on_buttonZoomOnHeightsZUC_clicked()\0"
    "on_buttonZoomOutZDCLog_clicked()\0"
    "on_buttonZoomOnZDCLog_clicked()\0"
    "on_buttonZoomOutZDC_clicked()\0"
    "on_buttonZoomOnZDC_clicked()\0"
    "on_buttonZoomOutZUCLog_clicked()\0"
    "on_buttonZoomOnZUCLog_clicked()\0"
    "on_buttonZoomOutZUC_clicked()\0"
    "on_buttonZoomOnZUC_clicked()\0"
    "on_buttonZoomOutHeightsZDC_clicked()\0"
    "on_buttonZoomOnHeightsZDC_clicked()\0"
    "on_buttonZoomOut_clicked()\0"
    "on_buttonZoomOn_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonBrowse_M_clicked(); break;
        case 1: on_calculateButton_clicked(); break;
        case 2: on_buttonSaveAll_clicked(); break;
        case 3: on_buttonBrowse_clicked(); break;
        case 4: on_buttonZoomOutHeightsZUC_clicked(); break;
        case 5: on_buttonZoomOnHeightsZUC_clicked(); break;
        case 6: on_buttonZoomOutZDCLog_clicked(); break;
        case 7: on_buttonZoomOnZDCLog_clicked(); break;
        case 8: on_buttonZoomOutZDC_clicked(); break;
        case 9: on_buttonZoomOnZDC_clicked(); break;
        case 10: on_buttonZoomOutZUCLog_clicked(); break;
        case 11: on_buttonZoomOnZUCLog_clicked(); break;
        case 12: on_buttonZoomOutZUC_clicked(); break;
        case 13: on_buttonZoomOnZUC_clicked(); break;
        case 14: on_buttonZoomOutHeightsZDC_clicked(); break;
        case 15: on_buttonZoomOnHeightsZDC_clicked(); break;
        case 16: on_buttonZoomOut_clicked(); break;
        case 17: on_buttonZoomOn_clicked(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

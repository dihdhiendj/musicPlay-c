/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSlrc_lineENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSlrc_lineENDCLASS = QtMocHelpers::stringData(
    "lrc_line",
    "turn_time",
    ""
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlrc_lineENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject lrc_line::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_CLASSlrc_lineENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlrc_lineENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlrc_lineENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<lrc_line, std::true_type>,
        // method 'turn_time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void lrc_line::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lrc_line *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->turn_time((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lrc_line::*)(int );
            if (_t _q_method = &lrc_line::turn_time; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *lrc_line::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lrc_line::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlrc_lineENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int lrc_line::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void lrc_line::turn_time(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "playNext",
    "",
    "forward",
    "type",
    "on_pushButton_stop_clicked",
    "on_pushButton_seit_show_clicked",
    "on_pushButton_down_clicked",
    "on_pushButton_up_clicked",
    "on_pushButton_table_clicked",
    "on_pushButton_close_clicked",
    "on_pushButton_lrc_show_clicked",
    "on_pushButton_play_clicked",
    "on_horizontalSlider_volume_valueChanged",
    "value",
    "open_music",
    "musicCore*",
    "parameter",
    "build_dir",
    "insert_now_time",
    "time",
    "insert_end_time",
    "seit_play_value",
    "pos",
    "build_lyric_show",
    "url",
    "select_lrc",
    "clear_lyric_show",
    "writer_data",
    "read_data",
    "mousePressEvent",
    "QMouseEvent*",
    "event",
    "mouseMoveEvent",
    "set_bakcgroung_pic",
    "QImage*",
    "img",
    "on_pushButton_value_clicked",
    "set_font_type",
    "f",
    "on_pushButton_min_clicked",
    "updateAudioDevice",
    "set_void_play"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  182,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,  187,    2, 0x08,    4 /* Private */,
       6,    0,  188,    2, 0x08,    5 /* Private */,
       7,    0,  189,    2, 0x08,    6 /* Private */,
       8,    0,  190,    2, 0x08,    7 /* Private */,
       9,    0,  191,    2, 0x08,    8 /* Private */,
      10,    0,  192,    2, 0x08,    9 /* Private */,
      11,    0,  193,    2, 0x08,   10 /* Private */,
      12,    0,  194,    2, 0x08,   11 /* Private */,
      13,    1,  195,    2, 0x08,   12 /* Private */,
      15,    1,  198,    2, 0x08,   14 /* Private */,
      18,    0,  201,    2, 0x08,   16 /* Private */,
      19,    1,  202,    2, 0x08,   17 /* Private */,
      21,    1,  205,    2, 0x08,   19 /* Private */,
      22,    1,  208,    2, 0x08,   21 /* Private */,
      24,    1,  211,    2, 0x08,   23 /* Private */,
      26,    1,  214,    2, 0x08,   25 /* Private */,
      27,    0,  217,    2, 0x08,   27 /* Private */,
      28,    0,  218,    2, 0x08,   28 /* Private */,
      29,    0,  219,    2, 0x08,   29 /* Private */,
      30,    1,  220,    2, 0x08,   30 /* Private */,
      33,    1,  223,    2, 0x08,   32 /* Private */,
      34,    1,  226,    2, 0x08,   34 /* Private */,
      37,    0,  229,    2, 0x08,   36 /* Private */,
      38,    1,  230,    2, 0x08,   37 /* Private */,
      40,    0,  233,    2, 0x08,   39 /* Private */,
      41,    0,  234,    2, 0x08,   40 /* Private */,
      42,    0,  235,    2, 0x08,   41 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'playNext'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_seit_show_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_down_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_up_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_table_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_close_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_lrc_show_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_play_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_volume_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'open_music'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<musicCore *, std::false_type>,
        // method 'build_dir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'insert_now_time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'insert_end_time'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'seit_play_value'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'build_lyric_show'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'select_lrc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clear_lyric_show'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writer_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'read_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mousePressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mouseMoveEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'set_bakcgroung_pic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage *, std::false_type>,
        // method 'on_pushButton_value_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_font_type'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_min_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateAudioDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_void_play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->playNext((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->on_pushButton_stop_clicked(); break;
        case 2: _t->on_pushButton_seit_show_clicked(); break;
        case 3: _t->on_pushButton_down_clicked(); break;
        case 4: _t->on_pushButton_up_clicked(); break;
        case 5: _t->on_pushButton_table_clicked(); break;
        case 6: _t->on_pushButton_close_clicked(); break;
        case 7: _t->on_pushButton_lrc_show_clicked(); break;
        case 8: _t->on_pushButton_play_clicked(); break;
        case 9: _t->on_horizontalSlider_volume_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->open_music((*reinterpret_cast< std::add_pointer_t<musicCore*>>(_a[1]))); break;
        case 11: _t->build_dir(); break;
        case 12: _t->insert_now_time((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 13: _t->insert_end_time((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 14: _t->seit_play_value((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->build_lyric_show((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->select_lrc((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->clear_lyric_show(); break;
        case 18: _t->writer_data(); break;
        case 19: _t->read_data(); break;
        case 20: _t->mousePressEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 21: _t->mouseMoveEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 22: _t->set_bakcgroung_pic((*reinterpret_cast< std::add_pointer_t<QImage*>>(_a[1]))); break;
        case 23: _t->on_pushButton_value_clicked(); break;
        case 24: _t->set_font_type((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_pushButton_min_clicked(); break;
        case 26: _t->updateAudioDevice(); break;
        case 27: _t->set_void_play(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(bool , QString );
            if (_t _q_method = &MainWindow::playNext; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::playNext(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP

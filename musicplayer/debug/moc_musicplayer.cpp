/****************************************************************************
** Meta object code from reading C++ file 'musicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../musicplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicPlayer_t {
    QByteArrayData data[21];
    char stringdata[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPlayer_t qt_meta_stringdata_MusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MusicPlayer"
QT_MOC_LITERAL(1, 12, 8), // "openFile"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "playFile"
QT_MOC_LITERAL(4, 31, 8), // "filePath"
QT_MOC_LITERAL(5, 40, 14), // "togglePlayback"
QT_MOC_LITERAL(6, 55, 11), // "seekForward"
QT_MOC_LITERAL(7, 67, 12), // "seekBackward"
QT_MOC_LITERAL(8, 80, 7), // "stylize"
QT_MOC_LITERAL(9, 88, 11), // "updateState"
QT_MOC_LITERAL(10, 100, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(11, 120, 5), // "state"
QT_MOC_LITERAL(12, 126, 14), // "updatePosition"
QT_MOC_LITERAL(13, 141, 8), // "position"
QT_MOC_LITERAL(14, 150, 14), // "updateDuration"
QT_MOC_LITERAL(15, 165, 8), // "duration"
QT_MOC_LITERAL(16, 174, 11), // "setPosition"
QT_MOC_LITERAL(17, 186, 10), // "updateInfo"
QT_MOC_LITERAL(18, 197, 11), // "handleError"
QT_MOC_LITERAL(19, 209, 13), // "updateTaskbar"
QT_MOC_LITERAL(20, 223, 22) // "updateThumbnailToolBar"

    },
    "MusicPlayer\0openFile\0\0playFile\0filePath\0"
    "togglePlayback\0seekForward\0seekBackward\0"
    "stylize\0updateState\0QMediaPlayer::State\0"
    "state\0updatePosition\0position\0"
    "updateDuration\0duration\0setPosition\0"
    "updateInfo\0handleError\0updateTaskbar\0"
    "updateThumbnailToolBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    1,   85,    2, 0x0a /* Public */,
       5,    0,   88,    2, 0x0a /* Public */,
       6,    0,   89,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    1,   92,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,
      19,    0,  106,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::LongLong,   13,
    QMetaType::Void, QMetaType::LongLong,   15,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicPlayer *_t = static_cast<MusicPlayer *>(_o);
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->playFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->togglePlayback(); break;
        case 3: _t->seekForward(); break;
        case 4: _t->seekBackward(); break;
        case 5: _t->stylize(); break;
        case 6: _t->updateState((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 7: _t->updatePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->updateDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateInfo(); break;
        case 11: _t->handleError(); break;
        case 12: _t->updateTaskbar(); break;
        case 13: _t->updateThumbnailToolBar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    }
}

const QMetaObject MusicPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MusicPlayer.data,
      qt_meta_data_MusicPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPlayer.stringdata))
        return static_cast<void*>(const_cast< MusicPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

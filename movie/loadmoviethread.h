#ifndef LOADMOVIETHREAD_H
#define LOADMOVIETHREAD_H

#include <QThread>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>
#include "mainwindow.h"

class PlayLinemoviethread : public QThread {
    Q_OBJECT
public:
    PlayLinemoviethread(QObject *parent=0);
    ~PlayLinemoviethread();
protected:
    void run();
};


#endif // LOADMOVIETHREAD_H


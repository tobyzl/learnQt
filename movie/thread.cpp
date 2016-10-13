#include "thread.h"

MyThread::MyThread(QObject *parent)
{
   number = 0;
}

MyThread::~MyThread()
{

}

void MyThread::run()
{

}

void MyThread::urlSlot(QString url)
{
    QMediaPlayer *player = new QMediaPlayer;

    QVideoWidget *videoWidget = new QVideoWidget;

    player->setVideoOutput(videoWidget);

    player->setMedia(QUrl(url));

    videoWidget->show();
    player->play();
}




#include "loadmoviethread.h"

PlayLinemoviethread::PlayLinemoviethread(QObject *parent)
{
}

PlayLinemoviethread::~PlayLinemoviethread()
{

}

void PlayLinemoviethread::run() {
    QMediaPlayer *player = new QMediaPlayer;

    QVideoWidget *videoWidget = new QVideoWidget;

    player->setVideoOutput(videoWidget);
}


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

    //QUrl url = ui->lineEdit->text();

   // player->setMedia(QUrl(url));
   // videoWidget->show();
    //player->play();
}

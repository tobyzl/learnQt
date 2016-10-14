#include "musicplayer.h"

#include <QApplication>
#include <QFileInfo>
#include <QSettings>
#include <QIcon>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MusicPlayer player;

    player.resize(600, 120);
    player.show();


    return a.exec();
}

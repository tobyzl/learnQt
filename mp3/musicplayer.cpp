#include "musicplayer.h"
//#include "volumebutton.h"

#include <QtWidgets>
#include <QtWinExtras>

MusicPlayer::MusicPlayer(QWidget *parent) : QWidget(parent),
    taskbarButton(0), taskbarProgress(0), thumbnailToolBar(0),
    playToolButton(0), forwardToolButton(0), backwardToolButton(0),
    mediaPlayer(0), playButton(0), volumeButton(0),
    positionSlider(0), positionLabel(0), infoLabel(0)
{
   createWidgets();/*
    createShortcuts();
    createJumpList();
    createTaskbar();
    createThumbnailToolBar();

    connect(&mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(updatePosition(qint64)));
    connect(&mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(updateDuration(qint64)));
    connect(&mediaPlayer, SIGNAL(metaDataAvailableChanged(bool)), this, SLOT(updateInfo()));
    connect(&mediaPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(handleError()));
    connect(&mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(updateState(QMediaPlayer::State)));

    stylize();*/
}

void MusicPlayer::createWidgets()
{
    playButton = new QToolButton(this);
    playButton->setEnabled(false);
    playButton->setToolTip(tr("Play"));
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    //connect(playButton, SIGNAL(clicked()), this, SLOT(togglePlayback()));

    QAbstractButton *openButton = new QToolButton(this);
    openButton->setText(tr("..."));
    openButton->setToolTip(tr("Open a file..."));
    openButton->setFixedSize(playButton->sizeHint());
   // connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

    //volumeButton = new VolumeButton(this);
    //volumeButton->setToolTip(tr("Adjust volume"));
   // volumeButton->setVolume(mediaPlayer.volume());
    //connect(volumeButton, SIGNAL(volumeChanged(int)), &mediaPlayer, SLOT(setVolume(int)));

    positionSlider = new QSlider(Qt::Horizontal, this);
    positionSlider->setEnabled(false);
    positionSlider->setToolTip(tr("Seek"));
    //connect(positionSlider, SIGNAL(valueChanged(int)), this, SLOT(setPosition(int)));

    infoLabel = new QLabel(this);
    positionLabel = new QLabel(tr("00:00"), this);
    positionLabel->setMinimumWidth(positionLabel->sizeHint().width());

    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionSlider);
    controlLayout->addWidget(positionLabel);
    //controlLayout->addWidget(volumeButton);

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(controlLayout);
}


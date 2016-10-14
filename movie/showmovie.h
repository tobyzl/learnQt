
#ifndef SHOWMOVIE_H
#define SHOWMOVIE_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>

class VolumeButton;

QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QAbstractButton)
QT_FORWARD_DECLARE_CLASS(QWinTaskbarButton)
QT_FORWARD_DECLARE_CLASS(QWinTaskbarProgress)
QT_FORWARD_DECLARE_CLASS(QWinThumbnailToolBar)
QT_FORWARD_DECLARE_CLASS(QWinThumbnailToolButton)

class ShowMovieWidget : public QWidget
{
    Q_OBJECT
public:
    ShowMovieWidget(QWidget *parent = 0);

public slots:
    void togglePlayback();
    void updateState(QMediaPlayer::State state);

    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void seekForward();
    void seekBackward();
    void setPosition(int position);
 /*
protected:
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void stylize();



    void updateInfo();
    void handleError();

    void updateTaskbar();
    void updateThumbnailToolBar();*/

private:

    void createWidgets();/*
    void createShortcuts();
    void createJumpList();
    void createTaskbar();
    void createThumbnailToolBar();*/

    QWinTaskbarButton* taskbarButton;
    QWinTaskbarProgress* taskbarProgress;
    QWinThumbnailToolBar* thumbnailToolBar;
    QWinThumbnailToolButton *playToolButton;
    QWinThumbnailToolButton *forwardToolButton;
    QWinThumbnailToolButton *backwardToolButton;

    //QMediaPlayer mediaPlayer;
    QAbstractButton *playButton;
    VolumeButton *volumeButton;
    QSlider *positionSlider;
    QLabel *positionLabel;
    QPoint offset;
public:
    QVideoWidget *playMovieWidget;
     QMediaPlayer *player;
};

#endif // SHOWMOVIE_H


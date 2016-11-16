#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFile>
#include <QDebug>
#include <QWebView>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTextCodec>
#include <QUrl>
#include <QEvent>
#include <QFileInfo>
#include <QIODevice>
#include "showmovie.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
   void playMovie();
signals:
    void urlSignal(QString str);
public slots:
    void loadAndPlayMovie();
    void httpFinished(); //完成下载后的处理
    void httpReadyRead(); // 接受到数据的处理
private:
    Ui::MainWindow *ui;
    //QNetworkAccessManager *manager;
    QPushButton *pushButton;
    QNetworkReply *reply;

    QFile *file;
};

#endif // MAINWINDOW_H

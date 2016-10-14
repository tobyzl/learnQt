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
#include "loadmoviethread.h"
#include "thread.h"
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

    void webView();
    void startRequest(QUrl url); // 请求链接
    QUrl returnQUrl() { return url;}
protected:
   void playMovie();
signals:
    void urlSignal(QString str);
public slots:
    void loadAndPlayMovie();
    void replyFinished(QNetworkReply *);
    void loadMovie();
    void httpFinished(); //完成下载后的处理
    void httpReadyRead(); // 接受到数据的处理
    void updateDateReadProgress(qint64, qint64); // 更新进度条
private:
    MyThread *myThread;
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QPushButton *pushButton;
    QNetworkReply *reply;
    QUrl url;
    QFile *file;
};

#endif // MAINWINDOW_H

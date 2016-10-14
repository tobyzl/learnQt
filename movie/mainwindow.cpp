#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // webView();
    myThread = new MyThread;
    myThread->start();

   connect(this, SIGNAL(urlSignal(QString)), myThread, SLOT(urlSlot(QString)));

  // myThread->wait()


    manager = new QNetworkAccessManager(this);
    //connect(manager,SIGNAL(finished(QNetworkReply*)), this,SLOT(replyFinished(QNetworkReply*)));
    //manager->get(QNetworkRequest(QUrl("http://www.padsystem.com"))); //发送请求
    ui->progressBar->hide();


    pushButton = new QPushButton("movie");
    connect(pushButton, SIGNAL(clicked()), this, SLOT(loadAndPlayMovie()));
    statusBar()->addPermanentWidget(pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAndPlayMovie() {
    QString urlStr = ui->lineEdit->text();

    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());

    QFile *loacalFile = new QFile(fileName);
    if (!loacalFile->open(QIODevice::ReadOnly)) {
        delete loacalFile;
        loacalFile = NULL;
        emit urlSignal(urlStr);
        loadMovie();
    } else {
        playMovie();
    }
}


void MainWindow::replyFinished(QNetworkReply *reply) {
  QTextCodec *codec = QTextCodec::codecForName("utf8");
  //使用utf8编码，这样才可以显示中文
  QString all = codec->toUnicode(reply->readAll());
  //ui->textBrowser->setText(all);
  reply->deleteLater();   //最后要释放reply对象
}


void MainWindow::playMovie() {
    //QMediaPlayer *player = new QMediaPlayer;

    ShowMovieWidget *videoWidget = new ShowMovieWidget;

    QVideoWidget *playMovie = videoWidget->playMovieWidget;
    videoWidget->player->setVideoOutput(playMovie);
   // player->setVideoOutput(videoWidget->playMovieWidget);

    //QString fileNamePath = "F:/learnQt/movie/build/";
    //fileNamePath += fileName;

   // char* filePath;
    //QByteArray path = file->fileName().toLatin1();
   // filePath = path.data();

    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());

    //player->setMedia(QUrl(url));
    //player->setMedia(QUrl::fromLocalFile(QString::fromLocal8Bit(filePath)));
    videoWidget->player->setMedia(QUrl::fromLocalFile(fileName));
  // player->setMedia(QUrl("http://example.com/movie3.mp4"));
    videoWidget->setWindowTitle(fileName);

    videoWidget->resize(822, 500);
    //playMovie->show();

    videoWidget->show();
    videoWidget->player->play();
}

void MainWindow::loadMovie() {
    url = ui->lineEdit->text();
    // ttp://www.padsystem.com/PadSystemWeb/en/static/movie/p02_Zoom.mp4

    QFileInfo info(url.path());
    QString fileName(info.fileName());
    // 获取文件名

   // playMovie();

    if (fileName.isEmpty()) {
        fileName = "test.html";
    }

    //fileName += "F:\learnQt\movie";
    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        qDebug() << "open file error";
        delete file;
        file = NULL;
        return;
    }

    startRequest(url); // 进行连接请求
    ui->progressBar->setValue(0);
     ui->progressBar->show();
}

void MainWindow::startRequest(QUrl url) { // 链接请求
    reply = manager->get(QNetworkRequest(url));

    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead())); // 有可用数据

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateDateReadProgress(qint64,qint64))); // 更新进度条

    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished())); // 下载完后
}


void MainWindow::httpReadyRead() { // 有可用数据
    if (file) {
        file->write(reply->readAll());
    }
}

void MainWindow::updateDateReadProgress(qint64 bytesRead, qint64 totalBytes) { // 有可用数据
    ui->progressBar->setMaximum(totalBytes); // 最大值
    ui->progressBar->setValue(bytesRead); // 当前值
}

void MainWindow::httpFinished() { // 完成下载
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = NULL;
    delete file;
    file = NULL;
}

void MainWindow::webView() {
    QWebView *view = new QWebView();
    view->load(QUrl("http://www.padsystem.com"));
    view->show();
}




//*mediaStatusChanged(QMediaPlayer::MediaStatus) // 这个是音视频状态改变的信号， 如：暂停， 停止， 播放，它都能直接监控

// ///durationChanged(qint64)//这个是播放文件数据总大小的信号， 它可以获得文件时间长度。


//positionChanged(qint64)// 这个是播放到什么位置的信号， 参数是以毫秒来计算的。


//volumeChanged(int)// 这个是声音调节的信号，监控当前声音的大小


//mutedChanged(bool)//这个是是否为静音的信号。*/

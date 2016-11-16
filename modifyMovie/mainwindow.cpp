#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myThread = new MyThread;
    myThread->start();


    ShowMovieWidget *videoWidget = new ShowMovieWidget;
    QVideoWidget *playMovie = videoWidget->playMovieWidget;
    videoWidget->player->setVideoOutput(playMovie);
    videoWidget->player->setMedia(QUrl("https://www.padsystem.com/PadSystemWeb/en/static/movie/p23_Walking_Piece.mp4"));
    videoWidget->resize(822, 500);
    videoWidget->show();
    videoWidget->player->play();

    connect(this, SIGNAL(urlSignal(QString)), myThread, SLOT(urlSlot(QString)));
    manager = new QNetworkAccessManager(this);
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
  QString all = codec->toUnicode(reply->readAll());
  reply->deleteLater();
}


void MainWindow::playMovie() {
    ShowMovieWidget *videoWidget = new ShowMovieWidget;

    QVideoWidget *playMovie = videoWidget->playMovieWidget;
    videoWidget->player->setVideoOutput(playMovie);

    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());

    videoWidget->player->setMedia(QUrl::fromLocalFile(fileName));
    videoWidget->setWindowTitle(fileName);
    videoWidget->resize(822, 500);
    videoWidget->show();
    videoWidget->player->play();
}

void MainWindow::loadMovie() {
    url = ui->lineEdit->text();

    QFileInfo info(url.path());
    QString fileName(info.fileName());

    if (fileName.isEmpty()) {
        fileName = "test.html";
    }

    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        qDebug() << "open file error";
        delete file;
        file = NULL;
        return;
    }

    startRequest(url); // 进行连接请求
}

void MainWindow::startRequest(QUrl url) { // 链接请求
    reply = manager->get(QNetworkRequest(url));

    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead())); // 有可用数据
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished())); // 下载完后
}


void MainWindow::httpReadyRead() { // 有可用数据
    if (file) {
        file->write(reply->readAll());
    }
}


void MainWindow::httpFinished() {
    file->flush();
    file->close();
    reply->deleteLater();
    reply = NULL;
    delete file;
    file = NULL;
}


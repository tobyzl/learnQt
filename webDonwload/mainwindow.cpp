#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    pushButton = new QPushButton("movie");
    connect(pushButton, SIGNAL(clicked()), this, SLOT(loadAndPlayMovie()));
    statusBar()->addPermanentWidget(pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAndPlayMovie() {
     QUrl url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QFile *loacalFile = new QFile(info.fileName());
    QString fileName(info.fileName());


    if (!loacalFile->open(QIODevice::ReadOnly)) {
        delete loacalFile;
        loacalFile = NULL;


        if (fileName.isEmpty()) {
           return;
        }

        file = new QFile(fileName);
        if (!file->open(QIODevice::WriteOnly)) {
            qDebug() << "open file error";
            delete file;
            file = NULL;
            return;
        }

        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        reply = manager->get(QNetworkRequest(url));

        connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead())); // 有可用数据

        connect(reply, SIGNAL(finished()), this, SLOT(httpFinished())); // 下载完后

        qDebug() << "go ..." << endl;
    }

}

void MainWindow::httpReadyRead() { // 有可用数据
    if (file) {
        file->write(reply->readAll());
    }
}



void MainWindow::httpFinished() { // 完成下载
    file->flush();
    file->close();
    delete file;
    file = NULL;

    reply->deleteLater();
    reply = NULL;
}

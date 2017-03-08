#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pix;
    pix.load("./images/bird.png");
    painter.translate(100, 100); //将（100，100）设为坐标原点
    painter.drawPixmap(0, 0, 100, 66, pix);

    qreal width = pix.width(); //获得以前图片的宽和高
    qreal height = pix.height();
    //将图片的宽和高都扩大两倍，并且在给定的矩形内保持宽高的比值不变
    pix = pix.scaled(width/2, height/2, Qt::KeepAspectRatio);
    painter.drawPixmap(70, 70,pix);

    //让图片的中心作为旋转的中心
    painter.translate(64, 33);
    painter.rotate(90);
    //顺时针旋转90度
    painter.translate(-64,-33);
    //使原点复原
    painter.drawPixmap(100, 100, 129, 66, pix);

    painter.shear(0.5, 0); //横向扭曲
    painter.drawPixmap(100, 0, 129, 66, pix);

}

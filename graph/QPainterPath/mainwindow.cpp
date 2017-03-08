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
//    QPainterPath path;
//    path.addEllipse(100, 100, 50, 50);
//    path.lineTo(200, 200);
//    QPainter painter(this);
//    painter.setPen(Qt::blue);
//    painter.setBrush(Qt::red);
//    painter.drawPath(path);


//    QPainterPath path2;
//    path2.addPath(path);
//    path2.translate(100,0);
//    painter.drawPath(path2);

// 绘制图形时的当前位置

//    QPainterPath path;
//        path.lineTo(100,100);
//        path.lineTo(200,100);
//        QPainter painter(this);
//        painter.drawPath(path);

    QPainterPath path;
       path.addRect(50, 50, 40, 40);
       //移动到(100, 100)点
       path.moveTo(100, 100);
       path.lineTo(200, 200);
       QPainter painter(this);
       painter.drawPath(path);

}

























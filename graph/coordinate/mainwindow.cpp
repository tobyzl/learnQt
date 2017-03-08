#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
          qDebug() << event->pos();
}

 void MainWindow::paintEvent(QPaintEvent *) {
//     QPainter painter(this);
//      painter.setBrush(Qt::red);
//         painter.drawRect(0, 0, 100, 100);
//         painter.setBrush(Qt::yellow);
//         painter.drawRect(-50, -50, 100, 100);

         // 平移变换
//         QPainter painter(this);
//         painter.setBrush(Qt::yellow);
//         painter.drawRect(0, 0, 50, 50);
//         painter.translate(100, 100);  //将点（100，100）设为原点
//         painter.setBrush(Qt::red);
//         painter.drawRect(0, 0, 50, 50);
//         painter.translate(-100, -100);
//         painter.drawLine(0, 0, 20, 20);

       // 缩放
//        QPainter painter(this);
//        painter.setBrush(Qt::yellow);
//        painter.drawRect(0, 0, 100, 100);
//        painter.scale(4, 2); //放大两倍
//        painter.setBrush(Qt::red);
//        painter.drawRect(50, 50, 50, 50);

        // 扭曲
//                   QPainter painter(this);
//                   painter.setBrush(Qt::yellow);
//                   painter.drawRect(0, 0, 50, 50);
//                   painter.shear(0, 1); //纵向扭曲变形
//                   painter.setBrush(Qt::red);
//                   painter.drawRect(50, 0, 50, 50);

     // 旋转
//         QPainter painter(this);
//         painter.drawLine(0, 0, 100, 0);
//         painter.rotate(30); //以原点为中心，顺时针旋转30度
//         painter.drawLine(0, 0, 100, 0);
//         painter.translate(100, 100);
//         painter.rotate(30);
//         painter.drawLine(0, 0, 100, 0);

         // 旋转
  //             QPainter painter(this);
              // painter.drawLine(0, 0, 100, 0);
//               painter.rotate(30); //以原点为中心，顺时针旋转30度
//               painter.drawLine(0, 0, 100, 0);
//               painter.rotate(-30); // 反向旋转
//               painter.translate(100, 100);
//               painter.rotate(30);
//               painter.drawLine(0, 0, 100, 0);

//               QPainter painter(this);
//               painter.save(); //保存坐标系状态
//                  painter.translate(100,100);
//                  painter.drawLine(0, 0, 50, 50);
//                  painter.restore(); //恢复以前的坐标系状态
//                  painter.drawLine(0, 0, 50, 50);



//     QPainter painter(this);
//         QPixmap pix(200, 200);
//         pix.fill(Qt::red);   //背景填充为红色

//         //新建QPainter类对象，在pix上进行绘图
//            QPainter pp(&pix);
//            //在pix上的（0，0）点和（50，50）点之间绘制直线
//            pp.drawLine(0, 0, 50, 50);
//         painter.drawPixmap(100, 100, pix);


         QPainter painter(this);
            QPixmap pix(200,200);
            //放大前输出画布的大小
            qDebug() << "1: " << pix.size();
            pix.fill(Qt::red);
            QPainter pp(&pix);
            //画布的坐标扩大2倍
            pp.scale(2, 2);
            //在画布上的（0，0）点和（50，50）点之间绘制直线
            pp.drawLine(0, 0, 50, 50);
            //放大后输出画布的大小
            qDebug() << "2: " << pix.size();
            painter.drawPixmap(0, 0, pix);
 }





















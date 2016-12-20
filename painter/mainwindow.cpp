#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

static const QPointF points[4] = {
    QPointF(10.0, 80.0),
    QPointF(20.0, 10.0),
    QPointF(80.0, 30.0),
    QPointF(90.0, 70.0)
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    //QPainter painter(this);
    //QRectF rect(10.0, 20.0, 80.0, 60.0);



    //painter.drawLine(QPointF(0,0), QPointF(100, 100));
    //painter.drawEllipse(rectangle);

   // painter.drawConvexPolygon(points, 4);
    //painter.drawText(rect, Qt::AlignCenter, tr("Qt\nProject"));



//    QPen pen;
//    pen.setColor(QColor(255, 0, 0));

//    QBrush brush(QColor(0, 255, 0, 125));

//    painter.setPen(pen);
//    painter.setBrush(brush);

//    painter.drawRect(50, 50, 200, 100);

//    QPainter painter(this);
//    QPen pen(Qt::DotLine);
//    QBrush brush(Qt::blue);
//    brush.setStyle(Qt::HorPattern);

//    painter.setPen(pen);
//    painter.setBrush(brush);
//    painter.drawRect(60, 60, 200, 200);

    QPainter painter(this);

    QRectF rectangle(50, 50, 100, 100);
    int startAngle = 30*16;
    int spandAngle = 120*16;

    painter.drawArc(rectangle, startAngle, spandAngle);

}

void MainWindow::pen() {
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor(255, 0, 0));

    QBrush brush(QColor(0, 255, 0, 125));

    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(50, 50, 200, 100);
}

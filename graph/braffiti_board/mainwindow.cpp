#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600, 500);    //窗口大小设置为600*500
    pix = QPixmap(500, 500);
    pix.fill(Qt::green);

    //设置初始放大倍数为1，即不放大
    scale =1;
    //新建按钮对象
    button_zoomin = new QPushButton(this);
    //设置按钮显示文本
    button_zoomin->setText(tr("zoomIn"));
    //设置按钮放置位置
    button_zoomin->move(500, 450);
    //对按钮的单击事件和其槽函数进行关联
    connect(button_zoomin, SIGNAL(clicked()), this, SLOT(zoomIn()));

    button_zoomout = new QPushButton(this);
    //设置按钮显示文本
    button_zoomout->setText(tr("zoomOut"));
    //设置按钮放置位置
    button_zoomout->move(500, 400);
    //对按钮的单击事件和其槽函数进行关联
    connect(button_zoomout, SIGNAL(clicked()), this, SLOT(zoomOut()));
    isDrawing = false;

}

void MainWindow::zoomIn() {
    scale *=2;
    update();
}

void MainWindow::zoomOut() {
    scale /=2;
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
//      QPainter pp(&pix);
//      // 根据鼠标指针前后两个位置就行绘制直线
//      pp.drawLine(startPoint, endPoint);
//      // 让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线
//      startPoint = endPoint;
//      QPainter painter(this);
//      painter.drawPixmap(0, 0, pix);

//    QPainter pp(&pix);
//        pp.drawLine(startPoint/scale, endPoint/scale);
//        startPoint = endPoint;
//        QPainter painter(this);
//        //进行放大操作
//        painter.scale(scale, scale);
//        painter.drawPixmap(0, 0, pix);

//    QPainter pp(&pix);
//        pp.scale(scale, scale);
//        pp.drawLine(startPoint,endPoint);
//        startPoint = endPoint;
//        QPainter painter(this);
//        painter.drawPixmap(0, 0, pix);

//    if(scale > 1) //如果进行放大操作
//       {
//          //临时画布，大小变化了scale倍
//          QPixmap copyPix(pix.size()*scale);
//          QPainter pter(&copyPix);
//          pter.scale(scale, scale);
//          //将以前画布上的内容复制到现在的画布上
//          pter.drawPixmap(0, 0, pix);
//          //将放大后的内容再复制回原来的画布上
//          pix = copyPix;
//          //让scale重新置1
//          scale =1;
//       }
//    if(scale < 1) //如果进行放大操作
//       {
//          //临时画布，大小变化了scale倍
//          QPixmap copyPix(pix.size()*scale);
//          QPainter pter(&copyPix);
//          pter.scale(scale, scale);
//          //将以前画布上的内容复制到现在的画布上
//          pter.drawPixmap(0, 0, pix);
//          //将放大后的内容再复制回原来的画布上
//          pix = copyPix;
//          //让scale重新置1
//          scale =1;
//       }
//       QPainter pp(&pix);
//       pp.scale(scale,scale);
//       pp.drawLine(startPoint/scale,endPoint/scale);
//       startPoint = endPoint;
//       QPainter painter(this);
//       painter.drawPixmap(0,0,pix);

//    QPainter painter(this);
//       int x,y,w,h;
//       x = startPoint.x();
//       y = startPoint.y();
//       w = endPoint.x() - x;
//       h = endPoint.y() - y;
//       painter.drawRect(x, y, w, h);

//    int x,y,w,h;
//        x = startPoint.x();
//        y = startPoint.y();
//        w = endPoint.x() - x;
//        h = endPoint.y() - y;
//        QPainter pp(&pix);
//        pp.drawRect(x, y, w, h);
//        QPainter painter(this);
//        painter.drawPixmap(0, 0, pix);

    int x,y,w,h;
        x = startPoint.x();
        y = startPoint.y();
        w = endPoint.x() - x;
        h = endPoint.y() - y;
        QPainter painter(this);
        if(isDrawing) //如果正在绘图，就在辅助画布上绘制
        {
           //将以前pix中的内容复制到tempPix中，保证以前的内容不消失
           tempPix = pix;
           QPainter pp(&tempPix);
           pp.drawRect(x,y,w,h);
           painter.drawPixmap(0, 0, tempPix);
        } else {
           QPainter pp(&pix);
           pp.drawRect(x,y,w,h);
           painter.drawPixmap(0,0,pix);
        }
}


 //  这里使用了两个点来绘制线条，这两个点在下面的鼠标事件中获得。
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //鼠标左键按下
         if(event->button()==Qt::LeftButton) {
              startPoint = event->pos();
              isDrawing = true;   //正在绘图
         }
}


 // 当鼠标左键按下时获得开始点。
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
         if(event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
        {
                   endPoint = event->pos();
                  update(); //进行绘制
         }
}

//当鼠标移动时获得结束点，并更新绘制。调用update()函数会执行paintEvent()函数进行重新绘制。
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
            if(event->button() == Qt::LeftButton) //鼠标左键释放
             {
                      endPoint = event->pos();
                      isDrawing = false;    //结束绘图
                      update();
             }
}







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

        //设置一个矩形
        QRectF rect(20, 20, 300, 200);
        //为了更直观地看到字体的位置，我们绘制出这个矩形
        painter.drawRect(rect);
        painter.setPen(QColor(Qt::red));
        //我们这里先让字体水平居中
        painter.drawText(rect, Qt::AlignHCenter, "yafeilinux");

        QFont font("宋体", 15, QFont::Bold, true);
        //设置下划线
        font.setUnderline(true);
        //设置上划线
        font.setOverline(true);
        //设置字母大小写
        font.setCapitalization(QFont::SmallCaps);
        //设置字符间的间距
        font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
        //使用字体
        painter.setFont(font);
        painter.setPen(Qt::green);
        painter.drawText(120, 80, tr("yafeilinux"));


        painter.translate(50, 50);
        painter.rotate(90);
        painter.drawText(0, 0, tr("helloqt"));
}

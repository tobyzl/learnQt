#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
    //this->setFixedSize(1000, 500);
    QString text = "aaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbccccccccccccddddddddddddddddddddeeeeeeeeeefffffffffffff";

    QFont font;
    QFontMetrics font_metrics(font);
    QString str = font_metrics.elidedText(text, Qt::ElideRight, 500);
    label = new QLabel(str);
    label->setMinimumWidth(1);
    //label->setMaximumWidth(500);
    label->setMaximumHeight(20);


    statusBar()->addWidget(label);

}

MainWindow::~MainWindow()
{
    delete ui;
}

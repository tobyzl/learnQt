#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *label = new QLabel("hello");

    //label->setWordWrap(true);

    label->setText("aaaaaaabbbbbbbbbccccccccccccccccddddddddddd\nddddddddeeeeeeee222222222222666666666666666\n6666666666666622222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222255555555555eeeeeeeeeeffffffffffffffffffff888888888888888");

    statusBar()->addPermanentWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

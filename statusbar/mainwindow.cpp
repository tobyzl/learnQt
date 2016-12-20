#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *label = new QLabel("hello");

    //label->setWordWrap(true);

    label->setText("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa6666666666666");

    statusBar()->addPermanentWidget(label, 0);
    //statusBar()->addWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

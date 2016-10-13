#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myThread = new MyThread;

    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopSlot()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startSlot()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(clearSlot()));
    connect(this, SIGNAL(resetSignal()), myThread, SLOT(resetSlot()));

     connect(myThread, SIGNAL(updateSignal(int)), this, SLOT(updateSlot(int)));


    //myThread->start();
   // myThread->wait();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSlot()
{
   myThread->start();
}

void MainWindow::stopSlot()
{
    myThread->terminate();
}

void MainWindow::updateSlot(int num)
{
   ui->label->setText(QString::number(num));
}

void MainWindow::clearSlot()
{
    emit resetSignal();
}


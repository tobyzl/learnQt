#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->pushButton->setIcon(QIcon("movie.png"));
    //ui->pushButton->setStylesheet("border-image: url(:/movie.png);");
    // ui->pushButton->setStylesheet("border-image: url(:/movie.png);");

    ui->pushButton->resize(16, 16);

    QPixmap mypixmap(":/movie.png");

     //ui->pushButton->setIcon(mypixmap);
     //ui->pushButton->setIconSize(QSize(20 ,10));

     ui->pushButton->setFixedSize( 16, 16);
    // ui->pushButton->setMask(mypixmap.createHeuristicMask());
     ui->pushButton->setIcon(mypixmap);
     ui->pushButton->setIconSize(QSize(16,16));


    // ui->pushButton->resize(QPixmap(":/movie.png").size());

     statusBar()->addWidget(ui->pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

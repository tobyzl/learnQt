#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString folderName = "marker_file";
    QDir dir(folderName);
    foreach(QFileInfo mfi, dir.entryInfoList())
    {
         if (mfi.isFile())
         {
             qDebug() << "File :" << mfi.fileName();
          }
             else
          {
              if (mfi.fileName() == "." || mfi.fileName() == "..")continue;
              qDebug() << "Entry Dir" << mfi.absoluteFilePath();
                    //chakan(mfi.absoluteFilePath());
              }
         }
}

MainWindow::~MainWindow()
{
    delete ui;
}

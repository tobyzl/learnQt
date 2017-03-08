#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QProcess::startDetached(tr("E:\\pad7.0\\build\\Win32\\Debug\\Pattern.exe"),
    //                        QStringList("E:\\pad7.0\\build\\Win32\\Debug\\pattern_file\\BLK_M_Shirt Gr.sty"));

    QProcess::startDetached("E:\\pad7.0\\build\\Win32\\Debug\\Marker.exe",
                    QStringList("E:\\pad7.0\\build\\Win32\\Debug\\marker_file\\5099 Jacket.mar"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

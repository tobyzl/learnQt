#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox::information(NULL, "title", "content",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    QMessageBox::critical(NULL, "critical", "content",
                          QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    QMessageBox::warning(NULL, "warning", "contnt",
                         QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    QMessageBox::question(NULL, "question", "content",
                          QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);



    QMessageBox::about(NULL, "about", "about this <font color='red'>application</font>");

    QMessageBox message(QMessageBox::NoIcon, "title", "content with icon");
    message.setIconPixmap(QPixmap("icon.png"));
    message.exec();

    QMessageBox::StandardButton standar_button = QMessageBox::question(NULL,
                          "show qt", "Do you want to show qt dialog ?",
                          QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (standar_button == QMessageBox::Yes) {
        QMessageBox::aboutQt(NULL, "about qt");
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

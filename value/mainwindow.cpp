#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QXmlStreamWriter>
#include <QDomNode>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file_name("test.xml");
    if (!file_name.open(QIODevice::ReadOnly)) {
         qDebug() << "open file failed" << endl;
    }

    QDomDocument doc;
    if (!doc.setContent(&file_name)) {
        qDebug() << "doc set content failed" << endl;
    }

    QDomNodeList nodes = doc.elementsByTagName("IP");
    QDomNode node = nodes.at(0);
    QString new_value = "192.168.50.57";
    node.firstChild().setNodeValue(new_value);

    file_name.close();

    QFile file("test.xml");
    if (!file.open(QIODevice::WriteOnly)) {
         qDebug() << "open file failed" << endl;
    }
    QString content = doc.toString();
    file.write(content.toLatin1());
}

MainWindow::~MainWindow()
{
    delete ui;
}

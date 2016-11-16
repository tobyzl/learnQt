#include "mainwindow.h"
#include <QApplication>
#include <QWebView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebView view;

    view.load(QUrl("http://www.baidu.com"));
    view.show();


    return a.exec();
}

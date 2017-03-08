#include <QCoreApplication>
#include <QDebug>
#include <QPluginLoader>
#include <QFile>

#include "MyInterface.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "plugin..." << endl;

    QPluginLoader loader(QCoreApplication::applicationDirPath().append("/MyPlugin.dll"));
    QObject *obj = qobject_cast<QObject *>(loader.instance());

    if (obj) {
        MyInterface *plugin = qobject_cast<MyInterface *>(obj);
        if (plugin) {
            qDebug() << "string : " << plugin->getString() << endl;
        } else {
            qDebug() << "plugin error" << endl;
        }
    } else {
        qDebug() << "object error" << endl;
    }

    a.exec();

    return 0;
}

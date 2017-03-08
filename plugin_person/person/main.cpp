#include <QCoreApplication>
#include <QDebug>
#include <QPluginLoader>
#include <QFile>

#include "personinterface.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "person..." << endl;

    QPluginLoader loader(QCoreApplication::applicationDirPath().append("/xiaoming.dll"));

    QObject *obj = qobject_cast<QObject *>(loader.instance());

    if (obj) {
        PersonInterface *person = qobject_cast<PersonInterface *>(obj);

        if (person) {
            qDebug() << "load success" << endl;
            qDebug() << "name : " << person->name() << endl;
            qDebug() << "age : " << person->age() << endl;
             person->sing();
        } else {
            qDebug() << "person error" << endl;
        }
    } else {
        qDebug() << "object error" << endl;
    }

    a.exec();

    return 0;
}

#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QDir>
#include <QDebug>


void file_lower_upper(QDir dir) {
    QString new_name;
    QStringList imgs = dir.entryList(QDir::Files);
    foreach (const QString& img, imgs) {
        if (1) {
           new_name = img.toLower();
        } else {
            new_name = img.toUpper();
        }
        QFile::rename(img, new_name);
    }
}

void file_space_underline(QDir dir) {
    QString new_name;
    QStringList imgs = dir.entryList(QDir::Files);
    foreach (const QString& img, imgs) {
        new_name = img;
        if (1) {
           new_name.replace(" ", "_");
        } else {
           new_name.replace("_", " ");
        }
        QFile::rename(img, new_name);
    }

    qDebug() << "ok" << endl;
}



int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QDir dir(a.applicationDirPath());

    file_lower_upper(dir);
    file_space_underline(dir);
    return a.exec();
}

void file_lower_upper() {

}

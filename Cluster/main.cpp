#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = a.applicationDirPath();
    QFile file(path + "/cluster.xml");
    if(!file.open(QIODevice::ReadOnly)){//file not found
        qDebug() << "file not found" << a.applicationDirPath();
        return 0;
    }
    QByteArray fileContent = file.readAll();
    QDomDocument doc;
    if (!doc.setContent(fileContent)) {
        qDebug() << "invalid file format";
        return 0;
    }

    QDomNodeList nodes = doc.elementsByTagName("wrap_type");
    QDir dir(a.applicationDirPath());
    dir.cd("images");
    QStringList imgs = dir.entryList(QDir::Files);
    foreach (const QString& img, imgs) {
        QFileInfo info(img);
        QString name = info.baseName();
        QStringList strs = name.split("@");
        if (strs.size() == 3) {
            for (int i = 0; i < nodes.size(); ++i) {
                const QDomNode& node = nodes.at(i);
                if (node.isElement()) {
                    QDomElement elem = node.toElement();
                    QString str = elem.attribute("image");
                    if (str.contains(strs[0])) {
                        elem.setAttribute("quadrant", strs[1]);
                        elem.setAttribute("sequence", strs[2]);
                        doc.replaceChild(elem, node);
                    }
                }
            }
        }
    }
    QString content = doc.toString();
    QFile ff(path + "/cluster1.xml");
    if (ff.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        ff.write(content.toLatin1());
        qDebug() << "OK";
    }
    return a.exec();
}

#include <QCoreApplication>
#include <QtXml>

void read_file() {
    QDomDocument doc;
    QFile file("my.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "open file faild" << endl;
    }
    if (!doc.setContent(&file)) {
        qDebug() << "set content faild" << endl;
    }

    file.close();
    QDomNode firstNode = doc.firstChild();
    //qDebug() << "name:" << firstNode.nodeName() << endl
    //         << "value:" << firstNode.nodeValue() << endl;


    QDomElement docElem  = doc.documentElement();
    QDomNode node = docElem.firstChild();

    while (!node.isNull()) {


        if (node.isElement()) {
            QDomElement elem = node.toElement();
            qDebug() << elem.tagName()
                     << elem.attribute("id") << endl;

            QDomNodeList list = elem.childNodes();
            for (int i=0; i<list.count(); ++i) {
                QDomNode node = list.at(i);
                if (node.isElement()) {
                    qDebug() << "  " <<  node.toElement().tagName()
                             << "  " << node.toElement().text() << endl;
                }
            }

        }

        node = node.nextSibling();
    }


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    read_file();

    return a.exec();
}

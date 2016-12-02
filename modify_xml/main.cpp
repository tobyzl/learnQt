#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QXmlStreamWriter>
#include <QDomNode>

void read_xml() {
    QFile file("test.xml");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QXmlStreamReader reader(&file);

        while (!reader.atEnd()) {
            if (reader.isStartElement()) {
                QXmlStreamAttributes attributes = reader.attributes();
                if (attributes.hasAttribute("quadrant")) {
                    qDebug() << attributes.value("quadrant").toString();
                }
                if (attributes.hasAttribute("type")) {
                    qDebug() << attributes.value("type").toString();
                }
                if (attributes.hasAttribute("sequence")) {
                    qDebug() << attributes.value("sequence").toString();
                }
                if (attributes.hasAttribute("image")) {
                    qDebug() << attributes.value("image").toString() << endl;
                }

                if (reader.name() == "wrap_type") {
                    qDebug() << reader.readElementText() << endl;
                }
            }
            reader.readNext();
        }
    }    
}

void write_xml() {
    QFile file("out.xml");
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QXmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);
        writer.setAutoFormattingIndent(2); //设置自动缩进大小
        writer.writeStartDocument(); //写入xml文档头

        writer.writeStartElement("FileMsg"); //写入开始标记FileMsg
            writer.writeStartElement("DATA");  //写入开始标记DATA
            writer.writeAttribute("ID","id"); //在开始标记中写入属性ID
                writer.writeTextElement("FILENAME", "fileName"); //写入文本信息
                writer.writeTextElement("FILESIZE", "fileSize");
                writer.writeTextElement("LASTMODIFY", "atTime");
                writer.writeTextElement("FILETYPE", "fileType");
            writer.writeEndElement(); //写入结束标记DATA
        writer.writeEndElement();  //写入结束标记FileMsg

        writer.writeStartElement("xml");
            writer.writeStartElement("round");
            writer.writeAttribute("id", "1");
            writer.writeAttribute("tableid", "2");
            //player1
                writer.writeStartElement("player1");
                writer.writeAttribute("framescore", "mPlayer1Frame");
                writer.writeAttribute("points", "mPlayer1Point");
                writer.writeAttribute("break", "mPlayer1ContinuePoint");
                writer.writeCharacters("Hello World");   //添加内容
                writer.writeEndElement();
            //player2
                writer.writeStartElement("player2");
                writer.writeAttribute("framescore", "mPlayer2Frame");
                writer.writeAttribute("points", "mPlayer2Point");
                writer.writeAttribute("break", "mPlayer2ContinuePoint");
                writer.writeEndElement();
             writer.writeEndElement();
        writer.writeEndElement();


        writer.writeEndDocument(); //xml文档结束
        file.close();
    }
}

void modify_xml() {
    QFile file_name("t.xml");
    if (!file_name.open(QIODevice::ReadOnly)) {
        qDebug() << "open file failed" << endl;
    }

    QDomDocument doc;
    if (!doc.setContent(&file_name)) {
        qDebug() << "doc set content failed" << endl;
    }

    QDomNodeList nodes = doc.elementsByTagName("wrap_type");
    for (int i=0; i<nodes.size(); ++i) {
        const QDomNode &node = nodes.at(i);
        if (node.isElement()) {
            QDomElement elem = node.toElement();
            QString image_attribute = elem.attribute("image");
            elem.setAttribute("image", image_attribute.toLower());
            doc.replaceChild(elem, node);
        }
    }

    QString content = doc.toString();
    QFile new_file("new_file.xml");
    if (new_file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        new_file.write(content.toLatin1());
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    //write_xml();
    //read_xml();
    modify_xml();
    qDebug() << "end..." << endl;

    return a.exec();
}


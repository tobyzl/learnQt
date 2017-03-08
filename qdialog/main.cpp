#include "qdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qdialog w;
    w.show();

    return a.exec();
}

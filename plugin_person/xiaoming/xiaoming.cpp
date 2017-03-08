#include "xiaoming.h"

#include <QDebug>

QString Xiaoming::name() {
    return "xiaoming";
}

int Xiaoming::age() {
    return 10;
}

void Xiaoming::sing() {
    qDebug() << "xiaoming sing" << endl;
}

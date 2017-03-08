#ifndef XIAOMING_H
#define XIAOMING_H

#include "../person/personinterface.h"

class Xiaoming : public QObject, PersonInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PersonInterface_IID FILE "Person.json")
    Q_INTERFACES(PersonInterface)
public :
    QString name();
    int age();
    void sing();

};

#endif // XIAOMING_H


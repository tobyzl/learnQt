#ifndef PERSONINTERFACE_H
#define PERSONINTERFACE_H

#include <QString>
#include <QtPlugin>

#define PersonInterface_IID "org.qt-project.Qt.Person"

class PersonInterface {
public:
    virtual QString name() = 0;
    virtual int age() = 0;
    virtual void sing() = 0;

};

Q_DECLARE_INTERFACE(PersonInterface, PersonInterface_IID)

#endif // PERSONINTERFACE_H


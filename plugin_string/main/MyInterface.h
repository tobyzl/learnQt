#ifndef MYINTERFACE_H
#define MYINTERFACE_H
#include <QString>
#include <QtPlugin>

#define MyInterface_IID "org.qt-project.Qt.plugin"

class MyInterface {
public:
    MyInterface(){}
    virtual ~MyInterface() {}

    virtual QString getString() = 0;
};

// 将MyInterface和MyInterface_IID这一唯一标识符绑定
// 注意该操作不能在任何namespace内完成

Q_DECLARE_INTERFACE(MyInterface, MyInterface_IID)

#endif // MYINTERFACE_H


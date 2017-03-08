#ifndef MYPLUGIN
#define MYPLUGIN
#include <QtCore>
#include <QString>
#include <QObject>
#include "MyInterface.h"

class MyPlugin : public QObject, public MyInterface {
    Q_OBJECT
    //Q_PLUGIN_METADATA(IID MyInterface_IID FILE "plugin.json")
	Q_PLUGIN_METADATA(IID MyInterface_IID)
    // 将该接口注册到qt的meta-object system
    Q_INTERFACES(MyInterface)    
public:
    MyPlugin(){}
    virtual ~MyPlugin() {}
 public:
    virtual QString getString();
};

#endif // MYPLUGIN


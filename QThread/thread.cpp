#include "thread.h"

MyThread::MyThread(QObject *parent)
{
   number = 0;
}

MyThread::~MyThread()
{

}

void MyThread::run()
{
   while(1)
 {
      //开启一个死循环，让number每秒自增1，并通过发送UpdateSignal信号通知主界面更新
       emit updateSignal(number);
       number++;
       sleep(1);
   }
}

void MyThread::resetSlot()
{
    number = 0;
    emit updateSignal(number);
}



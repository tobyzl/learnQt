#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>

class MyThread : public QThread {
    Q_OBJECT
public:
    MyThread(QObject *parent=0);
    ~MyThread();

protected:
    void run();
signals:
    void updateSignal(int num);
public slots:
        void resetSlot();

private:
    int number;
};

#endif // THREAD_H


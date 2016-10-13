#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void resetSignal();
public slots:
    void clearSlot();
    void startSlot();
    void stopSlot();
    void updateSlot(int num);


private:
    Ui::MainWindow *ui;
    MyThread *myThread;
    int number;

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void zoomIn();
    void zoomOut();

private:
    QPushButton *button_zoomin;
    QPushButton *button_zoomout;
    Ui::MainWindow *ui;
    QPixmap pix;
    QPoint startPoint;
    QPoint endPoint;
    qreal scale;
    QPixmap tempPix; //辅助画布
    bool isDrawing;   //标志是否正在绘图

};

#endif // MAINWINDOW_H

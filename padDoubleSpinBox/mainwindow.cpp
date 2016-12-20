#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleSpinBox>
#include <QLabel>

class PADDoubleSpinBox : public QDoubleSpinBox {

public:
    virtual double valueFromText(const QString &text) const;
    virtual QString textFromValue(double val) const;
};

QString	PADDoubleSpinBox::textFromValue(double value) const{
    QString str = "3.00";
    return str;
}

 double	PADDoubleSpinBox::valueFromText(const QString & text) const{
    double value = 2.000;
    return value;
 }


};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PADDoubleSpinBox *pSpinBox = new PADDoubleSpinBox;
    pSpinBox->setRange(0, 20);  // 范围
    pSpinBox->setDecimals(3);  // 精度
    pSpinBox->setSingleStep(0.005); // 步长
    setCentralWidget(pSpinBox);

}

MainWindow::~MainWindow()
{
    delete ui;
}

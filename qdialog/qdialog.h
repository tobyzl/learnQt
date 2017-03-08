#ifndef QDIALOG_H
#define QDIALOG_H

#include <QMainWindow>

namespace Ui {
class qdialog;
}

class qdialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit qdialog(QWidget *parent = 0);
    ~qdialog();

private:
    Ui::qdialog *ui;
};

#endif // QDIALOG_H

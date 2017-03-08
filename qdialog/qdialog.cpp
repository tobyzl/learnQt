#include "qdialog.h"
#include "ui_qdialog.h"
#include <QDialog>

qdialog::qdialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qdialog)
{
   ui->setupUi(this);

   QDialog dialog;

   while (dialog.exec() == QDialog::Accepted) {
       const QString fileName = dlg.returnTablewidgetFileName();
        //const QString fileName = "BLK_W_Pants Gr";
        openShareFile(fileName);
       break;
  }

}

qdialog::~qdialog()
{
    delete ui;
}

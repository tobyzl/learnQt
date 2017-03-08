/********************************************************************************
** Form generated from reading UI file 'qdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOG_H
#define UI_QDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qdialog
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qdialog)
    {
        if (qdialog->objectName().isEmpty())
            qdialog->setObjectName(QStringLiteral("qdialog"));
        qdialog->resize(400, 300);
        menuBar = new QMenuBar(qdialog);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        qdialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qdialog);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qdialog->addToolBar(mainToolBar);
        centralWidget = new QWidget(qdialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qdialog->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qdialog);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qdialog->setStatusBar(statusBar);

        retranslateUi(qdialog);

        QMetaObject::connectSlotsByName(qdialog);
    } // setupUi

    void retranslateUi(QMainWindow *qdialog)
    {
        qdialog->setWindowTitle(QApplication::translate("qdialog", "qdialog", 0));
    } // retranslateUi

};

namespace Ui {
    class qdialog: public Ui_qdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOG_H

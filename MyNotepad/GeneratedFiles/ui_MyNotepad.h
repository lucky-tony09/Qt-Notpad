/********************************************************************************
** Form generated from reading UI file 'MyNotepad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYNOTEPAD_H
#define UI_MYNOTEPAD_H

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

class Ui_MyNotepadClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyNotepadClass)
    {
        if (MyNotepadClass->objectName().isEmpty())
            MyNotepadClass->setObjectName(QStringLiteral("MyNotepadClass"));
        MyNotepadClass->resize(600, 400);
        centralWidget = new QWidget(MyNotepadClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyNotepadClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyNotepadClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        MyNotepadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyNotepadClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyNotepadClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyNotepadClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyNotepadClass->setStatusBar(statusBar);

        retranslateUi(MyNotepadClass);

        QMetaObject::connectSlotsByName(MyNotepadClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyNotepadClass)
    {
        MyNotepadClass->setWindowTitle(QApplication::translate("MyNotepadClass", "MyNotepad", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyNotepadClass: public Ui_MyNotepadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYNOTEPAD_H

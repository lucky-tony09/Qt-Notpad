/********************************************************************************
** Form generated from reading UI file 'Replace.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACE_H
#define UI_REPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Replace
{
public:

    void setupUi(QWidget *Replace)
    {
        if (Replace->objectName().isEmpty())
            Replace->setObjectName(QStringLiteral("Replace"));
        Replace->resize(400, 300);

        retranslateUi(Replace);

        QMetaObject::connectSlotsByName(Replace);
    } // setupUi

    void retranslateUi(QWidget *Replace)
    {
        Replace->setWindowTitle(QApplication::translate("Replace", "Replace", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Replace: public Ui_Replace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACE_H

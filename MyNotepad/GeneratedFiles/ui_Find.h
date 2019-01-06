/********************************************************************************
** Form generated from reading UI file 'Find.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Find
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QWidget *widget;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QButtonGroup *radioGroup;

    void setupUi(QWidget *Find)
    {
        if (Find->objectName().isEmpty())
            Find->setObjectName(QStringLiteral("Find"));
        Find->setEnabled(true);
        Find->resize(312, 137);
        layoutWidget = new QWidget(Find);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 246, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        layoutWidget_2 = new QWidget(Find);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 50, 261, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        widget = new QWidget(layoutWidget_2);
        widget->setObjectName(QStringLiteral("widget"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 0, 54, 12));
        radioButton = new QRadioButton(widget);
        radioGroup = new QButtonGroup(Find);
        radioGroup->setObjectName(QStringLiteral("radioGroup"));
        radioGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 20, 51, 16));
        radioButton_2 = new QRadioButton(widget);
        radioGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(40, 40, 89, 16));

        horizontalLayout_2->addWidget(widget);


        retranslateUi(Find);

        QMetaObject::connectSlotsByName(Find);
    } // setupUi

    void retranslateUi(QWidget *Find)
    {
        Find->setWindowTitle(QApplication::translate("Find", "Find", Q_NULLPTR));
        label->setText(QApplication::translate("Find", "\346\237\245\346\211\276", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Find", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Find", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        label_2->setText(QApplication::translate("Find", "\346\226\271\345\220\221", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Find", "\345\220\221\345\211\215", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Find", "\345\220\221\345\220\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Find: public Ui_Find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H

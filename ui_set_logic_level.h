/********************************************************************************
** Form generated from reading UI file 'set_logic_level.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_LOGIC_LEVEL_H
#define UI_SET_LOGIC_LEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Set_logic_level
{
public:
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *cancel;

    void setupUi(QWidget *Set_logic_level)
    {
        if (Set_logic_level->objectName().isEmpty())
            Set_logic_level->setObjectName(QString::fromUtf8("Set_logic_level"));
        Set_logic_level->resize(215, 91);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Set_logic_level->sizePolicy().hasHeightForWidth());
        Set_logic_level->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Set_logic_level);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox = new QSpinBox(Set_logic_level);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QFont font;
        font.setPointSize(12);
        spinBox->setFont(font);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label = new QLabel(Set_logic_level);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setFocusPolicy(Qt::NoFocus);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(Set_logic_level);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setPointSize(9);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        cancel = new QPushButton(Set_logic_level);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cancel, 1, 1, 1, 1);


        retranslateUi(Set_logic_level);

        QMetaObject::connectSlotsByName(Set_logic_level);
    } // setupUi

    void retranslateUi(QWidget *Set_logic_level)
    {
        Set_logic_level->setWindowTitle(QCoreApplication::translate("Set_logic_level", "Form", nullptr));
        label->setText(QCoreApplication::translate("Set_logic_level", "Logic level", nullptr));
        pushButton->setText(QCoreApplication::translate("Set_logic_level", "OK", nullptr));
        cancel->setText(QCoreApplication::translate("Set_logic_level", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Set_logic_level: public Ui_Set_logic_level {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_LOGIC_LEVEL_H

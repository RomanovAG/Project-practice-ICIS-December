/********************************************************************************
** Form generated from reading UI file 'logical_element_properties.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGICAL_ELEMENT_PROPERTIES_H
#define UI_LOGICAL_ELEMENT_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logical_Element_Properties
{
public:
    QGridLayout *gridLayout;
    QPushButton *Cancel;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QPushButton *OK;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_6;

    void setupUi(QWidget *Logical_Element_Properties)
    {
        if (Logical_Element_Properties->objectName().isEmpty())
            Logical_Element_Properties->setObjectName(QString::fromUtf8("Logical_Element_Properties"));
        Logical_Element_Properties->resize(400, 300);
        gridLayout = new QGridLayout(Logical_Element_Properties);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Cancel = new QPushButton(Logical_Element_Properties);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 2, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBox = new QSpinBox(Logical_Element_Properties);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QFont font;
        font.setPointSize(12);
        spinBox->setFont(font);

        verticalLayout_2->addWidget(spinBox);

        spinBox_2 = new QSpinBox(Logical_Element_Properties);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setFont(font);

        verticalLayout_2->addWidget(spinBox_2);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        OK = new QPushButton(Logical_Element_Properties);
        OK->setObjectName(QString::fromUtf8("OK"));

        gridLayout->addWidget(OK, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Logical_Element_Properties);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Logical_Element_Properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinBox_5 = new QSpinBox(Logical_Element_Properties);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));

        gridLayout_2->addWidget(spinBox_5, 1, 1, 1, 1);

        spinBox_4 = new QSpinBox(Logical_Element_Properties);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        gridLayout_2->addWidget(spinBox_4, 0, 2, 1, 1);

        label_3 = new QLabel(Logical_Element_Properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        spinBox_3 = new QSpinBox(Logical_Element_Properties);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        verticalLayout_3->addWidget(spinBox_3);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 1, 1);

        spinBox_6 = new QSpinBox(Logical_Element_Properties);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));

        gridLayout_2->addWidget(spinBox_6, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 3);


        retranslateUi(Logical_Element_Properties);

        QMetaObject::connectSlotsByName(Logical_Element_Properties);
    } // setupUi

    void retranslateUi(QWidget *Logical_Element_Properties)
    {
        Logical_Element_Properties->setWindowTitle(QCoreApplication::translate("Logical_Element_Properties", "Form", nullptr));
        Cancel->setText(QCoreApplication::translate("Logical_Element_Properties", "Cancel", nullptr));
        OK->setText(QCoreApplication::translate("Logical_Element_Properties", "OK", nullptr));
        label->setText(QCoreApplication::translate("Logical_Element_Properties", "Number of inputs", nullptr));
        label_2->setText(QCoreApplication::translate("Logical_Element_Properties", "Number of outputs", nullptr));
        label_3->setText(QCoreApplication::translate("Logical_Element_Properties", "Truth table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logical_Element_Properties: public Ui_Logical_Element_Properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICAL_ELEMENT_PROPERTIES_H

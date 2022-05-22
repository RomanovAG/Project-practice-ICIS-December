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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logical_Element_Properties
{
public:
    QGridLayout *gridLayout;
    QPushButton *OK;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QFrame *line;
    QPushButton *delButton;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *inputNumBox;
    QSpinBox *outputNumBox;
    QSpinBox *delayBox;
    QGridLayout *gridLayout_2;
    QTextEdit *inputsTextEdit;
    QTextEdit *outputsTextEdit;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *Cancel;

    void setupUi(QWidget *Logical_Element_Properties)
    {
        if (Logical_Element_Properties->objectName().isEmpty())
            Logical_Element_Properties->setObjectName(QString::fromUtf8("Logical_Element_Properties"));
        Logical_Element_Properties->resize(400, 306);
        gridLayout = new QGridLayout(Logical_Element_Properties);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        OK = new QPushButton(Logical_Element_Properties);
        OK->setObjectName(QString::fromUtf8("OK"));

        gridLayout->addWidget(OK, 5, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Logical_Element_Properties);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Logical_Element_Properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_7 = new QLabel(Logical_Element_Properties);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        line = new QFrame(Logical_Element_Properties);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 2, 4);

        delButton = new QPushButton(Logical_Element_Properties);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        gridLayout->addWidget(delButton, 5, 0, 1, 1);

        label_3 = new QLabel(Logical_Element_Properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        nameEdit = new QLineEdit(Logical_Element_Properties);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setFont(font);

        gridLayout->addWidget(nameEdit, 0, 2, 1, 2);

        label_6 = new QLabel(Logical_Element_Properties);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        inputNumBox = new QSpinBox(Logical_Element_Properties);
        inputNumBox->setObjectName(QString::fromUtf8("inputNumBox"));
        inputNumBox->setFont(font);

        verticalLayout_2->addWidget(inputNumBox);

        outputNumBox = new QSpinBox(Logical_Element_Properties);
        outputNumBox->setObjectName(QString::fromUtf8("outputNumBox"));
        outputNumBox->setFont(font);

        verticalLayout_2->addWidget(outputNumBox);

        delayBox = new QSpinBox(Logical_Element_Properties);
        delayBox->setObjectName(QString::fromUtf8("delayBox"));
        delayBox->setFont(font);

        verticalLayout_2->addWidget(delayBox);


        gridLayout->addLayout(verticalLayout_2, 1, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        inputsTextEdit = new QTextEdit(Logical_Element_Properties);
        inputsTextEdit->setObjectName(QString::fromUtf8("inputsTextEdit"));

        gridLayout_2->addWidget(inputsTextEdit, 1, 0, 1, 1);

        outputsTextEdit = new QTextEdit(Logical_Element_Properties);
        outputsTextEdit->setObjectName(QString::fromUtf8("outputsTextEdit"));

        gridLayout_2->addWidget(outputsTextEdit, 1, 1, 1, 1);

        label_4 = new QLabel(Logical_Element_Properties);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(Logical_Element_Properties);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 2, 1, 2);

        Cancel = new QPushButton(Logical_Element_Properties);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 5, 3, 1, 1);


        retranslateUi(Logical_Element_Properties);

        QMetaObject::connectSlotsByName(Logical_Element_Properties);
    } // setupUi

    void retranslateUi(QWidget *Logical_Element_Properties)
    {
        Logical_Element_Properties->setWindowTitle(QCoreApplication::translate("Logical_Element_Properties", "Form", nullptr));
        OK->setText(QCoreApplication::translate("Logical_Element_Properties", "OK", nullptr));
        label->setText(QCoreApplication::translate("Logical_Element_Properties", "Number of inputs", nullptr));
        label_2->setText(QCoreApplication::translate("Logical_Element_Properties", "Number of outputs", nullptr));
        label_7->setText(QCoreApplication::translate("Logical_Element_Properties", "Delay", nullptr));
        delButton->setText(QCoreApplication::translate("Logical_Element_Properties", "Delete", nullptr));
        label_3->setText(QCoreApplication::translate("Logical_Element_Properties", "Truth table", nullptr));
        label_6->setText(QCoreApplication::translate("Logical_Element_Properties", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("Logical_Element_Properties", "Inputs", nullptr));
        label_5->setText(QCoreApplication::translate("Logical_Element_Properties", "Outputs", nullptr));
        Cancel->setText(QCoreApplication::translate("Logical_Element_Properties", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logical_Element_Properties: public Ui_Logical_Element_Properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICAL_ELEMENT_PROPERTIES_H

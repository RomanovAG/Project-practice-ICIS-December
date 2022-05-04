/********************************************************************************
** Form generated from reading UI file 'input_output_properties.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_OUTPUT_PROPERTIES_H
#define UI_INPUT_OUTPUT_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Input_Output_Properties
{
public:
    QGridLayout *gridLayout;
    QSpinBox *inputBox;
    QSpinBox *outputBox;
    QSpinBox *IDBox;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpinBox *valueBox;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QPushButton *delButton;

    void setupUi(QWidget *Input_Output_Properties)
    {
        if (Input_Output_Properties->objectName().isEmpty())
            Input_Output_Properties->setObjectName(QString::fromUtf8("Input_Output_Properties"));
        Input_Output_Properties->resize(320, 240);
        gridLayout = new QGridLayout(Input_Output_Properties);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        inputBox = new QSpinBox(Input_Output_Properties);
        inputBox->setObjectName(QString::fromUtf8("inputBox"));

        gridLayout->addWidget(inputBox, 1, 5, 1, 1);

        outputBox = new QSpinBox(Input_Output_Properties);
        outputBox->setObjectName(QString::fromUtf8("outputBox"));

        gridLayout->addWidget(outputBox, 2, 5, 1, 1);

        IDBox = new QSpinBox(Input_Output_Properties);
        IDBox->setObjectName(QString::fromUtf8("IDBox"));

        gridLayout->addWidget(IDBox, 0, 5, 1, 1);

        label_4 = new QLabel(Input_Output_Properties);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 4, 1, 1);

        valueBox = new QSpinBox(Input_Output_Properties);
        valueBox->setObjectName(QString::fromUtf8("valueBox"));

        gridLayout->addWidget(valueBox, 4, 5, 1, 1);

        label_3 = new QLabel(Input_Output_Properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        buttonBox = new QDialogButtonBox(Input_Output_Properties);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 5, 1, 1);

        label = new QLabel(Input_Output_Properties);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 2, 1, 1);

        label_2 = new QLabel(Input_Output_Properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        line = new QFrame(Input_Output_Properties);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 2, 1, 4);

        delButton = new QPushButton(Input_Output_Properties);
        delButton->setObjectName(QString::fromUtf8("delButton"));

        gridLayout->addWidget(delButton, 5, 2, 1, 1);


        retranslateUi(Input_Output_Properties);

        QMetaObject::connectSlotsByName(Input_Output_Properties);
    } // setupUi

    void retranslateUi(QWidget *Input_Output_Properties)
    {
        Input_Output_Properties->setWindowTitle(QCoreApplication::translate("Input_Output_Properties", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("Input_Output_Properties", "ID", nullptr));
        label_3->setText(QCoreApplication::translate("Input_Output_Properties", "Output", nullptr));
        label->setText(QCoreApplication::translate("Input_Output_Properties", "Value", nullptr));
        label_2->setText(QCoreApplication::translate("Input_Output_Properties", "Input", nullptr));
        delButton->setText(QCoreApplication::translate("Input_Output_Properties", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Input_Output_Properties: public Ui_Input_Output_Properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_OUTPUT_PROPERTIES_H

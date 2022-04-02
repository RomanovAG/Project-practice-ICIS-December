/********************************************************************************
** Form generated from reading UI file 'net_properties.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NET_PROPERTIES_H
#define UI_NET_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Net_Properties
{
public:
    QGridLayout *gridLayout;
    QPushButton *OK;
    QPushButton *Cancel;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QSpinBox *inumBox;
    QSpinBox *onumBox;
    QSpinBox *endidBox;
    QSpinBox *startidtBox;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *delayBox;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QWidget *Net_Properties)
    {
        if (Net_Properties->objectName().isEmpty())
            Net_Properties->setObjectName(QString::fromUtf8("Net_Properties"));
        Net_Properties->resize(632, 229);
        gridLayout = new QGridLayout(Net_Properties);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        OK = new QPushButton(Net_Properties);
        OK->setObjectName(QString::fromUtf8("OK"));

        gridLayout->addWidget(OK, 5, 0, 1, 1);

        Cancel = new QPushButton(Net_Properties);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 5, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Net_Properties);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(Net_Properties);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        inumBox = new QSpinBox(Net_Properties);
        inumBox->setObjectName(QString::fromUtf8("inumBox"));
        inumBox->setFont(font);

        gridLayout_2->addWidget(inumBox, 2, 1, 1, 1);

        onumBox = new QSpinBox(Net_Properties);
        onumBox->setObjectName(QString::fromUtf8("onumBox"));
        onumBox->setFont(font);

        gridLayout_2->addWidget(onumBox, 0, 1, 1, 1);

        endidBox = new QSpinBox(Net_Properties);
        endidBox->setObjectName(QString::fromUtf8("endidBox"));
        endidBox->setFont(font);

        gridLayout_2->addWidget(endidBox, 2, 0, 1, 1);

        startidtBox = new QSpinBox(Net_Properties);
        startidtBox->setObjectName(QString::fromUtf8("startidtBox"));
        startidtBox->setFont(font);

        gridLayout_2->addWidget(startidtBox, 0, 0, 1, 1);

        label_6 = new QLabel(Net_Properties);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_4 = new QLabel(Net_Properties);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(Net_Properties);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 2, 1, 1);

        label_3 = new QLabel(Net_Properties);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        delayBox = new QSpinBox(Net_Properties);
        delayBox->setObjectName(QString::fromUtf8("delayBox"));
        delayBox->setFont(font);

        gridLayout->addWidget(delayBox, 4, 2, 1, 1);

        line = new QFrame(Net_Properties);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 2, 1, 1);

        line_2 = new QFrame(Net_Properties);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 1);


        retranslateUi(Net_Properties);

        QMetaObject::connectSlotsByName(Net_Properties);
    } // setupUi

    void retranslateUi(QWidget *Net_Properties)
    {
        Net_Properties->setWindowTitle(QCoreApplication::translate("Net_Properties", "Form", nullptr));
        OK->setText(QCoreApplication::translate("Net_Properties", "OK", nullptr));
        Cancel->setText(QCoreApplication::translate("Net_Properties", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("Net_Properties", "Start address", nullptr));
        label_2->setText(QCoreApplication::translate("Net_Properties", "End address", nullptr));
        label_6->setText(QCoreApplication::translate("Net_Properties", "Input index", nullptr));
        label_4->setText(QCoreApplication::translate("Net_Properties", "ID", nullptr));
        label_5->setText(QCoreApplication::translate("Net_Properties", "Output index", nullptr));
        label_3->setText(QCoreApplication::translate("Net_Properties", "Delay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Net_Properties: public Ui_Net_Properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NET_PROPERTIES_H

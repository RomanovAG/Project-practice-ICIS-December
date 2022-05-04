/********************************************************************************
** Form generated from reading UI file 'el_to_save_form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EL_TO_SAVE_FORM_H
#define UI_EL_TO_SAVE_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_el_to_save_form
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QDialog *el_to_save_form)
    {
        if (el_to_save_form->objectName().isEmpty())
            el_to_save_form->setObjectName(QString::fromUtf8("el_to_save_form"));
        el_to_save_form->resize(320, 240);
        gridLayout = new QGridLayout(el_to_save_form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(el_to_save_form);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        spinBox = new QSpinBox(el_to_save_form);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 1, 0, 1, 1);

        label = new QLabel(el_to_save_form);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(el_to_save_form);
        QObject::connect(buttonBox, SIGNAL(accepted()), el_to_save_form, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), el_to_save_form, SLOT(reject()));

        QMetaObject::connectSlotsByName(el_to_save_form);
    } // setupUi

    void retranslateUi(QDialog *el_to_save_form)
    {
        el_to_save_form->setWindowTitle(QCoreApplication::translate("el_to_save_form", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("el_to_save_form", "Element ID to save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class el_to_save_form: public Ui_el_to_save_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EL_TO_SAVE_FORM_H

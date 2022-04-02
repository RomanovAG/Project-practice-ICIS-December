#ifndef LOGICAL_ELEMENT_PROPERTIES_H
#define LOGICAL_ELEMENT_PROPERTIES_H

#include <QWidget>
#include "logictypes.h"

namespace Ui {
class Logical_Element_Properties;
}

class Logical_Element_Properties : public QWidget
{
    Q_OBJECT

public:
    explicit Logical_Element_Properties(QWidget *parent = nullptr);
    ~Logical_Element_Properties();

signals:
    void propSignal(QString name, ionum_t inum, ionum_t onum, std::vector<std::vector<value_t>> output_table);

private slots:

    void on_OK_clicked();

    void on_Cancel_clicked();

    void on_inputNumBox_valueChanged(int arg1);

    void on_outputNumBox_valueChanged(int arg1);

private:
    Ui::Logical_Element_Properties *ui;
};

#endif // LOGICAL_ELEMENT_PROPERTIES_H

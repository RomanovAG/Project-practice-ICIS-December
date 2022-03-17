#ifndef LOGICAL_ELEMENT_PROPERTIES_H
#define LOGICAL_ELEMENT_PROPERTIES_H

#include <QWidget>

namespace Ui {
class Logical_Element_Properties;
}

class Logical_Element_Properties : public QWidget
{
    Q_OBJECT

public:
    explicit Logical_Element_Properties(QWidget *parent = nullptr);
    ~Logical_Element_Properties();

private slots:

    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::Logical_Element_Properties *ui;
};

#endif // LOGICAL_ELEMENT_PROPERTIES_H

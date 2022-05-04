#ifndef EL_TO_SAVE_FORM_H
#define EL_TO_SAVE_FORM_H

#include <QDialog>

namespace Ui {
class el_to_save_form;
}

class el_to_save_form : public QDialog
{
    Q_OBJECT

public:
    explicit el_to_save_form(QWidget *parent = nullptr);
    ~el_to_save_form();

signals:
    void box_value(size_t value);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::el_to_save_form *ui;
};

#endif // EL_TO_SAVE_FORM_H

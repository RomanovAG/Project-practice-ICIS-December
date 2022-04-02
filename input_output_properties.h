#ifndef INPUT_OUTPUT_PROPERTIES_H
#define INPUT_OUTPUT_PROPERTIES_H

#include <QWidget>
#include "logictypes.h"

namespace Ui {
class Input_Output_Properties;
}

class Input_Output_Properties : public QWidget
{
    Q_OBJECT

public:
    explicit Input_Output_Properties(QWidget *parent = nullptr);
    ~Input_Output_Properties();

signals:
    void valueChanged(value_t value, id_t ID, ionum_t io_id, bool is_input);

private slots:
    void on_buttonBox_accepted();

    void on_inputBox_valueChanged(int arg1);

    void on_outputBox_valueChanged(int arg1);

    void on_buttonBox_rejected();

private:
    Ui::Input_Output_Properties *ui;
};

#endif // INPUT_OUTPUT_PROPERTIES_H

#ifndef SET_LOGIC_LEVEL_H
#define SET_LOGIC_LEVEL_H

#include <QWidget>
#include "logictypes.h"

namespace Ui {
class Set_logic_level;
}

class Set_logic_level : public QWidget
{
    Q_OBJECT

public:
    explicit Set_logic_level(QWidget *parent = nullptr);
    ~Set_logic_level();

private slots:
    void on_pushButton_clicked();

    void on_cancel_clicked();

signals:
    void logicLevelChanged(level_t new_logic_level);

private:
    Ui::Set_logic_level *ui;
};

#endif // SET_LOGIC_LEVEL_H

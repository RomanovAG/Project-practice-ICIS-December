#ifndef METHODS_H
#define METHODS_H

#include "classes.h"

id_t findLID(std::vector<LogicalElement> src);
void setLogicLevel();
void addElements();
void delElements();
void connect();
void disconnect();
void setTT();
void setName();
void update();
void setValue();
void open();
void save();
void saveAs();

#endif // METHODS_H

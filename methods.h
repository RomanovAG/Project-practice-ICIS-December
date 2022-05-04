#ifndef METHODS_H
#define METHODS_H

#include "logictypes.h"
#include "logicalelement.h"
#include "input_output.h"
#include "net.h"
#include "mainwindow.h"

int randomBetween(int low, int high);

bool compLID(LogicalElement *a, LogicalElement *b);
bool compIOID(Input_Output *a, Input_Output *b);
bool compNID(Net *a, Net *b);

std::vector<LogicalElement *>::iterator isLIDExist(id_t id);
std::vector<Input_Output *>::iterator isIOIDExist(id_t id);
std::vector<Net *>::iterator isNIDExist(id_t id);

id_t findLID(std::vector<LogicalElement *> src);
id_t findIOID(std::vector<Input_Output *> src);
id_t findNID(std::vector<Net *> src);

long returnLID(std::vector<LogicalElement *> src, id_t id);
std::vector<std::vector<value_t>> makeInputTable(ionum_t input_num, level_t logic_level);

LogicalElement *convertToElement(std::vector<id_t> inputs_ids, std::vector<id_t> outputs_ids);
int saveToLib(QString lib_name, LogicalElement *el);
LogicalElement *loadFromLib(QString file_name);
int saveFile(QString file_name);
int loadFile(QString file_name, QGraphicsScene *scene, MainWindow *window);

int updateScheme(unsigned max_iterations);

#endif // METHODS_H

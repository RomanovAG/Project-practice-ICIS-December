#ifndef METHODS_H
#define METHODS_H

#include "logictypes.h"
#include "logicalelement.h"
#include "input_output.h"
#include "net.h"

bool compLID(LogicalElement *a, LogicalElement *b);
bool compIOID(Input_Output *a, Input_Output *b);
bool compNID(Net *a, Net *b);
id_t findLID(std::vector<LogicalElement *> src);
id_t findIOID(std::vector<Input_Output *> src);
id_t findNID(std::vector<Net *> src);
unsigned long long returnLID(std::vector<LogicalElement *> src, id_t id);
int pointsToLen(QPoint p1, QPoint p2);
int updateScheme();

#endif // METHODS_H

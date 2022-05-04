#ifndef TEMP_H
#define TEMP_H
#include "logictypes.h"
#include <vector>

class Temp
{
public:
    std::vector<value_t> values;
    ticker_t timestamp;
    Temp(std::vector<value_t> values, ticker_t timestamp)
    {
        this->values = values;
        this->timestamp = timestamp;
    }
};

#endif // TEMP_H

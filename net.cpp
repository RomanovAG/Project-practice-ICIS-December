#include "classes.h"
#include "logictypes.h"
#include <vector>

extern ticker_t ticker;

void Net::writeToTemp(value_t value, ticker_t t)
{
    Temp x.values = value;
    temps.push_back();
    temps.at(i).timestamp = t;
}

void Net::updateValue()
{
    static int n = 0;
    previous_value = current_value;
    if (temps.at(n).timestamp == ticker)
        current_value = temps.at(n).values;
}

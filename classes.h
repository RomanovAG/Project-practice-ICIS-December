#ifndef CLASSES_H
#define CLASSES_H
#include "logictypes.h"
#include <vector>
#include <tuple>

extern ticker_t ticker;

class LogicalElement;
class Net;

std::vector<LogicalElement> all_elements;
std::vector<Net> all_nets;
std::vector<std::tuple<id_t, value_t>> global_inputs;
std::vector<std::tuple<id_t, value_t>> global_outputs;


class Temp
{
public:
    std::vector<value_t> values;
    ticker_t timestamp;

    Temp(std::vector<value_t> new_inputs, ticker_t t)
    {
        values = new_inputs;
        timestamp = t;
    }
};

class TruthTable
{
public:
    id_t T_ID;
    std::vector<std::vector<value_t>> T_outputs;
    ionum_t input_num;
    ionum_t output_num;

    TruthTable(id_t ID, ionum_t inum, ionum_t onum)
    {
        T_ID = ID;
        input_num = inum;
        output_num = onum;
    }
    void setTT(level_t logic_level, ionum_t input_num, ionum_t output_num);
    std::vector<value_t> getOutput(rows_t row);
    void calculateTT();
};

class LogicalElement
{
public:
    id_t L_ID;
    delay_t L_delay;
    std::vector<ionum_t> L_inputs_addr, L_outputs_addr;
    std::vector<value_t> L_inputs, L_outputs;
    std::vector<Temp> temps;
    bool is_visible;

    LogicalElement(id_t el_num, delay_t delay, ionum_t inum, ionum_t onum)
    {
        L_ID = el_num;
        L_delay = delay;
        L_inputs.resize(inum);
        L_outputs.resize(onum);
    }
    void findFreeInputs();
    void findFreeOutputs();
    void updateOutputs(level_t logic_level, std::vector<std::vector<value_t>> outputs);
};

class Net
{
public:
    id_t Net_ID;
    std::tuple<id_t, ionum_t> start_addr, end_addr;
    delay_t net_delay;
    value_t previous_value, current_value;
    std::vector<Temp> temps;

    bool is_visible;

    Net(std::tuple<id_t, ionum_t> start, std::tuple<id_t, ionum_t> end, delay_t delay)
    {
        Net_ID = all_nets.size();
        start_addr = start;
        end_addr = end;
        net_delay = delay;
    }
    void writeToTemp(value_t new_value, ticker_t t);
    void updateValue();
};

#endif // CLASSES_H

#include "classes.h"
#include "logictypes.h"
#include <cmath>

void LogicalElement::findFreeInputs()
{

}

void LogicalElement::findFreeOutputs()
{

}

void LogicalElement::updateOutputs(level_t logic_level, std::vector<std::vector<value_t>> outputs)
{
    rows_t row = 0;
    int n = 1;

    for (auto i = L_inputs.size() - 1; i >= 0; i--)
    {
        row += L_inputs[i] * (rows_t) pow(logic_level, n);
        n++;
    }
    L_outputs = outputs[row];
}

#include "classes.h"
#include "logictypes.h"
#include <cmath>
#include <iostream>
using namespace std;

void LogicalElement::updateDelay()
{

}

void LogicalElement::updateOutputs(level_t logic_level, vector<vector<value_t>> outputs)
{
    rows_t row = 0;
    int n = 1;

    for (int i = L_inputs.size() - 1; i >= 0; i--)
    {
        row += L_inputs[i] * (rows_t) pow(logic_level, n);
        n++;
    }
    L_outputs = outputs[row];
}

void LogicalElement::setName()
{
    string name;
    cout << "Enter name of the element: ";
    cin >> name;
    L_name = name;
}

void LogicalElement::showTT(level_t logic_level)
{
    auto input_num = L_inputs.size();
    auto output_num = L_outputs.size();
    auto rows = (rows_t) pow(logic_level, input_num);
    vector<vector<value_t>> input_table (rows, vector<value_t> (input_num));

    for (unsigned i = 0; i < rows; i++)
    {
        auto current_row = i;
        for (int j = input_num - 1; j >= 0; j--)
        {
            input_table[i][j] = current_row % logic_level;
            current_row /= logic_level;
        }
    }
    cout << "Inputs ";
    if (input_num > 6)
    {
        for (auto i = 0; i < input_num - 6; i++)
            cout << " ";
    }
    cout << "Outputs" << endl;
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < input_num; column++)
        {
            cout << (int) input_table[row][column] << " ";
        }
        for (auto n = 0; n < 5 - input_num; n++)
        {
            cout << " ";
        }
        for (auto column = 0; column < output_num; column++)
        {
            cout << (int) T_outputs[row][column] << " ";
        }
        cout << "\n";
    }
}

void LogicalElement::setTT(level_t logic_level)
{
    auto input_num = L_inputs.size();
    auto output_num = L_outputs.size();
    auto rows = (rows_t) pow(logic_level, input_num);
    vector<vector<value_t>> input_table (rows, vector<value_t> (input_num));
    vector<vector<value_t>> output_table (rows, vector<value_t> (output_num));

    for (unsigned i = 0; i < rows; i++)
    {
        auto current_row = i;
        for (int j = input_num - 1; j >= 0; j--)
        {
            input_table[i][j] = current_row % logic_level;
            current_row /= logic_level;
        }
    }
    cout << "Inputs ";
    if (input_num > 6)
    {
        for (auto i = 0; i < input_num - 6; i++)
            cout << " ";
    }
    cout << "Outputs" << endl;
    for (unsigned row = 0; row < rows; row++)
    {
        for (auto column = 0; column < input_num; column++)
        {
            cout << (int) input_table[row][column] << " ";
        }
        for (auto n = 0; n < 5 - input_num; n++)
        {
            cout << " ";
        }
        for (auto column = 0; column < output_num; column++)
        {
            cin >> output_table[row][column];
        }
    }
    T_outputs = output_table;
}

vector<value_t> LogicalElement::getOutput(level_t logic_level, vector<value_t> L_inputs)
{
    rows_t row = 0;
    for (unsigned i = 0, j = L_inputs.size() - 1; i < L_inputs.size(); i++, j--)
    {
        row += (rows_t) L_inputs[i] * pow(logic_level, j);
    }
    //cout << "row: " << row << "\n";
    return T_outputs[row];
}

void LogicalElement::calculateTT()
{

}

//#include "classes.h"
//#include "logictypes.h"
//#include <cmath>
//#include <vector>
//#include <iostream>

//void TruthTable::setTT(level_t logic_level, ionum_t input_num, ionum_t output_num)
//{
//    auto rows = (rows_t) pow(logic_level, input_num);
//    std::vector<std::vector<value_t>> input_table (rows, std::vector<value_t> (input_num));
//    std::vector<std::vector<value_t>> output_table (rows, std::vector<value_t> (output_num));

//    for (unsigned i = 0; i < rows; i++)
//    {
//        auto current_row = i;
//        for (auto j = input_num - 1; j >= 0; j--)
//        {
//            input_table[i][j] = current_row % logic_level;
//            current_row /= logic_level;
//        }
//    }

//    cout << "Inputs ";
//    if (input_num > 6)
//    {
//        for (auto i = 0; i < input_num - 6; i++)
//            cout << " ";
//    }
//    cout << "Outputs" << endl;
//    for (unsigned row = 0; row < rows; row++)
//    {
//        for (auto column = 0; column < input_num; column++)
//        {
//            cout << input_table[row][column];
//        }
//        for (auto n = 0; n < 7 - input_num; n++)
//        {
//            cout << " ";
//        }
//        for (auto column = 0; column < output_num; column++)
//        {
//            std::cin >> output_table[row][column];
//        }
//    }
//    T_outputs = output_table;
//}

//std::vector<value_t> TruthTable::getOutput(rows_t row)
//{
//    return T_outputs[row];
//}

//void TruthTable::calculateTT()
//{

//}

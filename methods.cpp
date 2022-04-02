#include "logictypes.h"
#include "logicalelement.h"
#include "input_output.h"
#include "net.h"
#include "methods.h"
#include "QString"
#include <vector>
using namespace std;

QString current_file = "";
extern level_t logic_level;
extern vector<LogicalElement *> all_elements;
extern vector<Input_Output *> all_inOutputs;
extern vector<Net *> all_nets;

bool compLID(LogicalElement *a, LogicalElement *b) { return a->L_ID < b->L_ID; }
bool compIOID(Input_Output *a, Input_Output *b) { return a->IO_ID < b->IO_ID;}
bool compNID(Net *a, Net *b) { return a->Net_ID < b->Net_ID; }

vector<LogicalElement *>::iterator isLIDExist(id_t id)
{
    vector<LogicalElement *>::iterator iter = all_elements.begin();
    while (iter < all_elements.end())
    {
        if ((*iter)->L_ID == id)
            return iter;
        iter++;
    }
    return all_elements.end();
}

vector<Net *>::iterator isNIDExist(id_t id)
{
    vector<Net *>::iterator iter = all_nets.begin();
    while (iter < all_nets.end())
    {
        if ((*iter)->Net_ID == id)
            return iter;
        iter++;
    }
    return all_nets.end();
}

unsigned long long returnLID(vector<LogicalElement *> src, id_t id)
{
    for (id_t i = 0; i < src.size(); i++)
    {
        if (src[i]->L_ID == id)
            return i;
    }
    return ULLONG_MAX;
}

id_t findLID(vector<LogicalElement *> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0]->L_ID > 0)
        return src[0]->L_ID - 1;
    for (unsigned i = 0; i < src.size() - 1; i++)
    {
        if (src[i]->L_ID < src[i + 1]->L_ID - 1)
        {
            return src[i + 1]->L_ID - 1;
        }
    }
    return src.back()->L_ID + 1;
}

id_t findIOID(vector<Input_Output *> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0]->IO_ID > 0)
        return src[0]->IO_ID - 1;
    for (unsigned i = 0; i < src.size() - 1; i++)
    {
        if (src[i]->IO_ID < src[i + 1]->IO_ID - 1)
        {
            return src[i + 1]->IO_ID - 1;
        }
    }
    return src.back()->IO_ID + 1;
}

id_t findNID(vector<Net *> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0]->Net_ID > 0)
        return src[0]->Net_ID - 1;
    for (unsigned i = 0; i < src.size() - 1; i++)
    {
        if (src[i]->Net_ID < src[i + 1]->Net_ID - 1)
        {
            return src[i + 1]->Net_ID - 1;
        }
    }
    return src.back()->Net_ID + 1;
}

int updateScheme()
{
    if (all_elements.size() == 0 /*|| all_nets.size() == 0 */|| logic_level == 0)
    {
        qDebug() << "No elements or no nets...";
        return 0;
    }
    int iterations;
    for (iterations = 0; iterations < 1000; iterations++)
    {
        qDebug() << "iter:" << iterations;
        bool changed = false;
        for (unsigned i = 0; i < all_inOutputs.size(); i++)
        {
            if (all_inOutputs[i]->is_input == true)
            {
                if (all_elements[all_inOutputs[i]->addr.first]->L_inputs[all_inOutputs[i]->addr.second] != all_inOutputs[i]->value)
                    changed = true;
                all_elements[all_inOutputs[i]->addr.first]->L_inputs[all_inOutputs[i]->addr.second] = all_inOutputs[i]->value;
            }
            else
            {
                if (all_inOutputs[i]->value != all_elements[all_inOutputs[i]->addr.first]->L_outputs[all_inOutputs[i]->addr.second])
                    changed = true;
                all_inOutputs[i]->value = all_elements[all_inOutputs[i]->addr.first]->L_outputs[all_inOutputs[i]->addr.second];
            }
            all_inOutputs[i]->update();
        }
        for (unsigned i = 0; i < all_elements.size(); i++)
        {
            if (all_elements[i]->L_outputs != all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs))
                changed = true;
            all_elements[i]->L_outputs = all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs);
        }
        for (unsigned i = 0; i < all_nets.size(); i++)
        {
            auto x = 0;
            while (all_elements[x]->L_ID != all_nets[i]->start_addr.first)
                x++;
            qDebug() << "x:" << x;
            if (all_elements[x]->L_outputs != all_elements[x]->getOutput(logic_level, all_elements[x]->L_inputs))
                changed = true;
            qDebug() << "changed:" << changed;
            all_elements[x]->L_outputs = all_elements[x]->getOutput(logic_level, all_elements[x]->L_inputs);
            if (all_nets[i]->value != all_elements[x]->L_outputs[all_nets[i]->start_addr.second])
                changed = true;
            all_nets[i]->value = all_elements[x]->L_outputs[all_nets[i]->start_addr.second];

            auto y = 0;
            while (all_elements[y]->L_ID != all_nets[i]->end_addr.first)
                y++;
            if (all_elements[y]->L_inputs[all_nets[i]->end_addr.second] != all_nets[i]->value)
                changed = true;
            all_elements[y]->L_inputs[all_nets[i]->end_addr.second] = all_nets[i]->value;
            if (all_elements[y]->L_outputs != all_elements[y]->getOutput(logic_level, all_elements[y]->L_inputs))
                changed = true;
            all_elements[y]->L_outputs = all_elements[y]->getOutput(logic_level, all_elements[y]->L_inputs);
        }
        if (changed == false)
            break;
    }
    qDebug() << "iterations:" << iterations + 1;
    for (unsigned i = 0; i < all_nets.size(); i++)
    {
        all_nets[i]->update();
    }
    return iterations;
}

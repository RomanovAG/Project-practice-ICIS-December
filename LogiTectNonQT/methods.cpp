#include "logictypes.h"
#include "classes.h"
#include "methods.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#define INVALID printf("Invalid value. Try again...\n")
#define CLOSED printf("Closed...\n")
using namespace std;

string current_file = "";
extern level_t logic_level;
extern vector<LogicalElement> all_elements;
extern vector<Net> all_nets;
//extern vector<pair<id_t, vector<value_t>>> global_inputs;
//extern vector<pair<id_t, vector<value_t>>> global_outputs;

bool compLID(LogicalElement a, LogicalElement b)
{
    return a.L_ID < b.L_ID;
}

bool compNID(Net a, Net b)
{
    return a.Net_ID < b.Net_ID;
}
/*
bool compGlobalInOut(pair<id_t, vector<value_t>> a, pair<id_t, vector<value_t>> b)
{
    return a.first < b.first;
}*/

vector<LogicalElement>::iterator isLIDExist(id_t id)
{
    vector<LogicalElement>::iterator iter = all_elements.begin();
    while (iter < all_elements.end())
    {
        if ((*iter).L_ID == id)
            return iter;
        iter++;
    }
    return all_elements.end();
}

vector<Net>::iterator isNIDExist(id_t id)
{
    vector<Net>::iterator iter = all_nets.begin();
    while (iter < all_nets.end())
    {
        if ((*iter).Net_ID == id)
            return iter;
        iter++;
    }
    return all_nets.end();
}

id_t findLID(vector<LogicalElement> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0].L_ID > 0)
        return src[0].L_ID - 1;
    for (auto i = 0; i < src.size() - 1; i++)
    {
        if (src[i].L_ID < src[i + 1].L_ID - 1)
        {
            return src[i + 1].L_ID - 1;
        }
    }
    return src.back().L_ID + 1;
}

id_t findNID(vector<Net> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0].Net_ID > 0)
        return src[0].Net_ID - 1;
    for (auto i = 0; i < src.size() - 1; i++)
    {
        if (src[i].Net_ID < src[i + 1].Net_ID - 1)
        {
            return src[i + 1].Net_ID - 1;
        }
    }
    return src.back().Net_ID + 1;
}

void setLogicLevel()
{
    level_t new_level = 0;
    int flag;
    do
    {
        cout << ">";
        flag = scanf("%d", &new_level);
        if (flag < 0)
        {
            CLOSED;
            exit(0);
        }
        if (flag == 0)
        {
            INVALID;
            scanf("%*c");
            flag = 0;
        }
        if (new_level < 1 || new_level > 255)
            cout << "Logic level can't be lower than 1 or higher than 255\n";
    } while (flag < 1 || new_level < 1 || new_level > 255);
    logic_level = new_level;
    cout << "Done...";
    scanf("%*c");
    getchar();
}

void addElements()
{
    auto i = 0;
    id_t max;
    cout << "Enter num of elements: ";
    if (scanf("%lld", &max) < 0)
        exit(0);
    //    all_elements.push_back((LogicalElement(2, 9, 9, 9)));
    //    all_elements.push_back((LogicalElement(4, 9, 9, 9)));
    while (i < max)
    {
        delay_t delay;
        cout << "delay of element ID_" << findLID(all_elements) << " (" << max - i << " elements left)" << " : ";
        cin >> delay;
        ionum_t inputs, outputs;
        cout << "Enter input num: ";
        cin >> inputs;
        cout << "Enter output num: ";
        cin >> outputs;
        all_elements.push_back((LogicalElement(findLID(all_elements), delay, inputs, outputs)));

//        cout << "before: ";
//        for (auto x = 0; x < all_elements.size(); x++)
//        {
//            cout << all_elements[x].L_ID << " ";
//        }

        if (all_elements.size() > 1)
        {
            sort(all_elements.begin(), all_elements.end(), compLID);
        }

//        cout << "after: ";
//        for (auto x = 0; x < all_elements.size(); x++)
//        {
//            cout << all_elements[x].L_ID << " ";
//        }
//        cout << "\n";
        i++;
    }
}

void delElements()
{
    id_t id = 0;
    int flag;
    do
    {
        cout << "Enter element ID to delete: ";
        flag = scanf("%lld", &id);
        if (flag < 0)
        {
            //CLOSED;
            return;
        }
        if (flag == 0)
        {
            INVALID;
            scanf("%*c");
            flag = 0;
        }
        if (isLIDExist(id) == all_elements.end())
            cout << "There are no elements with this ID...\n";
    } while (flag == 0 || isLIDExist(id) == all_elements.end());
    all_elements.erase(isLIDExist(id));
//    cout << "after: ";
//    for (auto x = 0; x < all_elements.size(); x++)
//    {
//        cout << all_elements[x].L_ID << " ";
//    }
//    cout << "\n";
}

void connect()
{
    cout << "Enter start id, start output, end id, end input, delay :\n";
    id_t start_id;
    ionum_t start_output;
    id_t end_id;
    ionum_t end_input;
    delay_t delay;
    cin >> start_id >> start_output >> end_id >> end_input >> delay;
    pair<id_t, ionum_t> start_addr;
    start_addr.first = start_id;
    start_addr.second = start_output;
    pair<id_t, ionum_t> end_addr;
    end_addr.first = end_id;
    end_addr.second = end_input;
    Net new_net(findNID(all_nets), start_addr, end_addr, delay);
    all_nets.push_back(new_net);
    if (all_nets.size() > 1)
    {
        sort(all_nets.begin(), all_nets.end(), compNID);
    }
}

void disconnect()
{
    id_t id = 0;
    int flag;
    do
    {
        cout << "Enter IDs of the elements to disconnect:";
        flag = scanf("%lld", &id);
        if (flag < 0)
        {
            //CLOSED;
            return;
        }
        if (flag == 0)
        {
            INVALID;
            scanf("%*c");
            flag = 0;
        }
        if (isNIDExist(id) == all_nets.end())
            cout << "There are no nets with this ID...\n";
    } while (flag == 0 || isNIDExist(id) == all_nets.end());
    all_nets.erase(isNIDExist(id));
}

void setTT()
{
    printf("Enter ID of the element to set truth table\n");
    for (auto i = 0; i < all_elements.size(); i++)
    {
        cout << "ID_" << all_elements[i].L_ID << " \"" << all_elements[i].L_name << "\"\n";
    }
    int flag;
    id_t temp;
    do
    {
        cout << ">";
        flag = scanf("%lld", &temp);
        if (flag < 0)
        {
            //CLOSED;
            return;
        }
        if (flag == 0 || temp > all_elements.back().L_ID)
        {
            INVALID;
            scanf("%*c");
            flag = 0;
        }
    } while (flag < 1 || temp > all_elements.back().L_ID);
    all_elements[temp].setTT(logic_level);
}

void setName()
{
    printf("Enter ID of the element to set name\n");
    for (auto i = 0; i < all_elements.size(); i++)
    {
        cout << "ID_" << all_elements[i].L_ID << " \"" << all_elements[i].L_name << "\"\n";
    }
    int flag;
    id_t temp;
    do
    {
        cout << ">";
        flag = scanf("%lld", &temp);
        if (flag < 0)
        {
            //CLOSED;
            return;;
        }
        if (flag == 0 || temp > all_elements.back().L_ID)
        {
            INVALID;
            scanf("%*c");
            flag = 0;
        }
    } while (flag < 1 || temp > all_elements.back().L_ID);
    all_elements[temp].setName();
}

void showElements()
{
    for (auto i = 0; i < all_elements.size(); i++)
    {
        //printf("Element ID_%d \"%s\"\n", all_elements[i].L_ID, all_elements[i].L_name.c_str());
        cout << "ID_" << all_elements[i].L_ID << " \"" << all_elements[i].L_name << "\"\n";
        if (all_elements[i].T_outputs.size() > 0)
            all_elements[i].showTT(logic_level);
        cout << "\n";
    }
}

void showNets()
{
    for (auto i = 0; i < all_nets.size(); i++)
    {
        cout << "Net ID_" << all_nets[i].Net_ID << " connects elements: ID_" << all_nets[i].start_addr.first
             << " output " << all_nets[i].start_addr.second << " and ID_"<< all_nets[i].end_addr.first
             << " input " << all_nets[i].end_addr.second << "\n";
    }
}

void update()
{
    if (all_elements.size() == 0 || all_nets.size() == 0)
        exit(0);
    all_elements[0].L_outputs = all_elements[0].getOutput(logic_level, all_elements[0].L_inputs);

    for (auto A = 0; A < 2; A++)
    {
    for (auto i = 0; i < all_nets.size(); i++)
    {
        auto x = 0;
        while (all_elements[x].L_ID != all_nets[i].start_addr.first)
            x++;
        all_elements[x].L_outputs = all_elements[x].getOutput(logic_level, all_elements[x].L_inputs);
        all_nets[i].value = all_elements[x].L_outputs[all_nets[i].start_addr.second];
        cout << "value of net " << i << " : " << all_nets[i].value << "\n";

        auto y = 0;
        while (all_elements[y].L_ID != all_nets[i].end_addr.first)
            y++;
        all_elements[y].L_inputs[all_nets[i].end_addr.second] = all_nets[i].value;
        all_elements[y].L_outputs = all_elements[y].getOutput(logic_level, all_elements[y].L_inputs);
    }
    cout << "\n";
    }
//    cout << "inputs:\n";
//    for (auto i = 0; i < all_elements[1].L_inputs.size(); i++)
//    {
//        cout << all_elements[1].L_inputs[i] << "\n";
//    }
    //cout << "ID 1 output: " << all_elements[1].L_outputs[0];
    all_elements[5].L_outputs = all_elements[5].getOutput(logic_level, all_elements[5].L_inputs);
    cout << "result: ";
    for (auto i = 0; i < all_elements[1].L_outputs.size(); i++)
    {
        cout << all_elements[5].L_outputs[i] << " ";
    }
    cout << "\n";
}

//vector<pair<id_t, ionum_t>> findFreeInputs()
//{

//}

void setValue()
{
    for (auto i = 0; i < all_elements[0].L_inputs.size(); i++)
    {
        cin >> all_elements[0].L_inputs[i];
    }
    all_elements[0].L_outputs = all_elements[0].getOutput(logic_level, all_elements[0].L_inputs);
}

void open()
{
    cout << "This will discard current project (save it if you haven't done this yet) continue? (y/n)\n";
    cout << ">";
    string choice;
    do
    {
        if (!getline(cin, choice))
            return;
        if (choice == "n")
            return;
        if (choice == "y")
        {
            cout << "Enter file name: ";
            string file_name;
            if (!getline(cin, file_name))
                return;
            ifstream in(file_name, ios::binary);
            if (!in.is_open())
            {
                cout << "Wrong file name...";
                return;
            }
            current_file = file_name;
            in.read((char *) &logic_level, sizeof (level_t));
            id_t size_of_all_elements;
            in.read((char *) &size_of_all_elements, sizeof (id_t));
            for (auto i = 0; i < size_of_all_elements; i++)
            {
                id_t L_ID;
                in.read((char *) &L_ID, sizeof (id_t));
                size_t name_size;
                in.read((char *) &name_size, sizeof (name_size));
                char *name = (char *) malloc(name_size + 1);
                in.read(name, name_size);
                name[name_size] = '\0';
                string L_name = name;
                free(name);
                delay_t L_delay;
                in.read((char *) &L_delay, sizeof (delay_t));
                ionum_t input_num;
                in.read((char *) &input_num, sizeof (ionum_t));
                ionum_t output_num;
                in.read((char *) &output_num, sizeof (ionum_t));
                LogicalElement el(L_ID, L_delay, input_num, output_num);
                el.L_name = L_name; //cout << "name " << L_name << " ";

                size_t rows;
                in.read((char *) &rows, sizeof (rows));
                if (rows > 0)
                {
                    size_t columns;
                    in.read((char *) &columns, sizeof (columns));

                    for (auto row = 0; row < rows; row++)
                    {
                        vector<value_t> vcolumn;
                        for (auto column = 0; column < columns; column++)
                        {
                            value_t temp;
                            in.read((char *) &temp, sizeof (value_t));
                            vcolumn.push_back(temp);
                        }
                        el.T_outputs.push_back(vcolumn);
                    }
                }
                all_elements.push_back(el);
            }
            id_t size_of_all_nets;
            in.read((char *) &size_of_all_nets, sizeof (id_t));
            for (auto i = 0; i < size_of_all_nets; i++)
            {
                id_t net_id;
                in.read((char *) &net_id, sizeof (id_t));
                delay_t net_delay;
                in.read((char *) &net_delay, sizeof (delay_t));
                pair<id_t, ionum_t> start_addr;
                in.read((char *) &start_addr, sizeof (start_addr));
                pair<id_t, ionum_t> end_addr;
                in.read((char *) &end_addr, sizeof (end_addr));
                all_nets.push_back(Net(net_id, start_addr, end_addr, net_delay));
            }
            return;
        }
    } while (choice != "y" || choice != "n");
}

void saveAs();

//void save()
//{
//    if (current_file == "")
//        saveAs();
//    else
//    {
//        ofstream out(current_file, ios::binary);
//        out.write((char *) &logic_level, sizeof (level_t));
//        id_t size_of_all_elements = all_elements.size();
//        out.write((char *) &size_of_all_elements, sizeof (id_t));
//        for (auto i = 0; i < all_elements.size(); i++)
//        {
//            out.write((char *) &all_elements[i], sizeof (LogicalElement));
//        }
//        id_t size_of_all_nets = all_nets.size();
//        out.write((char *) &size_of_all_nets, sizeof (id_t));
//        for (auto i = 0; i < all_nets.size(); i++)
//        {
//            out.write((char *) &all_nets[i], sizeof (Net));
//        }
//    }
//}

void saveAs()
{
    cout << "Enter file name: ";
    string file_name;
    if (!getline(cin, file_name))
        return;
    ofstream out(file_name, ios::binary);
    out.write((char *) &logic_level, sizeof (level_t));
    id_t size_of_all_elements = all_elements.size();
    out.write((char *) &size_of_all_elements, sizeof (id_t));
    for (auto i = 0; i < all_elements.size(); i++)
    {
        out.write((char *) &all_elements[i].L_ID, sizeof (id_t));
        size_t name_size = all_elements[i].L_name.size();
        //cout << "name size " << name_size << " " << all_elements[i].L_name.c_str() << "\n";
        out.write((char *) &name_size, sizeof (name_size));
        out.write(all_elements[i].L_name.c_str(), name_size);
        out.write((char *) &all_elements[i].L_delay, sizeof (delay_t));
        ionum_t input_num = all_elements[i].L_inputs.size();
        out.write((char *) &input_num, sizeof (ionum_t));
        ionum_t output_num = all_elements[i].L_outputs.size();
        out.write((char *) &output_num, sizeof (ionum_t));
        size_t rows = all_elements[i].T_outputs.size();
        out.write((char *) &rows, sizeof (rows));
        if (rows > 0)
        {
            size_t columns = all_elements[i].T_outputs[0].size();
            out.write((char *) &columns, sizeof (columns));
            for (auto row = 0; row < all_elements[i].T_outputs.size(); row++)
            {
                for (auto column = 0; column < all_elements[i].T_outputs[row].size(); column++)
                {
                    out.write((char *) &all_elements[i].T_outputs[row][column], sizeof (value_t));
                }
            }
        }
    }
    id_t size_of_all_nets = all_nets.size();
    out.write((char *) &size_of_all_nets, sizeof (id_t));
    for (auto i = 0; i < all_nets.size(); i++)
    {
        out.write((char *) &all_nets[i].Net_ID, sizeof (id_t));
        out.write((char *) &all_nets[i].net_delay, sizeof (delay_t));
        out.write((char *) &all_nets[i].start_addr, sizeof (all_nets[i].start_addr));
        out.write((char *) &all_nets[i].end_addr, sizeof (all_nets[i].end_addr));
    }
}

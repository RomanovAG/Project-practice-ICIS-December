#include "mainwindow.h"
#include "logictypes.h"
#include "logicalelement.h"
#include "input_output.h"
#include "net.h"
#include "methods.h"
#include "temp.h"
#include "ui_mainwindow.h"
using namespace std;

extern QString current_file;
extern ticker_t ticker;
extern level_t logic_level;
extern vector<LogicalElement *> all_elements;
extern vector<Input_Output *> all_inOutputs;
extern vector<Net *> all_nets;
bool simulated;

int randomBetween(int low, int high) { return (QRandomGenerator::global()->generate() % ((high + 1) - low) + low); }

LogicalElement *convertToElement(vector<id_t> inputs_ids, vector<id_t> outputs_ids)
{
    vector<vector<value_t>> output_table ((rows_t) pow(logic_level, inputs_ids.size()), vector<value_t> (outputs_ids.size()));
    vector<vector<value_t>> input_table = makeInputTable(inputs_ids.size(), logic_level);
    vector<size_t> inputs_indexes, outputs_indexes;
    for (size_t i = 0; i < inputs_ids.size(); i++)
        for (size_t j = 0; j < all_inOutputs.size(); j++)
            if (all_inOutputs[j]->IO_ID == inputs_ids[i])
                inputs_indexes.push_back(j);
    for (size_t i = 0; i < outputs_ids.size(); i++)
        for (size_t j = 0; j < all_inOutputs.size(); j++)
            if (all_inOutputs[j]->IO_ID == outputs_ids[i])
                outputs_indexes.push_back(j);
    for (rows_t i = 0; i < pow(logic_level, inputs_ids.size()); i++)
    {
        for (ionum_t j = 0; j < inputs_ids.size(); j++)
            all_inOutputs[inputs_indexes[j]]->value = input_table[i][j];
        updateScheme(MAX_ITERATIONS);
        for (ionum_t k = 0; k < outputs_indexes.size(); k++)
            output_table[i][k] = all_inOutputs[outputs_indexes[k]]->value;
    }
    LogicalElement *el = new LogicalElement;
    el->L_inputs.resize(inputs_ids.size());
    el->L_outputs.resize(outputs_ids.size());
    el->T_outputs = output_table;
    el->is_connector = false;
    return el;
}

int saveToLib(QString lib_name, LogicalElement *el)
{
    QFile out(lib_name);
    out.open(QIODevice::WriteOnly);
    out.write((char *) &logic_level, sizeof (logic_level));
    out.write((char *) &el->is_connector, sizeof (LogicalElement::is_connector));
    out.write((char *) &el->width, sizeof (LogicalElement::width));
    out.write((char *) &el->height, sizeof (LogicalElement::height));
    out.write((char *) &el->L_ID, sizeof (LogicalElement::L_ID));
    out.write((char *) &el->L_delay, sizeof (LogicalElement::L_delay));
//    size_t name_size = lib_name.size();
//    out.write((char *) &name_size, sizeof (name_size));
//    out.write(lib_name.toStdString().c_str(), name_size);
    ionum_t input_num = el->L_inputs.size();
    out.write((char *) &input_num, sizeof (input_num));
    ionum_t output_num = el->L_outputs.size();
    out.write((char *) &output_num, sizeof (output_num));
    size_t rows = el->T_outputs.size();
    out.write((char *) &rows, sizeof (rows));
    if (rows > 0)
    {
        size_t columns = el->T_outputs[0].size();
        out.write((char *) &columns, sizeof (columns));
        for (size_t row = 0; row < el->T_outputs.size(); row++)
            for (size_t column = 0; column < el->T_outputs[row].size(); column++)
                out.write((char *) &el->T_outputs[row][column], sizeof (value_t));
    }
    out.close();
    return 0;
}

LogicalElement *loadFromLib(QString file_name)
{
    QFile in(file_name);
    in.open(QIODevice::ReadOnly);
    if (in.isOpen() == false)
        return NULL;
    level_t level;
    in.read((char *) &level, sizeof (level));
    if (level != logic_level)
    {
        QMessageBox box;
        QString warning = "Logic level is ";
        warning += QString::number(level) + " (project logic level is " + QString::number(logic_level) + ")";
        box.warning(nullptr, "Warning", warning);
        box.show();
        return NULL;
    }
    LogicalElement *el = new LogicalElement;
    el->L_name = file_name;
    in.read((char *) &el->is_connector, sizeof (LogicalElement::is_connector));
    in.read((char *) &el->width, sizeof (LogicalElement::width));
    in.read((char *) &el->height, sizeof (LogicalElement::height));
    in.read((char *) &el->L_ID, sizeof (LogicalElement::L_ID));
    in.read((char *) &el->L_delay, sizeof (LogicalElement::L_delay));
    ionum_t input_num;
    in.read((char *) &input_num, sizeof (input_num));
    el->L_inputs.resize(input_num);
    ionum_t output_num;
    in.read((char *) &output_num, sizeof (output_num));
    el->L_outputs.resize(output_num);
    rows_t rows;
    in.read((char *) &rows, sizeof (rows));
    el->T_outputs.resize(rows);
    if (rows > 0)
    {
        size_t columns;
        in.read((char *) &columns, sizeof (columns));
        for (size_t row = 0; row < el->T_outputs.size(); row++)
        {
            el->T_outputs[row].resize(columns);
            for (size_t column = 0; column < el->T_outputs[row].size(); column++)
                in.read((char *) &el->T_outputs[row][column], sizeof (value_t));
        }
    }
    in.close();
    return el;
}

int saveFile(QString file_name)
{
    QFile out(file_name);
    out.open(QIODevice::WriteOnly);
    out.write((char *) &logic_level, sizeof (logic_level));
    size_t size_of_all_elements = all_elements.size();
    size_t size_of_all_inOutputs = all_inOutputs.size();
    size_t size_of_all_nets = all_nets.size();
    out.write((char *) &size_of_all_elements, sizeof (size_t));
    out.write((char *) &size_of_all_inOutputs, sizeof (size_t));
    out.write((char *) &size_of_all_nets, sizeof (size_t));
    qDebug() << size_of_all_elements;
    qDebug() << size_of_all_inOutputs;
    qDebug() << size_of_all_nets;
    for (size_t i = 0; i < size_of_all_elements; i++)
    {
        out.write((char *) &all_elements[i]->is_connector, sizeof (LogicalElement::is_connector));
        out.write((char *) &all_elements[i]->width, sizeof (LogicalElement::width));
        out.write((char *) &all_elements[i]->height, sizeof (LogicalElement::height));
        QPointF pos = all_elements[i]->pos();
        out.write((char *) &pos, sizeof (pos));
        out.write((char *) &all_elements[i]->L_ID, sizeof (LogicalElement::L_ID));
        out.write((char *) &all_elements[i]->L_delay, sizeof (LogicalElement::L_delay));
        size_t name_size = all_elements[i]->L_name.size();
        out.write((char *) &name_size, sizeof (name_size));
        out.write(all_elements[i]->L_name.toStdString().c_str(), name_size);
        ionum_t input_num = all_elements[i]->L_inputs.size();
        out.write((char *) &input_num, sizeof (input_num));
        ionum_t output_num = all_elements[i]->L_outputs.size();
        out.write((char *) &output_num, sizeof (output_num));
        size_t rows = all_elements[i]->T_outputs.size();
        out.write((char *) &rows, sizeof (rows));
        if (rows > 0)
        {
            size_t columns = all_elements[i]->T_outputs[0].size();
            out.write((char *) &columns, sizeof (columns));
            for (size_t row = 0; row < all_elements[i]->T_outputs.size(); row++)
                for (size_t column = 0; column < all_elements[i]->T_outputs[row].size(); column++)
                    out.write((char *) &all_elements[i]->T_outputs[row][column], sizeof (value_t));
        }
        for (ionum_t output = 0; output < output_num; output++)
            out.write((char *) &all_elements[i]->L_outputs[output], sizeof (value_t));
        // out.write L_outputs
    }
    for (size_t i = 0; i < size_of_all_inOutputs; i++)
    {
        out.write((char *) &all_inOutputs[i]->IO_ID, sizeof (Input_Output::IO_ID));
        out.write((char *) &all_inOutputs[i]->width, sizeof (Input_Output::width));
        out.write((char *) &all_inOutputs[i]->height, sizeof (Input_Output::height));
        out.write((char *) &all_inOutputs[i]->addr, sizeof (Input_Output::addr));
        out.write((char *) &all_inOutputs[i]->is_input, sizeof (Input_Output::is_input));
        out.write((char *) &all_inOutputs[i]->value, sizeof (Input_Output::value));
    }
    for (size_t i = 0; i < size_of_all_nets; i++)
    {
        out.write((char *) &all_nets[i]->Net_ID, sizeof (Net::Net_ID));
        out.write((char *) &all_nets[i]->net_delay, sizeof (Net::net_delay));
        out.write((char *) &all_nets[i]->start_addr, sizeof (Net::start_addr));
        out.write((char *) &all_nets[i]->end_addr, sizeof (Net::end_addr));
        out.write((char *) &all_nets[i]->start_pos, sizeof (Net::start_pos));
        out.write((char *) &all_nets[i]->end_pos, sizeof (Net::end_pos));
        out.write((char *) &all_nets[i]->value, sizeof (Net::value));
    }
    return 0;
}

int loadFile(QString file_name, QGraphicsScene *scene, MainWindow *window)
{
    Q_UNUSED(scene);
    QFile in(file_name);
    in.open(QIODevice::ReadOnly);
    if (in.isOpen() == false)
        return -1;
    window->scene->clear();
    for (auto i = 0; i <= 1920; i += 40)
        window->scene->addLine(i, 0, i, 1080, QPen(Qt::darkGray));
    for (auto i = 0; i <= 1080; i += 40)
        window->scene->addLine(0, i, 1920, i, QPen(Qt::darkGray));
    all_elements.resize(0);
    all_nets.resize(0);
    all_inOutputs.resize(0);
    //qDebug("load");
    in.read((char *) &logic_level, sizeof (logic_level));
    {
        window->ui->tab->setEnabled(true);
        if (logic_level == 2)
            window->ui->tab_1->setEnabled(true);
        else
            window->ui->tab_1->setEnabled(false);
        if (logic_level == 3)
            window->ui->tab_2->setEnabled(true);
        else
            window->ui->tab_2->setEnabled(false);
        window->ui->pushButton->setEnabled(true);
        window->ui->connector->setEnabled(true);
        window->ui->addInOut->setEnabled(true);
        window->ui->addNet->setEnabled(true);
        window->logic_status->setText("Logic level: " + QString::number(logic_level));
        window->enableUpdate(true);
    }
    size_t size_of_all_elements = 0;
    size_t size_of_all_inOutputs = 0;
    size_t size_of_all_nets = 0;
    in.read((char *) &size_of_all_elements, sizeof (size_t));
    in.read((char *) &size_of_all_inOutputs, sizeof (size_t));
    in.read((char *) &size_of_all_nets, sizeof (size_t));
    qDebug() << size_of_all_elements;
    qDebug() << size_of_all_inOutputs;
    qDebug() << size_of_all_nets;
    all_elements.resize(size_of_all_elements);
    all_inOutputs.resize(size_of_all_inOutputs);
    all_nets.resize(size_of_all_nets);
    for (size_t i = 0; i < size_of_all_elements; i++)
    {
        LogicalElement *el = new LogicalElement;
        in.read((char *) &el->is_connector, sizeof (LogicalElement::is_connector));
        in.read((char *) &el->width, sizeof (LogicalElement::width));
        in.read((char *) &el->height, sizeof (LogicalElement::height));
        QPointF pos;
        in.read((char *) &pos, sizeof (pos));
        el->setPos(pos);
        in.read((char *) &el->L_ID, sizeof (LogicalElement::L_ID));
        in.read((char *) &el->L_delay, sizeof (LogicalElement::L_delay));
        size_t name_size;
        in.read((char *) &name_size, sizeof (name_size));
        char *name = (char *) malloc(name_size + 1);
        in.read(name, name_size);
        name[name_size] = '\0';
        el->L_name = name;
        free(name);
        ionum_t input_num;
        in.read((char *) &input_num, sizeof (input_num));
        el->L_inputs.resize(input_num);
        ionum_t output_num;
        in.read((char *) &output_num, sizeof (output_num));
        el->L_outputs.resize(output_num);
        size_t rows;
        in.read((char *) &rows, sizeof (rows));
        el->T_outputs.resize(rows);
        if (rows > 0)
        {
            size_t columns;
            in.read((char *) &columns, sizeof (columns));
            for (size_t row = 0; row < el->T_outputs.size(); row++)
            {
                el->T_outputs[row].resize(columns);
                for (size_t column = 0; column < el->T_outputs[row].size(); column++)
                    in.read((char *) &el->T_outputs[row][column], sizeof (value_t));
            }
        }
        for (ionum_t output = 0; output < output_num; output++)
            in.read((char *) &el->L_outputs[output], sizeof (value_t));
        QObject::connect(el, &LogicalElement::connectSignal, window, &MainWindow::connectSlot);
        QObject::connect(el, &LogicalElement::delSignal, window, &MainWindow::delElSlot);
        window->scene->addItem(el);
        el->update();
        all_elements[i] = el;
    }
    for (size_t i = 0; i < size_of_all_inOutputs; i++)
    {
        Input_Output *io = new Input_Output;
        in.read((char *) &io->IO_ID, sizeof (Input_Output::IO_ID));
        in.read((char *) &io->width, sizeof (Input_Output::width));
        in.read((char *) &io->height, sizeof (Input_Output::height));
        in.read((char *) &io->addr, sizeof (Input_Output::addr));
        in.read((char *) &io->is_input, sizeof (Input_Output::is_input));
        in.read((char *) &io->value, sizeof (Input_Output::value));
        QObject::connect(io, &Input_Output::delSignal, window, &MainWindow::delIOSlot);
        QObject::connect(all_elements[io->addr.first], &LogicalElement::coordsSignal, io, &Input_Output::coordsSlot);
        if (io->is_input == false)
        {
            QPointF position = all_elements[io->addr.first]->pos() + QPointF(all_elements[io->addr.first]->width,
                                                                             -all_elements[io->addr.first]->height / 2
                                                                                 + (all_elements[io->addr.first]->height / (all_elements[io->addr.first]->L_outputs.size() + 1)) * (io->addr.second + 1));
            io->setPos(position);
        }
        else
        {
            QPointF position = all_elements[io->addr.first]->pos() + QPointF(-all_elements[io->addr.first]->width,
                                                                             -all_elements[io->addr.first]->height / 2
                                                                                 + (all_elements[io->addr.first]->height / (all_elements[io->addr.first]->L_inputs.size() + 1)) * (io->addr.second + 1));
            io->setPos(position);
        }
        window->scene->addItem(io);
        io->update();
        all_inOutputs[i] = io;
    }
    for (size_t i = 0; i < size_of_all_nets; i++)
    {
        Net *net = new Net;
        in.read((char *) &net->Net_ID, sizeof (Net::Net_ID));
        in.read((char *) &net->net_delay, sizeof (Net::net_delay));
        in.read((char *) &net->start_addr, sizeof (Net::start_addr));
        in.read((char *) &net->end_addr, sizeof (Net::end_addr));
        in.read((char *) &net->start_pos, sizeof (Net::start_pos));
        in.read((char *) &net->end_pos, sizeof (Net::end_pos));
        value_t trash;
        in.read((char *) &trash, sizeof (Net::value));
        net->setPos(0, 0);
        id_t id_start = returnLID(all_elements, net->start_addr.first), id_end = returnLID(all_elements, net->end_addr.first);
        QObject::connect(all_elements[id_start], &LogicalElement::coordsSignal, net, &Net::coordsStartSlot);
        QObject::connect(all_elements[id_end], &LogicalElement::coordsSignal, net, &Net::coordsEndSlot);
        window->scene->addItem(net);
        net->update();
        all_nets[i] = net;
    }
    //updateScheme(MAX_ITERATIONS);
    return 0;
}

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

vector<Input_Output *>::iterator isIOIDExist(id_t id)
{
    vector<Input_Output *>::iterator iter = all_inOutputs.begin();
    while (iter < all_inOutputs.end())
    {
        if ((*iter)->IO_ID == id)
            return iter;
        iter++;
    }
    return all_inOutputs.end();
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

long returnLID(vector<LogicalElement *> src, id_t id)
{
    for (id_t i = 0; i < src.size(); i++)
        if (src[i]->L_ID == id)
            return i;
    return -1;
}

id_t findLID(vector<LogicalElement *> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0]->L_ID > 0)
        return src[0]->L_ID - 1;
    for (size_t i = 0; i < src.size() - 1; i++)
        if (src[i]->L_ID < src[i + 1]->L_ID - 1)
            return src[i + 1]->L_ID - 1;
    return src.back()->L_ID + 1;
}

id_t findIOID(vector<Input_Output *> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0]->IO_ID > 0)
        return src[0]->IO_ID - 1;
    for (size_t i = 0; i < src.size() - 1; i++)
        if (src[i]->IO_ID < src[i + 1]->IO_ID - 1)
            return src[i + 1]->IO_ID - 1;
    return src.back()->IO_ID + 1;
}

id_t findNID(vector<Net *> src)
{
    if (src.size() == 0)
        return 0;
    if (src[0]->Net_ID > 0)
        return src[0]->Net_ID - 1;
    for (size_t i = 0; i < src.size() - 1; i++)
        if (src[i]->Net_ID < src[i + 1]->Net_ID - 1)
            return src[i + 1]->Net_ID - 1;
    return src.back()->Net_ID + 1;
}

vector<vector<value_t>> makeInputTable(ionum_t input_num, level_t logic_level)
{
    auto rows = (rows_t) pow(logic_level, input_num);
    vector<vector<value_t>> input_table (rows, vector<value_t> (input_num));
    for (rows_t i = 0; i < rows; i++)
    {
        auto current_row = i;
        for (int j = input_num - 1; j >= 0; j--)
        {
            input_table[i][j] = current_row % logic_level;
            current_row /= logic_level;
        }
    }
    return input_table;
}

int updateScheme(unsigned max_iterations/*vector<id_t> inOutput_ids_to_ignore*/)
{
    if (all_elements.size() == 0 || logic_level == 0)
    {
        qDebug() << "No elements or logic level is undefined...";
        return 0;
    }
    unsigned iterations;
    for (iterations = 0; iterations < max_iterations; iterations++)
    {
        //qDebug() << "iter:" << iterations;
        bool changed = false;
        for (size_t i = 0; i < all_inOutputs.size(); i++)
        {
            if (all_inOutputs[i]->is_input == true)
            {
                long x = 0;
                x = returnLID(all_elements, all_inOutputs[i]->addr.first);
                /*
                //while (all_elements[x]->L_ID != all_inOutputs[i]->addr.first)
                    //x++;
*/
                if (all_elements[x]->L_inputs[all_inOutputs[i]->addr.second] != all_inOutputs[i]->value)
                {
                    changed = true;
                    all_elements[x]->L_inputs[all_inOutputs[i]->addr.second] = all_inOutputs[i]->value;
                }
            }
            else
            {
                long x = 0;
                x = returnLID(all_elements, all_inOutputs[i]->addr.first);
                /*
                //while (all_elements[x]->L_ID != all_inOutputs[i]->addr.first)
                    //x++;
*/
                if (all_inOutputs[i]->value != all_elements[x]->L_outputs[all_inOutputs[i]->addr.second])
                {
                    changed = true;
                    all_inOutputs[i]->value = all_elements[x]->L_outputs[all_inOutputs[i]->addr.second];
                }
            }
            all_inOutputs[i]->update();
        }
        for (size_t i = 0; i < all_elements.size(); i++)
        {
            if (all_elements[i]->L_outputs != all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs))
            {
                changed = true;
                all_elements[i]->setOutput(logic_level);
            }
        }
        for (size_t i = 0; i < all_nets.size(); i++)
        {
            /*
//            if (all_nets[i]->value != all_elements[all_nets[i]->start_addr.first]->L_outputs[all_nets[i]->start_addr.second])
//            {
//                changed = true;
//                all_nets[i]->value = all_elements[all_nets[i]->start_addr.first]->L_outputs[all_nets[i]->start_addr.second];
//                all_elements[all_nets[i]->end_addr.first]->L_inputs[all_nets[i]->end_addr.second] = all_nets[i]->value;
//            }
*/
            long x = returnLID(all_elements, all_nets[i]->start_addr.first);
            /*
//            size_t x = 0;
//            while (all_elements[x]->L_ID != all_nets[i]->start_addr.first)
//                x++;
            //qDebug() << "x:" << x;
*/
            if (all_elements[x]->L_outputs != all_elements[x]->getOutput(logic_level, all_elements[x]->L_inputs))
            {
                changed = true;
                //qDebug() << "changed:" << changed;
                all_elements[x]->setOutput(logic_level);
            }
            if (all_nets[i]->value != all_elements[x]->L_outputs[all_nets[i]->start_addr.second])
            {
                changed = true;
                all_nets[i]->value = all_elements[x]->L_outputs[all_nets[i]->start_addr.second];
            }

            long y = returnLID(all_elements, all_nets[i]->end_addr.first);
            /*
//            size_t y = 0;
//            while (all_elements[y]->L_ID != all_nets[i]->end_addr.first)
//                y++;

//            bool ignore = false;
//            if (inOutput_ids_to_ignore.size() > 0)
//                for (size_t a = 0; a < inOutput_ids_to_ignore.size(); a++)
//                    if (all_inOutputs[i]->IO_ID == inOutput_ids_to_ignore[a])
//                    {
//                        ignore = true;
//                        break;
//                    }
*/
            if (all_elements[y]->L_inputs[all_nets[i]->end_addr.second] != all_nets[i]->value)
            {
                changed = true;
                all_elements[y]->L_inputs[all_nets[i]->end_addr.second] = all_nets[i]->value;
            }
            if (all_elements[y]->L_outputs != all_elements[y]->getOutput(logic_level, all_elements[y]->L_inputs))
            {
                changed = true;
                all_elements[y]->setOutput(logic_level);
            }
            all_nets[i]->update();
        }
        if (changed == false)
            break;
    }
    qDebug() << "iterations:" << iterations + 1;
    if (iterations == max_iterations)
        return -1;
    return iterations;
}

int simulateScheme(MainWindow *window)
{
    ticker = 0;
    ticker_t global_delay = 0;
    for (size_t i = 0; i < all_elements.size(); i++)
        global_delay += all_elements[i]->L_delay;
    for (size_t i = 0; i < all_nets.size(); i++)
        global_delay += all_nets[i]->net_delay;
    global_delay++;
    global_delay *= 2;
    qDebug() << "global delay: " << global_delay;
    window->ui->tickerSlider->setMaximum(global_delay);
    for (size_t i = 0; i < all_elements.size(); i++)
    {
        for (size_t t = 0; t < all_elements[i]->temps.size(); t++)
            all_elements[i]->temps.resize(0, Temp(vector<value_t> {0}, 0));
        all_elements[i]->temps.push_back(Temp(all_elements[i]->L_outputs, 0));
        //qDebug() << "Element ID " << all_elements[i]->L_ID << " temps size after sim" << all_elements[i]->temps.size();
    }
    for (size_t i = 0; i < all_nets.size(); i++)
    {
        for (size_t t = 0; t < all_nets[i]->temps.size(); t++)
            all_nets[i]->temps.resize(0, Temp(vector<value_t> {0}, 0));
        all_nets[i]->temps.push_back(Temp(vector<value_t> {all_nets[i]->value}, 0));
    }

    for (; ticker <= global_delay; ticker++)
    {
        for (size_t i = 0; i < all_inOutputs.size(); i++)
        {
            if (all_inOutputs[i]->is_input == true)
            {
                long x = 0;
                x = returnLID(all_elements, all_inOutputs[i]->addr.first);
                if (all_elements[x]->L_inputs[all_inOutputs[i]->addr.second] != all_inOutputs[i]->value)
                    all_elements[x]->L_inputs[all_inOutputs[i]->addr.second] = all_inOutputs[i]->value;
            }
        }
        for (size_t i = 0; i < all_elements.size(); i++)
        {
            //if (all_elements[i]->L_outputs != all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs) &&
            //    all_elements[i]->temps.size() > 0 /*&&
            //    all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs) != all_elements[i]->temps.back().values*/)
            //{
                all_elements[i]->temps.push_back
                    (Temp(all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs), ticker + all_elements[i]->L_delay));
            //}
            //else if (all_elements[i]->L_outputs != all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs) &&
            //         all_elements[i]->temps.size() == 0)
            //    all_elements[i]->temps.push_back
            //        (Temp(all_elements[i]->getOutput(logic_level, all_elements[i]->L_inputs), ticker + all_elements[i]->L_delay));
            for (size_t t = 0; t < all_elements[i]->temps.size(); t++)
            {
                if (all_elements[i]->temps[t].timestamp == ticker)
                    all_elements[i]->L_outputs = all_elements[i]->temps[t].values;
            }
        }
        for (size_t i = 0; i < all_nets.size(); i++)
        {
            long x = returnLID(all_elements, all_nets[i]->start_addr.first);
            //if (all_nets[i]->value != all_elements[x]->L_outputs[all_nets[i]->start_addr.second] &&
            //    all_nets[i]->temps.size() > 0 /*&&
            //    all_elements[x]->L_outputs[all_nets[i]->start_addr.second] != all_nets[i]->temps.back().values[0]*/)
            //{
                all_nets[i]->temps.push_back
                    (Temp(vector<value_t> {all_elements[x]->L_outputs[all_nets[i]->start_addr.second]},
                          ticker + all_nets[i]->net_delay));
            //}
            //else if (all_nets[i]->value != all_elements[x]->L_outputs[all_nets[i]->start_addr.second] && all_nets[i]->temps.size() == 0)
            //    all_nets[i]->temps.push_back
            //        (Temp(vector<value_t> {all_elements[x]->L_outputs[all_nets[i]->start_addr.second]},
            //              ticker + all_nets[i]->net_delay));
            for (size_t t = 0; t < all_nets[i]->temps.size(); t++)
            {
                if (all_nets[i]->temps[t].timestamp == ticker)
                    all_nets[i]->value = all_nets[i]->temps[t].values[0];
                long y = returnLID(all_elements, all_nets[i]->end_addr.first);
                all_elements[y]->L_inputs[all_nets[i]->end_addr.second] = all_nets[i]->value;
            }
        }
    }
    ticker = 0;
    return 0;
}

int useSimulation(ticker_t time)
{
    for (size_t i = 0; i < all_elements.size(); i++)
    {
        //qDebug() << "Element ID " << all_elements[i]->L_ID << " temps size" << all_elements[i]->temps.size();
        if (all_elements[i]->temps.size() == 0)
            continue;
        if (all_elements[i]->temps.size() == 1)
        {
            all_elements[i]->L_outputs = all_elements[i]->temps[0].values;
            continue;
        }
        for (size_t t = 0; t < all_elements[i]->temps.size(); t++)
        {
            if (time == all_elements[i]->temps[t].timestamp /*&& time < all_elements[i]->temps[t + 1].timestamp*/)
                all_elements[i]->L_outputs = all_elements[i]->temps[t].values;
            //else
                //all_elements[i]->L_outputs = all_elements[i]->temps[t + 1].values;
        }
    }
    for (size_t i = 0; i < all_nets.size(); i++)
    {
        //qDebug() << "net temps size" << all_nets[i]->temps.size();
        if (all_nets[i]->temps.size() == 0)
            continue;
        if (all_nets[i]->temps.size() == 1)
        {
            all_nets[i]->value = all_nets[i]->temps[0].values[0];
            continue;
        }
        for (size_t t = 0; t < all_nets[i]->temps.size(); t++)
        {
            if (time == all_nets[i]->temps[t].timestamp /*&& time < all_nets[i]->temps[t + 1].timestamp*/)
                all_nets[i]->value = all_nets[i]->temps[t].values[0];
            //else
                //all_nets[i]->value = all_nets[i]->temps[t + 1].values[0];
        }
        all_nets[i]->update();
    }
    for (size_t i = 0; i < all_inOutputs.size(); i++)
    {
        if (all_inOutputs[i]->is_input == false)
        {
            long x = returnLID(all_elements, all_inOutputs[i]->addr.first);
            /*
                //while (all_elements[x]->L_ID != all_inOutputs[i]->addr.first)
                    //x++;
*/
            if (all_inOutputs[i]->value != all_elements[x]->L_outputs[all_inOutputs[i]->addr.second])
            {
                all_inOutputs[i]->value = all_elements[x]->L_outputs[all_inOutputs[i]->addr.second];
            }
        }
        else
        {
            long x = 0;
            x = returnLID(all_elements, all_inOutputs[i]->addr.first);
            all_inOutputs[i]->value = all_elements[x]->L_inputs[all_inOutputs[i]->addr.second];
        }
        all_inOutputs[i]->update();
    }
    return 0;
}

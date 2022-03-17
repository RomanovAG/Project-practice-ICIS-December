#include "mainwindow.h"
#include "classes.h"
#include "logictypes.h"
#include "windows.h"
//#include "methods.h"
#include <algorithm>
#include <iostream>

#include <QtWidgets>
#include <QLocale>
#include <QTranslator>

//std::vector<LogicalElement> all_elements;
std::vector<Net> all_nets;
std::vector<std::tuple<id_t, value_t>> global_inputs;
std::vector<std::tuple<id_t, value_t>> global_outputs;

ticker_t ticker;
level_t logic_level;

//bool comp(LogicalElement a, LogicalElement b)
//{
//    return a.L_ID < b.L_ID;
//}

int main(int argc, char *argv[])
{
    logic_level = 0;
/*    int i = 0;
    int max = 1;
    std::cin >> max;
//    while (i < max)
//    {
//        logic_level = 3;
//        delay_t delay;
//        std::cout << "delay of element " << i << " : ";
//        std::cin >> delay;
//        ionum_t inputs, outputs;
//        std::cout << "Enter input/output num: ";
//        std::cin >> inputs >> outputs;

//        //all_elements.push_back((LogicalElement(findId(all_elements), delay, inputs, outputs)));
//        //sort(all_elements.begin(), all_elements.end(), comp);
//        for (unsigned i = 0; i < all_elements.size(); i++)
//        {
//            std::cout << (all_elements[i]).L_ID << " ";
//        }
//    }

    //qsort(&all_elements, all_elements.size(), sizeof (tuple<LogicalElement, TruthTable>), comparID);
    //TruthTable table_1(element_1.L_ID, element_1.L_inputs.size(), element_1.L_outputs.size());
*/
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "LogiTect_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            app.installTranslator(&translator);
            break;
        }
    }
    qDebug() << "hello\n";
    MainWindow w;
    //w.resize(1280, 720);
    w.show();
    QObject::connect(&w.form_SLL, &Set_logic_level::logicLevelChanged, &w, &MainWindow::onLogicLevelChanged);
    return app.exec();
        return 0;
}

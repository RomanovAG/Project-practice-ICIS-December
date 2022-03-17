//#include "mainwindow.h"

#include "windows.h"

#include <algorithm>
#include <iostream>

#include "classes.h"
#include "methods.h"
#include "logictypes.h"
#include "menu.h"

//#include <QApplication>
//#include <QLocale>
//#include <QTranslator>
using namespace std;

extern MenuParts cmd_list;

ticker_t ticker;
level_t logic_level = 0;
vector<LogicalElement> all_elements;
vector<Net> all_nets;
//vector<pair<id_t, vector<value_t>>> global_inputs;
//vector<pair<id_t, vector<value_t>>> global_outputs;

int main(int argc, char *argv[])
{
    cmd_list.used_now = 1;
    drawEverything();
    if (logic_level < 1)
    {
        cout << "Logic level is uninitialized. Please, set the logic level\n";
        setLogicLevel();
        cout << "Logic level: " << (int) logic_level << "\n";
    }
    drawEverything();
    while (1)
    {
        executeCommand();
    }

//    for (auto i = 0; i < all_elements[0].L_outputs.size(); i++)
//    {
//        cout << all_elements[0].getOutput(logic_level, vector<value_t> {2, 1})[i];
//    }
    /*QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "LogiTect_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();*/

    return 0;
}

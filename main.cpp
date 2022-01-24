#include "mainwindow.h"
#include "classes.h"
#include "windows.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

ticker_t ticker;
level_t logic_level;

int main(int argc, char *argv[])
{
    logic_level = 3;

    LogicalElement element_1(all_elements.back().L_ID + 1, 5, 2, 2);
    TruthTable table_1(element_1.L_ID, element_1.L_inputs.size(), element_1.L_outputs.size());

//    QApplication a(argc, argv);

//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages)
//    {
//        const QString baseName = "LogiTect_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName))
//        {
//            a.installTranslator(&translator);
//            break;
//        }
//    }
//    MainWindow w;
//    w.show();
//    return a.exec();
    return 0;
}

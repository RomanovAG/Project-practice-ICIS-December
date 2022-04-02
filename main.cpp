#include "mainwindow.h"
#include "logictypes.h"
#include "logicalelement.h"
#include "net.h"
#include "input_output.h"
#include "windows.h"
//#include "methods.h"
#include <algorithm>
#include <iostream>

#include <QtWidgets>
#include <QLocale>
#include <QTranslator>

std::vector<LogicalElement *> all_elements;
std::vector<Input_Output *> all_inOutputs;
std::vector<Net *> all_nets;

ticker_t ticker;
level_t logic_level;

int main(int argc, char *argv[])
{
    logic_level = 0;
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
    qDebug() << QStyleFactory::keys();
    app.setStyle(QStyleFactory::create("windowsvista"));
    MainWindow w;
    w.show();
    return app.exec();
}

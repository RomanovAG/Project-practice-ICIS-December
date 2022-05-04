#include "mainwindow.h"
#include "logictypes.h"
#include "logicalelement.h"
#include "net.h"
#include "input_output.h"
#include "windows.h"
#include <stdio.h>

#include <QtWidgets>

QString current_file;
std::vector<LogicalElement *> all_elements;
std::vector<Input_Output *> all_inOutputs;
std::vector<Net *> all_nets;

ticker_t ticker;
level_t logic_level;

//void showLogo(QApplication *app, unsigned time);

int main(int argc, char *argv[])
{
    current_file = "";
    ticker = 0;
    logic_level = 0;

    QApplication app(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "LogiTect_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName) == true)
        {
            app.installTranslator(&translator);
            break;
        }
    }
    qDebug() << QStyleFactory::keys();
    app.setStyle(QStyleFactory::create("windowsvista"));
    /*
//    FILE *settings = fopen("Settings.txt", "r+");
//    //QFile file("Settings.txt");
//    //file.open(QIODevice::WriteOnly);
//    //int first_start = 1;
//    //file.write((char *) &first_start, sizeof (int));
//    //int show_logo = 0;
//    //file.write((char *) &show_logo, sizeof (int));
//    //file.close();
//    //return 0;
//    if (settings == NULL)
//    {
//        QMessageBox message;
//        message.critical(NULL, "Error", "Invalud output table");
//        message.show();
//    }
//    else
//    {
//        for (int i = 0; i < 20; i++)
//            fprintf(settings, "lol\n");
//        int first_start = 9;
//        int show_logo;
//        fscanf(settings, "%d", &first_start);
//        fscanf(settings, "%*c");
//        fscanf(settings, "%d", &show_logo);
//        qDebug() << "first start " << first_start;
//        if (first_start == 1)
//        {

//            fseek(settings, 0, SEEK_SET);
//            first_start = 0;
//            fprintf(settings, "0\n");
//            showLogo(&app, 1500);
//        }
//        else if (show_logo == 1)
//            showLogo(&app, 1500);
//    }
//    fclose(settings);
*/
    MainWindow w;
    w.show();
    return app.exec();
}

void showLogo(QApplication *app, unsigned time)
{
    QPixmap pix;
    pix.load("D:/Programs/LogiTect/LogiTect/LogiTect 512.png");
    QLabel label;
    label.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    label.setAttribute(Qt::WA_NoSystemBackground);
    label.setAttribute(Qt::WA_TranslucentBackground);
    label.setAttribute(Qt::WA_TransparentForMouseEvents);
    label.setPixmap(pix);
    QPoint pos = QPoint(128, 0);
    label.move(app->desktop()->screen()->rect().center() - label.rect().center() + pos);
    label.show();
    QTimer *tmr = new QTimer;
    QObject::connect(tmr, &QTimer::timeout, &label, &QLabel::close);
    tmr->setInterval(time);
    tmr->start();
}

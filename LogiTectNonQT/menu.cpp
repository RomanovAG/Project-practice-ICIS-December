#include <iostream>
#include <string>
#include "menu.h"
#include "methods.h"
#include "logictypes.h"
using namespace std;

MenuParts cmd_list;
extern string current_file;
extern level_t logic_level;

void drawCommandList()
{
    if (cmd_list.used_now == 1)
    {
        printf("|----------------------------|-----------------------------------|--------------------------------------|\n"
               "|           Main             |            Simulation             |                Scheme                |\n"
               "|----------------------------|-----------------------------------|--------------------------------------|\n"
               "|    pin: Pin command list   |  update: Start simulation         |       new: Add new logical elements  |\n"
               "|  unpin: Unpin command list |      ++: Increase time            |    delete: Delete element            |\n"
               "|   open: Open file          |      --: Decrease time            |   connect: Connect elements          |\n"
               "|   save: Save file          |                                   |disconnect: Disconnect elements       |\n"
               "| saveas: Save file as       |                                   |     setTT: Set the truth table of the element|\n"
               "|                            |  showel: Show elements            |   setname: Change name of the element|\n"
               "|   quit: Close the program  |   shown: Show nets                |    setval: Set value                 |\n"
               "|----------------------------|-----------------------------------|--------------------------------------|\n");
        cout << "\n";
    }
}

void drawEverything()
{
    system("cls");
    printf("== Program is working == File: \"%s\" == Logic level: %d ==\n\n", current_file.c_str(), logic_level);
    drawCommandList();
}

void executeCommand()
{
    string command;
    int check;
    do
    {
        cout << ">";
        if (!getline(cin, command))
            exit(0);
        if (command == "pin")
        {
            pin();
            check = 1;
        }
        else if (command == "unpin")
        {
            unpin();
            check = 1;
        }
        else if (command == "open")
        {
            open();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "save")
        {
            //save();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "saveas")
        {
            saveAs();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "quit")
        {
            quit();
            check = 1;
        }
        else if (command == "new")
        {
            addElements();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "delete")
        {
            delElements();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "connect")
        {
            connect();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "disconnect")
        {
            disconnect();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "setTT")
        {
            setTT();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "setname")
        {
            setName();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "update")
        {
            update();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else if (command == "showel")
        {
            showElements();
            printf("Press enter to continue . . .");
            getchar();
            check = 1;
        }
        else if (command == "shown")
        {
            showNets();
            printf("Press enter to continue . . .");
            getchar();
            check = 1;
        }
        else if (command == "setval")
        {
            setValue();
            printf("Press enter to continue . . .");
            getchar();
            scanf("%*c");
            check = 1;
        }
        else
        {
            drawEverything();
            cout << "Error: \"" << command << "\" is not a command\n";
            check = 0;
        }
        if (check == 1)
            drawEverything();
    }
    while (check == 0);
}

void pin()
{
    cmd_list.used_now = 1;
}

void unpin()
{
    cmd_list.used_now = 0;
}

void quit()
{
    exit(0);
}

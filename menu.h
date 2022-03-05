#ifndef MENU_H
#define MENU_H

void drawEverything();
void executeCommand();

typedef struct MenuParts
{
    int used_now;
} MenuParts;

void pin();
void unpin();
void quit();

#endif // MENU_H

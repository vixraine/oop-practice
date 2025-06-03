#include <iostream>
#include "menu.hpp"
#include "database.hpp"

using namespace std;

int main()
{
    system("chcp 65001");

    Database db("D:/qt-lab/pr2/docks.db");
    Menu menu(db);

    int choice = 0;

    while (1) {
        // WINDOWS COMPATIBILITY. IM SO SORRY.
        system("cls");
        menu.draw_main_menu();
        cin >> choice;
        menu.func_switch(choice);
        cin.get();
        cin.get();
    }

    return 0;
}

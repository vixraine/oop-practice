#ifndef MENU_HPP
#define MENU_HPP
#include "database.hpp"

class Menu {
private:
    Database& db;

public:
    Menu(Database& database);
    void draw_main_menu() const;
    void func_switch(int input);
    void add_item();
    void remove_item();
    void edit_item();
    void find_item();
    void print_all_items();
    void about();
};

#endif // MENU_HPP

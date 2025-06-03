#include "menu.hpp"
#include <iostream>

using namespace std;

Menu::Menu(Database& database): db(database) {}

void Menu::draw_main_menu() const {
    cout << " === Меню ===" << endl;
    cout << " 1. Вывести на экран все данные" << endl;
    cout << " 2. Добавить запись" << endl;
    cout << " 3. Удалить запись" << endl;
    cout << " 4. Редактировать запись" << endl;
    cout << " 5. Найти запись" << endl;
    cout << " 6. О программе" << endl;
    cout << " 7. Выход" << endl;
    cout << " >> ";
}

void Menu::func_switch(int input) {
    switch (input) {
    case 1:
        print_all_items();
        break;
    case 2:
        add_item();
        break;
    case 3:
        remove_item();
        break;
    case 4:
        edit_item();
        break;
    case 5:
        find_item();
        break;
    case 6:
        about();
        break;
    case 7:
        cout << "Завершение работы и сохранение базы данных." << endl;
        exit(EXIT_SUCCESS);
    }
}

void Menu::add_item() {
    std::string man, mdl;
    int prc, hdmis, usbs, ethernet;
    bool hot;

    cout << "\n --- Добавление записи ---" << endl;
    cout << "Производитель: ";
    getline(cin >> ws, man);
    cout << "Модель: ";
    getline(cin >> ws, mdl);
    cout << "Цена: ";
    cin >> prc;
    cout << "Количество портов USB: ";
    cin >> usbs;
    cout << "Количество портов HDMI: ";
    cin >> hdmis;
    cout << "Скорость проводного интернета в Мбит/с: ";
    cin >> ethernet;
    cout << "Горячая замена (1 - да / 0 - нет): ";
    cin >> hot;

    DockingStation new_dock(man, mdl, prc, usbs, hdmis, ethernet, hot);
    db.add_item(new_dock);
    cout << "Запись добавлена." << endl;
}


void Menu::remove_item() {
    string model;
    cout << " --- Удаление записи ---" << endl;
    cout << " Введите модель удаляемой записи: ";
    getline(cin >> ws, model);

    if (db.remove_item(model)) {
        cout << " Запись " << model << " успешно удалена." << endl;
    }
    else {
        cout << " Ошибка:" << endl
             << " Запись " << model << " не найдена." << endl;
    }
}

void Menu::edit_item() {
    string model;
    cout << " --- Редактирование записи ---" << endl;
    cout << " Введите модель редактируемой записи: ";
    getline(cin >> ws, model);

    DockingStation* dock = db.find_item(model);
    if (!dock) {
        cout << " Ошибка:" << endl
             << " Запись " << model << " не найдена." << endl;
        return;
    }

    string input;
    cout << " Текущяя запись:" << endl;
    dock->print_info();
    //  [" << dock->get_manufacturer() << "]
    cout << " Производитель [" << dock->get_manufacturer() << "]: ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_manufacturer(input);

    cout << " Модель [" << dock->get_model() << "]: ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_model(input);

    cout << " Цена [" << dock->get_price() << "]: ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_price(stoi(input));

    cout << " Количество портов USB [" << dock->get_usb_ports() << "]: ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_usb_ports(stoi(input));

    cout << " Количество портов HDMI [" << dock->get_hdmi_ports() << "]: ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_hdmi_ports(stoi(input));

    cout << " Скорость проводного интернета в Мбит/с [" << dock->get_ethernet_mbit() << "]: ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_ethernet_mbit(stoi(input));

    cout << " Горячая замена [" << (dock->get_hot_plug() ? "да" : "нет") << "] (1 - да / 0 - нет): ";
    getline(cin >> ws, input);
    if (!input.empty()) dock->set_hot_plug(stoi(input));

    cout << " Запись обновлена." << endl;
}

void Menu::find_item() {
    string model;
    cout << " --- Поиск записи ---" << endl;
    cout << " Введите модель искомой записи: ";
    getline(cin >> ws, model);

    DockingStation* dock = db.find_item(model);
    if (dock) {
        cout << " Найдена запись. ";
        dock->print_info();
    }
    else {
        cout << " Ошибка:" << endl
             << " Запись " << model << " не найдена." << endl;
    }
}

void Menu::print_all_items() {
    cout << " --- Полный список ---" << endl;
    if (db.is_empty()) {
        cout << " Ошибка:" << endl
             << " База данных пуста." << endl;
    }
    else {
        db.print_all_items();
    }
}

void Menu::about() {
    cout << " --- О программе ---" << endl
         << " vixia raine :3 (replace)" << endl;
}

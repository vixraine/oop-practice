#include "database.hpp"
#include <iostream>
#include <fstream>

Database::Database(const std::string& filename): first(nullptr), last(nullptr), length(0), filename(filename) {
    read_file();
}

// destructor - when the db object ceases existing,
// write its contents to (a) the file
// (Ooo, dangerous, stardust!)
Database::~Database() {
    write_file();
    Index* current = first;
    while (current != nullptr) {
        Index* next = current->next;
        delete current;
        current = next;
    }
}

void Database::read_file() {
    std::ifstream input_file(filename);
    if (!input_file) {
        std::cerr << "[CERR] не удалось открыть файл базы данных" << std::endl;
        std::cin.get();
        std::cin.get();
        return;
    }

    DockingStation dock;
    while (input_file.peek() != EOF) {
        dock.read_from_file(input_file);
        add_item(dock);
    }
}

void Database::write_file() const {
    std::ofstream output_file(filename);
    if (!output_file) {
        std::cerr << "[CERR] не удалось открыть файл для записи" << std::endl;
        std::cin.get();
        std::cin.get();
        return;
    }

    Index* current = first;
    while (current != nullptr) {
        current->item.write_to_file(output_file);
        current = current->next;
    }
}

int Database::get_length() const {
    return length;
}

void Database::add_item(const DockingStation& dock) {
    Index* new_item = new Index(dock);
    if (first == nullptr) {
        first = last = new_item;
    }
    else {
        last->next = new_item;
        new_item->previous = last;
        last = new_item;
    }
    length++;
}

int Database::remove_item(const std::string& model) {
    Index* current = first;
    while (current != nullptr) {
        if (current->item.get_model() == model) {
            if (current->previous) current->previous->next = current->next;
            if (current->next) current->next->previous = current->previous;
            if (current == first) first = current->next;
            if (current == last) last = current->previous;

            delete current;
            length--;
            return EXIT_SUCCESS;
        }
        current = current->next;
    }
    return EXIT_FAILURE;
}


DockingStation* Database::find_item(const std::string& model) {
    Index* current = first;
    while (current != nullptr) {
        if (current->item.get_model() == model) {
            return &(current->item);
        }
        current = current->next;
    }
    return nullptr;
}

int Database::edit_item(const std::string& model, const DockingStation& new_data) {
    DockingStation* dock = find_item(model);
    if (dock) {
        *dock = new_data;  // overloading but it doesn't work
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

void Database::print_all_items() const {
    Index* current = first;
    while (current != nullptr) {
        current->item.print_info();
        current = current->next;
    }
}

bool Database::is_full() const {
    return false;
}

bool Database::is_empty() const {
    return (length == 0);
}

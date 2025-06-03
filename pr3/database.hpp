#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "dockingstation.hpp"

struct Index {
    DockingStation item;
    Index* previous;
    Index* next;

    Index(const DockingStation& dock): item(dock), previous(nullptr), next(nullptr) {}
};

class Database {
private:
    Index* first;
    Index* last;
    int length;
    std::string filename;

    // forbid copying and assigning
    Database(const &Database) = delete;
    Database& operator=(const &Database) = delete;
public:
    Database(const std::string& filename);
    ~Database(); // destructor

    void read_file();
    void write_file() const;

    int get_length() const;

    void add_item(const DockingStation& dock);
    int remove_item(const std::string& model);
    DockingStation* find_item(const std::string& model);
    int edit_item(const std::string& model, const DockingStation& new_data);
    void print_all_items() const;
    bool is_full() const;
    bool is_empty() const;
};

#endif // DATABASE_HPP

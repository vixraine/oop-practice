#include <iostream>
#include <fstream>
#include <sstream>
#include "hub.hpp"
#include <string>

// polymorphism - take different actions based on input types
USBHub::USBHub(): manufacturer("Неизвестно"), model("Неизвестно"), price(0), usb_ports(0) {}

USBHub::USBHub(const std::string& man, const std::string& mdl, const int prc, const int usbs):
    manufacturer(man), model(mdl), price(prc), usb_ports(usbs)
{}

void USBHub::set_manufacturer(const std::string& man) {
    this->manufacturer = man;
}

void USBHub::set_model(const std::string& mdl) {
    this->model = mdl;
}

void USBHub::set_price(const int& prc) {
    this->price = prc;
}

void USBHub::set_usb_ports(const int& usbs) {
    this->usb_ports = usbs;
}

std::string USBHub::get_manufacturer() const {
    return this->manufacturer;
}

std::string USBHub::get_model() const {
    return this->model;
}

int USBHub::get_price() {
    return this->price;
}

int USBHub::get_usb_ports() {
    return this->usb_ports;
}

// output function
void USBHub::print_info() {
    std::cout << " 1. Производитель: " << get_manufacturer() << std::endl;
    std::cout << " 2. Модель: " << get_model() << std::endl;
    std::cout << " 3. Цена: " << get_price() << " р." << std::endl;
    std::cout << " 4. Порты: " << get_usb_ports() << " x USB" << std::endl;
}

void USBHub::write_to_file(std::ofstream& output_file) const {
    output_file << manufacturer << ";" << model << ";"
                << price << ";" << usb_ports << "\n";
}

void USBHub::read_from_file(std::ifstream& input_file) {
    std::string temp;
    getline(input_file, manufacturer, ';');

    // bandaid fix for incorrectly reading newlines
    // don't judge me.
    std::string::size_type pos = 0;
    while ((pos = manufacturer.find ("\n",pos)) != std::string::npos)
    {
        manufacturer.erase (pos, 1);
    }

    getline(input_file, model, ';');
    getline(input_file, temp, ';');
    price = stoi(temp);
    getline(input_file, temp, ';');
    usb_ports = stoi(temp);
    // input_file.ignore();
}

USBHub& USBHub::operator=(const USBHub& other) {
    if (this != &other) {
        manufacturer = other.manufacturer;
        model = other.model;
        price = other.price;
        usb_ports = other.usb_ports;
    }
    return *this;
}

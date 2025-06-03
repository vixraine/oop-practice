#include <iostream>
#include "hub.hpp"

// polymorphism - take different actions based on input types
USBHub::USBHub(): manufacturer("Неизвестно"), model("Неизвестно"), usb_ports(0) {}

USBHub::USBHub(const std::string& man, const std::string& mdl, const int usbs):
    manufacturer(man), model(mdl), usb_ports(usbs)
{}

void USBHub::set_manufacturer(const std::string& man) {
    this->manufacturer = man;
}

void USBHub::set_model(const std::string& mdl) {
    this->model = mdl;
}

void USBHub::set_usb_ports(const int& usbs) {
    this->usb_ports = usbs;
}

std::string USBHub::get_manufacturer() {
    return this->manufacturer;
}

std::string USBHub::get_model() {
    return this->model;
}

int USBHub::get_usb_ports() {
    return this->usb_ports;
}

// output function
void USBHub::printInfo() {
    std::cout << "1. Производитель: " << get_manufacturer() << std::endl;
    std::cout << "2. Модель: " << get_model() << std::endl;
    std::cout << "3. Порты: " << get_usb_ports() << " x USB" << std::endl;
}

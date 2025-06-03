#include <iostream>
#include <fstream>
#include <sstream>
#include "dockingstation.hpp"

// polymorphism - take different actions based on input types
DockingStation::DockingStation(): USBHub(), hdmi_ports(0), ethernet_mbit(0), hot_plug(false) {}

DockingStation::DockingStation(const std::string& man,
                               const std::string& mdl,
                               const int prc,
                               const int usbs,
                               const int hdmis,
                               const int ethernet,
                               const bool hot):
    USBHub(man, mdl, usbs, prc),
    hdmi_ports(hdmis), ethernet_mbit(ethernet), hot_plug(hot)
{}

void DockingStation::set_hdmi_ports(const int hdmis) {
    hdmi_ports = hdmis;
}

void DockingStation::set_ethernet_mbit(const int ethernet) {
    ethernet_mbit = ethernet;
}

void DockingStation::set_hot_plug(const bool hot) {
    hot_plug = hot;
}

int DockingStation::get_hdmi_ports() {
    return hdmi_ports;
}

std::string DockingStation::get_ethernet_mbit() {
    if (ethernet_mbit >= 1000) {
        return std::to_string(ethernet_mbit / 1000) + " Гбит/с";
    }
    else {
        return std::to_string(ethernet_mbit) + " Мбит/с";
    }
}

bool DockingStation::get_hot_plug() {
    return hot_plug;
}

// output function
void DockingStation::print_info() {
    USBHub::print_info();
    std::cout << " 5. Порты: " << get_hdmi_ports() << " x HDMI" << std::endl;
    std::cout << " 6. Скорость Ethernet: " << get_ethernet_mbit() << std::endl;
    std::cout << " 7. Замена: " << get_hot_plug() << std::endl << std::endl;
}

void DockingStation::write_to_file(std::ofstream& output_file) const {
    USBHub::write_to_file(output_file);
    output_file << hdmi_ports << ";" << ethernet_mbit << ";"
                << hot_plug << "\n";
}

void DockingStation::read_from_file(std::ifstream& input_file) {
    USBHub::read_from_file(input_file);
    std::string temp;
    getline(input_file, temp, ';');
    hdmi_ports = stoi(temp);
    getline(input_file, temp, ';');
    ethernet_mbit = stoi(temp);
    input_file >> hot_plug;
    input_file.ignore();
}

DockingStation& DockingStation::operator=(const DockingStation& other) {
    if (this != &other) {
        USBHub::operator = (other);
        hdmi_ports = other.hdmi_ports;
        ethernet_mbit = other.ethernet_mbit;
        hot_plug = other.hot_plug;
    }
    return *this;
}

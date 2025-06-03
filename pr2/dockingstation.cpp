#include <iostream>
#include <string>
#include "dockingstation.hpp"

// polymorphism - take different actions based on input types
DockingStation::DockingStation(): USBHub(), hdmi_ports(0), ethernet_mbit(0), hot_plug(false) {}

DockingStation::DockingStation(const std::string& man,
                               const std::string& mdl,
                               const int usbs,
                               const int hdmis,
                               const int ethernet,
                               const bool hot):
    USBHub(man, mdl, usbs),
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

std::string DockingStation::get_hot_plug() {
    if (hot_plug == true) {
        return "горячая";
    }
    else {
        return "холодная";
    }
}

// output function
void DockingStation::printInfo() {
    std::cout << "1. Порты: " << get_hdmi_ports() << " x HDMI" << std::endl;
    std::cout << "2. Скорость Ethernet: " << get_ethernet_mbit() << std::endl;
    std::cout << "3. Замена: " << get_hot_plug() << std::endl;
}

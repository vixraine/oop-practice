#ifndef DOCKINGSTATION_HPP
#define DOCKINGSTATION_HPP

#include "hub.hpp"
#include <iostream>

// class definition
class DockingStation: public USBHub {
private:
    int hdmi_ports;
    int ethernet_mbit;
    bool hot_plug;
public:
    DockingStation();
    DockingStation(const std::string& man,
                   const std::string& mdl,
                   const int prc,
                   const int usbs,
                   const int hdmis,
                   const int ethernet,
                   const bool hot);

    void set_hdmi_ports(const int hdmis);
    void set_ethernet_mbit(const int ethernet);
    void set_hot_plug(const bool hot);

    int get_hdmi_ports();
    std::string get_ethernet_mbit();
    bool get_hot_plug();

    void print_info() override;
    virtual void write_to_file(std::ofstream& output_file) const override;
    virtual void read_from_file(std::ifstream& input_file) override;

    DockingStation& operator=(const DockingStation& other);
};

#endif // DOCKINGSTATION_HPP

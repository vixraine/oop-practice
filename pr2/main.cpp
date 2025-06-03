#include <iostream>
#include "dockingstation.hpp"

using namespace std;

int main()
{
    system("chcp 65001"); // localisation

    cout << "класс USBHub:" << endl;
    USBHub usbh("Hoco", "USB 2.0", 4);
    usbh.printInfo();

    cout << endl << "класс DockingStation:" << endl;
    DockingStation dock("Connect", "Universal USB-C", 5, 3, 1000, false);
    dock.printInfo();

    cout << endl << "изменение свойств:" << endl;
    DockingStation dock_mod("Connect", "Universal USB-C", 5, 3, 1000, false);
    dock.set_ethernet_mbit(10000);
    dock.set_usb_ports(7);
    dock.set_hot_plug(true);
    dock.printInfo();

    return 0;
}

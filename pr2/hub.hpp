#ifndef HUB_HPP
#define HUB_HPP

#include <iostream>

// class definition
class USBHub {
// encapsulation: obscure raw data and only provide
// an interface for it using public methods
protected:  // 'private' doesn't give child classes access to these
    std::string manufacturer;
    std::string model;
    int usb_ports;
public:
    // constructors
    USBHub();
    USBHub(const std::string& man,
           const std::string& mdl,
           const int usbs);
    virtual ~USBHub() = default;

    // "setters"
    void set_manufacturer(const std::string& man) ;
    void set_model(const std::string& model);
    void set_usb_ports(const int& usbs);

    // "getter"
    std::string get_manufacturer();
    std::string get_model();
    int get_usb_ports();

    virtual void printInfo();

    USBHub& operator=(const USBHub& other);
};
#endif // HUB_HPP

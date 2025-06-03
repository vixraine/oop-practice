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
    int price;
    int usb_ports;
public:
    // constructors
    USBHub();
    USBHub(const std::string& man,
           const std::string& mdl,
           const int price,
           const int usbs);
    virtual ~USBHub() = default;

    // "setters"
    void set_manufacturer(const std::string& man) ;
    void set_model(const std::string& model);
    void set_price(const int& price);
    void set_usb_ports(const int& usbs);

    // "getter"
    std::string get_manufacturer() const;
    std::string get_model() const;
    int get_price();
    int get_usb_ports();

    virtual void print_info();
    virtual void write_to_file(std::ofstream& output_file) const;
    virtual void read_from_file(std::ifstream& input_file);

    USBHub& operator=(const USBHub& other);
};
#endif // HUB_HPP

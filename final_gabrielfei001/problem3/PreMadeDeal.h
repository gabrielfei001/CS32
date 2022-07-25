#ifndef PREMADEDEAL_H
#define PREMADEDEAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "FootwearItem.h"

class PreMadeDeal : public FootwearItem {
public:
    PreMadeDeal(std::string name, std::string brand);

    virtual ~PreMadeDeal();
    
    std::string composeItem() {
        std::string order = "PremadeDeal Brand: " + PreMadeDeal::brand + "\n";
        order += "Name: " + name + "\n";
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << getPrice();
        order += "Price: $" + stream.str() + "\n";
        return order;
    }

    double getPrice() {
        return price;
    }

protected:
    std::string name;
};

#endif
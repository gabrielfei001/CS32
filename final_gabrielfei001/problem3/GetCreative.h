#ifndef GETCREATIVE_H
#define GETCREATIVE_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>

#include "FootwearItem.h"

class GetCreative : public FootwearItem {
public: 
    GetCreative(std::string choice);

    virtual ~GetCreative();

    void addAccessory(std::string accessory);

    std::string composeItem() {
        std::string order = "GetCreative Brand: " + GetCreative::brand + "\n";
        std::map<std::string, int>::iterator i = mapAccess.begin();
        order += "Accessories:\n";
        while (i != mapAccess.end()) {
            order += i->first + ": " + std::to_string(i->second) + " quantity\n";
            i++;
        }
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << getPrice();
        order += "Price: $" + stream.str() + "\n";
        return order;
    }

    double getPrice() {
        return price;
    }
protected:
    std::vector<std::string> accessList;
    std::map<std::string, int> mapAccess;
    double addon = 5.00;

};



#endif
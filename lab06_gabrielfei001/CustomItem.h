#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>

#include "IceCreamItem.h"

class CustomItem : public IceCreamItem {
public:
    CustomItem(std::string size);
    // Constructs a custom icecream order with a size (small, medium, large)
    // Each size will have a different price.
    // Small is $3.00, medium is $5.00, and large is $6.50.
    
    virtual ~CustomItem();
    // Destructor

    void addTopping(std::string topping); 
    // method that allows you to add a toping to the custom ice cream order
    // toppings are not predefined and can be identified with strings. You can
    // assume any topping added to a CustomItem has a weight of 1 oz. Each oz. 
    // increases the price of teh CustomItem by $0.40 cents.
    // Can add the same topping as many times as you want, each one is 1 oz.
    // Need to keep track of the number of ounces for each topping and display
    // the correct number of ounces when constructing a string in composeItem.

    std::string composeItem() {
    // A virtual method that composes a string with the details
	// of an IceCreamItem. See the lab writeup and test files
	// for examples of the format for composeItem.
        std::string order = "Custom Size: " + CustomItem::size + "\n";
        std::map<std::string, int>::iterator i = maptop.begin();
        order += "Toppings:\n";
        while (i != maptop.end()) {
            order += i->first + ": " + std::to_string(i->second) + " oz" + "\n";
            i++;
        }
        std::stringstream stream;
	    stream << std::fixed << std::setprecision(2) << getPrice();
        order += "Price: $" + stream.str() + "\n";
        return order;
    }
    double getPrice() {
    // Returns the dollar amount of an ice cream item.
        return price;
    }
protected:
    std::vector<std::string> toplist;
    std::map<std::string, int> maptop;
    double addon = 0.40;
};

#endif
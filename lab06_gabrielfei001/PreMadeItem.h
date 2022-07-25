#ifndef PREMADEITEM_H
#define PREMADEITEM_H
#include <iostream>
#include <iomanip>
#include <sstream>

#include "IceCreamItem.h"

class PreMadeItem : public IceCreamItem {
public:
    PreMadeItem(std::string name, std::string size);
    // Constructs a pre-made ice cream order with a size (small, medium, large)
    // Each PreMadeItem also consists of a name (string) used when composing the details for this item.
    // Each size will have a base price for the order (without addition of toppings).
    // Small is $4.00, medium is $6.00, and large is $7.50.
    // Since PreMadeItem already has toppings built in, no need to add toppings like CustomItem.
    
    virtual ~PreMadeItem();
    // Destructor

    std::string composeItem() {
    // A virtual method that composes a string with the details
	// of an IceCreamItem. See the lab writeup and test files
	// for examples of the format for composeItem.
        std::string order = "Pre-made Size: " + PreMadeItem::size + "\n";
        order += "Pre-made Item: " + name + "\n";
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
        std::string name;
};

#endif 
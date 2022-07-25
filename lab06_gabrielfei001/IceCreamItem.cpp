#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "IceCreamItem.h"

using namespace std;

IceCreamItem::IceCreamItem(std::string size) {
    this->size = size;
}

double IceCreamItem::getPrice() {
    return price;
}
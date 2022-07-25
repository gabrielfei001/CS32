#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "IceCreamItem.h"
#include "PreMadeItem.h"

using namespace std;

PreMadeItem::PreMadeItem(string name, string size) : IceCreamItem(size) {
    this->name = name;
    if (size == "small") {
        IceCreamItem::price = 4.00;
    }
    if (size == "medium") {
        IceCreamItem::price = 6.00;
    }
    if (size == "large") {
        IceCreamItem::price = 7.50;
    }
}

PreMadeItem::~PreMadeItem(){
    //cout << "in PreMadeItem destructor" << endl;
}

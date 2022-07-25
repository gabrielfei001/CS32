#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <vector>

#include "FootwearItem.h"
#include "GetCreative.h"

using namespace std;

GetCreative::GetCreative(string choice) : FootwearItem(choice) {
    if (brand == "Adidas") {
        FootwearItem::price = 35.00;
    }
    if (brand == "Nike") {
        FootwearItem::price = 30.00;
    }
    if (brand == "Fila") {
        FootwearItem::price = 30.00;
    }
    if (brand == "Skechers") {
        FootwearItem::price = 25.00;
    }
}

GetCreative::~GetCreative() {

}

void GetCreative::addAccessory(string accessory) {
    map<string, int>::iterator i = mapAccess.find(accessory);
    accessList.push_back(accessory);
    if (i != mapAccess.end()) {
        mapAccess.insert(pair<string, int> (accessory, i->second++));
    }
    else {
        mapAccess.insert(pair<string, int> (accessory, 1));
    }
    price += addon;
}
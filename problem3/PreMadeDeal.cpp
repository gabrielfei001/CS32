#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "FootwearItem.h"
#include "PreMadeDeal.h"

using namespace std;

PreMadeDeal::PreMadeDeal(string name, string brand) : FootwearItem(brand) {
    this->name = name;
    this->brand = brand;
    if (brand == "Adidas") {
        FootwearItem::price = 45.00;
    }
    if (brand == "Nike") {
        FootwearItem::price = 40.00;
    }
    if (brand == "Fila") {
        FootwearItem::price = 40.00;
    }
    if (brand == "Skechers") {
        FootwearItem::price = 35.00;
    }
}

PreMadeDeal::~PreMadeDeal() {
    
}
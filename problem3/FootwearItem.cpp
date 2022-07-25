#include <string>
#include "FootwearItem.h"

using namespace std;

FootwearItem::FootwearItem(std::string brand) {
    this->brand = brand;

}

double FootwearItem::getPrice() {
    return price;
}
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <vector>

#include "IceCreamItem.h"
#include "CustomItem.h"

using namespace std;

CustomItem::CustomItem(string size) : IceCreamItem(size) {
    if (size == "small") {
        IceCreamItem::price = 3.00;
    }
    if (size == "medium") {
        IceCreamItem::price = 5.00;
    }
    if (size == "large") {
        IceCreamItem::price = 6.50;
    }
}

CustomItem::~CustomItem() {
    //cout << "inside CustomItem destructor" << endl;
}

void CustomItem::addTopping(string topping) {
    map<string, int>::iterator i = maptop.find(topping);
    toplist.push_back(topping);
    if( i != maptop.end()) {
        maptop.insert(pair<string, int> (topping, i->second++));
    }
    else {
        maptop.insert(pair<string, int> (topping, 1));
    }
    price += addon;
    // double addon = 0.40;
    // if (p.size() == 0) {
    //     pair<string, int> x (topping, 1);
    //     p.push_back(x);
    // }
    // for (size_t i = 0; i < p.size(); i++) {
    //     pair<string, int> x = p[i];
    //     if (p[i].first == topping) {
    //         p[i].second++;
    //         addon += 0.40;
    //         p[i] = x;
    //         return;
    //     }
    // }
    // pair<string, int> q;
    // q.first = topping;
    // q.second = 1;
    // p.push_back(q);
    // price += addon;
    // for (size_t i = 0; i < p.size(); i++) {
    //     toplist += p[i].first + ": " + to_string(p[i].second) + " oz\n";
    // }
}
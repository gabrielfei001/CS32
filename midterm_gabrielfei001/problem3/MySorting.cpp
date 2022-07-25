#include "MySorting.h"
#include <string>
#include <string.h>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string customSort(string a[], size_t size) {
    string temp;
    string result;
    bool swapped;
    for (size_t x = 0; x < size; x++) {
        transform(a[x].begin(), a[x].end(), a[x].begin(), ::toupper);
    }
    for (int i = size - 1; i > 0; i--) {
        swapped = false;
        for (int j = 0; j < i; j++) {
            if((a[j]).length() > a[j + 1].length()) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
            else if (a[j].length() == a[j + 1].length()) { //alphabetical order of first comes after the second one then switch
                for (size_t p = 0; p < a[j].length(); p++) {
                    if (swapped == true) {
                        break;
                    }
                    else {
                        for (size_t q = 0; q < a[j + 1].length(); q++) {
                            if (a[j][p] > a[j + 1][q]) {
                                temp = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = temp;
                                swapped = true;
                                break;
                            }
                            else {
                                break;
                            }
                        }
                    }     
                } 
            }
        }
        if (!swapped) {
            continue;
        }
    }
    for (size_t m = 0; m < size; m++) {
        result = result + a[m] + ",";
    }
    result.pop_back();
    return result;
}
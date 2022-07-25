//testException2.cpp

#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"

using namespace std;

int main() {
    bool ElementNotFound = false;
    int arr3[] = {1, 2, 3, 4, 5};
    int x = 6;
    int n=sizeof(arr3)/sizeof(arr3[0]);
    try {
        binarySearch(arr3, 0, n-1, x);
    }
    catch(ElementNotFoundException d) {
        ElementNotFound = true;
    }
    ASSERT_EQUALS(true, ElementNotFound);

    return 0;
}

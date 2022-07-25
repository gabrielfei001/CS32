//testException2.cpp

#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"

using namespace std;

int main() {
    bool InvalidIndex = false;
    int arr5[] = {1, 2, 3, 4, 5};
    int x = 3;
    int n=sizeof(arr5)/sizeof(arr5[0]);
    try {
        binarySearch(arr5, 6, n-1, x);
    }
    catch(InvalidIndexException d) {
        InvalidIndex = true;
    }
    ASSERT_EQUALS(true, InvalidIndex);

    return 0;
}

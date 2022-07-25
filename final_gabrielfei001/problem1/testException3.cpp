//testException3.cpp

#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"

using namespace std;

int main() {
    bool IndexOutOfBounds = false;
    int arr4[] = {1, 2, 3, 4, 5};
    int x = 5;
    int n=sizeof(arr4)/sizeof(arr4[0]);
    try {
        binarySearch(arr4, -1, n-7, x);
    }
    catch(IndexOutOfBoundsException d) {
        IndexOutOfBounds = true;
    }
    ASSERT_EQUALS(true, IndexOutOfBounds);

    return 0;
}

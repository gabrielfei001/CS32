/* Below is a simple iterative binary search algorithm, implement it with
 * all the exception handling - if needed use gdb and valgrind*/

#include <iostream>
#include "ElementNotFoundException.h"
#include "ArrayNotSortedException.h"
#include <algorithm>
#include "InvalidIndexException.h"
#include "IndexOutOfBoundsException.h"

using namespace std;

/*iterative binary search: it returns the location of x in given array
 * arr[l..r] else it should throw appropriate exceptions
 * */
int binarySearch(int arr[], int l, int r, int x)
{
	//1. throw for sum overflows and goes to negative int - this produces unexpected results
	if (r < 0 || l < 0) {
		IndexOutOfBoundsException a;
		throw a;
	}
	
	if (l <= r) {
		int m = l + ((r - l)/2);
		if (m < 0) {
			IndexOutOfBoundsException a;
			throw a;
		}
	}

	//3. throw if accessing invalid indices
	if (l > r) {
		InvalidIndexException b;
		throw b;
	}

	//2. throw if array is not sorted
	for (int i = 0; i < r; i++) {
		if (arr[i] > arr[i + 1]) {
			ArrayNotSortedException c;
			throw c;
		}
	}


	//5. this should return proper value once all exceptions are added
	while (l <=r)
	{
		int m=l+((r-l)/2);
		//Check if x is present at mid
		if (arr[m] == x)
			return m;
		//If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;
		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	//4. throw if element is not found
	int p = 0;
	for (int i = 0; i < r; i++) {
		if (arr[i] == x) {
			p = arr[i];
		}
	}
	if (p == 0) {
		ElementNotFoundException d;
		throw d;
	}

	return -1;
}

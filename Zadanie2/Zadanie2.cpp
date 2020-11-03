
#include <iostream>

#include "Sorting.h"

using namespace std;




int main()
{
	int arr[10] = { 4,3,1,5,3,7,8,2,1,4 };
	N::Sorting sorting;

	sorting.print(arr, 10);
	sorting.test(arr, 10);
	sorting.heapSort(arr, 10);
	sorting.print(arr, 10);
	sorting.test(arr, 10);

}

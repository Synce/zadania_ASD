
#include <iostream>

#include "Sorting.h"

using namespace std;




int main()
{
	int arr[10] = { 4,3,1,5,3,7,8,2,1,4 };
	int arr2[10] = { 4,3,1,5,3,7,8,2,1,4 };
	int arr3[10] = { 4,3,1,5,3,7,8,2,1,4 };
	N::Sorting sorting;



	cout << "InsertSort" << endl;



	sorting.print(arr3, 10);
	sorting.test(arr3, 10);
	sorting.insertSort(arr3, 10);
	sorting.print(arr3, 10);
	sorting.test(arr3, 10);



	cout << "mergeSort" << endl;

	sorting.print(arr2, 10);
	sorting.test(arr2, 10);
	sorting.heapSort(arr2, 10);
	sorting.print(arr2, 10);
	sorting.test(arr2, 10);


	cout << "heapSort" << endl;
	sorting.print(arr, 10);
	sorting.test(arr, 10);
	sorting.heapSort(arr, 10);
	sorting.print(arr, 10);
	sorting.test(arr, 10);











}

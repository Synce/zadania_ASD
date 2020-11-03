#include <iostream>
#include "Sorting.h"
#include "Heap.h"
using namespace std;

void N::Sorting::print(int arr[], int len)
{

	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i];
	}
	cout << endl;
}


void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;


	int L[n1];
	int R[n2];


	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void N::Sorting::mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void N::Sorting::heapSort(int arr[], int size)
{
	Heap heap;
	heap.buildHeap(arr, size);
	int heapSize = size;
	for (int i = size - 1; i >= 1; i--)
	{
		heap.swap(arr[0], arr[i]);
		heapSize--;
		heap.heapify(arr, heapSize, 0);
	}


}


void N::Sorting::test(int arr[], int len)
{

	for (int i = 1; i < len; i++)
	{

		if (arr[i - 1] > arr[i]) {
			cout << "Test result: false" << endl;
			return;
		}

	}

	cout << "Test result: true" << endl;
}



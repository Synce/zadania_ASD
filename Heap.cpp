#include "Heap.h"
int Heap::left(int i) { return (2 * i + 1); }
int Heap::right(int i) { return (2 * i + 2); }

using namespace std;

void Heap::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heap::heapify(int arr[], int size, int i)
{
	int l = left(i);
	int r = right(i);

	int x;
	if (l < size && arr[l] > arr[i])
		x = l;
	else
		x = i;
	if (r < size && arr[r] > arr[x])
		x = r;
	if (x != i)
	{
		swap(arr[i], arr[x]);
		heapify(arr, size, x);
	}
}
void Heap::buildHeap(int arr[], int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		heapify(arr, size, i);
	}


}
#pragma once
class Heap
{
public:
	void heapify(int arr[], int size, int i);
	void buildHeap(int arr[], int size);
	int left(int i);
	int right(int i);
	void swap(int& a, int& b);
};


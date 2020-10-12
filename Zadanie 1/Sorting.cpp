#include <iostream>
#include "Sorting.h"
using namespace std;

	void N::Sorting::print(int arr[], int len)
	{		

		for (int i = 0; i < len; i++)
		{
			std::cout << arr[i];
		}
		cout << endl;
	}

	void N::Sorting::sort(int array[], int len)
	{		
	
		for (int i, element, j = 1; j < len; j++) {
			i = j - 1;
			element = array[j];

			while (i >= 0 && array[i] > element) {
				array[i + 1] = array[i];
				i--;
			}
			array[i + 1] = element;
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



//============================================================================
// Name        : Selection.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE     7

void displayArray(const int *arr, int size);
void swap(int *num1,int *num2);


void selectionSort(int arr[], int size) {

	int min; /* Used to identify the index contains the minimum value each iteration*/

	int temp; /* Used for Swapping positions between MIN. of each iteration and
	 the last position to be sorted */

	/* OUTER loop:
	 *     Compares the value at each array index with the other values in the array
	 *     to determine the Min. of each iteration and then SWAPPING
	 *     Range -->  0 <= index < size - 1
	 *     As arr[size - 1] will already be sorted correctly
	 * */

	for (int i = 0; i < (size - 1); i++) {

		min = i; /* Update Min. with the next index to continue sorting*/

		/* INNER loop:
		 *    iterates over the whole array searching for index of the Min. value
		 *    Range --> ( i+1 ) <= j < size
		 *    as it should start searching from the next position not the current one
		 */

		for (int j = (i + 1); j < size; j++) {

			if (arr[min] > arr[j]) {
				min = j;
			}
		}

		/* Here is the SWAPPING */
		swap(&arr[min],&arr[i]);

	}
}

int main()
{

	int arr[SIZE] = {1,9,-3,12,-4,25,-6};

	displayArray(arr, SIZE);

	cout<< endl;

	selectionSort(arr, SIZE);

	displayArray(arr, SIZE);

	return 0;
}




void displayArray(const int *arr, int size)
{
	printf("Array Elements: ");

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	printf("\n");
}


void swap(int *num1,int *num2)
{
	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

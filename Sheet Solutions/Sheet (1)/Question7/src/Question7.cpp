//============================================================================
// Name        : Question7.cpp
// Author      : Mostafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SIZE 7


void displayArray(const int *arr, int size);
void swap(int *num1,int *num2);

/*
7- Sort an array using bubble sort where you compare each two consecutive numbers and swap
   them if they are not in an ascending order. You may run your operations in a number of paths
   equal to the array size or if all array elements are in ascending order stop!
*/
void bubbleSorting(int *arr, int size) {

	int i, j; /* OUTER and INNER loop counters */

	/* OUTER loop:
	 *  Traverse the array by element at a time
	 *  Range -->  0 <= index < size - 1
	 *  As arr[size - 1] will already be sorted correctly with Max. value
	 *  Counter of it (i) --> represent number of sorts done
	 */
	for (i = 0; i < (size - 1); i++)
	{
		/* Flag for more optimization to the algorithm
		 * Operation: To check if the array is completely sorted (Finished Sorting) or not
		 * Initially (for each outer loop iteration) assume flag is TRUE
		 */
		bool isSorted = true;

		/* OUTER loop:
		 *  Comparing every two adjacent values in the array each iteration
		 *  Range -->  0 <= index < ((size - 1) - i)  WHY ?
		 *  No need to check on some elements that already been sorted correctly
		 */
		for (j = 0; j < ((size - 1) - i); j++)
		{
			/* SWAPPING if the current value of array is bigger than the next adjacent value */
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);

				/* flag updated for every sorting operation */
				isSorted = false;
			}
		}

		/*Check on the status of the flag
		 * if the flag stays the same with TRUE then the array is completely sorted
		 */
		if (isSorted == true)
			/* No More Sorting (saves some useless iterations) */
			break;
	}
}

int main()
{

	int arr[SIZE] = {1,9,-3,12,-4,25,-6};

	displayArray(arr, SIZE);

	cout<< endl;

	bubbleSorting(arr, SIZE);

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


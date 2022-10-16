//============================================================================
// Name        : Question2.cpp
// Author      : Mostafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>    /* For C/C++ Mixed Code */
using namespace std;

#define SIZE    5

void displayArray(const int *arr,int size)
{
	/* Displaying array elements */
	for (int i = 0; i <size; i++)
	{
		cout<< arr[i] << " ";
	}
	cout << endl;
}


/*
2- Create a C/C++ function that takes an array of integers and returns whether it has repeated items or not.
   Determine the big O of your solution. Repeat if the array is sorted.
*/

bool Unsorted_containsRepeated(const int *arr, int n) // Time Complexity -->  O(n^2)
{
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = (i + 1); j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				return true;
			}
		}

	}

	return false;
}


bool Sorted_containsRepeated(const int *arr, int n) // Time Complexity -->  O(n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		if (arr[i] == arr[i + 1])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int arr1[SIZE] = {3,6,3,8,7};  /* Unsorted Array */

	int arr2[SIZE] = {3,6,6,8,9};  /* Sorted Array */


	displayArray(arr1, SIZE);

	if (Unsorted_containsRepeated(arr1, SIZE))
		puts("Array contains repeated items");
	else
		puts("Array has no repeated items");

	printf("\n");

	displayArray(arr2, SIZE);

	if (Sorted_containsRepeated(arr2, SIZE))
		puts("Array contains repeated items");
	else
		puts("Array has no repeated items");



	return 0;
}

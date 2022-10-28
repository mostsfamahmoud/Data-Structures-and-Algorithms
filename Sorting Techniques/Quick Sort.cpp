//============================================================================
// Name        : Quick.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;


void displayArray(const int *arr, int size);
void swap(int *num1,int *num2);

/* Function to return the partitioning position of the Quick sort Function */
int partition(int *arr,int low , int high)
{
	int pivot = arr[low];     /* Select first element of the array as Pivot */
	int i = low;              /* Index pointer points to the start of the array */
	int j = high;             /* Index pointer points to the end of the array */

	do
	{
		do {
			i++;
		} while(arr[i] <= pivot);  /* To make index pointer (i) stop at index that its element is Greater than pivot */


		do {
			j--;
		} while(arr[j] > pivot);   /* To make index pointer (j) stop at index that its element is Smaller than or Equal pivot */

		if (i < j)
			swap(&arr[i],&arr[j]);   /* After i,j Stop at the required indexes , then swap their elements */

	}while(i < j);

	/* As we jumped out of that while loop then i became greater than or equal j
	 * So Swap our pivot with element at index j as that element we know for sure that its smaller that pivot
	 * So swap it to the small elements side */
	swap(&arr[low],&arr[j]);

	return j;   /* returning the partitioning position */
}

void QuickSort(int *arr, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	else
	{
		int pos = partition(arr, low, high);

		QuickSort(arr, low, pos);          /* First SubProblem --> Recursive call over the left side of the pivot */
		QuickSort(arr, (pos + 1), high);   /* Second SubProblem --> Recursive call over the right side of the pivot */
	}
}



int main()
{
	int arr[] = {10,12,8,16,20,6,24,30,10,INT32_MAX};    /* INT32_MAX --> Represent end of list marker (infinity) */

	cout<<"Before Sorting:" << endl;
	displayArray(arr, 9);

	QuickSort(arr, 0, 9);

	cout<<"After Sorting:" << endl;
	displayArray(arr, 9);
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

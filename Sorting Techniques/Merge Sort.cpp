//============================================================================
// Name        : Merge.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define MAX_SIZE   100

void displayArray(const int *arr, int size);
void swap(int *num1,int *num2);

void Merge(int A[], int low, int mid, int high);
void Recursive_MergeSort(int *arr, int low , int high);
void Iterative_MergeSort(int *arr, int n);


int main()
{
	int arr[] = {10,12,8,16,20,6,24,30,10};

	cout<<"Before Sorting:" << endl;
	displayArray(arr, 9);

	//Recursive_MergeSort(arr, 0, 8);
	Iterative_MergeSort(arr, 9);

	cout<<"After Sorting:" << endl;
	displayArray(arr, 9);

	return 0;
}


void displayArray(const int *arr, int size)
{
	printf("Array Elements: ");

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout<< endl;
}


void swap(int *num1,int *num2)
{
	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


void Merge(int A[], int low, int mid, int high)
{
	int i,j,k;    /* Three Index Pointers */

	/* Extra Array with MAX_SIZE to sort and exchange data with the passed array */
	int *B = new int[MAX_SIZE];

	i = k = low;       /* i , k points to the first index of the passed and extra array respectively */
	j = mid + 1;       /* j points to the first element of the second half of the passed array */

	/* Sorting in case the both halves didn't reach to their endings */
	while((i <= mid) && (j <= high))
	{
		if (A[i] < A[j])
		{
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		}
	}

	/* Sorting in case either one of the two halves reached to its ending */
	while(i <= mid)
	{
		B[k++] = A[i++];
	}

	while(j <= high)
	{
		B[k++] = A[j++];
	}


	/* Copying the sorted elements from the extra array back to the original one */
	for (i = low; i <= high; i++)
	{
		A[i] = B[i];
	}

	/* Free the occupied memory in heap */
	delete[]B;
	B = NULL;
}


void Recursive_MergeSort(int *arr, int low , int high)
{
	int mid;

	/* When there is only one element in the array then it is already sorted */
	if (low >= high)
		return;
	else
	{
		mid = (low + high)/2;
		Recursive_MergeSort(arr, low, mid);           /* Recursive call on the first half of the array */
		Recursive_MergeSort(arr, mid + 1, high);      /* Recursive call on the second half of the array */
		Merge(arr, low, mid, high);                   /* Calling the merge function implemented above*/
	}
}

void Iterative_MergeSort(int *arr, int n)
{
	int low, high, mid;
	int i;
	int p;      /* Represent the number of passes */

	for (p = 2; p <= n; p = p * 2)
	{
		for (i = 0; (i + p - 1) < n; i += p)
		{
			low = i;
			high = i + p - 1;
			mid = (low + high)/2;
			Merge(arr,low,mid,high);
		}
	}

	/* if Number of elements in the passed array is odd */
	if ((p/2) < n)
		Merge(arr, 0, (p / 2) - 1, (n - 1));

}

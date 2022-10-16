//============================================================================
// Name        : Question6.cpp
// Author      : Mostafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cassert>
using namespace std;

#define SIZE 7

/*
6- Write a program that recursively finds the maximum value of an array of integers
*/

int find_max(const int *arr,int size) // Section Implementation
{
	if (size == 1)
		return arr[0];

	return max(arr[size - 1],find_max(arr, size - 1));
}

int maxArray(const int *arr,int start, int end) // Lecture Implementation
{
	assert((start <= end) && (start >= 0));

	if (start == end)
		return arr[start];

	int mid = (start + end)/2;

	int max1 = maxArray(arr, start, mid);
	int max2 = maxArray(arr, mid + 1, end);

	if (max1 >= max2)
		return max1;
	else
		return max2;
}

int main()
{
	int arr[SIZE] = {1,9,-3,12,4,25,-6};

	cout<<"Max value of the array: " << maxArray(arr, 0, 6) << endl;

	cout<<"Max value of the array: " << find_max(arr, SIZE) << endl;

	return 0;
}

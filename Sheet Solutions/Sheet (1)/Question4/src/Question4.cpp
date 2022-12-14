//============================================================================
// Name        : Question4.cpp
// Author      : Mostafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

/*
4- Create a dynamic array of float numbers, the size of the array is determined by the user through cin,
   each element in the array holds a value of 1/(index)! i.e a[i]=1.0/i!,
   Run your program and compute the sum of the array elements (which value the sum tends to ?)
*/

int main()
{
	int arrLength = 0;
	int fact_i = 1;
	float sum = 0;

	/* Taking the size of the array from the user */
	cout<< "Enter No. of elements in the array:" << endl;
	fflush(stdout);                      /* Used with Eclipse IDE */
	cin>> arrLength;

	float *arr = new float[arrLength];   /* Allocate an array of floats dynamically in heap */

	arr[0] = 1;

	for(int i = 1 ; i < arrLength; i++)
	{
		fact_i = fact_i * i;

		arr[i] = 1.0/fact_i;
	}

	for(int i = 0 ; i < arrLength; i++)
	{
		sum += arr[i];
	}

	cout<<"Sum of the array = " << sum << endl;

	delete[]arr;

	return 0;
}

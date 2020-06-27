#include <iostream>
#include "dynademo.h"

using namespace std;



void allocate_double_array(double_ptr& p, size_t& n)
{
	if (p != NULL) { p = new double[n]; }
}

void fill_array(double array[], size_t n)
{
	size_t i = 0;
	cout << "Enter n numbers" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}

double average(const double array[], size_t n)
{
	double retVal = 0.0;
	size_t i = 0;
	for (i = 0; i < n; i++)
	{
		retVal += array[i];
	}
	if (n > 0) { retVal /= n; }
	else
	{
		cout << "Number of elements in the array cannot be <= 0" << endl;
		retVal = 0.0;
	}
	return retVal;
}

void compare(const double array[], size_t n, double value)
{
	size_t i = 0;
	for (i = 0; i < n; i++)
	{
		const char * str = (array[i] < value) ? " is less than " : (array[i] > value) ? " is greater than " : " is equal to ";
		cout << array[i] << str << value << endl;
	}
}

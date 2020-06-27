#ifndef ABHIJEET_DYNADEMO_1A
#define ABHIJEET_DYNADEMO_1A

#include <iostream>

typedef double* double_ptr;

void allocate_double_array(double_ptr& p, size_t& n);
void fill_array(double array[], size_t n);
double average(const double array[], size_t n);
void compare(const double array[], size_t n, double value);


#endif

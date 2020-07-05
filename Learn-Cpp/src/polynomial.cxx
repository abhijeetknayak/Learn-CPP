#include <iostream>
#include <math.h>
#include "polynomial.h"

using namespace std;

namespace abhijeet1A
{
    Polynomial::Polynomial(size_type deg)
    {
    	if (deg >= 0)
    	{
    		coefficients = new double[deg + 1];
    		degree = deg;
    	}
    }

    Polynomial::Polynomial(double a0)
    {
    	coefficients = new double[1];
    	degree = 0;

    	*coefficients = a0;
    }

    Polynomial::~Polynomial()
    {
    	delete [] coefficients;
    }

    Polynomial::Polynomial(const Polynomial& poly)
    {
    	/* Copy Constructor */
    	double * new_coeff = new double[poly.degree + 1];
    	copy(poly.coefficients, poly.coefficients + poly.degree + 1, new_coeff);

    	delete [] coefficients;
    	coefficients = new_coeff;

    	degree = poly.degree;
    }

    void Polynomial::operator =(const Polynomial& poly)
    {
    	double * new_coeff = new double[poly.degree + 1];

    	copy(poly.coefficients, poly.coefficients + poly.degree + 1, new_coeff);

    	delete [] coefficients;
    	coefficients = new_coeff;

    	degree = poly.degree;
    }

    ostream& operator <<(ostream& out, const Polynomial& target)
    {
    	for (Polynomial::size_type i = 0; i < target.degree + 1; i++)
    	{
    		if (i == target.degree) { out << target.coefficients[i] << " * x" << i << endl; }
    		else { out << target.coefficients[i] << " * x" << i << "+ ";}
    	}

    	return out;
    }

	void Polynomial::add_to_coef(double amount, size_type k)
	{
		if (k >= 0 && k <= degree)
		{
			coefficients[k] += amount;
		}
		else { assign_coef(amount, k); }
	}

	void Polynomial::assign_coef(double new_coefficient, size_type k)
	{
		if (k > degree)
			reserve(k);
		coefficients[k] = new_coefficient;
//		if (k >= 0 && k <= degree)
//		{
//			coefficients[k] = new_coefficient;
//		}
//		else if (k > degree)
//		{
//			double * new_coeff = new double[k + 1];
//			copy(coefficients, coefficients + degree + 1, new_coeff);
//
//			delete [] coefficients;
//			coefficients = new_coeff;
//
//			degree = k;
//			coefficients[k] = new_coefficient;
//		}
	}

	void Polynomial::clear(void)
	{
		for(size_type i = 0; i <= degree; i++)
		{
			coefficients[i] = 0.0;
		}
	}

	void Polynomial::reserve(size_t number)
	{
		double * new_coeff = new double[number + 1];
		copy(coefficients, coefficients + degree + 1, new_coeff);

		delete [] coefficients;
		coefficients = new_coeff;

		degree = number;
	}

	double Polynomial::coefficient(size_type k) const
	{
		if (k >= 0 && k <= degree)
			return coefficients[k];
		return 0.0;
	}

	Polynomial::size_type Polynomial::get_degree( ) const
	{
		return degree;
	}

	Polynomial::size_type Polynomial::next_term(size_type k) const
	{
		size_type i = 0, retVal = UINT_MAX;
		for (i = k + 1; i <= degree; i++)
		{
			if (abs(coefficients[i]) > 1e-6f)
			{
				retVal = i;
				break;
			}
		}
		return retVal;
	}

	double Polynomial::eval(double x) const
	{
		double retVal = 0.0;
		size_type i = 0;
		for (i = 0; i <= degree; i++)
		{
			/* Sum(Coefficient * x^i) */
			retVal += coefficients[i] * (pow(x, (double)i));
		}
		return retVal;
	}

	double Polynomial::operator ( )(double x) const
	{
		return eval(x);
	}
}

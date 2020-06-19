#ifndef ABHIJEET_POLYNOMIAL_1A
#define ABHIJEET_POLYNOMIAL_1A

#include <iostream>

namespace abhijeet1A
{
	class Polynomial
	{
	public:
		typedef std::size_t size_type;
		static const size_type MAXDEGREE = 10;

		/* Constructor */
		Polynomial();
	private:
		float coefficients[MAXDEGREE];
	};
}

#endif

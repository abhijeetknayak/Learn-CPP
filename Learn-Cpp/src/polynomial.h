#ifndef ABHIJEET_POLYNOMIAL_1A
#define ABHIJEET_POLYNOMIAL_1A

#include <iostream>

namespace abhijeet1A
{
	class Polynomial
	{
	public:
		typedef std::size_t size_type;

		/* Constructor */
		Polynomial();
		Polynomial(double a0);
		Polynomial(const Polynomial& poly);
		Polynomial(size_type deg = 0);

		/* Destructor */
		~Polynomial();

		/* Friend Function */
		friend std::ostream& operator <<(std::ostream& out, const Polynomial& target);

		void operator =(const Polynomial& poly);

		/* Modifier member functions */
		void add_to_coef(double amount, size_type k);
		void assign_coef(double new_coefficient, size_type k);
		void clear(void);
		void reserve(size_t number);

		/* Constant Member functions */
		double coefficient(size_type k) const;
		size_type get_degree( ) const;
		size_type next_term(size_type k) const;

		/* Evaluation Functions */
		double eval(double x) const;
		double operator ( )(double x) const;

	private:
		double * coefficients;
		size_type degree;
	};




}

#endif

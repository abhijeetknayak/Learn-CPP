#ifndef ABHIJEET_TOWERS_1A
#define ABHIJEET_TOWERS_1A

#include <iostream>
#include "peg.h"


namespace abhijeet1A
{
	class Tower
	{
	public:
		/* Constructor */
		Tower(Peg::size_type n);

		/* Overloaded output function - Friend function */
		friend std::ostream& operator <<(std::ostream& out, Tower& tower);

		/* Member Functions */
		Peg::size_type many_rings(int peg_number) const;
		Peg::size_type top_diameter(int peg_number) const;
		void move(int start_peg, int end_peg);
	private:
		Peg pegs[3];


	};


}

#endif

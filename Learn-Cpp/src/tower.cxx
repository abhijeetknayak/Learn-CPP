#include <iostream>
#include <algorithm>
#include "tower.h"
#include "peg.h"

using namespace std;

namespace abhijeet1A
{
    Tower::Tower(Peg::size_type n)
    {
    	/* Constructor - n rings on first peg, other pegs are empty */
		pegs[0] = Peg(n);
		pegs[1] = Peg(0);
		pegs[2] = Peg(0);
    }

    Peg::size_type Tower::many_rings(int peg_number) const
    {
    	if (peg_number <= 3)
    	{
    		return pegs[peg_number - 1].size();
    	}
    	return 0;
    }

    Peg::size_type Tower::top_diameter(int peg_number) const
    {
    	if (peg_number < 3)
    	{
    		return pegs[peg_number - 1].data[0];
    	}
    	return 0;
    }

    void Tower::move(int start_peg, int end_peg)
    {
    	if (start_peg < 3 && end_peg < 3)
    	{
    		/* Valid Pegs */
    		Peg::size_type value = pegs[start_peg - 1].remove_top_ring();

    		bool move_possible = pegs[end_peg - 1].insert_new_ring(value);

    		if (!move_possible)
    		{
    			/* Move not possible. Insert back into the start peg */
    			(void)pegs[start_peg - 1].insert_new_ring(value);
    		}
    	}
    }

    ostream& operator <<(ostream& out, Tower& tower)
    {
    	/* Overloaded output function */
    	out << "----------------------------------------------------------------------" << endl;
    	for (Peg::size_type i = 0; i < 3; i++)
    	{
    		out << "Peg " << i + 1 << endl;
    		out << tower.pegs[i];
    	}

    	return out;
    }

}

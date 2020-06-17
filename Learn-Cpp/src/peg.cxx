#include <iostream>
#include <algorithm>
#include "peg.h"

using namespace std;

namespace abhijeet1A
{
    const Peg::size_type Peg::CAPACITY;
    Peg::Peg(size_type n)
    {
    	if (n <= CAPACITY)
    	{
        	used_size = n;
        	for (size_type i = 0; i < n; i++)
        	{
        		data[i] = i + 1;
        	}
    	}
    }

    Peg::size_type Peg::size(void) const
    {
    	return used_size;
    }

    bool Peg::insert_new_ring(const size_type& new_dia)
    {
    	bool retVal = false;
    	if ((used_size + 1 < CAPACITY) && (new_dia < data[0]))
    	{
    		/* Possible to add new ring. Increment used size */
    		used_size++;
    		for(size_type i = used_size - 1; ((i > 0) && (i < CAPACITY)); i--)
    		{
    			/* Shift data to the right in the stack */
    			data[i] = data[i - 1];
    		}

    		/* Add new ring at the front */
    		data[0] = new_dia;
    		retVal = true;
    	}

    	return retVal;
    }

    Peg::size_type Peg::remove_top_ring()
    {
    	size_type retVal = 0;
    	if (used_size != 0)
    	{
    		/* Peg not empty */
    		used_size--;

    		/* Removed ring */
    		retVal = data[0];

    		for (size_type i = 0; i < used_size; i++)
    		{
    			data[i] = data[i + 1];
    		}
    	}

    	return retVal;
    }

    ostream& operator <<(ostream& out, const abhijeet1A::Peg& peg)
    {
    	Peg::size_type i, num_space, max_val, j;
    	max_val = peg.data[peg.used_size - 1];
    	for (i = 0; i < peg.used_size; i++)
    	{
    		num_space = max_val - peg.data[i];
    		for (j = 0; j < num_space; j++)
    		{
    			out << ' ';
    		}
    		for (j = 0; j < peg.data[i]; j++)
    		{
    			out << '-' << ' ';
    		}
    		out << endl;
    	}

    	return out;
    }
}

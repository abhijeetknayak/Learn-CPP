#include <iostream>
#include <algorithm>
#include "sequence.h"

using namespace std;

namespace abhijeet1A
{
    const Sequence::size_type Sequence::CAPACITY;
    Sequence::Sequence()
    {
    	used_size = 0;
    	current_idx = CAPACITY;
    }

    Sequence::size_type Sequence::size(void) const
    {
    	return used_size;
    }

    void Sequence::start(void)
    {
    	if (current_idx < CAPACITY)
    	{
    		/* Current Idx will be equal to CAPACITY if there are no items */
    		current_idx = 0;
    	}
    }

    bool Sequence::is_item() const
    {
    	bool retVal = false;
    	if (current_idx < used_size)
    	{
    		retVal = true;
    	}
    	return retVal;
    }

    void Sequence::advance()
    {
    	if (current_idx < used_size - 1)
    	{
    		current_idx++;
    	}
    	else
    	{
    		current_idx = used_size;
    	}
    }

    Sequence::value_type Sequence::current() const
    {
    	if (is_item()) { return(data[current_idx]); }

    	return 0.0f;
    }

    void Sequence::remove_current()
    {
    	size_type i = 0;
    	if (is_item())
    	{
    		for (i = current_idx; i < used_size - 1; i++)
    		{
    			/* Shifting elements to the left */
    			data[i] = data[i + 1];
    		}
    		used_size--;
    	}

    }

    void Sequence::insert(const value_type& entry)
    {
    	size_type i = 0;
    	if (size() < CAPACITY)
    	{
    		/* Insertion possible */
    		if (used_size == 0)
    		{
    			/* First element */
    			current_idx = 0;
    			used_size++;
    		}
    		else
    		{
    			used_size++;
        		for (i = used_size - 1; ((i > current_idx) && (i < CAPACITY)); i--)
        		{
        			/* Shifting elements to the right */
        			data[i] = data[i - 1];
        		}
        		/* Current Index remains unaltered */


    		}
			data[current_idx] = entry;

    	}
    }

    void Sequence::attach(const value_type& entry)
    {
    	if (size() < CAPACITY)
    	{
    		/* Insertion possible */
    		if (used_size == 0) { insert(entry); }
    		else
    		{
        		advance();
        		insert(entry);
    		}
    	}
    }

    void Sequence::print_sequence(void)
    {
    	size_type idx = current_idx;
    	for(start(); is_item(); advance())
    	{
    		/* Iterating over all items in the sequence */
    		cout << current() << " ";
    	}
    	cout << endl;

    	current_idx = idx;
    }

}

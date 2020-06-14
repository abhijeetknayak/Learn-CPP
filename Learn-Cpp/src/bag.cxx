#include <iostream>
#include <algorithm>
#include "bag.h"

using namespace std;

namespace abhijeet1A
{
    const Bag::size_type Bag::CAPACITY;
    Bag::Bag() { used_size = 0; }

    Bag::size_type Bag::size(void) const
    {
    	return used_size;
    }

    Bag::size_type Bag::count(const value_type& target) const
    {
    	size_type answer = 0, i = 0;
    	for (i = 0; i < used_size; i++)
    	{
    		if (data[i] == target)
    		{
    			answer++;
    		}
    	}
    	return answer;
    }

    void Bag::insert(const value_type& entry)
    {
       	if (used_size < CAPACITY)
    	{
    		data[used_size] = entry;
    	}
    	used_size++;
    }

    bool Bag::erase_one(const value_type& target)
    {
    	bool retVal = false;
    	size_type i;
    	for (i = 0; ((i < used_size) && (retVal != true)); i++)
    	{
    		if (data[i] == target)
    		{
    			data[i] = data[used_size - 1];
    			used_size--;
    			retVal = true;
    		}
    	}
    	return retVal;
    }

    Bag::size_type Bag::erase(const value_type& target)
    {
    	size_type i = 0, count = 0;

    	for (i = used_size - 1; ((i >= 0) && (i < CAPACITY)); i--)
    	{
    		if (data[i] == target)
    		{
    			count++;
    			if (i != used_size - 1)
    			{
    				/* Moving the right element into the target position */
    				data[i] = data[i + 1];
    			}
    		}
    	}
    	used_size -= count;
    	return count;
    }

    void Bag::operator +=(const Bag& bag)
	{
//    	size_type i, total_size, j = 0;
//    	if (used_size + bag.used_size <= CAPACITY)
//    	{
//    		total_size = used_size + bag.used_size;
//    		for (i = used_size; i < total_size; i++)
//    		{
//    			data[i] = bag.data[j];
//    			j++;
//    		}
//    		used_size = total_size;
//    	}
#if 1
    	if(used_size + bag.size() <= CAPACITY)
    	{
    		copy(bag.data, bag.data + bag.used_size, data + used_size);
    		used_size += bag.used_size;
    	}

#endif
	}

    Bag operator +(const Bag& bag1, const Bag& bag2)
    {
    	Bag result;

    	if (bag1.size() + bag2.size() <= Bag::CAPACITY)
    	{
    		result += bag1;
    		result += bag2;
    	}
    	return result;
    }



}

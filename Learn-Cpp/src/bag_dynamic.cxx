#include <iostream>
#include <algorithm>
#include <math.h>
#include "bag_dynamic.h"

using namespace std;

namespace abhijeet1A
{
    const BagDyn::size_type BagDyn::DEFAULT_CAPACITY;
    BagDyn::BagDyn(size_type cap)
    {
    	used_size = 0;
    	capacity = cap;
    	data = new value_type[cap];
    }

    BagDyn::BagDyn(const BagDyn& sourceBag)
    {
    	/* Copy constructor : During new bag creation */
    	capacity = sourceBag.capacity;
    	used_size = sourceBag.used_size;
    	data = new value_type[capacity];

    	copy(sourceBag.data, sourceBag.data + sourceBag.used_size, data);
    }

    BagDyn::~BagDyn()
    {
    	/* Destructor. Clearing dynamically allocated array */
    	delete [] data;
    }

    BagDyn::size_type BagDyn::size(void) const
    {
    	return used_size;
    }

    BagDyn::size_type BagDyn::bag_capacity(void) const
    {
    	return capacity;
    }

    BagDyn::size_type BagDyn::count(const value_type& target) const
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

    void BagDyn::insert(const value_type& entry, const size_type& multiple)
    {
       	if (used_size == capacity) { reserve(used_size + 1, multiple); }

       	data[used_size] = entry;
    	used_size++;
    }

    bool BagDyn::erase_one(const value_type& target)
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

    BagDyn::size_type BagDyn::erase(const value_type& target)
    {
    	size_type i = 0, count = 0;

    	for (i = used_size - 1; ((i >= 0) && (i < capacity)); i--)
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

    void BagDyn::reserve(size_type new_capacity, const size_type& multiple)
    {
    	/* The value of multiple can be used to change the amount of new memory that is allocated.
    	 * Think of this in terms of extra percentage points. Defaults to 0 */
    	value_type * new_data;
    	if (new_capacity == capacity)
    	{
    		/* Nothing for us to do, Return */
    		return;
    	}
//    	if (new_capacity < capacity) { new_capacity = used_size; }

    	/* If we want to increase bag size by 10% at every insert to make it more efficient */
    	if (new_capacity < capacity) { new_capacity = used_size; }

    	new_capacity = ceil(new_capacity * (1.0f + multiple / 100.0f));

		/* Need to reserve a larger capacity only if the new_capacity is greater than the current capacity.
		 * First copy data into the new location, and then delete the old allocations */
		new_data = new value_type[new_capacity];
		copy(data, data + used_size, new_data);
		delete [] data;
		data = new_data;
		capacity = new_capacity;
    }

    void BagDyn::operator =(const BagDyn& sourceBag)
    {
    	value_type * new_data;
    	if (this == &sourceBag)
    	{
    		/* This source object is the same as the object that activates the member function */
    		return;
    	}
    	if (capacity != sourceBag.capacity)
    	{
    		delete [] data;
    		new_data = new value_type[sourceBag.capacity];
    		data = new_data;
    		capacity = sourceBag.capacity;
    	}
    	used_size = sourceBag.used_size;
    	copy(sourceBag.data, sourceBag.data + sourceBag.used_size, data);
    }

    void BagDyn::operator +=(const BagDyn& bag)
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
    	if(used_size + bag.size() > capacity)
    	{
    		/* Reserve new memory */
    		reserve(used_size + bag.used_size);
    	}

		copy(bag.data, bag.data + bag.used_size, data + used_size);
		used_size += bag.used_size;

#endif
	}

    BagDyn operator +(const BagDyn& bag1, const BagDyn& bag2)
    {
    	BagDyn result(bag1.bag_capacity() + bag2.bag_capacity());

		result += bag1;
		result += bag2;

    	return result;
    }



}

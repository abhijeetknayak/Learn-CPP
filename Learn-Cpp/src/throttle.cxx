#include <iostream>
#include "throttle.h"

using namespace std;

namespace abhijeet1A
{
	/* Constructor */
	throttle::throttle(int size)
	{
		position = 0;
		if (size > 0)
			top_position = size;
	}

	/* Default Constructor */
	throttle::throttle(void)
	{
		position = 0;
		top_position = 1;
	}

	/* Constructor with two arguments */
	throttle::throttle(int size, int current_pos)
	{
		if (size > 0)
			top_position = size;
		if (current_pos < size)
			position = current_pos;
	}

	void throttle::shutoff(void)
	{
		position = 0;
	}

	void throttle::set_throttle_position(int amount)
	{
		position += amount;
		if (position < 0)
			position = 0;
		else if (position > top_position)
			position = top_position;
	}

	bool throttle::throttle_on(void) const
	{
		if (position > 0)
			return true;
		else
			return false;
	}

	bool throttle::flow_more_than_half(void) const
	{
		return (flow() > 0.5);
	}

	bool operator ==(const abhijeet1A::throttle& A, const abhijeet1A::throttle& B)
	{
		return (A.flow() == B.flow());
	}

	bool operator !=(const abhijeet1A::throttle& A, const abhijeet1A::throttle& B)
	{
		return !(A == B);
	}
}

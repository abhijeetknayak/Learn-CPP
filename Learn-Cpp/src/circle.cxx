#include <iostream>
#include "math.h"
#include "circle.h"

using namespace std;

namespace abhijeet1A
{
	/* Constructor */
	circle_location::circle_location()
	{
		angle = 0.0f;
	}

	/* Default Constructor */
	circle_location::circle_location(float initial_angle)
	{
		if (abs(initial_angle) > 360)
		{
			int dec = int(initial_angle / 360.0f);
			angle = ((initial_angle / 360.0f) - dec) * 360.0f;
		}
		else
			angle = initial_angle;

		if (angle < 0.0f)
			angle += 360.0f;
	}

	void circle_location::move_position(float amount)
	{
		angle += amount;
		if (angle > 360.0f)
		{
			int dec = int(angle / 360.0f);
			angle = ((angle / 360.0f) - dec) * 360.0f;
		}
		else if (angle < 0.0f)
			angle += 360.0f;
	}

	float circle_location::get_position(void) const
	{
		return angle;
	}
}

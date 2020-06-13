#include <iostream>
#include "math.h"
#include "point.h"

using namespace std;

namespace abhijeet1A
{
    point::point(float x_initial, float y_initial)
    {
    	x = x_initial;
    	y = y_initial;
    }

    void point::shift(float x_amt, float y_amt)
    {
    	x += x_amt;
    	y += y_amt;
    }

    void point::rotate90(void)
    {
    	float temp = x;
    	x = y;
    	y = -temp;
    }

    float point::get_x(void) const
    {
    	return x;
    }

    float point::get_y(void) const
	{
		return y;
	}

    istream& operator >>(istream& in, abhijeet1A::point& A)
    {
    	in >> A.x >> A.y;
    	return in;
    }

    int num_rotations_value(abhijeet1A::point P)
    {
    	int num_rot = 0;
    	while((P.get_x() < 0.0f) || (P.get_y() < 0.0f))
    	{
    		P.rotate90();
    		num_rot += 1;
    	}
    	return num_rot;
    }

    int num_rotations_value_reference(abhijeet1A::point& P)
    {
    	int num_rot = 0;
    	while((P.get_x() < 0.0f) || (P.get_y() < 0.0f))
    	{
    		P.rotate90();
    		num_rot += 1;
    	}
    	return num_rot;
    }

    float distance(const abhijeet1A::point& A, const abhijeet1A::point& B)
    {
    	float x = 0.0f, y = 0.0f, distsq;
    	x = A.get_x() - B.get_x();
    	y = A.get_y() - B.get_y();

    	distsq = x * x + y * y;
    	return sqrtf(distsq);
    }

    bool operator ==(const abhijeet1A::point& A, const abhijeet1A::point& B)
    {
    	return ((A.get_x() == B.get_x()) && (A.get_y() == B.get_y()));
    }

    bool operator !=(const abhijeet1A::point& A, const abhijeet1A::point& B)
    {
    	return !(A == B);
    }

    ostream& operator <<(ostream& out, const abhijeet1A::point& A)
    {
    	out << "(" << A.get_x() << ", " << A.get_y() << ")" << endl;
    	return out;
    }
}

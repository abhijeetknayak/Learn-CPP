#include <iostream>
#include <utility>
#include "math.h"
#include "throttle.h"
#include "circle.h"
#include "point.h"
#include "bag.h"

using namespace std;
using namespace abhijeet1A;

int main()
{
	abhijeet1A::throttle c(6);
	c.shutoff();
	c.set_throttle_position(3);
	cout << c.flow() << endl;

	/* Calling the Automatic Copy Constructor */
	abhijeet1A::throttle b(c);
	cout << b.flow() << endl;

	if (c == b)
		cout << "Equal Flow" << endl;

	abhijeet1A::circle_location c1;
	cout << "Initial Angle is " << c1.get_position() << endl;
	c1.move_position(230.0f);
	cout << "Angle is " << c1.get_position() << endl;
	c1.move_position(-250.0f);
	cout << "Angle is " << c1.get_position() << endl;
	c1.move_position(370.0f);
	cout << "Angle is " << c1.get_position() << endl;

	abhijeet1A::point p;
	cout << "X is " << p.get_x() << ";" << " Y is " << p.get_y() << endl;
	p.shift(5.2, 3.4);
	cout << "X is " << p.get_x() << ";" << " Y is " << p.get_y() << endl;
	p.shift(0.8, 0.6);
	cout << "X is " << p.get_x() << ";" << " Y is " << p.get_y() << endl;
	p.rotate90();
	cout << "X is " << p.get_x() << ";" << " Y is " << p.get_y() << endl;

	int num = num_rotations_value(p);
	cout << "Rotations : " << num << "; X is " << p.get_x() << ";" << " Y is " << p.get_y() << endl;
	num = num_rotations_value_reference(p);
	cout << "Rotations : " << num << "; X is " << p.get_x() << ";" << " Y is " << p.get_y() << endl;

	if (p == p)
		cout << "Equal" << endl;
	else if (p != p)
		cout << "Not Equal" << endl;

	cout << p << endl;

	pair<int, double> K;
	K.first = 12;
	K.second = 23.4;

	Bag bag1, bag2;
	cout << bag1.CAPACITY << endl;
	cout << Bag::CAPACITY;

}

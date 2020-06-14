#include <iostream>
#include <utility>
#include "math.h"

#include "throttle.h"
#include "circle.h"
#include "point.h"
#include "bag.h"
#include "sequence.h"
#include "Learn-Cpp.h"

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
	cout << Bag::CAPACITY << endl;

	bag_functions();

	sequence_functions();

}

void bag_functions(void)
{
	Bag bag1, bag2;
	bag1.insert(3);
	bag1.insert(2);
	bag1.insert(3);
	bag1.insert(4);
	bag1.insert(5);
	bag1.insert(32);
	bag1.insert(3);

	cout << "Bag1 size is : " << bag1.size() << endl;

	cout << int(bag1.erase(32)) << endl;
	cout << "Bag1 size is : " << bag1.size() << endl;

	bag2.insert(23);
	bag2.insert(3);
	bag2.insert(34);
	bag2.insert(25);
	bag2.insert(2);

	cout << "Bag2 size is : " << bag2.size() << endl;

	bag1 += bag2;
	cout << "Bag1 size after appending bag2 is : " << bag1.size() << endl;

	cout << "Count of 3 is : " << bag1.count(3) << endl;
	cout << "Number of 3's removed is : " << bag1.erase(3) << endl;

	bag2 += bag2;
	cout << bag2.size() << endl;
}

void sequence_functions(void)
{
	Sequence s1;
	s1.insert(2.0);
	s1.insert(4.0);
	s1.insert(6.0);
	s1.insert(8.0);
	s1.insert(10.0);
	s1.insert(12.0);
	s1.insert(14.0);

	s1.print_sequence();

	cout << "After three advances current item is : " << s1.current() << endl;

	s1.attach(25);
	s1.print_sequence();

	s1.remove_current();
	s1.print_sequence();
}

void multiset_functions(void)
{

}

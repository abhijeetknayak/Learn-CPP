#include <iostream>
#include <utility>
#include <set>
#include <iterator>
#include "math.h"
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

	multiset_functions();

	peg_functions();

	tower_functions();

	pointer_functions();

	dynamic_bag_functions();

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
	multiset<int>::iterator iter;
	multiset <int> first;
	first.insert(30);
	first.insert(3);
	first.insert(12);
	first.insert(23);
	first.insert(34);
	first.insert(33);
	first.insert(31);
	first.insert(30);
	first.insert(30);

	for(iter = first.begin(); iter != first.end(); iter++)
	{
		/* Printing all elements in the multiset */
		cout << *iter << " ";
	}
	cout << endl;

	iter = first.insert(25);
	for(; iter != first.end(); iter++)
	{
		/* Printing all elements in the multiset */
		cout << *iter << " ";
	}
	cout << endl;

	iter = first.find(12);
	for(; iter != first.end(); iter++)
	{
		/* Printing all elements in the multiset */
		cout << *iter << " ";
	}
	cout << endl;

	iter = first.find(33);
	if (iter != first.end())
	{
		first.erase(iter);
	}
	for(iter = first.begin(); iter != first.end(); iter++)
	{
		/* Printing all elements in the multiset */
		cout << *iter << " ";
	}
}

void peg_functions(void)
{
	Peg peg(10);
	cout << peg;

	peg.remove_top_ring();
	cout << peg;

	peg.remove_top_ring();
	peg.remove_top_ring();
	peg.remove_top_ring();
	peg.remove_top_ring();
	peg.remove_top_ring();

	peg.insert_new_ring(1);
	cout << peg;

	peg.insert_new_ring(4);
	cout << peg;
}

void tower_functions(void)
{
	Tower tower(3);

	cout << tower.many_rings(1) << endl;

	tower.move(1, 2);
	cout << tower;

	tower.move(1, 3);
	cout << tower;

	tower.move(2, 3);
	cout << tower;

	tower.move(1, 2);
	cout << tower;

	tower.move(3, 1);
	cout << tower;

	tower.move(3, 2);
	cout << tower;

	tower.move(1, 2);
	cout << tower;

}

void pointer_functions(void)
{
	double_ptr p;
	size_t n = 10;

	allocate_double_array(p, n);
	fill_array(p, n);

	compare(p, n, 3.2);
	cout << "Average : " << average(p, n) << endl;
}

void dynamic_bag_functions(void)
{
	/* Bag of capacity 10 */
	BagDyn bag1(10);

	/* Bag of capacity 5 */
	BagDyn bag2(5);

	bag1.insert(5);
	bag1.insert(23);
	bag1.insert(45);
	bag1.insert(66);
	bag1.insert(12);

	bag2.insert(5);
	bag2.insert(15);
	bag2.insert(52);
	bag2.insert(53);
	bag2.insert(85);

	cout << "Bag1 size and capacity are : " << bag1.size() << ", " << bag1.bag_capacity() << endl;
	cout << "Bag2 size and capacity are : " << bag2.size() << ", " << bag2.bag_capacity() << endl;

	bag1 += bag2;

	/* Capacity of Bag1 should remain unchanged */
	cout << "Bag1 size and capacity are : " << bag1.size() << ", " << bag1.bag_capacity() << endl;

	BagDyn bag3 = bag1 + bag2;
	cout << "Bag3 size and capacity are : " << bag3.size() << ", " << bag3.bag_capacity() << endl;

}

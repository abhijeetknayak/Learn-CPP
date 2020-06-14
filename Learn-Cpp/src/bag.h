#ifndef ABHIJEET_BAG_1A
#define ABHIJEET_BAG_1A

#include <iostream>

namespace abhijeet1A
{
	class Bag
	{
	public:
		typedef int value_type;
		typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

		/* Constructor */
		Bag();

		/* Member Functions */
		size_type size() const;
		void insert(const value_type& entry);
		size_type count(const value_type& target) const;
		bool erase_one(const value_type& target);
		size_type erase(const value_type& target);

		void operator +=(const Bag& bag);

	private:
		value_type data[CAPACITY];
		size_type used_size;


	protected:
	};

	/* Overloaded Operators */
	Bag operator +(const Bag& A, const Bag& B);

}

#endif

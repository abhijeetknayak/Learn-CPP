#ifndef ABHIJEET_BAGDYN_1A
#define ABHIJEET_BAGDYN_1A

#include <iostream>

namespace abhijeet1A
{
	class BagDyn
	{
	public:
		typedef int value_type;
		typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;

		/* Constructor */
		BagDyn(size_type cap = DEFAULT_CAPACITY);

		/* Member Functions */
		size_type size() const;
		size_type bag_capacity(void) const;
		void insert(const value_type& entry);
		size_type count(const value_type& target) const;
		bool erase_one(const value_type& target);
		size_type erase(const value_type& target);

		void operator +=(const BagDyn& bag);

	private:
		value_type * data;
		size_type used_size;
		size_type capacity;


	protected:
	};

	/* Overloaded Operators */
	BagDyn operator +(const BagDyn& A, const BagDyn& B);

}

#endif

#ifndef ABHIJEET_PEG_1A
#define ABHIJEET_PEG_1A

#include <iostream>

namespace abhijeet1A
{
	class Peg
	{
	public:
		typedef std::size_t size_type;
        static const size_type CAPACITY = 64;

		/* Constructor */
		Peg(size_type n = 0);

		/* Overloaded Operators */
		friend std::ostream& operator <<(std::ostream& out, const Peg& peg);

		/* Member Functions */
		size_type size() const;
		bool insert_new_ring(const size_type& new_dia);
		size_type remove_top_ring();

		friend class Tower;



	private:
		size_type data[CAPACITY];
		size_type used_size;
	};
}

#endif

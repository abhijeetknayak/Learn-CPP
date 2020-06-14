#ifndef ABHIJEET_SEQUENCE_1A
#define ABHIJEET_SEQUENCE_1A

#include <iostream>

namespace abhijeet1A
{
	class Sequence
	{
	public:
		typedef float value_type;
		typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

		/* Constructor */
		Sequence();

		/* Member Functions */
		size_type size() const;
		void start();
		value_type current() const;
		void advance();

		/* Checks if the current item is valid */
		bool is_item() const;

		/* Entry added before the current item */
		void insert(const value_type& entry);

		/* Entry added after the current item */
		void attach(const value_type& entry);

		void remove_current(void);
		void print_sequence(void);

	private:
		value_type data[CAPACITY];
		size_type used_size;
		size_type current_idx;


	protected:
	};




}

#endif

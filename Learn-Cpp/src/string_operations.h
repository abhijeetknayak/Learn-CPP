#ifndef ABHIJEET_STR_1A
#define ABHIJEET_STR_1A

#include <iostream>

namespace abhijeet1A
{
	class String
	{
	public:
		typedef std::size_t size_type;

		/* Constructor */
		String(const char str [] = "");
		~String();

		/* Member Functions */
		char * strcpy(char target [], char source []);
		char * strcat(char target [], char source []);
		size_type strlen(const char source []);

		/* int return */
		int strcmp(char string1 [], char string2 []);

		char operator [](size_type position) const;
		void operator +=(char addend []);
		void operator +=(char addend);
		void reserve(size_type new_capacity);
		size_type length(void) const;

	private:
		char * data;
		size_type allocated;
		size_type str_length;


	protected:
	};

	String operator +(char str1 [], char str2 []);
	std::istream& operator >>(std::istream& ins, String& target);
	std::ostream& operator <<(std::ostream& out, String& output);
	std::istream& getline(std::istream& ins, String& target, char delimiter = '\n');


#endif

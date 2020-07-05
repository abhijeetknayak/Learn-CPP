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

		/* Copy Constructor */
		String(String& str1);

		/* Destructor */
		~String();

		/* Member Functions */
		char * strcpy(char target [], char source []);
		char * strcat(char target [], char source []);

		/* int return */
		int strcmp(char string1 [], char string2 []);

		char operator [](size_type position) const;
		void operator +=(char addend []);
		void operator +=(char addend);
		void operator +=(const String& str1);
		void operator =(const String& str1);
		void reserve(size_type new_capacity);
		size_type length(void) const;

		char * getData() const;

	private:
		char * data;
		size_type allocated;
		size_type str_length;


	protected:
	};

	String operator +(const String& str1, const String& str2);
	std::istream& operator >>(std::istream& ins, String& target);
	std::ostream& operator <<(std::ostream& out, String& output);
	std::istream& getline(std::istream& ins, String& target, char delimiter = '\n');
	String::size_type string_length(const char source []);
}


#endif

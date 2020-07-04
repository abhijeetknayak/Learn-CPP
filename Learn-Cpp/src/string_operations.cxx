#include <iostream>
#include <algorithm>
#include "string_operations.h"

using namespace std;

namespace abhijeet1A
{
    String::String(const char str [])
	{
    	str_length = string_length(str);
    	allocated = str_length + 1;
    	data = new char[allocated];
    	copy(str, str + allocated, data);
	}

    String::~String()
    {
    	delete [] data;
    }

    String::size_type string_length(const char source [])
    {
    	String::size_type count = 0;
    	while(true)
    	{
    		if (source[count] == '\0') { break; }
    		else { count++; }
    	}
    	return count;
    }

	char * strcpy(char target [], char source [])
	{

	}

	char * strcat(char target [], char source [])
	{

	}

	/* int return */
	int strcmp(char string1 [], char string2 [])
	{

	}

	char String::operator [](size_type position) const
	{
		if (position > 0 && position < allocated)
		{
			return(data[position - 1]);
		}
		return ' ';
	}

	void String::operator +=(char addend [])
	{
		size_type len = string_length(addend);
		size_type new_size = str_length + len;
		allocated = new_size + 1;
		char * new_data = new char[allocated];

		copy(data, data + str_length, new_data);
		copy(addend, addend + len + 1, new_data + str_length);

		delete [] data;
		data = new_data;
		str_length = new_size;
	}

	void String::operator +=(char addend)
	{


	}

	void String::reserve(size_type new_capacity)
	{

	}

	String::size_type String::length(void) const
	{
		return str_length;
	}

	String operator +(String str1, String str2)
	{
		String result;


		return result;
	}
	std::istream& operator >>(std::istream& ins, String& target)
	{


		return ins;
	}
	std::ostream& operator <<(std::ostream& out, String& output)
	{


		return out;
	}
	std::istream& getline(std::istream& ins, String& target, char delimiter)
	{


		return ins;
	}
}

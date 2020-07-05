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
		//TODO
		char * new_data = new char[1];

		return new_data;
	}

	char * strcat(char target [], char source [])
	{
		//TODO
		char * new_data = new char[1];

		return new_data;

	}

	/* int return */
	int strcmp(char string1 [], char string2 [])
	{
		//TODO
		int k = 0;
		return k;

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
		allocated += 1;

		char * new_data = new char[allocated];
		copy(data, data + str_length, new_data);
		new_data[str_length] = addend;

		str_length += 1;
		new_data[str_length] = '\0';

		delete [] data;
		data = new_data;
	}

	void String::operator +=(const String& str1)
	{
		allocated += str1.length();

		char * new_data = new char[allocated];
		copy(data, data + str_length, new_data);
		copy(str1.data, str1.data + str1.str_length + 1, new_data + str_length);

		delete [] data;
		data = new_data;
		str_length += str1.str_length;
	}

	void String::operator =(const String& str1)
	{
		char * new_data;
		if (this == &str1)
		{
			return;
		}

		str_length = str1.length();
		allocated = str1.allocated;
		new_data = new char[allocated];
		copy(str1.data, str1.data + str1.allocated, new_data);

		delete [] data;
		data = new_data;
	}

	char * String::getData(void) const
	{
		return data;
	}

	void String::reserve(size_type new_capacity)
	{
		char * new_data;
		if (new_capacity <= allocated) { return; }

		new_data = new char[new_capacity];
		copy(data, data + allocated, new_data);
		allocated = new_capacity;
	}

	String::size_type String::length(void) const
	{
		return str_length;
	}

	String operator +(const String& str1, const String& str2)
	{
		String result;

		result += str1;
		result += str2;

		return result;
	}

	std::istream& operator >>(std::istream& ins, String& target)
	{
		//TODO
		return ins;
	}

	std::ostream& operator <<(std::ostream& out, String& output)
	{
		out << output.getData() << endl;
		return out;
	}

	std::istream& getline(std::istream& ins, String& target, char delimiter)
	{
		//TODO
		return ins;
	}
}

#include <iostream>
#include "string_operations.h"

using namespace std;

namespace abhijeet1A
{
    String::String(const char str [])
	{
    	data = new char[strlen(str)];
	}

    String::size_type String::strlen(const char source [])
    {
    	size_type count = 0;
    	while(true)
    	{
    		if (source[count] == '\0') { break; }
    		else { count++; }
    	}
    	return count;
    }




}

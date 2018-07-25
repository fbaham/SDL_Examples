#ifndef __TOOLS__
#define __TOOLS__

#include <iostream>
#include <sstream>

class Tools
{
public:
	template <typename T>
	static std::string to_string(const T& object) 
	{
	    std::ostringstream ss;
	    ss << object;
	    return ss.str();
	}
};

#endif
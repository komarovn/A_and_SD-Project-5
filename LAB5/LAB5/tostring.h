#ifndef _TOSTRING_H
#define _TOSTRING_H

#include <string>
//#include <sstream>

using namespace std;

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss<< val;
	return oss.str();
}

#endif
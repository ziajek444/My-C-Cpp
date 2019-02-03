#pragma once

#include <iostream>

class AbstractClass
{
public:

};

template <typename T>
class BackPack : public AbstractClass
{
public:
	BackPack() : case_pointer((T)0)
	{

	}
	BackPack(T value) : case_pointer(value)
	{

	}

	~BackPack()
	{
		std::cout << "deleted" << std::endl;
	}

private:
	const T case_pointer;
public:
	//template <typename T>
	//friend std::ostream & operator<< (std::ostream  out, const AbstractClass & BP);

	/*friend std::ostream& operator<< (std::ostream & os, const BackPack& rhs) {
		os << "dziala !";
		return os;
	}*/

};

/*std::ostream& operator<<  (std::ostream  out, const AbstractClass & BP)
{
	
	out << "elo";

	return out;
}*/




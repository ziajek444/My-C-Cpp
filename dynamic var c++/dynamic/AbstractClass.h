#pragma once

#include <iostream>
#include <string>
#include <string.h>

class AbstractClass
{
public:
	virtual const AbstractClass& getRef() const = 0;
	virtual ~AbstractClass() {};
};

template <class TtT>
class BackPack : public AbstractClass
{
public:
	BackPack() : case_pointer((TtT)0)
	{

	}
	BackPack(TtT value)
	{
		case_pointer = new TtT;

		// HELP
		/*
		char f = 'f';
		char ** pip = new char*;
		pip[0] = &f;
		*(pip[0]) = 'g';
		println(*(pip[0]));
		*/
		// HH
		
		if (std::string(typeid(TtT).name()).find('*') != std::string::npos) // var *
		{
			case_pointer = &value;
			asterix = true;
		}
		else // var
		{
			case_pointer = &value;
			asterix = false;
		}
	}

	~BackPack()
	{
		std::cout << "deleted" << std::endl;
	}

private:
	TtT * case_pointer;
	bool asterix;
public:
	const BackPack& getRef() const {
		return *this;
	}
public:
	template <class TtT>
	friend std::ostream & operator<< (std::ostream & out, const BackPack<TtT> & BP);

};

template <class TtT>
std::ostream & operator<< (std::ostream & out, class BackPack<typename TtT> const& BP)
{
	if(!BP.asterix)
		out << "type: " << typeid(TtT).name() << " [" << *BP.case_pointer << "]\r\n";
	else
		out << "type: " << typeid(TtT).name() << " [" << (TtT)BP.case_pointer << "]\r\n";
	//out << "type: " << typeid(TtT).name() << " [" << *(TtT)BP.case_pointer << "]\r\n";

	return out;
}




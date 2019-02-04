#pragma once

#include <iostream>
#include <string>
#include <string.h>

class AbstractClass
{
public:
	virtual const AbstractClass& getRef() const = 0;
	virtual ~AbstractClass() {};
public:
	friend std::ostream & operator<< (std::ostream & out, const AbstractClass & BP)
	{

		out << "W kamarze !! ";

		return out;
	}
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
		
		case_pointer = new TtT[1];
		// HELP
		/*
		char f = 'f';

		char ** pip;
		pip = new char*;

		pip[0] = &f;
		*(pip[0]) = 'g';
		println(*(pip[0]));

		char * pipi;
		pipi = new char;
		pipi = &f;
		*(pipi) = 'n';
		println(*(pipi));
		*/
		// HH
		auto A = *case_pointer;
		*case_pointer = '\0'; // for 0 is ambiguous
		if (std::string(typeid(TtT).name()).find('*') != std::string::npos) // var *
		{
			A = value;
			*case_pointer = A;
			asterix = true;
		}
		else // var
		{
			A = value;
			*case_pointer = A;
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
		out << *(BP.case_pointer) << "\r\n";
	else
		out  << *(BP.case_pointer) << "\r\n";


	return out;
}





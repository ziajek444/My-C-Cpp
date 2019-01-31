//#include "pch.h"
#include <iostream>
#include <typeinfo>       // operator typeid
#include <typeindex>      // std::type_index
#include <string>
#include <string.h>

#define TYPE(x) typeid(x).name()


template <class Type>
void print(const Type p);
template <class Type>
void println(const Type p);

//------------------------------------------------- prototype

class dynamic
{
public:
	int v;
	void * pointer;
	int var_size;
	int item_size;
	std::type_index data_type;

	dynamic() : v(0), data_type(typeid(void))
	{
		this->ID += 1;
		this->self_ID = this->ID;
	}

	int getID()
	{
		return this->self_ID;
	}

	template <class Temp>
	dynamic & operator =(const Temp & x)
	{
		this->var_size = sizeof(x);
		this->item_size = sizeof(Temp);

		if (0 == this->var_size) {
			throw "Size od input variable can't be 0B (empty variable)";
		}

		this->data_type = typeid(Temp);

		if (this->pointer == nullptr)
		{
			this->pointer = new Temp[this->var_size / this->item_size];
		}
		else
		{
			delete this->pointer;
			this->pointer = new Temp[this->var_size / this->item_size];
		}

		(*(Temp*)(this->pointer)) = x;

		return *this;
	}

	friend std::ostream & operator<< (std::ostream & out, const dynamic & am);

	//template <class Temp>
	//operator Temp() { println(typeid(Temp).name()); return (Temp)0x05; }

	virtual ~dynamic() {
		print("dynamic ");
		print(this->self_ID);
		println(" destroyed");
	}

private:

	static int ID;
	int self_ID;

};

//------------------------------------------------- main


int main()
{
	println("hejeczka");
	println(TYPE(int));
	int rozm = sizeof(dynamic);

	dynamic d1;
	dynamic d2;

	println(d1.getID());
	println(d2.getID());

	println(d1);
	rozm = 9999;
	d1 = rozm;
	println(d1);
	
	std::type_index ii = typeid(int);

	std::cin.get();
	return 0;

}

//------------------------------------------------- body
std::ostream & operator<< (std::ostream & out, const dynamic & am)
{
	if(am.pointer != nullptr)
		out << (int)(*(int*)(am.pointer))<<" id: "<<am.self_ID;
	else
		out << "nulptr " << " id: " << am.self_ID;
	return out;
}

int dynamic::ID = 0;

template <class Type>
void print(const Type p)
{
	std::cout << p;
}

template <class Type>
void println(const Type p)
{
	std::cout << p << std::endl;
}

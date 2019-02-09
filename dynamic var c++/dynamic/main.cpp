//#include "pch.h"
#include <iostream>
#include <typeinfo>       // operator typeid
#include <typeindex>      // std::type_index
#include <string>
#include <string.h>
#include <stdint.h>
#include "AbstractClass.h"


#define TYPE(x) typeid(x).name()


template <class Type>
void print(const Type p);
template <class Type>
void println(const Type p);

//------------------------------------------------- dynamic

template <typename T4, typename T5>
void printToConsole(T4 typ, T5 wartosc)
{
	std::cout << static_cast<T4>(wartosc);
}

class dynamic
{
	// type erasure
	
private:
	struct ObjectConcept {
	public:
		virtual void T_print_() const = 0;
		virtual ~ObjectConcept() {}

	};

	template< typename T > struct ObjectModel : ObjectConcept {
	public:
		ObjectModel(const T& t) : object(t) {}
		virtual void T_print_() const
		{
			printToConsole(object, object);
		}
		virtual ~ObjectModel() {}
	private:
		T object;
	};
	//--------------------------------------------------------

public:
	dynamic() : initialized(false), data_type(typeid(void))
	{
		this->ID += 1;
		this->self_ID = this->ID;
	}

	int getID()
	{
		return this->self_ID;
	}

	template <class Temp>
	dynamic & operator= (const Temp & x)
	{

		return *this;
	}

	template <class Temp>
	dynamic & operator =(const Temp && x)
	{
		return *this;
	}

	friend std::ostream & operator<< (std::ostream & out, const dynamic & am) {}

	virtual ~dynamic() { }

private:
	static int ID;
	int self_ID;
	std::unique_ptr<ObjectConcept> object;
	bool initialized;
	int var_size;
	int item_size;
	std::type_index data_type;

};

//------------------------------------------------- main

int main()
{
	
	

	std::cin.get();
	return 0;

}

//------------------------------------------------- body

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

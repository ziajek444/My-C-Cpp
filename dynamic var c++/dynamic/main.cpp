//#include "pch.h"
#include <iostream>
#include <typeinfo>       // operator typeid
#include <typeindex>      // std::type_index
#include <string>
#include <string.h>
#include <stdint.h>

#define TYPE(x) typeid(x).name()


template <class Type>
void print(const Type p);
template <class Type>
void println(const Type p);

//------------------------------------------------- prototype

class DataTable
{
	std::string * _data_table;
	explicit DataTable() : _data_table(new std::string[5]) {
		int index = 0;
		_data_table[index++] = " ";
		_data_table[index++] = " ";
		_data_table[index++] = " ";
		_data_table[index++] = " ";
		_data_table[index++] = " ";
		_data_table[index++] = " ";
	}

	virtual ~DataTable()
	{
		delete[] _data_table;
	}

};

class dynamic
{
public:

	uint8_t * pointer;
	bool initialized;
	int var_size;
	int item_size;
	std::type_index data_type;


	explicit dynamic() : initialized(false), data_type(typeid(void))
	{
		this->ID += 1;
		this->self_ID = this->ID;
	}

	dynamic (const dynamic& D) : initialized(false), data_type(typeid(void))
	{
		if (D.initialized)
		{
			pointer = new uint8_t[D.var_size];
			for (int i = 0; i < var_size; i++)
			{
				pointer[i] = D.pointer[i];
			}
		}
		this->initialized = D.initialized;
		this->var_size = D.var_size;
		this->item_size = D.item_size;
		this->data_type = D.data_type;
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

		const uint8_t * tmp_pointer = &(uint8_t&)x;

		if (this->data_type == typeid(Temp) && this->initialized)
		{
			*(Temp*)(this->pointer) = x;
		}
		else if(this->initialized)
		{
			this->data_type = typeid(Temp);

			if (var_size == item_size)
				delete pointer;
			else
				delete[] pointer;

			this->pointer = new uint8_t[var_size];
			for (int i = 0; i < var_size; ++i) {
				this->pointer[i] = tmp_pointer[i];
			}
		}
		else
		{
			this->data_type = typeid(Temp);
			this->initialized = true;
			this->pointer = new uint8_t[var_size];
			for (int i = 0; i < var_size; ++i) {
				this->pointer[i] = tmp_pointer[i];
			}
		}

		return *this;
	}

	template <class Temp>
	dynamic & operator =(const Temp && x)
	{
		this->var_size = sizeof(x);
		this->item_size = sizeof(Temp);

		if (0 == this->var_size) {
			throw "Size od input variable can't be 0B (empty variable)";
		}

		const uint8_t * tmp_pointer = &(uint8_t&)x;

		if (this->data_type == typeid(Temp) && this->initialized)
		{
			*(Temp*)(this->pointer) = x;
		}
		else if (this->initialized)
		{
			this->data_type = typeid(Temp);

			if (var_size == item_size)
				delete pointer;
			else
				delete[] pointer;

			this->pointer = new uint8_t[var_size];
			for (int i = 0; i < var_size; ++i) {
				this->pointer[i] = tmp_pointer[i];
			}
		}
		else
		{
			this->data_type = typeid(Temp);
			this->initialized = true;
			this->pointer = new uint8_t[var_size];
			for (int i = 0; i < var_size; ++i) {
				this->pointer[i] = tmp_pointer[i];
			}
		}

		return *this;
	}

	
	//friend std::ostream & operator<< (std::ostream & out, const dynamic & am);


	virtual ~dynamic() {
		
		if (this->initialized && (var_size == item_size))
		{
			delete pointer;
		}
		else if (this->initialized && (var_size != item_size))
		{
			delete[] pointer;
		}
		else if (pointer != nullptr)
		{
			delete pointer;
		}
		else
		{
			println("pointer is null");
		}

		this->initialized = false;
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
	//println(TYPE(int));
	int rozm = sizeof(dynamic);

	dynamic d1;
	dynamic d2;
	d1 = rozm;
	d2 = '4';

	//std::cout << d1 << std::endl;
	//std::cout << d2 << std::endl;

	
	std::type_index tmp_data_type = std::type_index(typeid(void));
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(void*));
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(void**));
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(void***));
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(int));
	print("int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int*));
	print("int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int**));
	print("int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int***));
	print("int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int&));
	print("int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int&&));
	print("int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(unsigned int));
	print("unsigned int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(unsigned int*));
	print("unsigned int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(unsigned int**));
	print("unsigned int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(unsigned int***));
	print("unsigned int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(unsigned int&));
	print("unsigned int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(unsigned int&&));
	print("unsigned int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(signed int));
	print("signed int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(signed int*));
	print("signed int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(signed int**));
	print("signed int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(signed int***));
	print("signed int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(signed int&));
	print("signed int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(signed int&&));
	print("signed int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(short unsigned int));
	print("short unsigned int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned int*));
	print("short unsigned int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned int**));
	print("short unsigned int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned int***));
	print("short unsigned int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned int&));
	print("short unsigned int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned int&&));
	print("short unsigned int&&: ");
	println(tmp_data_type.name());
	
	tmp_data_type = std::type_index(typeid(short int));
	print("short int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short int*));
	print("short int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short int**));
	print("short int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short int***));
	print("short int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short int&));
	print("short int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short int&&));
	print("short int&&: ");
	println(tmp_data_type.name());
	
	tmp_data_type = std::type_index(typeid(short));
	print("short: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short*));
	print("short*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short**));
	print("short**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short***));
	print("short***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short&));
	print("short&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short&&));
	print("short&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(short unsigned));
	print("short unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned*));
	print("short unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned**));
	print("short unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned***));
	print("short unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned&));
	print("short unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(short unsigned&&));
	print("short unsigned&&: ");
	println(tmp_data_type.name());

	//------------- long ---------------------

	tmp_data_type = std::type_index(typeid(long unsigned int));
	print("long unsigned int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned int*));
	print("long unsigned int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned int**));
	print("long unsigned int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned int***));
	print("long unsigned int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned int&));
	print("long unsigned int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned int&&));
	print("long unsigned int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(long int));
	print("long int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long int*));
	print("long int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long int**));
	print("long int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long int***));
	print("long int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long int&));
	print("long int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long int&&));
	print("long int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(long));
	print("long: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long*));
	print("long*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long**));
	print("long**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long***));
	print("long***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long&));
	print("long&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long&&));
	print("long&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(long unsigned));
	print("long unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned*));
	print("long unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned**));
	print("long unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned***));
	print("long unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned&));
	print("long unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long unsigned&&));
	print("long unsigned&&: ");
	println(tmp_data_type.name());

	// ----------------- long long ---------------------


	tmp_data_type = std::type_index(typeid(long long unsigned int));
	print("long long unsigned int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned int*));
	print("long long unsigned int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned int**));
	print("long long unsigned int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned int***));
	print("long long unsigned int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned int&));
	print("long long unsigned int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned int&&));
	print("long long unsigned int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(long long int));
	print("long long int: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long int*));
	print("long long int*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long int**));
	print("long long int**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long int***));
	print("long long int***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long int&));
	print("long long int&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long int&&));
	print("long long int&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(long long));
	print("long long: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long*));
	print("long long*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long**));
	print("long long**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long***));
	print("long long***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long&));
	print("long long&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long&&));
	print("long long&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(long long unsigned));
	print("long long unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned*));
	print("long long unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned**));
	print("long long unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned***));
	print("long long unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned&));
	print("long long unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(long long unsigned&&));
	print("long long unsigned&&: ");
	println(tmp_data_type.name());

	// ----------------- __int8 --------------------------
	
	tmp_data_type = std::type_index(typeid(__int8 unsigned));
	print("__int8 unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 unsigned*));
	print("__int8 unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 unsigned**));
	print("__int8 unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 unsigned***));
	print("__int8 unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 unsigned&));
	print("__int8 unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 unsigned&&));
	print("__int8 unsigned&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int8 signed));
	print("__int8 signed: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 signed*));
	print("__int8 signed*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 signed**));
	print("__int8 signed**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 signed***));
	print("__int8 signed***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 signed&));
	print("__int8 signed&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8 signed&&));
	print("__int8 signed&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int8));
	print("__int8: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8*));
	print("__int8*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8**));
	print("__int8**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8***));
	print("__int8***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8&));
	print("__int8&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int8&&));
	print("__int8&&: ");
	println(tmp_data_type.name());


	// ----------------- __int16 --------------------------

	tmp_data_type = std::type_index(typeid(__int16 unsigned));
	print("__int16 unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 unsigned*));
	print("__int16 unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 unsigned**));
	print("__int16 unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 unsigned***));
	print("__int16 unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 unsigned&));
	print("__int16 unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 unsigned&&));
	print("__int16 unsigned&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int16 signed));
	print("__int16 signed: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 signed*));
	print("__int16 signed*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 signed**));
	print("__int16 signed**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 signed***));
	print("__int16 signed***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 signed&));
	print("__int16 signed&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16 signed&&));
	print("__int16 signed&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int16));
	print("__int16: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16*));
	print("__int16*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16**));
	print("__int16**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16***));
	print("__int16***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16&));
	print("__int16&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int16&&));
	print("__int16&&: ");
	println(tmp_data_type.name());

	// ----------------- __int32 --------------------------

	tmp_data_type = std::type_index(typeid(__int32 unsigned));
	print("__int32 unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 unsigned*));
	print("__int32 unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 unsigned**));
	print("__int32 unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 unsigned***));
	print("__int32 unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 unsigned&));
	print("__int32 unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 unsigned&&));
	print("__int32 unsigned&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int32 signed));
	print("__int32 signed: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 signed*));
	print("__int32 signed*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 signed**));
	print("__int32 signed**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 signed***));
	print("__int32 signed***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 signed&));
	print("__int32 signed&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32 signed&&));
	print("__int32 signed&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int32));
	print("__int32: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32*));
	print("__int32*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32**));
	print("__int32**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32***));
	print("__int32***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32&));
	print("__int32&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int32&&));
	print("__int32&&: ");
	println(tmp_data_type.name());
	
	// ----------------- __int64 --------------------------

	tmp_data_type = std::type_index(typeid(__int64 unsigned));
	print("__int64 unsigned: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 unsigned*));
	print("__int64 unsigned*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 unsigned**));
	print("__int64 unsigned**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 unsigned***));
	print("__int64 unsigned***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 unsigned&));
	print("__int64 unsigned&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 unsigned&&));
	print("__int64 unsigned&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int64 signed));
	print("__int64 signed: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 signed*));
	print("__int64 signed*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 signed**));
	print("__int64 signed**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 signed***));
	print("__int64 signed***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 signed&));
	print("__int64 signed&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64 signed&&));
	print("__int64 signed&&: ");
	println(tmp_data_type.name());

	tmp_data_type = std::type_index(typeid(__int64));
	print("__int64: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64*));
	print("__int64*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64**));
	print("__int64**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64***));
	print("__int64***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64&));
	print("__int64&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(__int64&&));
	print("__int64&&: ");
	println(tmp_data_type.name());

	// ----------------- __int128 --------------------------

	//Error	C2512	'std::type_index': no appropriate default constructor available	Dynamic

	// ----------------- uint8_t --------------------------


	tmp_data_type = std::type_index(typeid(uint8_t));
	print("uint8_t: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint8_t*));
	print("uint8_t*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint8_t**));
	print("uint8_t**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint8_t***));
	print("uint8_t***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint8_t&));
	print("uint8_t&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint8_t&&));
	print("uint8_t&&: ");
	println(tmp_data_type.name());

	// ----------------- int8_t --------------------------


	tmp_data_type = std::type_index(typeid(int8_t));
	print("int8_t: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int8_t*));
	print("int8_t*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int8_t**));
	print("int8_t**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int8_t***));
	print("int8_t***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int8_t&));
	print("int8_t&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int8_t&&));
	print("int8_t&&: ");
	println(tmp_data_type.name());

	// ----------------- uint16_t --------------------------


	tmp_data_type = std::type_index(typeid(uint16_t));
	print("uint16_t: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint16_t*));
	print("uint16_t*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint16_t**));
	print("uint16_t**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint16_t***));
	print("uint16_t***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint16_t&));
	print("uint16_t&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(uint16_t&&));
	print("uint16_t&&: ");
	println(tmp_data_type.name());

	// ----------------- int16_t --------------------------


	tmp_data_type = std::type_index(typeid(int16_t));
	print("int16_t: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int16_t*));
	print("int16_t*: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int16_t**));
	print("int16_t**: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int16_t***));
	print("int16_t***: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int16_t&));
	print("int16_t&: ");
	println(tmp_data_type.name());
	tmp_data_type = std::type_index(typeid(int16_t&&));
	print("int16_t&&: ");
	println(tmp_data_type.name());
	

	std::cin.get();
	return 0;

}

//------------------------------------------------- body

/*
std::ostream & operator<< (std::ostream & out, const dynamic & am)
{
	std::type_index tmp_data_type = am.data_type;

	if (am.pointer != nullptr)
	{
		switch (tmp_data_type.hash_code())
		{
			case typeid(int).hash_code():
			{
				int tmp = (int)(*(int*)(am.pointer));
				out << tmp << " id: " << am.self_ID;
				break;
			}
			case 1:
			{
				break;
			}
			default:
			{
				//for
				break;
			}
		}
		
		//out << (TT)(*(TT*)(am.pointer)) << " id: " << am.self_ID;
	}
	else
		out << "nulptr " << " id: " << am.self_ID;
	return out;
}*/

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

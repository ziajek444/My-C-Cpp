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
public:
	std::string * _data_table;
	int arr_size;
	explicit DataTable() : _data_table(new std::string[24]),arr_size(24) {
		int index = 0;
		_data_table[index++] = "void"; // 0
		_data_table[index++] = "void *";
		_data_table[index++] = "unsigned short"; // 2
		_data_table[index++] = "unsigned short *";
		_data_table[index++] = "short";// 4
		_data_table[index++] = "short *";
		_data_table[index++] = "unsigned char"; // 6
		_data_table[index++] = "unsigned char *";
		_data_table[index++] = "signed char"; // 8
		_data_table[index++] = "signed char *";
		_data_table[index++] = "char";//10
		_data_table[index++] = "char *";
		_data_table[index++] = "unsigned long";//12
		_data_table[index++] = "unsigned long *";
		_data_table[index++] = "long";//14
		_data_table[index++] = "long *";
		_data_table[index++] = "unsigned __int64";// 16
		_data_table[index++] = "unsigned __int64 *";
		_data_table[index++] = "__int64";// 18
		_data_table[index++] = "__int64 *";
		_data_table[index++] = "int"; // 20
		_data_table[index++] = "int *";
		_data_table[index++] = "class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> >"; // 22
		_data_table[index++] = "class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > *";

		//_data_table[index++] = "";
	}

	std::string operator[] (int index)
	{
		return _data_table[index];
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
	int var_size=0;
	int item_size;
	std::type_index data_type;

	dynamic() : initialized(false), data_type(typeid(void))
	{
		this->ID += 1;
		this->self_ID = this->ID;
	}

	explicit dynamic(const dynamic& D) : initialized(false), data_type(typeid(void))
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

	template <class Tymbark>
	explicit dynamic(const Tymbark& input) : initialized(false), data_type(typeid(void))
	{
		this->var_size = sizeof(input);
		this->item_size = sizeof(Tymbark);

		pointer = new Tymbark[this->var_size/ this->item_size];
				
		this->initialized = true;
		this->data_type = typeid(Tymbark);
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


	friend std::ostream & operator<< (std::ostream & out, const dynamic & am);


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
	int rozm = sizeof(dynamic);

	dynamic d1;
	dynamic d2;
	d1 = rozm;
	d2 = '4';

	std::cout << rozm << std::endl;
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	d2 = "jakis tam tekst";
	std::cout << d2 << std::endl;

	std::cin.get();
	return 0;

}

//------------------------------------------------- body


std::ostream & operator<< (std::ostream & out, const dynamic & am)
{
	std::type_index tmp_data_type = am.data_type;
	std::string tmp_string = tmp_data_type.name();
	DataTable DT;
	int index = -1;

	for (int i = 0; i < DT.arr_size; ++i)
	{
		if (!(  strcmp( DT[i].c_str(), tmp_string.c_str() )  ))
		{
			index = i;
			break;
		}
	}

	if (am.pointer != nullptr)
	{
		switch (index)
		{
			case 2:
			case 4:
			{
				short tmp = (short)(*(short*)(am.pointer));
				out << tmp;
				break;
			}
			case 3:
			case 5:
			{
				short tmp = (short)(*(short*)(am.pointer)[0]);
				out << tmp;
				break;
			}
			case 6:
			case 8:
			case 10:
			{
				char tmp = (char)(*(char*)(am.pointer));
				out << tmp;
				break;
			}
			case 7:
			case 9:
			case 11:
			{
				char tmp = (char)(*(char*)(am.pointer)[0]);
				out << tmp;
				break;
			}
			case 12:
			case 14:
			{
				long tmp = (long)(*(long*)(am.pointer));
				out << tmp;
				break;
			}
			case 13:
			case 15:
			{
				long tmp = (long)(*(long*)(am.pointer)[0]);
				out << tmp;
				break;
			}
			case 16:
			case 18:
			{
				__int64 tmp = (__int64)(*(__int64*)(am.pointer));
				out << tmp;
				break;
			}
			case 17:
			case 19:
			{
				__int64 tmp = (__int64)(*(__int64*)(am.pointer)[0]);
				out << tmp;
				break;
			}
			case 20:
			{
				int tmp = (int)(*(int*)(am.pointer));
				out << tmp;
				break;
			}
			case 21:
			{
				int tmp = (int)(*(int*)(am.pointer)[0]);
				out << tmp;
				break;
			}
			case 22:
			{
				std::string tmp = (std::string)(*(std::string*)(am.pointer));
				out << tmp;
				break;
			}
			case 23:
			{
				std::string tmp = (std::string)(*(std::string*)(am.pointer)[0]);
				out << tmp;
				break;
			}
			default:
			{
				for (int i = 0; i < am.var_size; ++i) {
					out << (__int8)(*am.pointer);
				}
				break;
			}
		}
	}
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

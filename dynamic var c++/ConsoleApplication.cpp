// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

//With cast operators the sizeof is 16B but without is only 8B.

class DYNAMIC
{
public:
	void *pointer;
	short type; // 0 undefined, 1 char, 2 short, 3 int, 4 float, 5 double, 6 string,
	//explicit
	DYNAMIC()
	{
		cout << "dynamic start ()" << endl;
		//pointer = new short;
		type = 0;
	}
	~DYNAMIC()
	{
		MakeMem();
		cout << "dynamic terminated" << endl;
	}

	//TO DO
	DYNAMIC(DYNAMIC &a) {
		cout << "dynamic start (DYNAMIC)" << endl;
		this->type = 3;
		this->pointer = new int;
		*((int *)this->pointer) = 999;
	}

	DYNAMIC(int &&a) {
		cout << "dynamic start (int &&)" << endl;
		this->type = 3;
		this->pointer = new int;
		*((int *)this->pointer) = a;
	}
	DYNAMIC(int &a) {
		cout << "dynamic start (int &)" << endl;
		this->type = 3;
		this->pointer = new int;
		*((int *)this->pointer) = a;
	}

	template <class obj>
	DYNAMIC (obj &a) {
			cout << "dynamic start (&a)" << endl;
			this->type = 3;
			this->pointer = new obj;
			*((obj *)this->pointer) = a;
	}
	template <class obj>
	DYNAMIC(obj &&a) {
		cout << "dynamic start (&&a)" << endl;
		this->type = 3;
		this->pointer = new obj;
		*((obj *)this->pointer) = a;

	}


	/*template <class obj>
	DYNAMIC(obj &&a)
	{
		int I;
		if (I = dynamic_cast<int>(a)) {
			this->type = 3; this->pointer = new obj;
			*((obj *)this->pointer) = a;
			cout << "Debug statement #3a" << endl;
		}
		else {
			this->type = 6;
			this->pointer = new string;
			*((string *)this->pointer) = "gowienko";
			cout << "Debug statement #3b" << endl;
		}
	}
	template <class obj>
	DYNAMIC(obj &a)
	{
		int I;
		if (I = dynamic_cast<int>(a)) { 
			this->type = 3; this->pointer = new obj;
			*((obj *)this->pointer) = a;
			cout << "Debug statement #3a" << endl;
		}
		else {
			this->type = 6;
			this->pointer = new string;
			*((string *)this->pointer) = "gowienko";
			cout << "Debug statement #3b" << endl;
		}
	}*/
	/*DYNAMIC(int &a)
	{
			cout << "konstruktor int" << endl;
			this->type = 3;
			this->pointer = new int;
			*((int *)this->pointer) = a;
	}
	DYNAMIC(int &&a)
	{
		cout << "konstruktor int" << endl;
		this->type = 3;
		this->pointer = new int;
		*((int *)this->pointer) = a;
	}*/

	operator char()
	{
		/*if (this->type==3)
			return *((int*)pointer)
		else return 0;*/
		return this->type == 1 ? *((char*)pointer) : '\0';
	}
	operator short()
	{
		/*if (this->type==3)
			return *((int*)pointer)
		else return 0;*/
		return this->type == 2 ? *((short*)pointer) : 0;
	}
	operator int()
	{
		/*if (this->type==3)
			return *((int*)pointer)
		else return 0;*/
		return this->type == 3 ? *((int*)pointer) : 0;
	}
	operator float()
	{
		/*if (this->type==3)
			return *((int*)pointer)
		else return 0;*/
		return this->type == 4 ? *((float*)pointer) : 0.0;
	}
	operator double()
	{
		/*if (this->type==3)
			return *((int*)pointer)
		else return 0;*/
		return this->type == 5 ? *((double*)pointer) : 0.0;
	}
	operator string()
	{
		/*if (this->type==3)
			return *((int*)pointer)
		else return 0;*/
		return this->type == 6 ? *((string*)pointer) : "";
	}

	// CHAR
	DYNAMIC& operator=(const char& arg1) //for auto variable
	{

		MakeMem();
		this->type = 1;
		pointer = new char;
		*((char*)pointer) = arg1;
		cout << "#a#char#" << endl;
		return *this;
	}
	DYNAMIC& operator=(const char&& arg2) //for rvalue
	{

		MakeMem();
		this->type = 1;
		pointer = new char;
		*((char*)pointer) = arg2;
		cout << "#r#char#" << endl;
		return *this;
	}
	// SHORT
	DYNAMIC& operator=(const short& arg1) //for auto variable
	{

		MakeMem();
		this->type = 2;
		pointer = new short;
		*((short*)pointer) = arg1;
		cout << "#a#short#" << endl;
		return *this;
	}
	DYNAMIC& operator=(const short&& arg2) //for rvalue
	{

		MakeMem();
		this->type = 2;
		pointer = new short;
		*((short*)pointer) = arg2;
		cout << "#r#short#" << endl;
		return *this;
	}
	// INT
	DYNAMIC& operator=(const int& arg1) //for auto variable
	{

		MakeMem();
		this->type = 3;
		pointer = new int;
		*((int*)pointer) = arg1;
		cout << "#a#int#" << endl;
		return *this;
	}
	DYNAMIC& operator=(const int&& arg2) //for rvalue
	{

		MakeMem();
		this->type = 3;
		pointer = new int;
		*((int*)pointer) = arg2;
		cout << "#r#int#" << endl;
		return *this;
	}
	// FLOAT
	DYNAMIC& operator=(const float& arg1) //for auto variable
	{

		MakeMem();
		this->type = 4;
		pointer = new float;
		*((float*)pointer) = arg1;
		cout << "#a#float#" << endl;
		return *this;
	}
	DYNAMIC& operator=(const float&& arg2) //for rvalue
	{

		MakeMem();
		this->type = 4;
		pointer = new float;
		*((float*)pointer) = arg2;
		cout << "#r#float#" << endl;
		return *this;
	}
	// DOUBLE
	DYNAMIC& operator=(const double& arg1) //for auto variable
	{

		MakeMem();
		this->type = 5;
		pointer = new double;
		*((double*)pointer) = arg1;
		cout << "#a#double#" << endl;
		return *this;
	}
	DYNAMIC& operator=(const double&& arg2) //for rvalue
	{

		MakeMem();
		this->type = 5;
		pointer = new double;
		*((double*)pointer) = arg2;
		cout << "#r#double#" << endl;
		return *this;
	}
	// STRING
	DYNAMIC& operator=(const string& arg1) //for auto variable
	{

		MakeMem();
		this->type = 6;
		pointer = new string;
		*((string*)pointer) = arg1;
		cout << "#a#string#" << endl;
		return *this;
	}
	DYNAMIC& operator=(const string&& arg2) //for rvalue
	{

		MakeMem();
		this->type = 6;
		pointer = new string;
		*((string*)pointer) = arg2;
		cout << "#r#string#" << endl;
		return *this;
	}
	friend ostream& operator<<(ostream& out, DYNAMIC& object);
	friend istream& operator>>(istream& in, DYNAMIC& object);

	void PRINT()
	{
		switch (this->type) //0 undefined, 1 char, 2 short, 3 int, 4 float, 5 double, 6 string,
		{
		case 0:

			break;
		case 1:
			cout << "get: " << *((char*)pointer) << endl;
			break;
		case 2:
			cout << "get: " << *((short*)pointer) << endl;
			break;
		case 3:
			cout << "get: " << *((int*)pointer) << endl;
			break;
		case 4:
			cout << "get: " << *((float*)pointer) << endl;
			break;
		case 5:
			cout << "get: " << *((double*)pointer) << endl;
			break;
		case 6:
			cout << "get: " << *((string*)pointer) << endl;
			break;
		default:
			break;
		}
	}

	void MakeMem()
	{
		switch (this->type) //0 undefined, 1 char, 2 short, 3 int, 4 float, 5 double, 6 string,
		{
		case 0:

			break;
		case 1:
			delete (char*)pointer;
			break;
		case 2:
			delete (short*)pointer;
			break;
		case 3:
			delete (int*)pointer;
			break;
		case 4:
			delete (float*)pointer;
			break;
		case 5:
			delete (double*)pointer;
			break;
		case 6:
			delete (string*)pointer;
			break;
		default:
			break;
		}
	}

};

ostream& operator<<(ostream& out, DYNAMIC& object)
{
	switch (object.type)
	{
	case 0:
		out << "\0";
		break;
	case 1:
		out << *((char*)object.pointer);
		break;
	case 2:
		out << *((short*)object.pointer);
		break;
	case 3:
		out << *((int*)object.pointer);
		break;
	case 4:
		out << *((float*)object.pointer);
		break;
	case 5:
		out << *((double*)object.pointer);
		break;
	case 6:
		out << *((string*)object.pointer);
		break;
	default:
		break;
	}
	return out;
}

istream& operator>>(istream& in, DYNAMIC& object)
{
	//Basically treat like string
// 43 +  45 -
// 44 ,  46 .
// 48-57 -> 0-9
	bool notInt = false;
	bool notDouble = false;
	short dots_counter = 0;
	int i = 0;
	string tmp = "";
	in >> tmp;
	if (!tmp.empty())
	{
		if (tmp.length() == 1)
		{
			if (object.type == 0 || object.type == 1) { object = static_cast<char>(tmp[0]); }
			else if (object.type == 2 && (tmp[0] >= '0' && tmp[0] <= '9')) { object = static_cast<short>(static_cast<short>(tmp[0]) - 48); }
			else if (object.type == 3 && (tmp[0] >= '0' && tmp[0] <= '9')) { object = static_cast<int>(static_cast<int>(tmp[0]) - 48); }
			else object = static_cast<string>(tmp);
		}
		else
		{
			if (object.type != 0 && object.type != 1 && object.type != 6) //If is number, not text try to find number
			{
				if (tmp[0] == '-' || tmp[0] == '+') i++;
				for (i; i < tmp.length(); i++)
				{
					if (tmp[i] >= '0' && tmp[i] <= '9') continue;
					else if ((tmp[i] == ',' || tmp[i] == '.') && notInt == false) { dots_counter++; notInt = true; }
					else { notDouble = true; break; }

				}
				if (!notInt)
				{
					object = atoi(tmp.c_str());
				}
				else if (!notDouble)
				{
					object = atof(tmp.c_str());
				}
			}
			else
			{
				object = static_cast<string>(tmp);
			}
		}

	}
	return in;
}

int main() {
	
	
	DYNAMIC dd=9;
	DYNAMIC cc = dd;
	string s = "asd";
	//dd = s;
	DYNAMIC dyn = s;
	cout << "sizeof dynamic: " << sizeof(dd) << endl;
	cout <<"dd:  "<< dd << endl;
	cout << "cc:  " << cc << endl;
	cout << "dyn: " << dyn << endl;
	//vector<int> INT;
	//INT.push_back(44);
	//INT.push_back(47);
	//for (int &data : INT) cout << data << endl;
	//cout << "vector of DYNAMIC" << endl;
	vector<DYNAMIC> VD;
	//int y = 8;
	VD.push_back(111);
	VD.push_back(222);
	cout << "foreach" << endl;
	for (DYNAMIC &data : VD) cout << data << endl;
	cout << "fin" << endl;

	return 0;
}















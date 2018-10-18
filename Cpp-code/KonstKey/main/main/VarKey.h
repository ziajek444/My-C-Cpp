#ifndef _VARKEY_H_
#define _VARKEY_H_

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */
#include <math.h>
#include <string>		/*std::to_string(int); */
#include <random>

#ifndef __uint8_t
typedef unsigned char uint8_t;
#define __uint8_t
#endif __uint8_t

using namespace std;

string FirstParameters();
char RandomNotNumber(); 
bool IsNumber(const char);
//

string FirstParameters()
{
	//conditions:
	// p1 <1,100>
	// p2 <2,10>
	// p3 <1,1000>
	// tconst <1,100>
	// tvar <1,unsigned int - 1>
	// offset <1,100> (co ile iteracji jest ta w³aœciwa)


	uint8_t p1,p2,tconst,offset;
	short p3;
	unsigned int tvar;
	short divide = 1;

	p1 = rand() % 100 + 1;

	string ret_str = "";
	ret_str += RandomNotNumber();
	ret_str += std::to_string(p1);

	p2 = rand() % 100 + 1;

	ret_str += RandomNotNumber();
	ret_str += std::to_string(p2);

	p3 = rand() % 100 + 1;

	ret_str += RandomNotNumber();
	ret_str += std::to_string(p3);

	tconst = rand() % 100 + 1;

	ret_str += RandomNotNumber();
	ret_str += std::to_string(tconst);

	tvar = rand() % 100 + 1;

	ret_str += RandomNotNumber();
	ret_str += std::to_string(tvar);

	offset = rand() % 100 + 1;

	ret_str += RandomNotNumber();
	ret_str += std::to_string(offset);

	ret_str += RandomNotNumber();

	return ret_str;
}

char RandomNotNumber()
{
	random_device rd;
	char sign = rd();
	while(!((sign >= '!' && sign<='/') || (sign >= ':' && sign <= '~'))) sign = (rd()&0xFF);
	return sign;
}

int* GetParametersTab(string parameters)
{
	int * param = new int[6];
	string number = "";
	//memset(tab, 0, sizeof(string)*6);
	// construction: 
	// p1 <1,100>
	// p2 <2,10>
	// p3 <1,1000>
	// tconst <1,100>
	// tvar <1,unsigned int - 1>
	// offset <1,100>
	// R - not number random,
	// R p1 R p2 R p3 R tconst R tvar R offset R // (without spaces) !!

	// test if 1st char is not a number 
	// test if 2nd char in number, schould be
	if (IsNumber(parameters[0]) || !IsNumber(parameters[1])) cout<<"Wrong parameters string\n";//throw "Wrong parameters string";
	int index = 1;
	for (int i=0;i<6;i++)
	{
		while( IsNumber(parameters[index]) ) number += static_cast<char>(parameters[index++]);
		if (number.length()) param[i] = atoi(number.c_str());
		//else --i;
		//std::cout << number << std::endl;
		//cout << "there is fakap" << endl;
		index++;
		number = "";
		
	}

	//int address =  reinterpret_cast<int>(param);
	//delete[] param;
	//return reinterpret_cast<int*>(address);
	return param;
}

bool IsNumber(const char in)
{
	if (in >= '0' && in <= '9') return 1;
	else return 0;
}

#endif _VARKEY_H_

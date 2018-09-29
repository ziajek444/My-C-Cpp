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

#endif _VARKEY_H_

#pragma once
// CriptFeatures are use to make cript text debugatable. Adding posibility sum control or bit counter.

#include <stdint.h>
#include <iostream>
#include <string>

using namespace std;

uint8_t BitCounter(unsigned char,const short);
uint8_t BitCounter(const unsigned char*,int, const short);
uint8_t SumControl(const unsigned char *, int);

uint8_t BitCounter(string, const short);
uint8_t SumControl(string);



uint8_t BitCounter(unsigned char single_char, const short type = 1)
{
	if (type > 1 || type < 0) cout<< "Wrong type inputed\n"; //throw "Wrong type inputed";

	uint8_t sum = 0;
	uint8_t mask = 1;
	for (int i = 0; i < 8; i++)
	{
		if ((mask&single_char) == type) sum++;
		single_char >>= 1;
	}
	return sum;
}

uint8_t BitCounter(const unsigned char * str,int len, const short type = 1)
{
	if (len < 1) cout<< "Wrong len inputed\n"; //throw "Wrong len inputed";

	uint8_t sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += BitCounter(str[i], type);
	}

	return sum;
}

uint8_t SumControl(const unsigned char * str, int len)
{
	uint8_t sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += str[i];
	}
	return sum;
}


uint8_t BitCounter(string s, const short type = 1)
{
	int len = s.length();
	if (len < 1) cout << "Wrong len inputed\n"; //throw "Wrong len inputed";

	uint8_t sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += BitCounter(s[i], type);
	}

	return sum;
}

uint8_t SumControl(string s)
{
	uint8_t sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum += s[i];
	}
	return sum;
}


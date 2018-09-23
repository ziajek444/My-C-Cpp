#ifndef _VARKEY_H_
#define _CONSTKEY_H_

#include "stdafx.h"
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

typedef unsigned char uint8_t;

using namespace std;

//uint8_t * ConstKey(int,int);
//uint8_t functionCK(int);
//int silnia (int);

int silnia (int liczba)
{
    if (liczba<2) return liczba;
    return liczba*silnia(liczba-1);
}

uint8_t functionCK(int t)
{
	uint8_t ret=0xFF;

	if(t<25 || t>100)
	{
		ret = silnia(t%5);
		ret = ret * t - t*t + (ret/2);
	}
	else
	{
		ret = silnia(t%10);
		ret = ret + 2*t - 4;
	}
	
    return ret==0 ? ret-1 : ret;
}


uint8_t * ConstKey(int start,int stop)
{
    if (start<0 || stop<=start || stop > 128) cout<<"Wrong input in ConstKey function\n"; //throw "Wrong input in ConstKey function"; //0x00 57 a6 d8
    int Size = (stop-start)+1;
    uint8_t * ret = new uint8_t[Size];
	
    for(int i=0;i<Size;i++)
    {
        ret[i] = functionCK(start++);
    }
	
    return ret;
}

#endif _CONSTKEY_H_
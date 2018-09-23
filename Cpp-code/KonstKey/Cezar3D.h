#ifndef _CEZAR3D_H_
#define _CEZAR3D_H_
#ifndef __uint8_t
typedef unsigned char uint8_t;
#define __uint8_t
#endif __uint8_t

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */
#include <math.h>
#include <string>		/*std::to_string(int); */
#include <random>
#include <algorithm>
#include "ConstKey.h"
#include "VarKey.h"


using namespace std;

bool IsTableUnique(const char*,int);
string Cezar3D_Encrypt(string const &msg_in,char const tab_in[38][76]);
string Cezar3D_Decrypt(string const &msg_in,char const tab_in[38][76]);

const uint8_t signs = 39;
unsigned char starter = 25;
const char Keytab[signs][signs*2] = {
	{starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=26,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=24,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=23,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=22,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=21,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=29,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=28,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=20,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=27,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=26,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=25,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=24,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=21,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=23,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=22,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=21,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=20,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=23,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=22,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=33,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=34,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=33,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=32,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=31,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=30,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=29,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=28,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=27,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=26,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=25,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=24,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=23,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=22,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=21,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=30,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=29,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
	{starter=28,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2,starter+=2},
};


//Add one byte in the begining as start byte, repleace all left bytes form bytes in tables dependency from pervious byte.
string Cezar3D_Encrypt(string const &msg_in,char const tab_in[38][76])//38 254
{
	for(int i =0;i<38;i++)
	{
		if(IsTableUnique(tab_in[i],76)) cout<<"Wrong key, mst be unique\n"; // throw "Wrong key, mst be unique";
	}

	int tab_index = 0; // 0='0' 1 = '1' ... 36='x' 37 = 'z'
	
	std::random_device rd;
	short choice = rd() % 40; //(0:40)
	char tmp=0;
	while(!((tmp>=48 && tmp<=58) || (tmp>=97 && tmp<=122))) tmp = rd() % 123;
	string msg_out = "";
	

	//1 char
	switch(tmp)
	{
		case '0':
			msg_out+= (choice>30) ?  0x12: ((choice>20) ? 0x21 : ((choice>10) ? 0x13 : 0x31 ) )  ;
			break;
		case '1':
			msg_out+= (choice>30) ?  0x14: ((choice>20) ? 0x41 : ((choice>10) ? 0x15 : 0x51 ) )  ;
			tab_index = 1;
			break;
		case '2':
			msg_out+= (choice>30) ?  0x16: ((choice>20) ? 0x61 : ((choice>10) ? 0x17 : 0x71 ) )  ;
			tab_index = 2;
			break;
		case '3':
			msg_out+= (choice>30) ?  0x18: ((choice>20) ? 0x81 : ((choice>10) ? 0x19 : 0x91 ) )  ;
			tab_index = 3;
			break;
		case '4':
			msg_out+= (choice>30) ?  0xFE: ((choice>20) ? 0xEF : ((choice>10) ? 0x1A : 0xA1 ) )  ;
			tab_index = 4;
			break;
		case '5':
			msg_out+= (choice>30) ?  0x1B: ((choice>20) ? 0xB1 : ((choice>10) ? 0x1C : 0xC1 ) )  ;
			tab_index = 5;
			break;
		case '6':
			tab_index = 6;
			msg_out+= (choice>30) ?  0x1D: ((choice>20) ? 0xD1 : ((choice>10) ? 0x1F : 0xF1 ) )  ;
			break;
		case '7':
			tab_index = 7;
			msg_out+= (choice>30) ?  0x20: ((choice>20) ? 0x02 : ((choice>10) ? 0x30 : 0x03 ) )  ;
			break;
		case '8':
			tab_index = 8;
			msg_out+= (choice>30) ?  0x40: ((choice>20) ? 0x04 : ((choice>10) ? 0x50 : 0x05 ) )  ;
			break;
		case '9':
			tab_index = 9;
			msg_out+= (choice>30) ?  0x60: ((choice>20) ? 0x06 : ((choice>10) ? 0x70 : 0x07 ) )  ;
			break;
		case ':':
			tab_index = 10;
			msg_out+= (choice>30) ?  0x80: ((choice>20) ? 0x08: ((choice>10) ? 0x90 : 0x09 ) )  ;
			break;
		case ';':
			tab_index = 11;
			msg_out+= (choice>30) ?  0xA0: ((choice>20) ? 0x0A : ((choice>10) ? 0xB0 : 0x0B ) )  ;
			break;
		case 'a':
			tab_index = 12;
			msg_out+= (choice>30) ?  0xC0: ((choice>20) ? 0x0C : ((choice>10) ? 0xD0 : 0x0D ) )  ;
			break;
		case 'b':
			tab_index = 13;
			msg_out+= (choice>30) ?  0xE0: ((choice>20) ? 0x0E : ((choice>10) ? 0xF0 : 0x0F ) )  ;
			break;
		case 'c':
			tab_index = 14;
			msg_out+= (choice>30) ?  0x23: ((choice>20) ? 0x32 : ((choice>10) ? 0x24 : 0x42 ) )  ;
			break;
		case 'd':
			tab_index = 15;
			msg_out+= (choice>30) ?  0x25: ((choice>20) ? 0x52 : ((choice>10) ? 0x26 : 0x62 ) )  ;
			break;
		case 'e':
			tab_index = 16;
			msg_out+= (choice>30) ?  0x27: ((choice>20) ? 0x72 : ((choice>10) ? 0x28 : 0x82 ) )  ;
			break;
		case 'f':
			tab_index = 17;
			msg_out+= (choice>30) ?  0x29: ((choice>20) ? 0x92 : ((choice>10) ? 0x2A : 0xA2 ) )  ;
			break;
		case 'g':
			tab_index = 18;
			msg_out+= (choice>30) ?  0x2B: ((choice>20) ? 0xB2 : ((choice>10) ? 0x2C : 0xC2 ) )  ;
			break;
		case 'h':
			tab_index = 19;
			msg_out+= (choice>30) ?  0x2D: ((choice>20) ? 0xD2 : ((choice>10) ? 0x2E : 0xE2 ) )  ;
			break;
		case 'i':
			tab_index = 20;
			msg_out+= (choice>30) ?  0x2F: ((choice>20) ? 0xF2 : ((choice>10) ? 0x34 : 0x43 ) )  ;
			break;
		case 'j':
			tab_index = 21;
			msg_out+= (choice>30) ?  0x35: ((choice>20) ? 0x53 : ((choice>10) ? 0x36 : 0x63 ) )  ;
			break;
		case 'k':
			tab_index = 22;
			msg_out+= (choice>30) ?  0x37: ((choice>20) ? 0x73 : ((choice>10) ? 0x38 : 0x83 ) )  ;
			break;
		case 'l':
			tab_index = 23;
			msg_out+= (choice>30) ?  0x39: ((choice>20) ? 0x93 : ((choice>10) ? 0xA3 : 0x3A ) )  ;
			break;
		case 'm':
			tab_index = 24;
			msg_out+= (choice>30) ?  0x3B: ((choice>20) ? 0xB3 : ((choice>10) ? 0x3C : 0xC3 ) )  ;
			break;
		case 'n':
			tab_index = 25;
			msg_out+= (choice>30) ?  0xE3: ((choice>20) ? 0x3E : ((choice>10) ? 0xF3 : 0x3F ) )  ;
			break;
		case 'o':
			tab_index = 26;
			msg_out+= (choice>30) ?  0x45: ((choice>20) ? 0x54 : ((choice>10) ? 0x46 : 0x64 ) )  ;
			break;
		case 'p':
			tab_index = 27;
			msg_out+= (choice>30) ?  0x47: ((choice>20) ? 0x74 : ((choice>10) ? 0x84 : 0x48 ) )  ;
			break;
		case 'q':
			tab_index = 28;
			msg_out+= (choice>30) ?  0x49: ((choice>20) ? 0x94 : ((choice>10) ? 0x4A : 0xA4 ) )  ;
			break;
		case 'r':
			tab_index = 29;
			msg_out+= (choice>30) ?  0x4B: ((choice>20) ? 0xB4 : ((choice>10) ? 0x4C : 0xC4 ) )  ;
			break;
		case 's':
			tab_index = 30;
			msg_out+= (choice>30) ?  0x4D: ((choice>20) ? 0xD4 : ((choice>10) ? 0x4E : 0xE4 ) )  ;
			break;
		case 't':
			tab_index = 31;
			msg_out+= (choice>30) ?  0x4F: ((choice>20) ? 0xF4 : ((choice>10) ? 0x56 : 0x65 ) )  ;
			break;
		case 'u':
			tab_index = 32;
			msg_out+= (choice>30) ?  0x57: ((choice>20) ? 0x75 : ((choice>10) ? 0x58 : 0x85 ) )  ;
			break;
		case 'v':
			tab_index = 33;
			msg_out+= (choice>30) ?  0x59: ((choice>20) ? 0x95 : ((choice>10) ? 0x5A : 0xA5 ) )  ;
			break;
		case 'w':
			tab_index = 34;
			msg_out+= (choice>30) ?  0x5B: ((choice>20) ? 0xB5 : ((choice>10) ? 0x5C : 0xC5 ) )  ;
			break;
		case 'x':
			tab_index = 35;
			msg_out+= (choice>30) ?  0x5D: ((choice>20) ? 0xD5 : ((choice>10) ? 0x5E : 0xE5 ) )  ;
			break;
		case 'y':
			tab_index = 36;
			msg_out+= (choice>30) ?  0x5F: ((choice>20) ? 0xF5 : ((choice>10) ? 0x67 : 0x76 ) )  ;
			break;
		case 'z':
			tab_index = 37;
			msg_out+= (choice>30) ?  0x68: ((choice>20) ? 0x86 : ((choice>10) ? 0x69 : 0x96 ) )  ;
			break;
		default:
			cout<<"wrong input data #3 \nSchould be 0:9 or a:z or # or <\n";
			//throw "wrong input data\nSchould be 0:9 or a:z or # or <";
			break;
	}

	for(char n : msg_in)
	{
		choice = rd() % 40; //(0:40)
		switch(n)
		{
			case '0':
				msg_out+= (choice>20) ?  tab_in[tab_index][0] : tab_in[tab_index][1];
				tab_index = 0;
				break;
			case '1':
				msg_out+= (choice>20) ?  tab_in[tab_index][2] : tab_in[tab_index][3];
				tab_index = 1;
				break;
			case '2':
				msg_out+= (choice>20) ?  tab_in[tab_index][4] : tab_in[tab_index][5];
				tab_index = 2;
				break;
			case '3':
				msg_out+= (choice>20) ?  tab_in[tab_index][6] : tab_in[tab_index][7];
				tab_index = 3;
				break;
			case '4':
				msg_out+= (choice>20) ?  tab_in[tab_index][8] : tab_in[tab_index][9];
				tab_index = 4;
				break;
			case '5':
				msg_out+= (choice>20) ?  tab_in[tab_index][10] : tab_in[tab_index][11];
				tab_index = 5;
				break;
			case '6':
				msg_out+= (choice>20) ?  tab_in[tab_index][12] : tab_in[tab_index][13];
				tab_index = 6;
				break;
			case '7':
				msg_out+= (choice>20) ?  tab_in[tab_index][14] : tab_in[tab_index][15];
				tab_index = 7;
				break;
			case '8':
				msg_out+= (choice>20) ?  tab_in[tab_index][16] : tab_in[tab_index][17];
				tab_index = 8;
				break;
			case '9':
				msg_out+= (choice>20) ?  tab_in[tab_index][18] : tab_in[tab_index][19];
				tab_index = 9;
				break;
			case ':':
				msg_out+= (choice>20) ?  tab_in[tab_index][20] : tab_in[tab_index][21];
				tab_index = 10;
				break;
			case ';':
				msg_out+= (choice>20) ?  tab_in[tab_index][22] : tab_in[tab_index][23];
				tab_index = 11;
				break;
			case 'a':
				msg_out+= (choice>20) ?  tab_in[tab_index][24] : tab_in[tab_index][25];
				tab_index = 12;
				break;
			case 'b':
				msg_out+= (choice>20) ?  tab_in[tab_index][26] : tab_in[tab_index][27];
				tab_index = 13;
				break;
			case 'c':
				msg_out+= (choice>20) ?  tab_in[tab_index][28] : tab_in[tab_index][29];
				tab_index = 14;
				break;
			case 'd':
				msg_out+= (choice>20) ?  tab_in[tab_index][30] : tab_in[tab_index][31];
				tab_index = 15;
				break;
			case 'e':
				msg_out+= (choice>20) ?  tab_in[tab_index][32] : tab_in[tab_index][33];
				tab_index = 16;
				break;
			case 'f':
				msg_out+= (choice>20) ?  tab_in[tab_index][34] : tab_in[tab_index][35];
				tab_index = 17;
				break;
			case 'g':
				msg_out+= (choice>20) ?  tab_in[tab_index][36] : tab_in[tab_index][37];
				tab_index = 18;
				break;
			case 'h':
				msg_out+= (choice>20) ?  tab_in[tab_index][38] : tab_in[tab_index][39];
				tab_index = 19;
				break;
			case 'i':
				msg_out+= (choice>20) ?  tab_in[tab_index][40] : tab_in[tab_index][41];
				tab_index = 20;
				break;
			case 'j':
				msg_out+= (choice>20) ?  tab_in[tab_index][42] : tab_in[tab_index][43];
				tab_index = 21;
				break;
			case 'k':
				msg_out+= (choice>20) ?  tab_in[tab_index][44] : tab_in[tab_index][45];
				tab_index = 22;
				break;
			case 'l':
				msg_out+= (choice>20) ?  tab_in[tab_index][46] : tab_in[tab_index][47];
				tab_index = 23;
				break;
			case 'm':
				msg_out+= (choice>20) ?  tab_in[tab_index][48] : tab_in[tab_index][49];
				tab_index = 24;
				break;
			case 'n':
				msg_out+= (choice>20) ?  tab_in[tab_index][50] : tab_in[tab_index][51];
				tab_index = 25;
				break;
			case 'o':
				msg_out+= (choice>20) ?  tab_in[tab_index][52] : tab_in[tab_index][53];
				tab_index = 26;
				break;
			case 'p':
				msg_out+= (choice>20) ?  tab_in[tab_index][54] : tab_in[tab_index][55];
				tab_index = 27;
				break;
			case 'q':
				msg_out+= (choice>20) ?  tab_in[tab_index][56] : tab_in[tab_index][57];
				tab_index = 28;
				break;
			case 'r':
				msg_out+= (choice>20) ?  tab_in[tab_index][58] : tab_in[tab_index][59];
				tab_index = 29;
				break;
			case 's':
				msg_out+= (choice>20) ?  tab_in[tab_index][60] : tab_in[tab_index][61];
				tab_index = 30;
				break;
			case 't':
				msg_out+= (choice>20) ?  tab_in[tab_index][62] : tab_in[tab_index][63];
				tab_index = 31;
				break;
			case 'u':
				msg_out+= (choice>20) ?  tab_in[tab_index][64] : tab_in[tab_index][65];
				tab_index = 32;
				break;
			case 'v':
				msg_out+= (choice>20) ?  tab_in[tab_index][66] : tab_in[tab_index][67];
				tab_index = 33;
				break;
			case 'w':
				msg_out+= (choice>20) ?  tab_in[tab_index][68] : tab_in[tab_index][69];
				tab_index = 34;
				break;
			case 'x':
				msg_out+= (choice>20) ?  tab_in[tab_index][70] : tab_in[tab_index][71];
				tab_index = 35;
				break;
			case 'y':
				msg_out+= (choice>20) ?  tab_in[tab_index][72] : tab_in[tab_index][73];
				tab_index = 36;
				break;
			case 'z':
				msg_out+= (choice>20) ?  tab_in[tab_index][74] : tab_in[tab_index][75];
				tab_index = 37;
				break;
			default:
				cout<<"wrong input data #1 \nSchould be 0:9 or a:z or # or <\n";
				//throw "wrong input data\nSchould be 0:9 or a:z or # or <";
				break;
		}
	}

	return msg_out;
}

string Cezar3D_Decrypt(string const &msg_in,char const tab_in[38][76])
{
	int tab_index = 0; // 0='0' 1 = '1' ... 36='x' 37 = 'z'
	
	//string msg_out = msg_in;
	string msg_out;

	//1 char
	switch((msg_in[0]&0xFF))
	{
		case 0x12:
		case 0x21:
		case 0x13:
		case 0x31:
			//msg_out.replace(0,  1,  1, '0');
			break;
		case 0x14:
		case 0x41:
		case 0x15:
		case 0x51:
			//msg_out.replace(0,  1,  1, '1');
			tab_index = 1;
			break;
		case 0x16:
		case 0x61:
		case 0x17:
		case 0x71:
			//msg_out.replace(0,  1,  1, '2');
			tab_index = 2;
			break;
		case 0x18:
		case 0x81:
		case 0x19:
		case 0x91:
			//msg_out.replace(0,  1,  1, '3');
			tab_index = 3;
			break;
		case 0xFE:
		case 0xEF:
		case 0x1A:
		case 0xA1:
			//msg_out.replace(0,  1,  1, '4');
			tab_index = 4;
			break;
		case 0x1B:
		case 0xB1:
		case 0x1C:
		case 0xC1:
			//msg_out+= '5';
			tab_index = 5;
			break;
		case 0x1D:
		case 0xD1:
		case 0x1F:
		case 0xF1:
			tab_index = 6;
			//msg_out+= '6';
			break;
		case 0x20:
		case 0x02:
		case 0x30:
		case 0x03:
			tab_index = 7;
			//msg_out+= '7';
			break;
		case 0x40:
		case 0x04:
		case 0x50:
		case 0x05:
			tab_index = 8;
			//msg_out+= '8';
			break;
		case 0x60:
		case 0x06:
		case 0x70:
		case 0x07:
			tab_index = 9;
			//msg_out+= '9';
			break;
		case 0x80:
		case 0x08:
		case 0x90:
		case 0x09:
			tab_index = 10;
			//msg_out+= ':';
			break;
		case 0xA0:
		case 0x0A:
		case 0xB0:
		case 0x0B:
			tab_index = 11;
			//msg_out+= ';';
			break;
		case 0xC0:
		case 0x0C:
		case 0xD0:
		case 0x0D:
			tab_index = 12;
			//msg_out+= 'a';
			break;
		case 0xE0:
		case 0x0E:
		case 0xF0:
		case 0x0F:
			tab_index = 13;
			//msg_out+= 'b';
			break;
		case 0x23:
		case 0x32:
		case 0x24:
		case 0x42:
			tab_index = 14;
			//msg_out+= 'c' ;
			break;
		case 0x25:
		case 0x52:
		case 0x26:
		case 0x62:
			tab_index = 15;
			//msg_out+= 'd' ;
			break;
		case 0x27:
		case 0x72:
		case 0x28:
		case 0x82:
			tab_index = 16;
			//msg_out+='e' ;
			break;
		case 0x29:
		case 0x92:
		case 0x2A:
		case 0xA2:
			tab_index = 17;
			//msg_out+= 'f';
			break;
		case 0x2B:
		case 0xB2:
		case 0x2C:
		case 0xC2:
			tab_index = 18;
			//msg_out+='g' ;
			break;
		case 0x2D:
		case 0xD2:
		case 0x2E:
		case 0xE2:
			tab_index = 19;
			//msg_out+= 'h' ;
			break;
		case 0x2F:
		case 0xF2:
		case 0x34:
		case 0x43:
			tab_index = 20;
			//msg_out+= 'i';
			break;
		case 0x35:
		case 0x53:
		case 0x36:
		case 0x63:
			tab_index = 21;
			//msg_out+= 'j';
			break;
		case 0x37:
		case 0x73:
		case 0x38:
		case 0x83:
			tab_index = 22;
			//msg_out+= 'k';
			break;
		case 0x39:
		case 0x93:
		case 0xA3:
		case 0x3A:
			tab_index = 23;
			//msg_out+= 'l';
			break;
		case 0x3B:
		case 0xB3:
		case 0x3C:
		case 0xC3:
			tab_index = 24;
			//msg_out+= 'm'  ;
			break;
		case 0xE3:
		case 0x3E:
		case 0xF3:
		case 0x3F:
			tab_index = 25;
			//msg_out+= 'n' ;
			break;
		case 0x45:
		case 0x54:
		case 0x46:
		case 0x64:
			tab_index = 26;
			//msg_out+= 'o';
			break;
		case 0x47:
		case 0x74:
		case 0x84:
		case 0x48:
			tab_index = 27;
			//msg_out+= 'p';
			break;
		case 0x49:
		case 0x94:
		case 0x4A:
		case 0xA4:
			tab_index = 28;
			//msg_out+= 'q'  ;
			break;
		case 0x4B:
		case 0xB4:
		case 0x4C:
		case 0xC4:
			tab_index = 29;
			//msg_out+= 'r';
			break;
		case 0x4D:
		case 0xD4:
		case 0x4E:
		case 0xE4:
			tab_index = 30;
			//msg_out+= 's' ;
			break;
		case 0x4F:
		case 0xF4:
		case 0x56:
		case 0x65:
			tab_index = 31;
			//msg_out+= 't' ;
			break;
		case 0x57:
		case 0x75:
		case 0x58:
		case 0x85:
			tab_index = 32;
			//msg_out+= 'u' ;
			break;
		case 0x59:
		case 0x95:
		case 0x5A:
		case 0xA5:
			tab_index = 33;
			//msg_out+= 'v'  ;
			break;
		case 0x5B:
		case 0xB5:
		case 0x5C:
		case 0xC5:
			tab_index = 34;
			//msg_out+= 'w'  ;
			break;
		case 0x5D:
		case 0xD5:
		case 0x5E:
		case 0xE5:
			tab_index = 35;
			//msg_out+= 'x';
			break;
		case 0x5F:
		case 0xF5:
		case 0x67:
		case 0x76:
			tab_index = 36;
			//msg_out+= 'y' ;
			break;
		case 0x68:
		case 0x86:
		case 0x69:
		case 0x96:
			tab_index = 37;
			//msg_out+= 'z';
			break;
		default:
			cout<<"wrong input data #2 \n{"<<msg_in[0]<<"}\n"<<"int_{"<<hex<<(unsigned int)(msg_in[0]&0xFF)<<"}\n";
			//throw "wrong input data 3#";
			break;
	}

	msg_out = msg_in.substr(1);

	int pos = -1;
	string s_temp = "";
	int i = 0;

	for(char n : msg_out)
	{
		s_temp = "";
		for(int n=0;n<254;n++) s_temp+=tab_in[tab_index][n];
		pos = s_temp.find(n);

		if(pos != (-1))
		{
			switch(pos)
			{
				case 0:
				case 1:
					msg_out.replace(i,  1,  1, '0');
					tab_index=0;
					break;
				case 2:
				case 3:
					msg_out.replace(i,  1,  1, '1');
					tab_index=1;
					break;
				case 4:
				case 5:
					msg_out.replace(i,  1,  1, '2');
					tab_index=2;
					break;
				case 6:
				case 7:
					msg_out.replace(i,  1,  1, '3');
					tab_index=3;
					break;
				case 8:
				case 9:
					msg_out.replace(i,  1,  1, '4');
					tab_index=4;
					break;
				case 10:
				case 11:
					msg_out.replace(i,  1,  1, '5');
					tab_index=5;
					break;
				case 12:
				case 13:
					msg_out.replace(i,  1,  1, '6');
					tab_index=6;
					break;
				case 14:
				case 15:
					msg_out.replace(i,  1,  1, '7');
					tab_index=7;
					break;
				case 16:
				case 17:
					msg_out.replace(i,  1,  1, '8');
					tab_index=8;
					break;
				case 18:
				case 19:
					msg_out.replace(i,  1,  1, '9');
					tab_index=9;
					break;
				case 20:
				case 21:
					msg_out.replace(i,  1,  1, ':');
					tab_index=10;
					break;
				case 22:
				case 23:
					msg_out.replace(i,  1,  1, ';');
					tab_index=11;
					break;
				case 24:
				case 25:
					msg_out.replace(i,  1,  1, 'a');
					tab_index=12;
					break;
				case 26:
				case 27:
					msg_out.replace(i,  1,  1, 'b');
					tab_index=13;
					break;
				case 28:
				case 29:
					msg_out.replace(i,  1,  1, 'c');
					tab_index=14;
					break;
				case 30:
				case 31:
					msg_out.replace(i,  1,  1, 'd');
					tab_index=15;
					break;
				case 32:
				case 33:
					msg_out.replace(i,  1,  1, 'e');
					tab_index=16;
					break;
				case 34:
				case 35:
					msg_out.replace(i,  1,  1, 'f');
					tab_index=17;
					break;
				case 36:
				case 37:
					msg_out.replace(i,  1,  1, 'g');
					tab_index=18;
					break;
				case 38:
				case 39:
					msg_out.replace(i,  1,  1, 'h');
					tab_index=19;
					break;
				case 40:
				case 41:
					msg_out.replace(i,  1,  1, 'i');
					tab_index=20;
					break;
				case 42:
				case 43:
					msg_out.replace(i,  1,  1, 'j');
					tab_index=21;
					break;
				case 44:
				case 45:
					msg_out.replace(i,  1,  1, 'k');
					tab_index=22;
					break;
				case 46:
				case 47:
					msg_out.replace(i,  1,  1, 'l');
					tab_index=23;
					break;
				case 48:
				case 49:
					msg_out.replace(i,  1,  1, 'm');
					tab_index=24;
					break;
				case 50:
				case 51:
					msg_out.replace(i,  1,  1, 'n');
					tab_index=25;
					break;
				case 52:
				case 53:
					msg_out.replace(i,  1,  1, 'o');
					tab_index=26;
					break;
				case 54:
				case 55:
					msg_out.replace(i,  1,  1, 'p');
					tab_index=27;
				case 56:
				case 57:
					msg_out.replace(i,  1,  1, 'q');
					tab_index=28;
					break;
				case 58:
				case 59:
					msg_out.replace(i,  1,  1, 'r');
					tab_index=29;
					break;
				case 60:
				case 61:
					msg_out.replace(i,  1,  1, 's');
					tab_index=30;
					break;
				case 62:
				case 63:
					msg_out.replace(i,  1,  1, 't');
					tab_index=31;
					break;
				case 64:
				case 65:
					msg_out.replace(i,  1,  1, 'u');
					tab_index=32;
					break;
				case 66:
				case 67:
					msg_out.replace(i,  1,  1, 'v');
					tab_index=33;
					break;
				case 68:
				case 69:
					msg_out.replace(i,  1,  1, 'w');
					tab_index=34;
					break;
				case 70:
				case 71:
					msg_out.replace(i,  1,  1, 'x');
					tab_index=35;
					break;
				case 72:
				case 73:
					msg_out.replace(i,  1,  1, 'y');
					tab_index=36;
					break;
				case 74:
				case 75:
					msg_out.replace(i,  1,  1, 'z');
					tab_index=37;
					break;
				default:
					cout<<"Not correct calculate\n";
			}
		}

		i++;
	}

	

	return msg_out;
}

/// 0 = uniqoe, 1 = not unique, 
bool IsTableUnique(const char * table,int length)
{
	bool ret = 0;
	//string s_tmp ="";
	//for(int i=0;i<length;i++) s_tmp+=table[i];
	int amount=0;
	for(int i=0;i<length;i++)
	{
		//amount = count(s_tmp.begin(),s_tmp.end() ,s_tmp[i]);
		amount = count(table,&table[length] ,table[i]);
		if(amount != 1) { ret = 1; cout<<"Fail: "<<i<<".\n"; }
	}
	return ret;
}

#endif _CEZAR3D_H_

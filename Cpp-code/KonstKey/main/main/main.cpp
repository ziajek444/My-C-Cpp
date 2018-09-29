// KonstKey.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
//#include "pch.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */
#include <math.h>
#include <string>		/*std::to_string(int); */
#include <random>
#include "ConstKey.h"
#include "VarKey.h"
#include "Cezar3d.h"
#include "CriptFeatures.h"

#ifndef __uint8_t
typedef unsigned char uint8_t;
#define __uint8_t
#endif __uint8_t

using namespace std;

int main()
{

	//string text = "ash512";
    //string cezar = Cezar3D_Encrypt(text,c3d::KEYTAB);
	//string decode = Cezar3D_Decrypt(cezar, c3d::KEYTAB);
	//cout << "text: " << text << "\ncezar: " << cezar<<"\ndecrypt: "<<decode<<"\n";


	string gogo = iCezar3D_Encrypt("abcadlo", c3d::KEYTAB, 10);
	string gogo2 = iCezar3D_Decrypt(gogo, c3d::KEYTAB, 10);
	cout << "abcadlo\n" << gogo << "\n" << gogo2 << endl;
	
	cout << "FIN" << endl;

	cin.get();
    return 0;
}


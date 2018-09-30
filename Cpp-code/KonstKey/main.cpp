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
#include "TextC3D.h"

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


	//string gogo = iCezar3D_Encrypt("abcadlo", c3d::KEYTAB, 10);
	//string gogo2 = iCezar3D_Decrypt(gogo, c3d::KEYTAB, 10);
	//cout << "abcadlo\n" << gogo << "\n" << gogo2 << endl;
	
	//string TEST = textToC3D("< > : 0 1 2 3 <3 d ¹ i");
	//cout << "< > : 0 1 2 3 <3 d ¹ i : " << TEST << endl;

	//cout << "Ambrerro hu³a³a i mam te¿ ¹ :D #$%^&*()\n";
	//string TEST1 = textToC3D("Ambrerro hu³a³a i mam te¿ ¹ :D #$%^&*()");
	//cout << TEST1 << "\n";
	//string TEST2 = c3dToText(TEST1);
	//cout << TEST2 << endl;

	cout << "Tajny tekst haha !@# .\n";
	string TEST1 = itextToC3D("Tajny tekst haha !@# .");
	cout << TEST1 << "\n";
	cout << "\n";
	string TEST2 = ic3dToText(TEST1);
	cout << TEST2 << "\n";

	cout<<"First parameters updated: "<<FirstParameters() << endl;

	//wyglad jak bym skonczyl :D


	cout << "FIN" << endl;

	cin.get();
    return 0;
}


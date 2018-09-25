// KonstKey.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include "pch.h"
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
    cout << "Hello world!" << endl;
/*
    uint8_t wiadomosc[] = "alba";
	uint8_t * U;
    U = ConstKey(1,128);
	uint8_t s = (128-1)+1;
	for(int i=0;i<s;i++) cout<<i<<": ["<<(int)U[i]<<"]\n";
	for(int i=0;i<s;i++) cout<<"["<<U[i]<<"]";
	cout<<endl;
	delete U;

	//tworzenie randomowych liczb kt�re bed� parametrami "123.234.45.6.456"
	//doda� sum� kontroln� "123.234.45.6.456.99"
	//dodac znaki koncz�ce (wypelniajace braki) �eby wiadomosc zawsze miala stala d�ugo��
	//zapisanie ich jako Cezar 3D (Cezar->znak+x) (Cezar tablicowy->[znak1 to znak2][znak2 to znak3][znakN to znak(N+1) ] )
	// (Cezar macierzowy -> znak1 to znak2 lub znak3 lub znak4 ...)
	// Cezar 3D to Cezar macierzowy dla pierwszego znaku, CM->znak1, na podstawie wyboru znaku zast�pczego dla nast�pnego znaku rozkodowywanego
	// wybierana jest kolejna inna macierz wyboru dla znak�w.
	//na�o�y� klucz statyczny (ConstKey)
	//Gotowe mozna wysylac
	//sprawdzic czy wiadomosc ma odp. d�ugo��.
	//sci�gn�� klucz ststyczny ~(ConstKey)
	//rozszyfrowac cezara (Cezar 3D mo�na debugowa�, sprawdzi� czy nast�pny znak jest w og�le dopuszczalny)
	// ka�dy znak a:z i 0:9 i # to 38 znak�w. mog� mie� maksymalnie 6 mo�liwo�ci i 0 oraz 255 s� zakazane.
	//sprawdzic poprawnosc wiadomosci: czy s� wszystkie paramtetry, czy maj� odpowiedni rozmiar, czy s� same liczby i #, czy jest suma kontrolna
	//zsumowac wiadomosc i por�wnac z suma kontroln�
	//jezeli wszystko przebieg�o bez b��d�w stworzyc klucz na podstawie parametrow podanych w wiadomosci

	char KEYTAB_own[39][39 * 2];
	for (int i = 0; i < 39; i++) MakeTableUnique(KEYTAB_own[i], 39 * 2);

	string heja;
	heja = Cezar3D_Encrypt("abcdd",c3d::KEYTAB);
	cout<<heja<<"\n";
	string ho;
	ho = Cezar3D_Decrypt(heja, c3d::KEYTAB);
	cout<<ho<<"\n";

	char tab2[20];
	MakeTableUnique(tab2, 254);
	cout << endl;
	for (int i = 0; i < 254; i++) cout << "{" << (unsigned short)(tab2[i]&0xFF) << "}";
	cout << "\n\nhere: " << IsTableUnique(tab2, 254) << endl; */


	string text = "ash512";
    string cezar = Cezar3D_Encrypt(text,c3d::KEYTAB);
    
	string decode = Cezar3D_Decrypt(cezar, c3d::KEYTAB);
	cout << "text: " << text << "\ncezar: " << cezar<<"\ndecrypt: "<<decode<<"\n";

	uint8_t *able;
	able = new uint8_t[2];
	able[0] = 0x01;
	able[1] = 0x10;
	uint8_t sum = 0;
	uint8_t mask = 1;
	cout << (int)BitCounter(able,2,0) << endl;
	

	cin.get();
    return 0;
}


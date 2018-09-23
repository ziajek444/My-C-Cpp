// KonstKey.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */
#include <math.h>
#include <string>		/*std::to_string(int); */
#include <random>
#include "ConstKey.h"
#include "VarKey.h"
#include "Cezar3D.h"

#ifndef __uint8_t
typedef unsigned char uint8_t;
#define __uint8_t
#endif __uint8_t

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    uint8_t wiadomosc[] = "alba";
	uint8_t * U;
    U = ConstKey(1,128);
	uint8_t s = (128-1)+1;
	for(int i=0;i<s;i++) cout<<i<<": ["<<(int)U[i]<<"]\n";
	for(int i=0;i<s;i++) cout<<"["<<U[i]<<"]";
	cout<<endl;
	delete U;


	//tworzenie randomowych liczb które bed¹ parametrami "123.234.45.6.456"

	//dodaæ sumê kontroln¹ "123.234.45.6.456.99"

	//dodac znaki koncz¹ce (wypelniajace braki) ¿eby wiadomosc zawsze miala stala d³ugoœæ

	//zapisanie ich jako Cezar 3D (Cezar->znak+x) (Cezar tablicowy->[znak1 to znak2][znak2 to znak3][znakN to znak(N+1) ] )
	// (Cezar macierzowy -> znak1 to znak2 lub znak3 lub znak4 ...)
	// Cezar 3D to Cezar macierzowy dla pierwszego znaku, CM->znak1, na podstawie wyboru znaku zastêpczego dla nastêpnego znaku rozkodowywanego
	// wybierana jest kolejna inna macierz wyboru dla znaków. 

	//na³o¿yæ klucz statyczny (ConstKey)

	//Gotowe mozna wysylac

	//sprawdzic czy wiadomosc ma odp. d³ugoœæ.

	//sci¹gn¹æ klucz ststyczny ~(ConstKey)

	//rozszyfrowac cezara (Cezar 3D mo¿na debugowaæ, sprawdziæ czy nastêpny znak jest w ogóle dopuszczalny)
	// ka¿dy znak a:z i 0:9 i # to 38 znaków. mog¹ mieæ maksymalnie 6 mo¿liwoœci i 0 oraz 255 s¹ zakazane. 

	//sprawdzic poprawnosc wiadomosci: czy s¹ wszystkie paramtetry, czy maj¹ odpowiedni rozmiar, czy s¹ same liczby i #, czy jest suma kontrolna

	//zsumowac wiadomosc i porównac z suma kontroln¹ 

	//jezeli wszystko przebieg³o bez b³êdów stworzyc klucz na podstawie parametrow podanych w wiadomosci
	
	
	

	string heja;
	heja = Cezar3D_Encrypt("abcdd",Keytab);
	cout<<heja<<"\n";
	string ho;
	ho = Cezar3D_Decrypt(heja,Keytab);
	cout<<ho<<"\n";

	cin.get();
    return 0;
}


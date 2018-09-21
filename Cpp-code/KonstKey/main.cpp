// KonstKey.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"


#include <iostream>

using namespace std;
typedef unsigned char uint8_t;

uint8_t * ConstKey(int,int);
uint8_t functionCK(int);
int silnia (int);


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
	
	//tworzenie randomowych liczb które bedą parametrami "123.234.45.6.456"

	//dodać sumę kontrolną "123.234.45.6.456.99"

	//dodac znaki konczące (wypelniajace braki) żeby wiadomosc zawsze miala stala długość

	//zapisanie ich jako Cezar 3D (Cezar->znak+x) (Cezar tablicowy->[znak1 to znak2][znak2 to znak3][znakN to znak(N+1) ] )
	// (Cezar macierzowy -> znak1 to znak2 lub znak3 lub znak4 ...)
	// Cezar 3D to Cezar macierzowy dla pierwszego znaku, CM->znak1, na podstawie wyboru znaku zastępczego dla następnego znaku rozkodowywanego
	// wybierana jest kolejna inna macierz wyboru dla znaków. 

	//nałożyć klucz statyczny (ConstKey)

	//Gotowe mozna wysylac

	//sprawdzic czy wiadomosc ma odp. długość.

	//sciągnąć klucz ststyczny ~(ConstKey)

	//rozszyfrowac cezara (Cezar 3D można debugować, sprawdzić czy następny znak jest w ogóle dopuszczalny)
	// każdy znak a:z i 0:9 i # to 38 znaków. mogą mieć maksymalnie 6 możliwości i 0 oraz 255 są zakazane. 

	//sprawdzic poprawnosc wiadomosci: czy są wszystkie paramtetry, czy mają odpowiedni rozmiar, czy są same liczby i #, czy jest suma kontrolna

	//zsumowac wiadomosc i porównac z suma kontrolną 

	//jezeli wszystko przebiegło bez błędów stworzyc klucz na podstawie parametrow podanych w wiadomosci


	cin.get();
    return 0;
}

uint8_t * ConstKey(int start,int stop)
{
    if (start<0 || stop<=start || stop > 128) throw "Wrong input in ConstKey function"; //0x00 57 a6 d8
    int Size = (stop-start)+1;
    uint8_t * ret = new uint8_t[Size];
	
    for(int i=0;i<Size;i++)
    {
        ret[i] = functionCK(start++);
    }
	
    return ret;
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


int silnia (int liczba)
{
    if (liczba<2) return liczba;
    return liczba*silnia(liczba-1);
}


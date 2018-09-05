#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello World\n\n";
   

    int arr[5] = {1, 2, 4, 8, 16};
    int arr_temp[2] = {0,1};
    
    
    int * iptr1 = arr + 2;              // rw value + r addres
    cout<<++*++iptr1<<endl;             //arr[2+1]+1 // 8+1 = 9
    iptr1 = arr_temp;                   // allow change addres
    
    const int * iptr2 = arr + 2;        // r value + rw addres
    cout<<*++iptr2<<endl;               //arr[2+1] // 9
    iptr2 = arr_temp;                   // allow change addres

    int * const iptr3 = arr + 2;        // rw value + r addres
    cout<<++*iptr3<<endl;               //arr[2]+1 // 4+1 = 5
    //iptr3 = arr_temp;                 // forbiden change addres
    
    const int * const iptr4 = arr + 2;  // r value + r addres
    cout<<*iptr4<<endl;                 //arr[2] // 5
    //iptr4 = arr_temp;                 // forbiden change addres

    return 0;
}
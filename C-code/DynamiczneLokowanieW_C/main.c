#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main()
{
    printf("Hello world!\n");
    printf("Deklaracja Dynamiczna zmiennej A_ptr\n");
    int *A_ptr = (int*) calloc(1,sizeof(int));
    printf("A_ptr Adres wskazywany: %d\n",A_ptr);

    printf("Deklaracja Statyczna zmiennej a\n");
    int a = 5;
    printf("a Adres zmiennej: %d\n",&a);

    printf("Deklaracja Dynamiczna zmiennej B_ptr\n");
    int *B_ptr = (int*) calloc(1,sizeof(int));
    printf("A_ptr Adres wskazywany: %d\n",B_ptr);


    printf("Wedlug mnie Vektoryzacja wskaznika A_ptr\n");
    A_ptr = (int*) realloc(A_ptr,16*sizeof(int));
    printf("A_ptr Adres wskazywany: %d\n",A_ptr);

    getch();

    return 0;
}

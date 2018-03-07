#include <stdio.h>
#include <stdlib.h>





int main(int amount,char * content[])
{
char charVar=254;
int intVar=0;
short int sintVar=0;
long int lintVar=0L;
unsigned char ucharVar=0;
unsigned int uintVar=0;
float fVar=0;
/* ISO c90 does not support 'long long' */
long long llVar=0LL; /* long long int */
unsigned long long ullVar=0ULL; /* unsigned long long int */

printf("Bytes (charVar): %d\n",sizeof(charVar));
printf("Bytes (intVar): %d\n",sizeof(intVar));
printf("Bytes (sintVar): %d\n",sizeof(sintVar));
printf("Bytes (lintVar): %d\n",sizeof(lintVar));
printf("Bytes (ucharVar): %d\n",sizeof(ucharVar));
printf("Bytes (uintVar): %d\n",sizeof(uintVar));
printf("Bytes (fVar): %d\n",sizeof(fVar));
printf("Bytes (llVar): %d\n",sizeof(llVar));
printf("Bytes (ullVar): %d\n",sizeof(ullVar));

/* Execute really long long time :D */
/* while(llVar<1234567890) { printf("%d, ",llVar); llVar++;} */


return 0;
}

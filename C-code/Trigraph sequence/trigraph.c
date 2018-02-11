/*Trigraph Sequences*/
/*
There can occurred the warrning,
trigraph ignored,
U have to use -trigraphs to enable [-Wtrigraphs] .
It means, u have to add -trigraphs to compiler options.
For Code blocks it is locate at Settings->Compiler->Other Compiler Options.
Type here -trigraphs .
*/

#include <stdio.h>
#include <stdlib.h>
int main(int amount,char * content[])
{

char* kk = (char*)calloc(256,sizeof(char));
printf("\n");

/* All escape sequences
??= converts to # ??( converts to [ ??) converts to ]
??/ converts to \ ??< converts to { ??> converts to }
??' converts to ^ ??! converts to | ??- converts to ~
*/


sprintf(kk,"\?\?= => ??= \t");
sprintf(kk,"%s\?\?( => ??( \t",kk);
sprintf(kk,"%s\?\?) => ??) \n",kk);

sprintf(kk,"%s\?\?/ => ??/\ \t",kk);/*There is a problem with displayed just ??/ coz this is a specific symbol for escape sequences*/
sprintf(kk,"%s\?\?< => ??< \t",kk);
sprintf(kk,"%s\?\?> => ??> \n",kk);

sprintf(kk,"%s\?\?' => ??' \t",kk);
sprintf(kk,"%s\?\?! => ??! \t",kk);
sprintf(kk,"%s\?\?- => ??- \n",kk);

printf(kk);

return 0;
}

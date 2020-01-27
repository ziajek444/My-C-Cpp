/******************************************************************************

Author: Marcin Ziajkowski
Brief: Calculate how much iteration do u neet to doubled ur money with certain
procent.
Function double_ur_cash multiply current money by procent until Your benefit
is doubled.
paramteres:
in_cash: starting amount of money
procent: current procent counting every iteration
*counter: pointer contain amount of iteration (usually months)
 
*******************************************************************************/
#define BEGIN printf("Hello There\n");
#define END printf("\nGeneral Kenobi\n"); \
return 0;
 
#include <stdio.h>
 
float double_ur_cash(const float in_cash, const float procent, unsigned int * counter)
{
    float expected_cash = in_cash * 2.0f;
    * counter = 0;
    float my_cash = in_cash;
   
    if(!(procent > 1.0))
    {
        printf("\n'nERROR\nProcent can not be decreasing\n\n");
    }
    else
    {
       
        while(my_cash < expected_cash)
        {
            my_cash *= procent;
            (*counter)++;
        }
    }
   
    return my_cash;
}
 
int main()
{
    BEGIN
   
    unsigned int counter = 0;
    float cash = 100.0f;
   
    // 1.5% = 1.015
    float benefit = double_ur_cash(cash, 1.015, (int *)&counter);
   
    printf("benefit: %.4f\ncounter: %i",benefit, counter);
   
    END
}
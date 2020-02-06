#include <stdio.h>
#include "struct_Sensor.h"
#include "local_DB.h"
#include <string.h>
#include <stdlib.h>

#define OK 0
#define NOK -1

int main(int args, char * argv[])
{

  //struct Sensor * ssw;
  struct Sensor stab[20];

  int i =0;
  for(i=0;i<MAX_SESORS;i++) {
    stab[i].ID = i;
    stab[i].tclass = 'A'+i;
    stab[i].value = 0.1 * (i+1);
    stab[i].voltage = 1.11 * (i+1);
    sprintf(stab[i].info, "Custom sensor 0%d%c", i+1, 'A'+i);
  }
  //ssw = stab;
  printf("result: %d\n",write_all_sensors(stab));

  return OK;
}

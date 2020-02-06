#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <sys/file.h>
#include <string.h>

#include "struct_Sensor.h"
#include "local_DB.h"

#define OK 0
#define NOK -1

int main(int args, char * argv[])
{

  int i = print_all_sensor();
  printf("\nresult: %d\n",i);

  return OK;
}













//

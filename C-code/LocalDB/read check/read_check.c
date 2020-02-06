#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <sys/file.h>
#include <string.h>

#include "struct_Sensor.h"
#include "local_DB.h"

#define OK 0
#define NOK -1

// prints whole local structure
void print_local_db(const struct Sensor s[20])
{
  int i = 0;
  for(i=0;i<MAX_SESORS;i++) {
    printf("Sensor %d\n",i);
    printf("ID:int: %d\r\n",s[i].ID);
    printf("tclass:char: %c\r\n",s[i].tclass);
    printf("value:double: %lf\r\n",s[i].value);
    printf("voltage:float: %f\r\n",s[i].voltage);
    printf("info:char[128]: %s\r\n",s[i].info);
    printf("-------------------------------------\n");
  }
}

int main(int args, char * argv[])
{
  struct Sensor ss[20] = {};

  printf("before:\n");
  print_local_db(ss);

  printf("result: %d\n",read_all_sensor(ss));
  printf("after\n");
  print_local_db(ss);

  return OK;
}













//

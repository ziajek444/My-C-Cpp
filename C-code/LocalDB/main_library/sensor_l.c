#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct_Sensor.h"

extern const unsigned int MAX_SESORS;

#define OK 0
#define NOK -1
#define FILEADDR "/home/ziajek/Desktop/programowanie/main_library/Red.bin"

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

void print_single_local_db(const struct Sensor s, const int index)
{
    printf("Sensor %d\n",index);
    printf("ID:int: %d\r\n",s.ID);
    printf("tclass:char: %c\r\n",s.tclass);
    printf("value:double: %lf\r\n",s.value);
    printf("voltage:float: %f\r\n",s.voltage);
    printf("info:char[128]: %s\r\n",s.info);
    printf("-------------------------------------\n");
}










//

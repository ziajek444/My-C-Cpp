#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <sys/file.h>
#include <string.h>
#include "struct_Sensor.h"
#include "local_DB.h"
#include <semaphore.h>
#define OK 0
#define NOK -1

int main(int args, char * argv[])
{

  char elo = 'h';
  while(1) {
    elo = getchar() & 0xFF;
    if(elo=='\n') continue;
    switch(elo) {
      case 'i': //init
        initDB();
        break;
      case 's': //show content
        SHCONTENT();
        break;
      case 'd': //deallocate process
        closeDB();
        break;
      case 'c': //clear
        SHCLEAR();
        break;
      case 'q': //quit
        break;
      default:
        printf("i:Init, s:Show, d:Deallocate, c:Clear\n");
        break;
    }
    if (elo == 'q') break;
}

  return OK;
}












//

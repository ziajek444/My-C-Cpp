#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <sys/file.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "struct_Sensor.h"
#include "local_DB.h"

#define OK 0
#define NOK -1

//signal handler
void sig_handler(int s_num) {
  if (s_num == SIGUSR1) { printf("Do Update\n");
    //read_all_sensors(ss);
  }
}

// fills up one sensor
static void fillup(struct Sensor * s) {
    printf("ID:int\r\n");
    scanf("%d",&(s->ID));
    printf("wartosc: %d\r\n",s->ID);

    printf("tclass:char\r\n");
    scanf(" %c",&(s->tclass)); // space + %c important
    printf("wartosc: %c\r\n",s->tclass);

    printf("value:double\r\n");
    scanf(" %lf",&(s->value));
    printf("wartosc: %lf\r\n",s->value);

    printf("voltage:float\r\n");
    scanf(" %f",&(s->voltage));
    printf("wartosc: %f\r\n",s->voltage);

    printf("info:char[128]\r\n");
    scanf(" %[^\n]s",(s->info));
    printf("wartosc: %s\r\n",s->info);
}

int main(int args, char * argv[])
{
  printf("Hello There my PID is %d\n",getpid());
  signal(SIGUSR1, sig_handler);
  char choice;
  int sens_nr=-1;
  struct Sensor ss[20] = {};

  while(1) {
    printf("what do u want to do?\n[h: help]\n");
    scanf(" %c",&choice);
    switch(choice)
      {
        case '1':
          initDB();
          break;
        case '2':
          SHCONTENT();
          break;
        case '3':
          closeDB();
          break;
        case '4':
          SHCLEAR();
          break;
        case 'l':
          printf("Print local data base\n");
          print_local_db(ss);
          break;
        case 's':
          printf("Print single local data base\n");
          scanf(" %d",&sens_nr);
          print_single_local_db(ss[sens_nr], sens_nr);
          break;
        case 'r':
          printf("read single sensor\n");
          scanf(" %d",&sens_nr);
          read_sensor(&ss[sens_nr], sens_nr);
          printf("\nDone!\n\n");
          break;
        case 'e':
          printf("read all sensors\n");
          read_all_sensors(ss);
          printf("\nDone!\n\n");
          break;
        case 'p':
          printf("print single sensor\n");
          scanf(" %d",&sens_nr);
          print_sensor(sens_nr);
          printf("\nDone!\n\n");
          break;
        case 'q':
          goto label;
        case 'w':
          printf("write single sensor\n");
          scanf(" %d",&sens_nr);
          write_sensor(ss, sens_nr);
          printf("wgrano %d item\n",sens_nr);
          break;
        case 'o':
          printf("write all sensors\n");
          write_all_sensors(ss);
          printf("wgrano item\n");
          break;
        case 'a':
          print_all_sensors();
          break;
        case 'c':
          printf("Set local value\n");
          scanf(" %d",&sens_nr);
          fillup(&ss[sens_nr]);
          break;
        case 'h':
        default:
          printf("try:\n"
          "r:read single\n"
          "e:read all sensors\n"
          "p:print single\n"
          "a:print all\n"
          "w:write single\n"
          "o:write all\n"
          "l:print all local\n"
          "s:print single local\n"
          "1:initDB\n"
          "2:SM CONTENT\n"
          "3:deallocateDB\n"
          "4:SM CLEAR\n"
          "q:quit\n");
          break;
      }
  }
  label:


  return OK;
}

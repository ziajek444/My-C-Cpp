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
#define DELAY 0

/*
  important for synch file access:
  for read:
    r+b
    fl.l_type = F_RDLCK;
    F_SETLKW
*/

/*
Read all file instead of just single part (todo)
index value is 0:(MAX_SESORS-1)
*/
int read_sensor(struct Sensor * out_single_sensor, const int index) {
  // private data
  int i;

  //check input data (parameters)
  if (out_single_sensor == NULL || index < 0 || index >= MAX_SESORS) return NOK;

  //open file
  FILE * f = fopen(FILEADDR, "r+b"); //read only + binary mode (fopen)
  int fd = fileno(f); // need number from open()
  if (fd == -1) {
      perror("open");
      return NOK;
  }

  // lock
  struct flock fl = {};
  fl.l_type = F_RDLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
  // F_SETFL
  // F_SETFD
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }

  // save to local data base
  // 1. read all
  struct Sensor * S_wsk = malloc(sizeof(struct Sensor)*MAX_SESORS);
  fseek (f, 0, SEEK_SET );
  for(i=0;i<MAX_SESORS;i++) {
    fread(&S_wsk[i], sizeof(struct Sensor), 1, f);
  }

  // 2.Change sensor data
   *out_single_sensor = S_wsk[index];

  // No need to write again

  if (DELAY) sleep(3);
  free(S_wsk);

  //release
  fl.l_type = F_UNLCK;
  fl.l_whence = 0;
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }
  fclose(f);
  return OK;
}

int read_all_sensors(struct Sensor * out_arr_sensors) {
  // private data
  int i;

  //check input data (parameters)
  if (out_arr_sensors == NULL) return NOK;

  //open file
  FILE * f = fopen(FILEADDR, "r+b"); //read only + binary mode (fopen)
  int fd = fileno(f); // need number from open()
  if (fd == -1) {
      perror("open");
      return NOK;
  }

  // lock
  struct flock fl = {};
  fl.l_type = F_RDLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
  //F_SETFL
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }

  // save to local data base
  // 1. read all
  struct Sensor * S_wsk = malloc(sizeof(struct Sensor)*MAX_SESORS);
  fseek (f, 0, SEEK_SET );
  for(i=0;i<MAX_SESORS;i++) {
    fread(&S_wsk[i], sizeof(struct Sensor), 1, f);
  }

  // 2.Change all sensors data
  for(i=0;i<MAX_SESORS;i++) {
    out_arr_sensors[i] = S_wsk[i];
  }

  // No need to write again

  if (DELAY) sleep(3);
  free(S_wsk);

  //release
  fl.l_type = F_UNLCK;
  fl.l_whence = 0;
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }
  fclose(f);
  return OK;
}

int print_sensor(const int index) {
  // private data
  int i;

  //check input data (parameters)
  if (index < 0 || index >= MAX_SESORS) return NOK;

  //open file
  FILE * f = fopen(FILEADDR, "r+b"); //read only + binary mode (fopen)
  int fd = fileno(f); // need number from open()
  if (fd == -1) {
      perror("open");
      return NOK;
  }

  // lock
  struct flock fl = {};
  fl.l_type = F_RDLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
  //F_SETFL
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }

  // save to local data base
  // 1. read all
  struct Sensor * S_wsk = malloc(sizeof(struct Sensor)*MAX_SESORS);
  fseek (f, 0, SEEK_SET );
  for(i=0;i<MAX_SESORS;i++) {
    fread(&S_wsk[i], sizeof(struct Sensor), 1, f);
  }

    // 2.Just print single data
    printf("sens%d: id:%d\n",index,(S_wsk+index)->ID);
    printf("sens%d: tclass:%c\n",index,(S_wsk+index)->tclass);
    printf("sens%d: value:%f\n",index,(S_wsk+index)->value);
    printf("sens%d: voltage:%f\n",index,(S_wsk+index)->voltage);
    printf("sens%d: info:%s\n",index,(S_wsk+index)->info);

  if (DELAY) sleep(3);
  free(S_wsk);

  //release
  fl.l_type = F_UNLCK;
  fl.l_whence = 0;
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }
  fclose(f);
  return OK;
}

int print_all_sensors() {
  // private data
  int i;

  //open file
  FILE * f = fopen(FILEADDR, "r+b"); //read only + binary mode (fopen)
  int fd = fileno(f); // need number from open()
  if (fd == -1) {
      perror("open");
      return NOK;
  }

  // lock
  struct flock fl = {};
  fl.l_type = F_RDLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
  //F_SETFL
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }

  // save to local data base
  // 1. read all
  struct Sensor * S_wsk = malloc(sizeof(struct Sensor)*MAX_SESORS);
  fseek (f, 0, SEEK_SET );
  for(i=0;i<MAX_SESORS;i++) {
    fread(&S_wsk[i], sizeof(struct Sensor), 1, f);
  }

  // 2.Print all data
  for(i=0;i<MAX_SESORS;i++) {
    printf("sens%d: id:%d\n",i,S_wsk->ID);
    printf("sens%d: tclass:%c\n",i,S_wsk->tclass);
    printf("sens%d: value:%f\n",i,S_wsk->value);
    printf("sens%d: voltage:%f\n",i,S_wsk->voltage);
    printf("sens%d: info:%s\n",i,S_wsk->info);
    S_wsk+=1;
  }
  S_wsk = S_wsk - MAX_SESORS;

  if (DELAY) sleep(3);
  free(S_wsk);

  //release
  fl.l_type = F_UNLCK;
  fl.l_whence = 0;
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }
  fclose(f);
  return OK;
}










//

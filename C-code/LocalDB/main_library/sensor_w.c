#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<sys/shm.h>
#include "struct_Sensor.h"

extern const unsigned int MAX_SESORS;

#define OK 0
#define NOK -1
#define FILEADDR "/home/ziajek/Desktop/programowanie/main_library/Red.bin"
#define DELAY 0

/*
  important for synch file access:
  for write:
    fl.l_type = F_WRLCK;
    F_SETLKW
*/

/*
Read all file instead of just single part (todo)
index value is 0:(MAX_SESORS-1)
*/

static int shmid;
static int shmkey = 12222;//u can choose it as your choice
static int size_of_shared_mem = 1024;

static int how_many_items(char * arr) {
    int amount = strlen(arr);

    return amount/3;
}

static int convert_3char_to_6digit(char tab[3]) {
    int digits = 0;
    int demask = 0x7F;
    tab[0] &= demask;
    tab[1] &= demask;
    tab[2] &= demask;
    digits += (int)(tab[0]) *  10000;
    digits += (int)(tab[1]) *  100;
    digits += (int)(tab[2]);

    return digits;
}

int write_sensor(const struct Sensor * single_sensor, const int index) {
  // private data
  int i;

  //check input data (parameters)
  if (single_sensor == NULL || index < 0 || index >= MAX_SESORS) return NOK;

  //open file
  FILE * f = fopen(FILEADDR, "r+b"); //read only + binary mode (fopen)
  int fd = fileno(f); // need number from open()
  if (fd == -1) {
      perror("open");
      return NOK;
  }

  // lock
  struct flock fl = {};
  fl.l_type = F_WRLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
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
  S_wsk[index] = *single_sensor;

  // 3. write all again (with modifications)
  fseek (f, 0, SEEK_SET );
  for(i=0;i<MAX_SESORS;i++) {
    fwrite(&S_wsk[i], sizeof(struct Sensor), 1, f);
  }

  if (DELAY) sleep(3);

  //release
  fl.l_type = F_UNLCK;
  fl.l_whence = 0;
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }
  fclose(f);

  // signals ------------------------------------------------
  int PID = getpid();
  // generate shared memory ID
  shmid = shmget(shmkey, size_of_shared_mem, IPC_CREAT | 0666);
  // allocate the pointer to memory block
  char * shmpointer = shmat(shmid,NULL,0);
  int next_pid = 0;
  int amount = how_many_items(shmpointer);
  char shmem[3]={};
  for(i=0;i<amount;i++) {
    strncpy(shmem,&shmpointer[i*3],3);
    next_pid = convert_3char_to_6digit(shmem);
    if (next_pid != PID)
      kill(next_pid, SIGUSR1);
  }
  shmdt(&shmpointer);
  //---------------------------------------------------------

  return OK;
}

int write_all_sensors(const struct Sensor * arr_sensors) {
  // private data
  int i;

  //check input data (parameters)
  if (arr_sensors == NULL) return NOK;

  //open file
  FILE * f = fopen(FILEADDR, "r+b"); //read only + binary mode (fopen)
  int fd = fileno(f); // need number from open()
  if (fd == -1) {
      perror("open");
      return NOK;
  }

  // lock
  struct flock fl = {};
  fl.l_type = F_WRLCK;
  fl.l_whence = SEEK_SET;
  fl.l_start = 0;
  fl.l_len = 0;
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
  S_wsk[i] = arr_sensors[i];
  }

  // 3. write all again (with modifications)
  fseek (f, 0, SEEK_SET );
  for(i=0;i<MAX_SESORS;i++) {
    fwrite(&S_wsk[i], sizeof(struct Sensor), 1, f);
  }


  if (DELAY) sleep(3);

  //release
  fl.l_type = F_UNLCK;
  fl.l_whence = 0;
  if (fcntl(fd, F_SETLKW, &fl) == -1) {
      perror("fcntl");
      return NOK;
  }
  fclose(f);

  // signals ------------------------------------------------
  int PID = getpid();
  // generate shared memory ID
  shmid = shmget(shmkey, size_of_shared_mem, IPC_CREAT | 0666);
  // allocate the pointer to memory block
  char * shmpointer = shmat(shmid,NULL,0);
  int next_pid = 0;
  int amount = how_many_items(shmpointer);
  char shmem[3]={};
  for(i=0;i<amount;i++) {
    strncpy(shmem,&shmpointer[i*3],3);
    next_pid = convert_3char_to_6digit(shmem);
    if (next_pid != PID)
      kill(next_pid, SIGUSR1);
  }
  shmdt(&shmpointer);
  //---------------------------------------------------------

  return OK;
}












//

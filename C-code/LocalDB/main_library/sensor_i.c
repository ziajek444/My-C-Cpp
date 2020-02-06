/// sensor init
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// shared memory
#include<sys/ipc.h>
#include<sys/shm.h>
#include <sys/mman.h>
#include <semaphore.h>

#include "struct_Sensor.h"

extern const unsigned int MAX_SESORS;

#define OK 0
#define NOK -1
#define FILEADDR "/home/ziajek/Desktop/programowanie/main_library/Red.bin"

static int shmid;
static int shmkey = 12222;//u can choose it as your choice
static int size_of_shared_mem = 1024;

static void addWords(char * shmem, char * input_arr) {
    int i;
    int j=0;
    //len allways is 3
    //from allways is from the end of shmem
    int from = strlen(shmem);
    int condition = from+3;
    for(i=from;i<condition;i++) {
        shmem[i] = input_arr[j++];
    }
}

static void convert_6digit_to_3char(int digits, char tab[3]) {
    int copy6d = digits % 1000000;
    // XX0000
    int XX = copy6d / 10000;
    tab[0] = (char)(XX) | 0x80;
    // 00XX00
    XX = (copy6d % 10000) / 100;
    tab[1] = (char)(XX) | 0x80;
    // 0000XX
    XX = copy6d % 100;
    tab[2] = (char)(XX) | 0x80;
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

static int how_many_items(char * arr) {
    int amount = strlen(arr);

    return amount/3;
}

// if nof found any PID then return -1 as error
static int removePID(char *shmem, int PID) {
    char myPID[3]={};
    char shmemPID[3]={};
    int index = 0;
    int i;
    int amount = how_many_items(shmem);
    int isFound = 0;

    convert_6digit_to_3char(PID, myPID);

    for(i=0;i<amount;i++) {
        strncpy(shmemPID,&shmem[i*3],3);
        if(strncmp(shmemPID, myPID, 3) == 0) { //found
            isFound = 1;
            break;
        }
        index ++;

    }
    if (!isFound) return -1; // error (already deleted)

    if (index+1 == amount){
        shmem[index*3] = '\0'; // remove last element
    }
    else if (index==0) {
        strncpy(shmem,&shmem[3],amount*3);
        amount--;
        shmem[amount*3] = '\0';
    }
    else { // middle
        strncpy(&shmem[index*3],&shmem[(index+1)*3],amount*3);
        amount--;
        shmem[amount*3] = '\0';
    }

    return 0; // ok

}

void initDB() {
    // ---- TODO -----
    // Prevent to add same PID few times
    // Locks dosen't works :(
    // ......

    int PID = getpid();
    // generate shared memory ID
    shmid = shmget(shmkey, size_of_shared_mem, IPC_CREAT | 0666);
    // allocate the pointer to memory block
    char * shmpointer = shmat(shmid,NULL,0);
    // lock
        //sem_t sem;
        //sem_init(&sem, 1, 0);
        //sem_wait(&sem);
        //sem_t sem = *sem_open("SEM01",O_CREAT);
        //printf("SEM: %d\n",sem);
    // ----
    //check if it is first init
    if(*shmpointer=='\0')
    { // add first one
        char tab[3];
        convert_6digit_to_3char(PID, tab); //zip PID into char arr (tab)
        addWords(shmpointer, tab); // write tab content into shared memory
    }
    else
    {
        char tab[3];
        convert_6digit_to_3char(PID, tab); //zip PID into char arr (tab)
        addWords(shmpointer, tab); // write tab content into shared memory
    }

      //sleep(3);
      // unlock
        //sem_unlink("SEM01");
      // ----
    shmdt(&shmpointer);
    printf("process %d has been initialized\n",PID);


}

void closeDB() {
  int PID = getpid();
  shmid = shmget(shmkey, size_of_shared_mem, 0666);
  char * shmpointer = shmat(shmid,NULL,0);

  int removed = removePID(shmpointer, PID);
    if(removed) printf("Already removed or not initialized!\n");
    else printf("removed\n");

  printf("in mem: %s\n",shmpointer);
  shmdt(&shmpointer);
}

// shared memory content prints
void SHCONTENT() {

  shmid = shmget(shmkey, size_of_shared_mem, IPC_CREAT | 0666);
  char * shmpointer = shmat(shmid,NULL,0);
  char * already = shmpointer;
  if(*already=='\0')
    {
        printf("Is empty\n");
    }
    else
    {
        int hmi = how_many_items(already);
        int i;
        char tab[3] = {};
        printf("%d items:\n",hmi);
        printf("Raw view | actually PID:\n");
        for(i=0;i<hmi;i++) {
            strncpy(tab,&already[i*3],3);
            printf("rv: %s | aP: %d\n",tab, convert_3char_to_6digit(tab));
        }
    }

  shmdt(&shmpointer);

}

// shared memory clear
void SHCLEAR() {
  shmid = shmget(shmkey, size_of_shared_mem, IPC_CREAT | 0666);
  char * shmpointer = shmat(shmid,NULL,0);
  memset(shmpointer,0,1024);
  printf("WARNING: Shared memory is cleared!!\n");
  shmdt(&shmpointer);
}









//

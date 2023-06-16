#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define SHMSIZE 27

int main()
{
  int shmid;
  key_t key;
  char *shm, *s;

  key = 1324;

  shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);

  printf(" %d ", shmid);

  if (shmid <0)
  {
    perror("shmget");
    exit(1);
  }
  
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
  {
    perror("shmat");
    exit(1);
  }

  for (s = shm; *s!=0; s++)
    putchar(*s);
  putchar('\n');

  *shm = '*';
  exit(0);
}

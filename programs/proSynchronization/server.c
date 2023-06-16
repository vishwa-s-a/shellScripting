#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SHMSIZE 27s

int main()
{
  char c;
  int shmid;
  key_t key;
  char *shm, *s;
  
  key = 1324;

  if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) 
  {
    perror("shmget");
    exit(1);
  }
  
  if ((shm=shmat(shmid, NULL, 0)) == (char *) -1)
  {
    perror("shmat");
    exit(1);
  }

  s = shm;

  for (c = 'a'; c<='z'; c++)
  {
    *s++ = c;
  }
  *s = 0;

  while (*shm != '*')
    sleep(1);
  exit(0);
}

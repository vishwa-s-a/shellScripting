#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int pfds[2];
  int status = pipe(pfds);

  if (status == -1)
  {
    printf("\n Unable to create pipe\n");
    exit(1);
  }
  char *writeMsg = "Pipes";
  long size = sizeof(writeMsg);
  char readMsg[30];

  printf("\n Writing info to pipe: \n");

  write(pfds[1], writeMsg, sizeof(writeMsg));

  printf("\n Information has been written\n");

  printf("\n Reading data from pipe: \n");

  read(pfds[0], readMsg, sizeof(readMsg));

  printf("\n Received Data: %s\n", readMsg);
}

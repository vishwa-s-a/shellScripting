#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
    printf("sleeping the process: %d\n",getpid());
    sleep(100);
    printf("sleep for 20 seconds completed\n");
    return 0;
}
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void forkExample()
{
    int x=10;
    if(fork() == 0)
    printf("child process has x: %d\n",++x);
    else
    printf("parent process has x : %d\n",--x);
}
int main()
{
    forkExample();
    return 0;
}
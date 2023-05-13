#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void forkExample()
{
    if(fork() == 0)
    printf("Hello from child process\n");
    else
    printf("Hello from parent process\n");
}
int main()
{
    forkExample();
    return 0;
}
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void execExample()
{
    int x=10;
    if(exec() == 0)
    printf("child process has x: %d\n",++x);
    else
    printf("parent process has x : %d\n",--x);
}
int main()
{
    execExample();
    return 0;
}
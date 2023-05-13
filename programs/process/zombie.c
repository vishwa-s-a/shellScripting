// link:https://www.geeksforgeeks.org/zombie-and-orphan-processes-in-c/

// a c program to demonstrate zombie process
// here child becomes zombie as parent is sleeping
// when child process exists

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    //fork returns process id in parent process
    pid_t child_pid=fork();

    //parent process
    if(child_pid >0)
    {
        sleep(10);//sleep for 10 seconds
    }

    //child process
    else
    exit(0);

    return 0;


}
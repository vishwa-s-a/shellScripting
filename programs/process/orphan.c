// A process whose parent process no more exists i.e. either finished or terminated 
//without waiting for its child process to terminate is called an orphan process.

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    //create a child process
    int pid =fork();

    if(pid>0)
    {
        printf("In parent process\n");
    }

    //note that pid is 0 in child process
    // and negative if fork() fails

    else if(pid==0)
    {
        sleep(10);
        printf("in child process");
    }

    return 0;
}
//example usage of fork()

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    // fork();
    // printf("Hello world\n");
    pid_t pid;
    pid=fork();

    if(pid<0)
    {
        printf("Process is not created\n");
    }
    else if(pid ==0)
    {
        printf("Child process created successfully\n");
        printf("Child process id is %d and parent process id is %d\n", getpid(),getppid());
    }
    else{
        printf("process id is %d and newly created process id is %d\n",getpid(),pid);
    }

    return 0;
}
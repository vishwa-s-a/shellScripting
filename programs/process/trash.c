#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
};
typedef struct Process Process;
void fcfs(Process process[],int n)
{
    int currentTime=0;
    for(int i=0;i<n;i++)
    {
        currentTime+=process[i].bt;
        process[i].ct=currentTime;
    }
    printf("tt\twt\n");
    for(int i=0;i<n;i++)
    {
        int temp=process[i].ct-process[i].at;
        printf("%d\t%d\n",temp,temp-process[i].bt);
    }
}
int main(){
    Process process[]={{1,0,24},{2,0,3},{3,0,3}};
    fcfs(process,3);
return 0;
}
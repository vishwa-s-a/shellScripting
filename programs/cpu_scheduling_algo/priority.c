//non-preemptive type

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 
struct Process{
    int pid;
    int bt;
    int priority;
    int ct;
};

typedef struct Process Process;
void priority(Process process[],int n)
{
    int i,j,currentTime=0;
    printf("Gantt chart: \n");
    for(i=1;i<=5;i++)
    {
        for(j=0;j<n;j++)
        {
            if(process[j].priority==i)
            break;
        }
        currentTime+=process[j].bt;
        process[j].ct=currentTime;
        printf("|P%d ",j+1);
    }
    printf("\n");
    printf("pid\tbt\tct\ttat\twt\n");
    for(int z=0;z<n;z++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",process[z].pid,process[z].bt,process[z].ct,process[z].ct,process[z].ct-process[z].bt);
    }
}
int main(){
    Process process[]={{1,10,3},{2,1,1},{3,2,4},{4,1,5},{5,5,2}};
    priority(process,5);
return 0;
}
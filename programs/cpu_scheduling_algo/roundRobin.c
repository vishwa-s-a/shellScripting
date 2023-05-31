//c program for roundRobin algo when it doesnt have arrival time column and 
// clearly it means that the arrival time is equal to 0 for all

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 
struct Process{
    int pid;// id of the process
    int bt;//burst time of the process
    int rbt;// remaining burst time of the process
    int ct;//completion time
};

typedef struct Process Process;
//round robin function
void roundRobin(Process process[],int n, int quantum){
    int i,totalBurstTime=0,currentTime=0;

    //calculate the total burst time of all processes
    for(i=0;i<n;i++)
    {
        totalBurstTime+=process[i].bt;
        process[i].rbt=process[i].bt;
    }

    //perform round robin scheduling 
    printf("Gantt Chart:\n");
    while(totalBurstTime >0){
        for(i=0;i<n;i++){
            if(process[i].rbt>0)
            {
                if(process[i].rbt<=quantum)
                {
                    currentTime+=process[i].rbt;
                    totalBurstTime-=process[i].rbt;
                    process[i].rbt=0;
                    process[i].ct=currentTime;
                }
                else{
                    currentTime+=quantum;
                    totalBurstTime-=quantum;
                    process[i].rbt-=quantum;
                }

                printf("| P%d |",process[i].pid);
            }
        }
    }
    printf("\n\n");

    //calculate the turnaround time and waiting time for each process
    int totalTT=0,totalWT=0;
    printf("Process\tTT\tWT\n");
    for(i=0;i<n;i++)
    {
        int turnAroundtime=process[i].ct;
        int waitingTime=turnAroundtime-process[i].bt;
        totalTT+=turnAroundtime;
        totalWT+=waitingTime;
        printf("P%d\t%d\t%d\n", process[i].pid, turnAroundtime, waitingTime); 
    }

    double avgTT=(double)totalTT/n;
    double avgWT=(double)totalWT/n;
    printf("\nAverage Turnaround Time: %.2lf\n", avgTT);
    printf("Average Waiting Time: %.2lf\n", avgWT);

}

int main(){
    // we are giving entries of value without taking input from the user
    Process process[]={{1,24},{2,3},{3,3}};
    roundRobin(process,3,4);
return 0;
}
#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int burstTime[n],arrivalTime[n],waitTime[n],turnAround[n],id[n];
    printf("Enter the id of the process: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&id[i]);
    }

    printf("Enter the burst time of the process: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&burstTime[i]);
    }

    printf("Enter the arrival time of the process: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arrivalTime[i]);
    }

    waitTime[0]=0;// initialising the waiting time of the first process as 0
    int totalWaitTime=0;
    int totalTurnAroundTime=0;
    //calculating the waiting time    
    for(i=1;i<n;i++)
    {
        waitTime[i]=waitTime[i-1]+burstTime[i-1];
        totalWaitTime+=waitTime[i];
    }

    //calculating the turnaround time
    for(i=0;i<n;i++)
    {
        turnAround[i]=waitTime[i]+burstTime[i];
        totalTurnAroundTime+=turnAround[i];
    }

    printf("process id\tArrival time\tburst time\twaiting time\tturn Around Time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",id[i],arrivalTime[i],burstTime[i],waitTime[i],turnAround[i]);
    }

    float averageWaitTime, averageTurnAroundTime;
    averageWaitTime=totalWaitTime/n;
    averageTurnAroundTime=totalTurnAroundTime/n;

    printf("Average waiting time: %f\n",averageWaitTime);
    printf("Average turn around time: %f\n",averageTurnAroundTime);




    return 0;
}
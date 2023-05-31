// c program for roundRobin algo arrival time and I/O operations are given

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Process
{
    int pid; // id of the process
    int at;  // arrival time
    int bt;  // burst time of the process
    int rbt; // remaining burst time of the process
    int ct;  // completion time
    int fat; // first arrival time
    int et;  // end time of the process
};

typedef struct Process Process;
// round robin function

void roundRobin(Process process[], int n, int quantum)
{
    int i, totalBurstTime = 0, currentTime = 0;

    int ready[50]; // ready queue of the cpu
    int j = 0;     // will be the tail of the array
    int z = 0;     // will be the head of the array

    // calculate the total burst time of all processes
    for (i = 0; i < n; i++)
    {
        totalBurstTime += process[i].bt;
        process[i].rbt = process[i].bt;
        if (process[i].at == 0)
            ready[j++] = process[i].pid;
    }
    // perform round robin scheduling
    printf("Gantt Chart:\n");
    while (totalBurstTime > 0 && z != j)
    {

        int v = 0;
        for (; v < n; v++)
        {
            if (ready[z] == process[v].pid)
                break;
        }
        // printf("v: %d\n",v);
        if (process[v].rbt > 0)
        {
            if (process[v].rbt <= quantum)
            {
                currentTime += process[v].rbt;
                totalBurstTime -= process[v].rbt;
                process[v].rbt = 0;
                process[v].ct = currentTime;
                process[v].et = currentTime;
                for (int h = 0; h < n; h++)
                {
                        if (process[h].at > process[v].at && process[h].at <= currentTime)
                        {
                            ready[j++] = process[h].pid;
                        }
                }
                z++;
            }
            else
            {
                currentTime += quantum;
                totalBurstTime -= quantum;
                process[v].rbt -= quantum;
                for (int h = 0; h < n; h++)
                {
                    
                        if (process[h].at > process[v].at && process[h].at <=currentTime)
                        {
                            ready[j++] = process[h].pid;
                        }
                    
                }
                ready[j++] = process[v].pid;
                z++;
            }

            // printf("| P%d", process[v].pid);
        }
        else if (process[v].rbt == 0)
        {
            for (int h = 0; h < n; h++)
            {
                
                        if (process[h].at > process[v].at && process[h].at < currentTime)
                        {
                            ready[j++] = process[h].pid;
                        }
                   
            }
            z++;
        }
    }
    printf("\n");
    for (int x = 0; x <= j - 1; x++)
    {
        printf("%d ", ready[x]);
    }

    // // calculate the turnaround time and waiting time for each process
    // int totalTT = 0, totalWT = 0;
    // printf("Process\tTT\tWT\n");
    // for (i = 0; i < n; i++)
    // {
    //     int turnAroundtime = process[i].ct;
    //     int waitingTime = turnAroundtime - process[i].bt;
    //     totalTT += turnAroundtime;
    //     totalWT += waitingTime;
    //     printf("P%d\t%d\t%d\n", process[i].pid, turnAroundtime, waitingTime);
    // }

    // double avgTT = (double)totalTT / n;
    // double avgWT = (double)totalWT / n;
    // printf("\nAverage Turnaround Time: %.2lf\n", avgTT);
    // printf("Average Waiting Time: %.2lf\n", avgWT);
}

int main()
{
    // we are giving entries of value without taking input from the user
    Process process[] = {{1, 0, 1000}, {2, 500, 3500}, {3, 1000, 2000}};
    roundRobin(process, 3, 500);
    return 0;
}
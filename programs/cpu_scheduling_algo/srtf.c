#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> // this is required for INT_MAX and INT_MIN

// this program is for shortest remaining time first algorithm which is also a SJF pre-emptive algorithm

// struct for defining process
struct Process
{
    int pid; // process id
    int bt;  // burst time
    int at;  // arrival time
};

// we will typedef struct Process so we can use it as Process
typedef struct Process Process;

// function to find the waiting time for all processes
void waitingTime(Process process[], int n, int wt[])
{              // here wt[] is array for waiting time
    int rt[n]; // here rt is remaining time;

    // at first we will copy the burst time of all process into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = process[i].bt; // we are copying burst time of process

    // initialising variables
    int complete = 0, current_time = 0, minRemaining_time = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    // loop until all the processes get completed
    while (complete != n)
    {
        // find process with minimum remaining time among the processes that arrived till the
        //  current_time
        for (int j = 0; j < n; j++)
        {
            if ((process[j].at <= current_time) && (rt[j] < minRemaining_time) && (rt[j] > 0))
            {
                minRemaining_time = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            current_time++;
            continue;
        }

        // reduce the remainining time by one
        rt[shortest]--;

        // update the minimum remaining time
        minRemaining_time = rt[shortest];
        if (minRemaining_time == 0)
            minRemaining_time = INT_MAX;

        // if a process gets completely executed
        if (rt[shortest] == 0)
        {
            // increment the complete variable

            complete++;
            check = false;

            // calculate the finish time of current process
            finish_time = current_time + 1;

            // calculate the waiting time
            wt[shortest] = finish_time - process[shortest].at - process[shortest].bt;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        // increment time
        current_time++;
    }
}

// function to calculate the turn around time
void turnAroundTime(Process process[], int n, int wt[], int tat[])
{
    // calculating turn around time from waiting time
    // i.e tt[i]=wt[i]+bt[i]
    for (int i = 0; i < n; i++)
    {
        tat[i] = process[i].bt + wt[i];
    }
}

// function to calculate the averate time
void avgTime(Process process[], int n)
{
    int wt[n], tat[n]; // wt is waiting time and tat is turn around time
    int total_wt = 0, total_tat = 0;

    // function call to find the waiting time of all process
    waitingTime(process, n, wt);

    // function call to find the turn around time of all process
    turnAroundTime(process, n, wt, tat);

    // to display the process along with all details

    printf(" p\tAT\tBT\tWT\tTAT\n");

    // calculate the total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        /* code */
        total_wt += wt[i];
        total_tat += tat[i];

        printf(" %d\t%d\t%d\t%d\t%d\n", process[i].pid,process[i].at,process[i].bt, wt[i], tat[i]);
    }

    // printing the average turn around time and waiting time
    printf("Average waiting time: %f\n", (float)total_wt / (float)n);
    printf("Average turn around time: %f\n", (float)total_tat / (float)n);
}

int main()
{
    int n;
    Process process[]={{1,1,0},{2,10,3},{3,3,5},{4,1,6}};
    n=sizeof(process)/sizeof(process[0]);

    //call the important function of the file
    avgTime(process,n);
    return 0;
}
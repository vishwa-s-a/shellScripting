// program for SJF non-preemptive scheduling algorithm
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct Process{
    int pid;//id of the process
    int at;//arrival time of the process
    int bt;//burst time of the process
};

typedef struct Process Process;

//swapping function
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//sorting function( which will sort the processes in the increasing order of burst time of process)
void sort(int num[], int n, int order[])
{
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(num[j+1]<num[j])
            {
                swap(&num[j],&num[j+1]);// it swaps the burst time in increasing order
                swap(&order[j],&order[j+1]);// it swaps the pid of the processes based on bt
            }
        }
    }
    printf("Printing the order of the processes in which they will be executed: \n");
    for(int j=0;j<n;j++)
    {
        printf("P%d ",order[j]);
    }
    printf("\n");
}

//calculating the completion time of the processes
void completionTime(int bt[],int order[],int ct[],int n){
    for (int i = 0; i < n; i++)
    {   
        int temp=order[i]-1;
        for(int j=0;j<=i;j++)
        {
            ct[temp]+=bt[j];
        }
    }
}

//calculation of turn around time of process

void tatTime(Process process[],int ct[],int n, int tat[]){
    for (int i = 0; i < n; i++)
    {
        tat[i]=ct[i]-process[i].at;
    }
    
}

//calculation of waiting time

void wtTime(Process process[],int tat[],int n,int wt[]){
    for (int i = 0; i < n; i++)
    {
        wt[i]=tat[i]-process[i].bt;
    }
    
}


void calculate(Process process[],int n)
{
    int order[n];//this will be the array which will contain the pid in increasing order of bt of the respective process
    int bt[n];//it has the copy of bt of process
    int ct[n];// this stores the completion time
    int tat[n];//stores the total turn around time
    int wt[n];// stores the waiting time
    int totaltat=0;
    int totalwt=0;
    for(int i=0;i<n;i++)
    {
        bt[i]=process[i].bt;
        order[i]=process[i].pid;
    }

    //now we will sort the bt inorder to get the required increasing order of bt
    sort(bt,n,order); 
    completionTime(bt,order,ct,n);
    tatTime(process,ct,n,tat);
    wtTime(process,tat,n,wt);

    //calculation of total waiting time and turn around time and printing the other details of the process
    printf(" P\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        totaltat+=tat[i];
        totalwt+=wt[i];
        printf(" %d\t%d\t%d\t%d\t%d\t%d\n",process[i].pid,process[i].at,process[i].bt,ct[i],tat[i],wt[i]);
    }

    //printing the average values
    printf("Average turn around time : %0.3f\n",(float) totaltat / (float) n);
    printf("Average waiting time of the process: %0.3f\n",(float) totalwt / (float) n);

}

int main()
{
    Process process[]={{1,0,6},{2,0,8},{3,0,7},{4,0,3}};
    int n;
    n=sizeof(process)/sizeof(process[0]);

    //calling the important function
    calculate(process,n);
    return 0;
}
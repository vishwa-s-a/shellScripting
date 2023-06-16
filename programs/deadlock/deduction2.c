#include<stdio.h>
#include<stdbool.h>
#define MAX 10
//defining global variables
int allocation[MAX][MAX], request[MAX][MAX], available[MAX], mark[MAX], work[MAX];

int main(){
    int processes, resources;
    printf("Enter the number of process: ");
    scanf("%d",&processes);
    printf("Enter the number of resources: ");
    scanf("%d",&resources);
    
    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    printf("Enter the resource allocation for each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("Enter the request for each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < resources; j++)
            scanf("%d", &request[i][j]);
    }

    //marking the processes with zero allocation
    for(int i=0;i<processes;i++)
    {
        int count=0;
        for(int j=0;j<resources;j++)
        {
            if(allocation[i][j]==0)
            count++;
            else
            break;
        }
        if(count==resources)
        mark[i]=1;
    }

    //initialize work with available
    for(int j=0;j<resources;j++)
    {
        work[j]=available[j];
    }

    //mark processes with request less than or equal to work
    for(int i=0;i<processes;i++)
    {
        int flag=0;
        if(mark[i]!=1)
        {
            for(int j=0;j<resources;j++)
            {
                if(request[i][j]<=work[j])
                flag=1;

                else{
                    flag=0;
                    break;
                }

            }
            if(flag)
            {
                mark[i]=1;
                for(int j=0;j<resources;j++)
                {
                    work[j]+=allocation[i][j];
                }
            }
        }

    }

    //checking for unmarked processes
    int deadlock=0;
    for(int i=0;i<processes;i++)
    {
        if(mark[i]!=1)
        deadlock=1;
    }

    if(deadlock)
    printf("Deadlock detected\n");

    else{
        printf("No deadlock possible");

    }
    return 0;
    
}
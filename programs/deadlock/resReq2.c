#include <stdio.h>
#include <stdbool.h>

// Maximum number of processes and resources
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

//global variables
int work[MAX_RESOURCES];
bool finish[MAX_PROCESSES] = {false};
int safeSequence[MAX_PROCESSES];
int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_RESOURCES];

bool isSafe(int processes, int resources)
{
    int i, j, z = 0;
    // Initialize work array with available resources
    for (i = 0; i < resources; i++)
        work[i] = available[i];
    
    for(int k=0;k<5;k++)
    {
        //printf("%d\n",completed);
        for(int i=0;i<processes;i++)
        {
            int j;
            if(finish[i] == false)
            {
                for(j=0;j<resources;j++)
                {
                    if(need[i][j] > work[j])
                    break;
                }
                if(j==resources)
                {
                    finish[i]=true;
                    safeSequence[z++]=i;
                    // now we have to return the resoruces to the available array
                    for(int v=0;v<resources;v++)
                    {
                        work[v]+=allocation[i][v];
                    }
                }
            }

        }
    }
    int flag = 1;  
    for (int i = 0; i < processes; i++)  
    {  
        if (finish[i] == false)  
        {  
            flag = 0;   
            return false;  
        }  
    }  
    if(flag==1)
    {
         return true;
    }
}

void requestResources(int pr, int resources, int processes) {
    int i;
    for (i = 0; i < resources; i++) {
        if (request[i] > need[pr][i] || request[i] > available[i]) {
            printf("Request exceeds maximum need or available resources!\n");
            return;
        }
    }
    for (i = 0; i < resources; i++) {
        available[i] -= request[i];
        allocation[pr][i] += request[i];
        need[pr][i] -= request[i];
    }
    if (isSafe(processes, resources))
    {
        printf("Request granted. System is in a safe state.\n");
        printf("The safe sequence is: \n");
        for (int i = 0; i < processes; i++)
        {
            printf("%d ",safeSequence[i]);
        }
        printf("\n");
        
    }
    else {
        // Rollback the allocation if the system becomes unsafe
        printf("Request denied. System will enter an unsafe state. Rolling back the allocation.\n");
        for (i = 0; i < resources; i++) {
            available[i] += request[i];
            allocation[pr][i] -= request[i];
            need[pr][i] += request[i];
        }
    }
}
int main()
{
    int i,j;
    int pr;
    int processes,resources;
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the available resources:\n");
    for (i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    printf("Enter the maximum resource allocation for each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the current resource allocation for each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);
    }
    // Calculate the need matrix
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Enter the process number making the resource request: ");
    scanf("%d", &pr);

    printf("Enter the resource request for process %d:\n", pr);
    for (i = 0; i < resources; i++)
        scanf("%d", &request[i]);

    requestResources( pr, resources,processes);
    return 0;

}
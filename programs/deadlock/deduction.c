#include <stdio.h>
#include <stdbool.h>
// Maximum number of processes and resources
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

// Function to detect deadlock
bool isDeadlock(int allocation[][MAX_RESOURCES], int need[][MAX_RESOURCES], int processes, int resources) {
    bool finish[MAX_PROCESSES] = {false};
    int work[MAX_RESOURCES];
    int i, j, count = 0;
    // Initialize work array with 0
    for (i = 0; i < resources; i++)
        work[i] = 0;
    // Find an unfinished process whose needs can be satisfied
    while (count < processes) {
        bool found = false;
        for (i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (j = 0; j < resources; j++)
                        work[j] += allocation[i][j];
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        // If no process found, break the loop
        if (!found)
            break;
    }
    // Check if all processes finished
    if (count == processes)
        return false; // No deadlock
    else
        return true; // Deadlock detected
}

int main() {
    int processes, resources;
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);
    printf("Enter the resource allocation for each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);
    }
    printf("Enter the resource need for each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++)
            scanf("%d", &need[i][j]);
    }
    // Check if deadlock exists
    if (isDeadlock(allocation, need, processes, resources))
        printf("Deadlock detected.\n");
    else
        printf("No deadlock.\n");

    return 0;
}
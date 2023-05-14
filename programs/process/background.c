#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include<sys/types.h>

int main() {
    // Set the process ID of the process you want to check
    pid_t pid = 628506; // replace with actual process ID

    // Use the kill system call to check if the process is running
    int result = kill(pid, 0);

    // Check the result of the kill system call
    if (result == 0) {
        printf("The process with PID %d is running in the background.\n", pid);
    } else if (errno == ESRCH) {
        printf("The process with PID %d does not exist.\n", pid);
    } else {
        printf("An error occurred while checking the status of the process with PID %d.\n", pid);
    }

    return 0;
}

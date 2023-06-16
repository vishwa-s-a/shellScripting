#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int pfds[2];
    int status = pipe(pfds);

    if (status < 0)
    {
        perror("Pipe Error");
        exit(1);
    }

    char *writeInfo = "Pipes";
    char readInfo[\\];
    printf("\n Writing information to pipe: ");
    write(pfds[1], writeInfo, sizeof(writeInfo));
    printf("\n Information has been written");

    printf("\n Reading the information from pipe.");
    read(pfds[0], readInfo, sizeof(writeInfo));
    printf("\n The information that was read is : %s",readInfo);

}
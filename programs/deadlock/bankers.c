#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 
struct Process{
    int allocation[4],maximum[4];
    int need[4];
    bool state;// indicates whether the process has completed its job and left the resource or not
};

typedef struct Process process;
int main()
{
    int number;
    scanf("%d",&number);
    int completed=number;
    process p[]={{{0,0,1,2},{0,0,1,2},{0,0,0,0},false},{{1,0,0,0},{1,7,5,0},{0,0,0,0},false},{{1,3,5,4},{2,3,5,6},{0,0,0,0},false},{{0,6,3,2},{0,6,5,2},{0,0,0,0},false},{{0,0,1,4},{0,6,5,6},{0,0,0,0},false}};

    int available[] = {1,5,2,0};
    int safe[number];// stores the order of the process which is safe
    int z=0;
    //need matrix calculation
    for(int i=0;i<number;i++)
    {
       for(int j=0;j<4;j++)
       {

           p[i].need[j]=p[i].maximum[j]-p[i].allocation[j];
       }
    }
    while(completed>0)
    {
        //printf("%d\n",completed);
        for(int i=0;i<number;i++)
        {
            int j;
            if(p[i].state == false)
            {
                for(j=0;j<4;j++)
                {
                    if(p[i].need[j] > available[j])
                    break;
                }
                if(j==4)
                {
                    completed--;
                    p[i].state=true;
                    safe[z++]=i;
                    // now we have to return the resoruces to the available array
                    for(int v=0;v<4;v++)
                    {
                        available[v]+=p[i].allocation[v];
                    }
                }
            }

        }
    }

    // now to print the safe sequnce array
    printf("The safe sequence is: \n");
    for(int i=0;i<number;i++)
        printf("%d ",safe[i]);
    printf("\n");    
    return 0;
}
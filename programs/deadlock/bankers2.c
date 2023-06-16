#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 
struct Process{
    int allocation[3],maximum[3];
    int need[3];
    bool state;// indicates whether the process has completed its job and left the resource or not
};

typedef struct Process process;
int main()
{
    int number;
    scanf("%d",&number);
    int completed=number;
    process p[]={{{0,1,0},{7,5,3},{0,0,0},false},{{2,0,0},{3,2,2},{0,0,0},false},{{3,0,2},{9,0,2},{0,0,0},false},{{2,1,1},{2,2,2},{0,0,0},false},{{0,0,2},{4,3,3},{0,0,0},false}};

    int available[] = {3,3,2};
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
    for(int k=0;k<5;k++)
    {
        //printf("%d\n",completed);
        for(int i=0;i<number;i++)
        {
            int j;
            if(p[i].state == false)
            {
                for(j=0;j<3;j++)
                {
                    if(p[i].need[j] > available[j])
                    break;
                }
                if(j==3)
                {
                    completed--;
                    p[i].state=true;
                    safe[z++]=i;
                    // now we have to return the resoruces to the available array
                    for(int v=0;v<3;v++)
                    {
                        available[v]+=p[i].allocation[v];
                    }
                }
            }

        }
    }
    int flag = 1;  
    for (int i = 0; i < number; i++)  
    {  
        if (p[i].state == false)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if(flag==1)
    {
         // now to print the safe sequnce array
        printf("The safe sequence is: \n");
        for(int i=0;i<number;i++)
            printf("%d ",safe[i]);
        printf("\n");
    }
       
    return 0;
}
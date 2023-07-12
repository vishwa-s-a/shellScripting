#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 void display(int arr[], int n)
 {
    printf("[");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
 }
 bool isPresent(int arr[],int num,int current)
 {
    for(int i=0;i<num;i++)
    {
        if(arr[i]==current)
        return true;
    }
    return false;
 }
 int find(int arr[], int frames[], int n, int num, int index)
 {
    int result=-1;
    int z=0;
    int temp[num];
    for(int i=0;i<num;i++)
    {
        temp[i]=-1;
    }
    for(int i=index;i>=0;i--)
    {
        if(z==num)
        break;
        for(int j=0;j<num;j++)
        {
            if(arr[i]==frames[j] && temp[j]==-1){
            temp[j]=z;
            z++;
            }
            if(z==num)
            {
                result=j;
                break;
            }

        }
    }
    if(z!=num)
    {
        for(int i=0;i<num;i++)
        {
            if(temp[i]==-1){
            result=i;
            break;
            }
        }
    }
    return result;
 }
void lru(int arr[] ,int n, int num)
{
    int frames[num];
    int hit=0,fault=0;
    for(int i=0;i<num;i++)
    {
        frames[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        int current=arr[i];
        if(isPresent(frames, num,current))
        {
            hit++;
            printf("page hit: %d\n",current);

        }
        else{
            int index=find(arr,frames,n,num,i);
            if(index==-1)
            {
                index=i;
            }
            frames[index]=current;
            fault++;
            printf("page fault: %d\n",current);

        }
        display(frames,num);
    }
    printf("\nhits: %d\tfaults: %d",hit,fault);
}
int main(){
    int n,num;
    printf("Enter the number of frames: ");
    scanf("%d",&num);
    printf("Enter the number of page references: ");
    scanf("%d",&n);
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    lru(arr,n, num);
    
return 0;
}
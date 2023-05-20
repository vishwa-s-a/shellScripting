#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
 
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int num[], int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(num[j+1]<num[j])
            {
                swap(&num[j],&num[j+1]);
            }
        }
    }

    printf("printing the sorted array: \n");
    for (int v = 0;v < n; v++)
    {
        printf("%d ",num[v]);
    }
    printf("\n");
}
int main(){
int num[]={29,72,98,13,87,66,52,51,36};
int n=sizeof(num)/sizeof(num[0]);
sort(num,n);
return 0;
}
#include <stdio.h>
#include <stdlib.h>

int abs(int x) {
    return (x < 0) ? -x : x;
}
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void display(int num[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
}


int find(int queue[],int head,int n)
{
    int size=n;
    int temp[size];
    int head_index;

    for (int i = 0; i < size; i++)
    {
        temp[i]=abs(queue[i]-head);
    }
    int min=temp[0];
    for(int i=0;i<size;i++)
    {
        if(temp[i]<min)
        {
            swap(&temp[i],&min);
            head_index=i;
        }
    }
    return head_index;
}
int  scan(int queue[],int direction, int head, int n)
{

    int index=find(queue,head,n);
    int temp[n];
    int total_st=0,i=0,j=0;
    if(direction==1)//right side rotation
    {
        for(i=index+1;i<n;i++)
        {
            temp[j++]=queue[i];
        }
        for(i=index;i>=0;i--)
        {
            temp[j++]=queue[i];
        }

    }
    else//left side rotation
    {
       for(i=index;i>=0;i--)
        {
            temp[j++]=queue[i];
        } 
        for(i=index+1;i<n;i++)
        {
            temp[j++]=queue[i];
        }
    }
    for (int i = 0; i < n; i++) {
        total_st += abs(head - temp[i]);
        head = temp[i];
    }
    return total_st;  
}
int main() {
    int queue[1000], head, n, total_seek = 0;
    int direction;

    printf("Enter the size of the disk queue: ");
    scanf("%d", &n);

    printf("Enter the disk queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    int i, j;
    int index,min,max;
    int distance;

    // Sort the queue in ascending order
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (queue[j] > queue[j + 1]) {
                   swap(&queue[j], &queue[j+1]);
                }
            }
        }
    min=queue[0];
    max=queue[n-1];
    total_seek=scan(queue,direction,head,n);
    if (direction == 0) { // Left direction
        total_seek += 2*min;

    } else { // Right direction
        total_seek += 2*(199-max);
    }

    printf("Total Seek Time: %d\n", total_seek);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int start;
    int end;
    int profit;
}node;

int cmp(const void *a, const void *b)
{
    return (*(node *)a).end - (*(node *)b).end;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){ 
    node* arr =(node*)malloc(startTimeSize*sizeof(node));
    int* temp = (int*)malloc(startTimeSize*sizeof(int));
    for(int i=0; i<startTimeSize; i++){
        arr[i].start = startTime[i];
        arr[i].end = endTime[i];
        arr[i].profit = profit[i];
        temp[i] = 0;
    }
    qsort(arr, startTimeSize, sizeof(node), cmp);
    temp[0] = arr[0].profit;
    for(int i=1; i<startTimeSize; i++)
    {
        int t = 0;
        for(int j=i-1; j>=0; j--)
            if(arr[j].end <= arr[i].start)
            {
                t = temp[j];
                break;
            }
            if(t+arr[i].profit < temp[i-1] )
            {
                temp[i] =temp[i-1];
            }
            else
            {
                temp[i] =t+arr[i].profit;
            }
    }
    return temp[startTimeSize-1];
}

int main()
{
    int n,k,a,b;
    printf("Enter the number of jobs:");
    scanf("%d",&n);
    int startTime[n];
    int endTime[n];
    int profit[n];
    printf("Enter start time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&startTime[i]);
    }
    printf("Enter end time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&endTime[i]);
    }
    printf("Enter profit:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&profit[i]);
    }
    int ans = jobScheduling(startTime,n,endTime,n,profit,n);
    printf("Maximum profit: %d",ans);
    return 0;
}
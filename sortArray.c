#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int l,int mid,int r){
    int i=l;
    int j=mid+1;
    int k=l;
    
    int b[r+1];

    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    
    if(i>mid){
        while(j<=r){
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            k++;
            i++;
        }
    }
    
    for(int z=l;z<=r;z++){
        a[z]=b[z];
    }
}

void mergesort(int *a,int l,int r){
  if(l<r){
   int mid = (l+r)/2;
   mergesort(a,l,mid);
   mergesort(a,mid+1,r);
   merge(a,l,mid,r);
  }
}

int *sortArray(int* nums, int numsSize, int* returnSize){
    
    int l=0;
    int r=numsSize-1;
    
    mergesort(nums,l,r);
    
    *returnSize = numsSize;
    return nums;
}

int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int b[30],a[30]={0};
    printf("Enter elements: ");
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&b[i]);
    }
    int *c=sortArray(b,numsSize,a);
    printf("After Sorting: \n");
    for(int i=0;i<numsSize;i++)
    {
        printf("%d",c[i]);
    }
}
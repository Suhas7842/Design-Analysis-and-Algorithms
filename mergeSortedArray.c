#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
int i = m - 1;
    int j = n -1;
    while(i>=0 && j>=0) {
        if(nums1[i] > nums2[j]) {
            nums1[i+j+1] = nums1[i];
            i--;
        } else {
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }
    while(j >= 0) {
        nums1[i+j+1] = nums2[j];
        j--;
    }
    printf("Array after merging: ");
    for(int i=0;i<nums1Size;i++)
    {
        printf("%d ",nums1[i]);
    }
}

int main()
{
    int n,m,n1,n2,i;
    printf("Enter sizes of 2 arrays:");
    scanf("%d%d",&m,&n);
    n1=m+n;
    n2=n;
    int arr1[n1],arr2[n2];
    printf("Enter values of 1st array:");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter values of 2nd array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    merge(arr1,n1,m,arr2,n2,n);
}
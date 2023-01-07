#include<stdio.h>

int NumberOfPath(int m, int n){
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

int main()
{
    int t,a,b;
    printf("Test Cases: ");
    scanf("%d",&t);
    while(t-->0)
    {
        printf("Enter number of rows:");
        scanf("%d",&a);
        printf("Enter number of columns:");
        scanf("%d",&b);
        printf("Number of unique paths: %d",NumberOfPath(a,b));
    }
    return 0;
}
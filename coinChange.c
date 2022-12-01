#include<stdio.h>

int coinChange(int* coins, int coinsSize, int amount){
    if(coinsSize==1)
    {
        if(amount%coins[0]==0)
        {
            return amount/coins[0];
        }
        else
        {
            return -1;
        }
        
    }
    else if(amount==0)
    {
        return 0;
    }
    else
    {
         int a[coinsSize][amount+1],i,j;
        for(i=0;i<amount+1;i++)
        {
            if(i%coins[0]!=0)
                a[0][i]=amount+1;
            else
                a[0][i]=i/coins[0];
        }
        for(i=1;i<coinsSize;i++)
        {
            for(j=0;j<amount+1;j++)
            {
                if(j<coins[i])
                {
                    a[i][j]=a[i-1][j];
                }
                else if(j==coins[i])
                {
                    a[i][j]=1;
                }
                else
                {
                    if(a[i-1][j]<(a[i][j-coins[i]]+1))
                    {
                        a[i][j]=a[i-1][j];
                    }
                    else
                    {
                        a[i][j]=a[i][j-coins[i]]+1;
                    }
                }
                    
            }
        }
        i=a[coinsSize-1][amount];
        if(i==0||i>amount)
        {
            return -1;
        }
        else
        {
            return i;
        }
        
    }
}

int main()
{
    int n,amount;
    printf("Enter the number of denominations:");
    scanf("%d",&n);
    int coins[n];
    printf("Enter the denominations:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
    }
    printf("Enter amount:");
    scanf("%d",&amount);
    int a = coinChange(coins,n,amount);
    printf("Minimum number of coins: %d",a);
    return 0;
}
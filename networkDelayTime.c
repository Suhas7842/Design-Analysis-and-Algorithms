#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int networkDelayTime( int timesSize, int timesColSize,int times[timesSize][timesColSize], int n, int k){
        int dis[n+1];
        int max = -1;
        for(int i = 0; i <n+1; i++){
            dis[i] = INT_MAX;
        }
        dis[k] = 0;
        for(int i = 0; i <n; ++i){
            for(int j = 0; j < timesSize; ++j){
                int u = times[j][0];
                int v = times[j][1];
                int w = times[j][2];
                if(dis[u] != INT_MAX && dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }
        }
        for(int i = 1; i < n+1; i++){
            if(dis[i] > max){
                max = dis[i];
            }
        }
        if(max==INT_MAX)
        {
            return -1;
        }
        else
        {
            return max;
        }
}

int main()
{
    int n,k,a,b;
    printf("Enter the size of times array:");
    scanf("%d %d",&a,&b);
    int times[a][b];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&times[i][j]);
        }
    }
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter node to send signal:");
    scanf("%d",&k);
    int ans = networkDelayTime(a,b,times,n,k);
    printf("Minimum time: %d",ans);
    return 0;
}
#include<stdio.h>

int maximumUnits(int boxTypesSize, int boxTypesColSize,int boxTypes[boxTypesSize][boxTypesColSize],  int truckSize){

    int i,j,k=1,x,temp;
        for(i=0;i<boxTypesSize;i++)
        {
                for(j=i+1;j<boxTypesSize;j++)
                {
                        if(boxTypes[i][k] < boxTypes[j][k])
                        {
                            for(x=0;x<2;x++) {
                                temp=boxTypes[i][x];
                                boxTypes[i][x]=boxTypes[j][x];
                                boxTypes[j][x]=temp;
                                }
                        }
                }
        }
        for(i=0;i<boxTypesSize;i++)
    {
        for(j=0;j<boxTypesColSize;j++)
        {
            printf("%d ",boxTypes[i][j]);
        }
        printf("\n");
    }
    int max=0;
        for(int i=0;i<boxTypesSize;i++)
        {
            if(truckSize>0)
            {
                if(truckSize<boxTypes[i][0])
                {
                    max+=(boxTypes[i][1]*truckSize);
                }
                else
                {
                    max+=(boxTypes[i][1]*boxTypes[i][0]);
                }
                truckSize-=boxTypes[i][0];
            }
        }
        return max;
}

int main()
{
    int i,j,boxTypesSize,boxTypesColSize,truckSize;
    printf("Enter number of boxes: ");
    scanf("%d",&boxTypesSize);
    printf("Enter number of units per box: ");
    scanf("%d",&boxTypesColSize);
    int boxTypes[boxTypesSize][boxTypesColSize];
    printf("Enter values:\n");
    for(i=0;i<boxTypesSize;i++)
    {
        for(j=0;j<boxTypesColSize;j++)
        {
            scanf("%d",&boxTypes[i][j]);
        }
    }
    printf("Enter Truck Size: ");
    scanf("%d",&truckSize);
    int a=maximumUnits(boxTypesSize,boxTypesColSize,boxTypes,truckSize);
    printf("Total number of units: %d ",a);
    return 0;
}



#include<stdio.h>
#define inf 999
int distance[20];
int visited[20];
int cost[20][20];
int source;
int n;

int min_distance()
{
    int min=inf;
    int min_index;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && distance[i]<=min)
        {
            min=distance[i];
            min_index=i;
        }
    }
        return min_index;
}

void printresult()
{
    printf("Vertex and distance :\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d",i,distance[i]);
    }
}

void dijkstras()
{
    for(int v=0;v<n;v++)
    {
        distance[v]=inf;
        visited[v]=0;
    }
    distance[source]=0;

    for(int i=0;i<n-1;i++)
    {
        int min=min_distance();
        visited[min]=1;

        for(int j=0;j<n;j++)
        {
            if(!visited[j] && cost[min][j] && distance[min]!=inf && distance[j]>distance[min]+cost[min][j])
            distance[j]=distance[min]+cost[min][j];
        }
    }
    printresult();
}

void main()
{
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter Cost Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter source vertex:\n");
    scanf("%d",&source);
    dijkstras();
}
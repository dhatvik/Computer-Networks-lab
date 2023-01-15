#include<stdio.h>
#include<stdlib.h>

int bellman_ford(int G[20][20],int n,int E,int edge[50][2])
{
    int u,v,i,k,distance[20],parent[20],s,flag=1;

    for(i=0;i<n;i++)
    {
        distance[i]=1000;
        parent[i]=-1;
    }
    printf("\n Enter Source matrix ");
    scanf("%d",&s);
    distance[s-1]=0;

    for(i=0;i<n-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u=edge[k][0];
            v=edge[k][1];
            if(distance[v]>distance[u]+G[u][v])
            {
                distance[v]=distance[u]+G[u][v];
                parent[v]=u;
            }
        }
    }

    for(k=0;k<E;k++)
    {
        u=edge[k][0];
        v=edge[k][1];
        if(distance[v]>distance[u]+G[u][v])
        flag=0;
    }
    
    if(flag)
    {
        for(i=0;i<n;i++)
        printf("\nVertex %d -> cost =%d parent =%d",i+1,distance[i],parent[i]+1);
    }
    return flag;
}

void main()
{
    int n,i,j,k=0,G[20][20],edge[50][2];
    printf("\n Enter number of vertices ");
    scanf("%d",&n);
    printf("\n Enter the cost matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
            {
                edge[k][0]=i;
                edge[k++][1]=j;
            }
        }
    }
    if(bellman_ford(G,n,k,edge))
        printf("\n no negative weight cycle");
    else
    printf("\n Negative weight cycle exits ");

}
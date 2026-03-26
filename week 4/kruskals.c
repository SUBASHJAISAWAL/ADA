#include<stdio.h>
void kruskals();
int costs[10][10], sum,n , min, i, j, count, k, u, v, parent[10], t[10][10];
int union_ij(int, int);
int find(int);
int main()
{
    printf("Enter the number of vetices.\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix.\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&costs[i][j]);
        }
    }
    kruskals();
    return 0;
}

void kruskals()
{
    count=0;
    k=0;
    sum=0;
    for(i=0; i<n; i++)
        parent[i]=i;
    while(count!=n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            for(j=0; j<n;j++)
            {
                if(costs[i][j]<min && costs[i][j]!=0)
                {
                    min=costs[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        i=find(u);
        j=find(v);
        if(i!=j)
        {
            t[k][0]=u;
            t[k][1]=v;
            k++;
            count++;
            sum=sum+min;
            union_ij(i,j);
        }
        costs[u][v]=costs[v][u]=999;
    }
    printf("Spanning Tree:\n");
    for(i=0;i<k;i++)
    {
        printf("%d->%d\n",t[i][0],t[i][1]);
    }
    printf("Total cost=%d\n",sum);
}

int union_ij(int i,int j)
{
    if(i<j)
        parent[j]=i;
    else
        parent[i]=j;
    return 0;
}

int find(int v)
{
    while (parent[v]!=v)
    {
        v=parent[v];
    }
    return v;
}

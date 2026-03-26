#include<stdio.h>

void prims();

int cost[10][10], vis[10], vt[10], et[10][10], e=0;
int i, j, k, u, v, sum=0, n, m;

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter Adjacency matrix:\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    for(i=1; i<=n; i++)
        vis[i]=0;

    prims();

    printf("Minimal spanning tree:\n");

    for(i=1; i<=e; i++)
    {
       printf("%d -> %d\n", et[i][1], et[i][2]);
    }

    printf("Total cost = %d\n", sum);
    return 0;
}

void prims()
{
    int x=1, min;

    vt[x]=1;
    vis[x]=1;

    for(i=1; i<=n-1; i++)
    {
        j=x;
        min=999;


        for(k=1; k<=j; k++)
        {
            int tree_vertex = vt[k];

            for(m=1; m<=n; m++)
            {
                if(cost[tree_vertex][m] < min && vis[m]==0 && cost[tree_vertex][m]!=0)
                {
                    min = cost[tree_vertex][m];
                    u = tree_vertex;
                    v = m;
                }
            }
        }

        vt[++x] = v;
        et[i][1] = u;
        et[i][2] = v;
        e++;

        vis[v] = 1;
        sum = sum + min;
    }
}

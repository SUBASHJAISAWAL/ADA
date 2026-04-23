#include<stdio.h>

int src, dest[10], cost[10][10], n, vis[10];

void Dijkastras();

int main()
{
    printf("Enter no. of vertices: ");
    scanf("%d",&n);

    printf("Enter the cost adjacency matrix:\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source vertex:\n");
    scanf("%d", &src);

    // Initialize visited array
    for(int i=1; i<=n; i++)
        vis[i] = 0;

    Dijkastras();

    printf("\nShortest path:\n");
    for(int i=1; i<=n; i++)
    {
        printf("%d -> %d = %d\n", src, i, dest[i]);
    }

    return 0;
}

void Dijkastras()
{
    int i, u, min, count;

    // Initialize distances
    for (i=1; i<=n; i++)
        dest[i] = cost[src][i];

    vis[src] = 1;
    dest[src] = 0;   // distance to itself is 0
    count = 1;

    while(count < n)
    {
        min = 999;

        // Find minimum unvisited vertex
        for(i=1; i<=n; i++)
        {
            if(dest[i] < min && vis[i] == 0)
            {
                min = dest[i];
                u = i;
            }
        }

        vis[u] = 1;   // Mark selected vertex

        // Update distances
        for(i=1; i<=n; i++)
        {
            if(vis[i] == 0 && dest[u] + cost[u][i] < dest[i])
            {
                dest[i] = dest[u] + cost[u][i];
            }
        }

        count++;
    }
}

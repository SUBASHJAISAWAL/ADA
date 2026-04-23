#include<stdio.h>

int main()
{
    int n, i, j;
    float w[10], p[10], ratio[10];
    float capacity, temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%f", &p[i]);

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%f", &w[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Step 1: Calculate ratio
    for(i = 1; i <= n; i++)
    {
        ratio[i] = p[i] / w[i];
    }

    // Step 2: Sort items by ratio (descending)
    for(i = 1; i <= n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                // swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap profit
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                // swap weight
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }

    // Step 3: Selection
    float total_profit = 0;

    for(i = 1; i <= n; i++)
    {
        if(w[i] <= capacity)
        {
            total_profit += p[i];
            capacity -= w[i];
        }
        else
        {
            total_profit += p[i] * (capacity / w[i]);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", total_profit);

    return 0;
}

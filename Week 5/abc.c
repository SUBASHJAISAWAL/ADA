#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX], temp[MAX];

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergesort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}


int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    int a[]={35,10,15,45,25,20,40};
    mergesort(0,6);
    printf("The sorted array is:");
    for(i=0;i<=6;i++)
    {
        printf("%d",a[i]);
    }

    srand(time(NULL));

    printf("\nTime Taken (seconds)\n");


    for (n = 10000; n <= 50000; n += 10000)
    {

        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }


        start = clock();


        mergesort(0, n - 1);


        end = clock();


        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("N = %d -> Time = %f seconds\n", n, time_taken);
    }

    return 0;
}

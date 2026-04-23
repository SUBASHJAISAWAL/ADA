#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    int n, i, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    printf("\nTime Taken (seconds):\n");

    for (y = 10000; y <= 50000; y += 10000) {


        int temp[y];
        for (i = 0; i < y; i++) {
            temp[i] = rand() % 10000;
        }

        start = clock();

        quicksort(temp, 0, y - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("N = %d, Time = %f seconds\n", y, time_taken);
    }

    return 0;
}

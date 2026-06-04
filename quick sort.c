#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randomPivot(int low, int high) {
    return low + rand() % (high - low + 1);
}

int partition(int arr[], int low, int high) {
    int randIndex = randomPivot(low, high);
    swap(&arr[low], &arr[randIndex]);

    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n, i;

    // Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));

    // Generate random elements automatically
    printf("Generated array:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // random numbers 0-99
        printf("%d ", arr[i]);
    }

    clock_t start, end;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}

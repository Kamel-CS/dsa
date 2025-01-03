#include <stdlib.h>

// Function to create a new array dynamically
int* createArray(int size) {
    return (int*)malloc(size * sizeof(int));
}

// Function to partition the array into two new subarrays
void Partition(int *arr, int n, int **Ainf, int *n1, int **Asup, int *n2, int pivot) {
    *n1 = 0; // Number of elements less than or equal to pivot
    *n2 = 0; // Number of elements greater than pivot

    // Allocate memory for subarrays
    *Ainf = createArray(n);
    *Asup = createArray(n);

    for (int i = 0; i < n - 1; i++) { // Iterate up to n - 1 (exclude pivot)
        if (arr[i] <= pivot)
            (*Ainf)[(*n1)++] = arr[i];
        else
            (*Asup)[(*n2)++] = arr[i];
    }
}

// Function to concatenate two arrays with the pivot
void Concatenate(int *arr, int *Ainf, int n1, int pivot, int *Asup, int n2) {
    int index = 0;

    // Copy elements of Ainf to the main array
    for (int i = 0; i < n1; i++)
        arr[index++] = Ainf[i];

    // Add the pivot
    arr[index++] = pivot;

    // Copy elements of Asup to the main array
    for (int i = 0; i < n2; i++)
        arr[index++] = Asup[i];
}

// Regular QuickSort function
void QuickSort(int *arr, int n) {
    if (n > 1) {
        int pivot = arr[n - 1]; // Choose the last element as the pivot

        int *Ainf, *Asup; // Subarrays for elements less and greater than pivot
        int n1, n2;       // Sizes of the subarrays

        // Partition the array
        Partition(arr, n, &Ainf, &n1, &Asup, &n2, pivot);

        // Recursively sort the subarrays
        QuickSort(Ainf, n1);
        QuickSort(Asup, n2);

        // Concatenate sorted subarrays and pivot into the main array
        Concatenate(arr, Ainf, n1, pivot, Asup, n2);

        // Free allocated memory for subarrays
        free(Ainf);
        free(Asup);
    }
}

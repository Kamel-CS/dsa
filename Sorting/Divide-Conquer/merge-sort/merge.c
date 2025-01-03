#include <stdlib.h>


void Merge(int* arr, int l, int mid, int h) {

    int n1 = mid - l + 1; // Size of the left subarray
    int n2 = h - mid;     // Size of the right subarray

    // Create temporary arrays
    int* left = (int*)malloc(n1 * sizeof(int));
    int* right = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }

    // Copy any remaining elements from the left subarray
    while (i < n1)
        arr[k++] = left[i++];

    // Copy any remaining elements from the right subarray
    while (j < n2)
        arr[k++] = right[j++];

    // Free the allocated memory
    free(left);
    free(right);
}

void MergeSort(int* arr, int l, int h) {
    
    if (l < h) {    // there is at least one element
        
        int mid = (l + h) / 2;

        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);

        Merge(arr, l, mid, h);
    }
}

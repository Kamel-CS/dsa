// Two-pointer Partition function to partition the array based on the pivot
int TwoPointerPartition(int *arr, int l, int h) {
    int pivot = arr[h]; // Last element as pivot
    int i = l - 1;      // Pointer to track smaller elements
    int j = h;          // Pointer to track larger elements

    while (1) {
        // Move i to the right until we find an element greater than the pivot
        do {
            i++;
        } while (arr[i] <= pivot && i <= h);

        // Move j to the left until we find an element smaller than the pivot
        do {
            j--;
        } while (arr[j] > pivot && j >= l);

        // If i < j, swap the elements at i and j
        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break; // Exit the loop when the pointers cross
    }

    // Place the pivot in its correct position
    swap(&arr[i], &arr[h]);

    return j; // Return the final position of the pivot
}


int Partition(int *arr, int l, int h) {
    int pivot = arr[h]; // Last element as pivot
    int j = l;          // decides the new position of the pivot

    for (int i = l; i < h; i++) // Loop through elements except the pivot
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[j]); // Swap current element to the correct position
            j++;                    // Increment boundary
        }

    // Place the pivot in its correct position
    swap(&arr[j], &arr[h]);

    return j; // Return the final position of the pivot
}

// QuickSort function to sort the array
void QuickSort(int *arr, int l, int h) {
    if (l < h) {
        int pivotIndex = Partition(arr, l, h); // Partition the array
        QuickSort(arr, l, pivotIndex - 1);    // Sort the left subarray
        QuickSort(arr, pivotIndex + 1, h);    // Sort the right subarray
    }
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {

        int maxIndex = i;

        for (int j = i + 1; j < size; j++)
            if (arr[j] > arr[maxIndex])
                maxIndex = j;

        if (maxIndex != i)      // optional condition
            swap(&arr[maxIndex], &arr[i]);
    }
}

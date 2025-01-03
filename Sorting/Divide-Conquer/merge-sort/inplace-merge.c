#define SIZE 100
int temp[SIZE];


void InPlaceMerge(int* arr, int l, int mid, int h) {

    int i = l;
    int j = mid + 1;
    int k = l;

    // merging
    while (i <= mid && j <= h) {    // use of '=' due to it being indexes
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    for (; i <= mid; i++)
        temp[k++] = arr[i++];
    for (; j <= h; j++)
        temp[k++] = arr[j++];

    // copy to original array
    for (i = l; i <= h; i++)
        arr[i] = temp[i];
}


void InPlaceMergeSort(int* arr, int l, int h) {
    
    if (l < h) {    // there is at least one element
        
        int mid = (l + h) / 2;

        InPlaceMergeSort(arr, l, mid);
        InPlaceMergeSort(arr, mid + 1, h);

        InPlaceMerge(arr, l, mid, h);
    }
}

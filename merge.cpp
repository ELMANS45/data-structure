void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int* L = new int[size1];
    int* R = new int[size2];
    int i, j, k=left;
    for (i = 0; i < size1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < size2; j++)
        R[j] = arr[mid + 1 + j];
    i = j = 0;
    while (i < size1 && j < size2) {
        if (L[i] < R[j]) {
            arr[k] = L[i]; i++;
        }
        else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < size1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < size2) {
        arr[k] = R[j];
        j++; k++;
    }
    delete[]R;
    delete[]L;
}
void merge_sort(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (left < right) {
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

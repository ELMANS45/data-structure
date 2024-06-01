void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >0  && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }       // 5 6 7 4 12
            //   
}
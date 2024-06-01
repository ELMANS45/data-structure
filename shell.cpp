void shell(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap = gap / 2) {//logn
        for (int i = gap; i < n; i++) {//n
            int tmp = arr[i];
            int j;
            for ( j = i; arr[j - gap] > tmp; j = j - gap) {//n
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
    }   //3 1 5 2 0 8 4 9 3 6
}
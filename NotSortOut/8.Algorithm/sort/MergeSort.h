#pragma once

void Merge(int arr[], int l, int m, int r) {
    int n = r-l+1;
    int *temp = new int [n];
 
    int index = 0;
    int i = l, j = m+1;
    while(i <= m && j <= r) {
        temp[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    for(; i <= m; arr[index++] = arr[i++]);
    for(; j <= r; arr[index++] = arr[j++]);
    
    for(int k = 0;k < n; arr[k++] = temp[k++]);
    
    delete [] temp;
}

void Devide(int arr[], int l, int r) {
    if(r > l && l >= 0) {
        int m = l+(r-l)/2;
        Devide(arr, l, m);
        Devide(arr, m+1, r);
        Merge(l, m, r);
    }
}

void MergeSort(int arr[], int n) {
    if(n > 1) {
        int l = 0, r = n;
        Devide(arr, l, n);
    }
}


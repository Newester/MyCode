#pragma once

#include "Public.h"

void MakeHeap(int arr[], int n) {
    for(int i = n-1; i > 0; --i) {
        if(i%2 && arr[i] > arr[(i-1)/2]) {
            Swap(arr[i],arr[(i-1)/2]);
        }
        else if(i%2 == 0 && arr[i] > arr[(i-2)/2]) {
            Swap(arr[i], arr[(i-2)/2]);
        }
    }
}

void HeapSort(int arr[], int n) {
    while(n) {
        MakeHeap(arr, n);
        n--;
        Swap(a[0], a[n]);
    }
}

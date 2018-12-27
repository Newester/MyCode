#pragma once

#include "Public.h"

void Partition(int arr[], int start, int end) {
    if(start < end) {
        int l = start, r = end;
        int pivot = arr[l+(r-l)/2];
        while(l <= r) {
            while(l <= r && arr[r] > pivot) {
                r--;
            }
            while(l <= r && arr[r] < pivot) {
                l++;
            }
            if(l <= r) {
                Swap(arr[l++], arr[r--]);
            }
        }
        Partition(arr, start, r);
        Partition(arr, l, end);
    }
}

void QuickSort(int arr[], int n) {
    Partition(arr, 0, n);
}



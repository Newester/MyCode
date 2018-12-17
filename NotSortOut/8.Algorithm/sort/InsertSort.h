#pragma once

#include "Public.h"

void InsertSort(int arr[], int n) {
    if(n > 1) {
        for(int i = 0; i < n; ++i) {
            for(int j = i; j > 0 && arr[j-1] > arr[j]; ++j) {
                Swap(arr[j-1], arr[j]);
            }
        }
    }
}


#pragma once

#include "Public.h"

void SelectSort(int arr[], int n) {
    if(n > 1) {
        int mindex = 0;
        for(int i = 0; i < n; ++i) {
            mindex = i;
            for(int j = i+1; j < n; ++j) {
                if(arr[j] < arr[mindex]) {
                    mindex = j;
                }
            }
            Swap(arr[mindex], arr[i]);
        }
    }
}

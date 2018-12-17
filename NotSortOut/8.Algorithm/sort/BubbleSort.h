#pragma once

#include "Public.h"

void BubbleSort(int arr[], int n) {
    if(n > 1) {
        bool flag = false;
        for(int i = 0; i < n; ++i) {
            flag = true;
            for(int j = 1; j < n-1-i; ++j) {
                if(arr[j-1] > arr[j]) {
                    Swap(arr[j-1], arr[j]);
                    flag = false;
                }
            }
            if(flag == true) {
                return;
            }
        }
    }
}

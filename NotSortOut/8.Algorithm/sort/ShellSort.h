
#pragma once

#include "Public.h"

void ShellSort(int arr[], int n) {
    if(n > 1) {
        for(int gap = n/2; gap > 0; gap /= 2) {
            for(int i = gap; i < n; ++i) {
                for(int j = i; j-gap >= 0 && arr[j-gap] > arr[j]; j -= gap) {
                    Swap(arr[j-gap], arr[j]);
                }
            }
        }
    }
}

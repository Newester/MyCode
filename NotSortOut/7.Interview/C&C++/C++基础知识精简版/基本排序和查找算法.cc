#include <iostream>

/**
 * @brief 冒泡排序
**/
template <typename T>
void bubble_sort(T arr[], int n)
{
    int i, j;
    bool flag;
    for(i = 0; i < n-1; ++i)
    {
        flag = false;
        for(j = i+1; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = true;
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
        if(false == flag)
        {
            break;
        }
    }
}

/**
 * @brief 快速排序
**/
template <typename T>
void quick_sort(T arr[], int left, int right)
{
    if(left < right)
    {
        int start = left, end = right;
        T piovt = arr[left];
        while(start < end)
        {
            while(start < end && arr[end] >= piovt)
            {
                end--;
            }
            if(start < end) 
            {
                arr[start] = arr[end];
                end++;
            }

            while(start < end && arr[start] < piovt)
            {
                start++;
            }
            if(start < end)
            {
                arr[end] = arr[start];
                end--;
            }
        }
        arr[start] = piovt;
        quick_sort(arr, left,start -1);
        quick_sort(arr, start+1, right);
    }
}

/**
 * @brief 插入排序
**/
template <typename T>
void insert_sort(T arr[], int n)
{
    int i, j;
    T temp;
    for(int i = 0; i < n; i++)
    {
        temp = arr[i+1];
        j = i;
        while(j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

/**
 * @brief 选择排序
**/
template <typename T>
void select_short(T arr[], int n)
{
    int i, j, min;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
            if(min != i)
            {
                arr[i] = arr[i] ^ arr[min];
                arr[min] = arr[i] ^ arr[min];
                arr[i] = arr[i] ^ arr[min];
            }
        }
    }
}

template <typename T>
int binary_search_by_loop(T arr[], const T& target, int n)
{
    int left = 0;
    int right = n -1;
    while(left <= right)
    {
        int middle = left + (right - left) / 2;
        if(arr[middle] == target)
        {
            return middle;
        }
        if(target > arr[middle])
        {
            left = middle+1;
        }
        else
        {
            right = middle-1;
        }
    }
    return -1;
}

template <typename T>
int binary_search_by_recursion(T arr[], const T& target, int left, int right)
{
    if(left > right)
    {
        return -1;
    }
    else
    {
        int middle = left + (right - left) / 2;
        if(target == arr[middle])
        {
            return middle;
        }
        else if(target < arr[middle])
        {
            return binary_search_by_recursion(arr, target, left, middle-1);
        }
        else
        {
            return binary_search_by_recursion(arr, target, middle+1, right);
        }
    }
}


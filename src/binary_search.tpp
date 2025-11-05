#include "binary_search.h"
#pragma once

template<typename T>
int BSorter<T>::binary_search(const T arr[], int n, const T& target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止整型溢位

        if (arr[mid] == target) {
            return mid;     // 找到了
        }
        else if (arr[mid] < target) {
            left = mid + 1; // 去右侧找
        }
        else {
            right = mid - 1; // 去左侧找
        }
    }

    return -1; // 找不到
}


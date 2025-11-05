#ifndef BSORTER_H
#define BSORTER_H

#include <iostream>

template<typename T>
class BSorter {
public:
    // 在已排序数组 arr 中进行二分查找，找元素 target
    // 如果找到返回下标，否则返回 -1
    static int binary_search(const T arr[], int n, const T& target);
};

#include "binary_search.tpp"   // 模板实现放这里

#endif // SORTER_H


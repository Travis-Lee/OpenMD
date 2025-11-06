#ifndef MAX_SUBARRAY_H
#define MAX_SUBARRAY_H

#include <vector>

template<typename T>
class MaxSubarray {
public:
    MaxSubarray() = default;
    ~MaxSubarray() = default;

    // 求最大连续子数组和
    T findMaxSum(const std::vector<T>& nums);
};

#endif // MAX_SUBARRAY_H


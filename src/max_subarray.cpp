#include "max_subarray.h"
#include <algorithm>
#include <limits>

/*
T(0)如果数组是空的，就返回 类型 T 的 0。用类型 T 构造一个值为 0 的对象;
return T{}; 也可以的。默认初始化（同样变成0）

T currentSum = nums[0];
T maxSum = nums[0];
当前连续子数组的和（我们正在累加的和）目前找到的最大子数组和的结果
| 变量         | 代表什么意思   | 初始化成啥   | 为什么          |
| ---------- | -------- | ------- | ------------ |
| currentSum | 当前连续子数组和 | nums[0] | 从第一个元素开始累加   |
| maxSum     | 目前找到的最大和 | nums[0] | 起初最大值就是第一个元素 |
| 步骤     | 代码                                                 | 人话解释                          |
| ------ | -------------------------------------------------- | ----------------------------- |
| 是否继续累加 | `currentSum = max(nums[i], currentSum + nums[i]);` | 这个数要么单干(重新开始)，要么加入队伍(累加)，谁大选谁 |
| 更新最大和  | `maxSum = max(maxSum, currentSum);`                | 当前结果比历史最好成绩还高吗？如果是就记录下来       |
*/

// 模板函数实现
template<typename T>
T MaxSubarray<T>::findMaxSum(const std::vector<T>& nums) {
    if (nums.empty()) return T(0);

    T currentSum = nums[0];
    T maxSum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

template class MaxSubarray<int>;
template class MaxSubarray<double>;


#include "two_sum.h"
#include <unordered_map> // 哈希表

std::vector<int> TwoSum::findIndices(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> mp; // 值 -> 下标

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i]; // 我需要另一个数

        // 如果 need 已经出现, 两个答案就找到了
        if (mp.count(need)) {
            return { mp[need], i };
        }

        // 记录当前数和它的下标
        mp[nums[i]] = i;
    }
    
    return {}; // 按题意一定有答案，这里只是兜底
}


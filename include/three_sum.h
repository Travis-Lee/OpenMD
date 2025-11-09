#ifndef THREESUM_H
#define THREESUM_H

#include <vector>

class ThreeSum {
public:
    ThreeSum() = default;
    ~ThreeSum() = default;
    // 返回所有不重复的三元组
    std::vector<std::vector<int>> findTriplets(std::vector<int>& nums);
};

#endif // THREESUM_H


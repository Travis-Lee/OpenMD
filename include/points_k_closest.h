#pragma once
#include <vector>
#include <cmath>
#include <queue>

template<typename T>

class KClosestPoints{
public:
    KClosestPoints() = default;
    ~KClosestPoints() = default;
   
    // 输入 points 矩阵和 k，返回离原点最近的 k 个点
    std::vector<std::vector<T>> findClosest(
        const std::vector<std::vector<T>>& points, int k);     

};

#include "points_k_closest.h"

// 模板类实现必须在 cpp 中显式实例化，否则链接会报错
template<typename T>
std::vector<std::vector<T>> KClosestPoints<T>::findClosest(
    const std::vector<std::vector<T>>& points, int k)
{
    
    std::vector<std::vector<T>> sortedPoints = points;
    
    std::sort(
        sortedPoints.begin(),
        sortedPoints.end(),
        [](const std::vector<T>& a, const std::vector<T>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        }
    );
    std::vector<std::vector<T>> result(sortedPoints.begin(), sortedPoints.begin() + k);
    
    return result;
}

// 显式实例化
template class KClosestPoints<int>;
template class KClosestPoints<double>;


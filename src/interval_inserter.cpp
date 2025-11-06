#include "interval_inserter.h"
#include <algorithm>


// ================= 比较函数 =================
template<typename T>
bool IntervalInserter<T>::compare(const Interval<T>& lhs, const Interval<T>& rhs) {
    return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

// ================= merge 实现 =================
template<typename T>
std::vector<Interval<T>> IntervalInserter<T>::merge(std::vector<Interval<T>>& intervals) {
    std::vector<Interval<T>> result;
    if (intervals.empty()) return result;

    std::sort(intervals.begin(), intervals.end(), compare);

    for (const auto& interval : intervals) {
        if (!result.empty() && result.back().end >= interval.start) {
            result.back().end = std::max(result.back().end, interval.end);
        } else {
            result.push_back(interval);
        }
    }
    return result;
}

// ================= insert 实现 =================
template<typename T>
std::vector<Interval<T>> IntervalInserter<T>::insert(std::vector<Interval<T>>& intervals,
                                                      const Interval<T>& newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
}

// ================= 显式实例化模板 =================
template class IntervalInserter<int>;
// template class IntervalInserter<double>; // 如果需要 double 可以取消注释


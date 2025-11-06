#ifndef INTERVAL_INSERTER_H
#define INTERVAL_INSERTER_H

#include <vector>

template<typename T>
struct Interval {
    T start;
    T end;
    Interval() : start(0), end(0) {}
    Interval(T s, T e) : start(s), end(e) {}
};

template<typename T>
class IntervalInserter {
public:
    IntervalInserter()=default;
    ~IntervalInserter()=default;

    std::vector<Interval<T>> insert(std::vector<Interval<T>>& intervals,
                                    const Interval<T>& newInterval);

private:
    std::vector<Interval<T>> merge(std::vector<Interval<T>>& intervals);
    static bool compare(const Interval<T>& lhs, const Interval<T>& rhs);
};

#endif // INTERVAL_INSERTER_H


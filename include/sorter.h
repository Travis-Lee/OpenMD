#ifndef SORTER_H
#define SORTER_H

template<typename T>
class Sorter {
public:
    Sorter();
    ~Sorter();
    static void sort(T arr[], int n);
    static T get_max(T arr[],int n);
    static T get_min(T arr[],int n);
    static double get_mean(T arr[],int n);
private:
    static T max;
    static T min;
    static double mean;
};

#include "sorter.tpp"
#endif // MAT_H

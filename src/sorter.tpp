#include "sorter.h"
#pragma once

template<typename T>
void Sorter<T>::sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

template<typename T>
T Sorter<T>::max;

template<typename T>
T Sorter<T>::min;

template<typename T>
double Sorter<T>::mean;

template<typename T>
T Sorter<T>::get_max(T arr[], int n) {
    if(n==0){
        throw std::invalid_argument("arr is null, cant get the max value");
    }
    max=arr[0];
    for(size_t i=1;i<n;i++){
        if(arr[i]>max){
           max=arr[i];
        }
    }
    return max;
}

template<typename T>
T Sorter<T>::get_min(T arr[], int n) {
    if(n==0){
        throw std::invalid_argument("arr is null, cant get the min value");
    }
    min=arr[0];
    for(size_t i=1;i<n;i++){
        if(arr[i]<min){
           min=arr[i];
        }
    }
    return min;
}

template<typename T>
double Sorter<T>::get_mean(T arr[], int n) {
    if (!arr || n <= 0)
        throw std::invalid_argument("arr is null or empty");

    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    mean= sum / n;
    return mean;
}


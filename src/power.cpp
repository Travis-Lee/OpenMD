#include "power.h"
#include <cmath>

template<typename T>
Power<T>::Power() {}  // 构造函数

template<typename T>
Power<T>::~Power() {} // 析构函数

template<typename T>
T Power<T>::power(T base, int exponent){
    g_InvalidInput = false;

    if (equal(base, T(0)) && exponent < 0){
        g_InvalidInput = true;
        return 0;
    }

    unsigned int absExponent = exponent < 0 ? -exponent : exponent;
    T result = PowerWithUnsignedExponent(base, absExponent);  // 注意大小写

    return exponent < 0 ? T(1) / result : result;
}

template<typename T>
bool Power<T>::equal(T num1, T num2){
    return std::abs(num1 - num2) < 1e-7;
}

template<typename T>
T Power<T>::PowerWithUnsignedExponent(T base, unsigned int exponent){
    if (exponent == 0) return 1;
    if (exponent == 1) return base;

    T result = PowerWithUnsignedExponent(base, exponent >> 1); // 注意大小写
    result *= result;
    if (exponent & 0x1) result *= base;

    return result;
}

// 显式实例化模板
template class Power<double>;


#ifndef ARRAY_DUPLICATION_H
#define ARRAY_DUPLICATION_H

#include <cstddef>

template<typename T>
class ArrDup
{
public:
    // 构造函数可选，这里简单使用静态方法
    ArrDup();
    ~ArrDup();

    // 查找重复元素
    // numbers: 数组指针
    // length: 数组长度
    // duplication: 输出重复元素
    // 返回 true 如果找到重复元素
    bool find_duplicate(T numbers[], std::size_t length, T* dup_element);

    void find_duplicate(T numbers[],std::size_t length);
    
    T dup_value;
    std::size_t dup_index;
    bool found = false; 
};

#include "array_duplication.tpp"  // 包含模板实现
#endif // ARRAY_DUPLICATION_H


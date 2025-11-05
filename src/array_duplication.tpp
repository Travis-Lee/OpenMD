#include "array_duplication.h"
#pragma once

template<typename T>
ArrDup<T>::ArrDup() = default;

template<typename T>
ArrDup<T>::~ArrDup() = default;

template<typename T>

bool ArrDup<T>::find_duplicate(T numbers[], std::size_t length, T* dup_element){

    if(numbers==nullptr || length==0){
        return false;
    }
    
    for(std::size_t i=0; i<length;i++){
        if(numbers[i]<0 || numbers[i]>=static_cast<T>(length))
        return false;
    }
    for(std::size_t i = 0; i < length; ++i)
    {
        while(numbers[i] != static_cast<T>(i))
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *dup_element = numbers[i];
                return true;
            }

            // 交换 numbers[i] 和 numbers[numbers[i]]
            T temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;

}

template<typename T>
void ArrDup<T>::find_duplicate(T numbers[], std::size_t length){
    found = false;
    
    if(numbers==nullptr || length==0){
        return;
    }
    
    for(std::size_t i=0; i<length;i++){
        if(numbers[i]<0 || numbers[i]>=static_cast<T>(length))
        return;
    }
    for(std::size_t i = 0; i < length; ++i)
    {
        while(numbers[i] != static_cast<T>(i))
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                dup_value = numbers[i];
                dup_index = i;
                found = true;
                return;
            }

            // 交换 numbers[i] 和 numbers[numbers[i]]
            T temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
}


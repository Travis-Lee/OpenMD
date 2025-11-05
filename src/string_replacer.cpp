#include "string_replacer.h"
#include <cstring>
#include <iostream>

/*
这段 ReplaceBlank 函数的作用是 在原地把字符串中的空格 ' ' 替换成 %20。它的做法是：
先统计字符串长度和空格数量，计算替换后字符串的新长度，并检查数组容量是否足够。
从字符串末尾开始向后搬运字符，遇到空格就写 %20（倒着写），普通字符原样搬过去，这样不会覆盖原有字符。
循环结束条件是：所有字符都搬完（即 indexOfOriginal 遍历到开头，或者新下标 indexOfNew 到达原字符位置），保证整个字符串安全完成空格替换。
简单来说，就是**“先数数，再从后往前搬，把空格扩展成 %20，原字符保持原位”**。
 while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
 indexOfOriginal：原字符串当前位置，从末尾向前
 indexOfNew：新字符串当前位置，从末尾向前
 循环只在 indexOfNew > indexOfOriginal 时才继续
 一旦 indexOfNew <= indexOfOriginal → 循环停止
*/
template <typename CharT>
void StringReplacer<CharT>::ReplaceBlank(CharT str[], int length) {
    if (str == nullptr || length <= 0) return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (str[i] != '\0') {
        ++originalLength;
        if (str[i] == ' ') ++numberOfBlank;
        ++i;
    }

    std::cout<<"OLen:"<<originalLength<<std::endl;

    int newLength = originalLength + numberOfBlank * 2;
    
    std::cout<<"NLen:"<<newLength<<std::endl;
    std::cout<<"Len:"<<length<<std::endl;
    
    if (newLength > length) return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if (str[indexOfOriginal] == ' ') {
            std::cout<<"index org"<<indexOfOriginal<<" =====>indexofnew:"<<indexOfNew<<std::endl;
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        } else {
            std::cout<<"indexofnew====>:"<<indexOfNew<<"   indexoforg====>:"<<indexOfOriginal<<std::endl;
            str[indexOfNew--] = str[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}

// 显式实例化模板
template class StringReplacer<char>;

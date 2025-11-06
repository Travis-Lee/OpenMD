#include "ransom_note.h"
#include <iostream>

// ----------------- 模板实现 -----------------
template<typename CharType>
std::vector<int> RansomNote<CharType>::countLetters(const std::basic_string<CharType>& str) {
    std::vector<int> counts(26, 0); // 假设只考虑小写 a-z
    for (CharType c : str) {
        counts[c - 'a']++;
    }

    // 打印结果
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {  // 只打印出现过的字母
            std::cout<<"!!!!!!!!!!!!!!"<<std::endl;
            //std::cout << char('a' + i) << ": " << counts[i] << std::endl;
            std::cout << "i:"<<i<<" letter : " << counts[i] << std::endl;
        }
    }

    return counts;
}

template<typename CharType>
bool RansomNote<CharType>::canConstruct(const std::basic_string<CharType>& ransomNote,
                                        const std::basic_string<CharType>& magazine) {
    std::vector<int> magCount = countLetters(magazine);

    for (CharType c : ransomNote) {
        if (--magCount[c - 'a'] < 0)
            return false;
    }
    return true;
}

// ----------------- 显式实例化模板 -----------------
template class RansomNote<char>;


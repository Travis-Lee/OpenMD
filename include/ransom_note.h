#ifndef RANSOM_NOTE_H
#define RANSOM_NOTE_H

#include <string>
#include <vector>

template<typename CharType>
class RansomNote {
public:
    RansomNote() = default;
    ~RansomNote() = default;

    // 判断 ransomNote 是否可以由 magazine 构造
    bool canConstruct(const std::basic_string<CharType>& ransomNote,
                      const std::basic_string<CharType>& magazine);

private:
    // 统计字符串中字母出现次数
    std::vector<int> countLetters(const std::basic_string<CharType>& str);
};

#endif // RANSOM_NOTE_H


#ifndef LONGEST_SUBSTRING_H
#define LONGEST_SUBSTRING_H

#include <string>

class LongestSubstring {
public:
    LongestSubstring() = default;
    ~LongestSubstring() = default;
    static int lengthOfLongestSubstring(const std::string &s);
    static std::string getLongestSubstring(const std::string &s);
};

#endif // LONGEST_SUBSTRING_H


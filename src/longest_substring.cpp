#include "longest_substring.h"
#include <vector>
#include <algorithm>

/*
len++是如何变化的？
开始: len = 0
遇到 a → len = 1
遇到 b → len = 2
遇到 c → len = 3
遇到 a (重复) → 停止！len 保持 = 3
*/
int LongestSubstring::lengthOfLongestSubstring(const std::string &s) {
    int maxLen = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        std::vector<bool> used(256, false); // ASCII 记录是否出现 创建一个 256 个位置的布尔数组，并把所有位置都初始化为 false，也就是256大小全是false的的数组
        int len = 0; //初始化一个长度的参数，初始值为0
        for (int j = i; j < n; j++) { //这里意思是从起点i开始，依次检查字符，这里从i开始是因为最长子串，可能不是从0开始的可能是任何的位置，必须尝试每个起点，才能保证找到最长的
            if (used[s[j]]) break; // 遇到重复，停止 这里意思是s[j]再次出现的话就是表示再词出现了
            used[s[j]] = true; //这个时候就是表示他从false编程器true了
            len++;
        }
        maxLen = std::max(maxLen, len);
    }
    return maxLen;
}

std::string LongestSubstring::getLongestSubstring(const std::string &s) {
    int maxLen = 0;
    int startIndex = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        std::vector<bool> used(256, false);
        int len = 0;
        for (int j = i; j < n; j++) {
            if (used[s[j]]) break;
            used[s[j]] = true;
            len++;
        }
        if (len > maxLen) {
            maxLen = len;
            startIndex = i;
        }
    }
    return s.substr(startIndex, maxLen);
}


/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map; // 用哈希表存储字符出现的次数
        int len = 0, count = 0; // 

        for(const auto& c : s) {
            map[c]++; // 统计字符出现的次数
        }
        for(const auto& m : map) {
            if(m.second % 2 == 0) { // 如果字符出现的次数为偶数，则直接加到len中
                len += m.second;
            } else { // 如果字符出现的次数为奇数，则加到len中的同时，count加1
                len += m.second - 1;
                count++;
            }
        }

        return count > 0 ? len + 1 : len; // 如果count大于0，则说明有字符出现的次数为奇数，此时len加1
    }
};
// @lc code=end


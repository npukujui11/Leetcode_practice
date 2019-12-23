/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())               //p为空的话，s也为空返回true，否则返回false
            return s.empty();

        if('*' == p[1]) //p中*在第2个相对位置

        //从字符串第3位接着递归调用isMatch            
            return isMatch(s, p.substr(2)) || 
                !s.empty() && 
                (s[0] == p[0] || p[0] == '.') && 
                isMatch(s.substr(1), p);
        else
            return 
                !s.empty() && 
                (s[0] == p[0] || p[0] =='.') &&
                isMatch(s.substr(1), p.substr(1));
    }
};
// @lc code=end


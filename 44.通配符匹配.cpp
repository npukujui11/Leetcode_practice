/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        
        int s_index = 0, p_index = 0;//设置双指针，s_index和p_index分别指向s和p
        int starMatchStringnumber = -1;
        int lastMatchLocation = 0;//记录s串当前的匹配位置
        
        while (s_index < s.size()) {
            if (s[s_index] == p[p_index] || p[p_index] == '?') {//字符配对成功
                s_index++;
                p_index++;
                continue;
            }else if (p[p_index] == '*') {
                starMatchStringnumber = p_index;
                p_index++;
                lastMatchLocation = s_index;
                continue;
            }else if (starMatchStringnumber != -1) {
                lastMatchLocation++;
                s_index = lastMatchLocation;
                p_index = starMatchStringnumber + 1;
                continue;
            }
            return false;
        }
        
        while (p_index < p.size() && p[p_index] == '*') ++p_index;
        
        return p_index == p.size();
    }
};
// @lc code=end


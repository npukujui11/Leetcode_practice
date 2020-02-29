/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stac_k;
        char flag;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stac_k.push(s[i]);
            else {
                if(stac_k.empty())
                    return false;
                flag = stac_k.top();

                if(flag == '(' && s[i] == ')' || flag == '[' && s[i] == ']' || flag == '{' && s[i] == '}')
                    stac_k.pop();
                else return false;
            }
        }
        if(stac_k.empty())
            return true;
        else return false;
    }
};
// @lc code=end


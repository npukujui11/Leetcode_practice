/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        vector<char> stark;
        char flag;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stark.push_back(s[i]);
            else{
                if(stark.size() == 0)//栈空 
                    return false;
                flag = stark.back();
                
                if(flag == '(' && s[i] == ')' || flag == '[' && s[i] == ']' || flag == '{' && s[i] == '}')
                    stark.pop_back();
                else return false;
            }
        }
        if(stark.size() == 0)
            return true;
        else return false;
    }
};
// @lc code=end


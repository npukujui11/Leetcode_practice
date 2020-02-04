/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        //特判
        if(s.size() == 0){
            return res;
        }

        vector<string> track;
        backtracking(s, res, track, 0);
        return res;
    }

private:
    /*
     * 检查字符是否是回文
     * left 字符串s的左索引
     * right 字符串s的右索引
     */
    bool checkPalindrome(string s, int left, int right){
        while(left < right){
            if(s.at(left) != s.at(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

    /*
     * 回溯函数
     * res 记录结果
     * track 记录子节点到根节点的结果，最后存储到res中去
     * start 起始字符的索引
     */
    void backtracking(string s, vector<vector<string>>& res, vector<string>& track, int start){
        //设置退出回溯条件
        if(start == s.size()){
            res.push_back(track);
            return;
        }

        for(int i = start; i < s.size(); i++){
            if(!checkPalindrome(s, start, i))
                continue;
            //把start到i+1中间的字符添加进track
            track.push_back(s.substr(start, i + 1 - start));
            backtracking(s, res, track, i + 1);
            //恢复现场
            track.pop_back();
        }
    }

};
// @lc code=end


/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
#include <vector>
#include <string>

/*
 * 回溯
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s){
        vector<string> ans; //存储答案
        string track = ""; //暂存IP地址

        //特判
        if(s.size() > 12)
            return ans;

        backtracking(4, s, ans, track);
        return ans;
    }

private:
    /*
     * 判断每个 . 前的数字是否合法
     */
    bool isValid(string segment){
        if(segment.size() > 3 || segment.size() <= 0)
            return false;
        if(segment.size() > 1 && segment[0] == '0')
            return false;
        //atoi引用字符串的指针，把数字字符串转换成int输出
        //c_str返回字符串的指针
        int num = atoi(segment.c_str());

        if(num > 255 || num < 0)//ip地址长度为32位
            return false;
        else return true;
    }
    
    /*
     * int nums是当前还剩余的段数
     * string s是当前的字符串
     * vector<string> res用于存储当前的结果
     * string track 用于转存结果
     */
    void backtracking(int nums, string s, vector<string>& res, string track){
        if(nums == 0){
            if(s.size() == 0)
                res.push_back(track);
        }

        for(int i = 1; i <= 3; i++){
            //substr(0, i)表示从第0位开始的长度为i的字符串 
            //substr(i)表示从第i位开始到最后一位的字符串
            if(s.size() >= i && isValid(s.substr(0, i))){    
                if(nums == 1)
                    backtracking(nums - 1, s.substr(i), res, track + s.substr(0, i));
                else
                    backtracking(nums - 1, s.substr(i), res, track + s.substr(0, i) + '.');
            }
        }
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; //用于存储答案
        string track;
        backktracking(0, 0, n, track, ans);
        return ans;
    }

    void backktracking(int left, int right, int n, string& track, vector<string>& res){
    /*
     * left和right分别用于记录左括号和右括号的个数
     * n为括号的对数
     * track用于存储每一次的结果
     * res用于存储结果
     */
        if(left == n && right == n){        //设定退出递归调用的条件
            res.push_back(track);
            return;
        }
        if(left < n){       //设定进入左子树的条件
            track = track + "(";
            backktracking(left + 1, right, n, track, res);
            track.pop_back();
            /* 因为递归栈中的任意一个函数都是要完全执行完的，
             * 每一个分支在执行完后都要对track进行清空，不然会影响到后续的分支变量
             */
        }
        if(right < left){       //设定进入右子树的条件
            track = track + ")";
            backktracking(left, right + 1, n, track, res);
            track.pop_back();
        }

    }
};
// @lc code=end


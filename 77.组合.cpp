/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //增加特判
        vector<vector<int>> ans;   
        vector<int> track;

        if(n <= 0 || k <= 0 || n < k){
            return ans;
        }
        backtracking(n, k, 1, track, ans);
        return ans;
    }

private:
    void backtracking(int n, int k, int begin, vector<int>& track, vector<vector<int>>& res){
        if(track.size() == k){
            res.push_back(track);
            return;
        }

        for(int i = begin; i <= n; i++){
            track.push_back(i);
            //进入递归
            backtracking(n, k, i+1, track, res);
            //清理现场
            track.pop_back();        
        }
    }
};
// @lc code=end


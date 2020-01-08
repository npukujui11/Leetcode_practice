/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;  //用于存储答案
        vector<int> track;
        backtracking(nums, track, ans);
        return ans;
    }

private:
    void backtracking(vector<int>& nums, vector<int>& track, vector<vector<int>>& res){
        if(track.size() == nums.size()){ //设定退出条件
            res.push_back(track);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            //判断track中nums[i]是否已经存在
            if(find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            track.push_back(nums[i]);
            //进入递归
            backtracking(nums, track, res);
            //清理现场
            track.pop_back();
        }
    }
};
// @lc code=end


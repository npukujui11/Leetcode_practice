/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;  //用于存储答案
        ans.push_back({});
        vector<int> track;
        backtracking(nums, 0, track, ans);
        return ans;
    }

private:
    void backtracking(vector<int>& nums, int begin, vector<int>& track, vector<vector<int>>& res){
        if(begin > nums.size()){ //设定退出条件
            return;
        }

        //判断track是否已经包含在res中，如果没有包含则push_back(track);
        if(find(res.begin(), res.end(), track) == res.end())
            res.push_back(track);

        for(int i = begin; i < nums.size(); i++){
            //判断track中nums[i]是否已经存在
            //因为子集是不会区分前后顺序的，所以必须加这条判断
            if(find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            track.push_back(nums[i]);
            //进入递归
            backtracking(nums, i + 1, track, res);
            //清理现场
            track.pop_back();
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> track;
        //对数组进行排序
        sort(nums.begin(), nums.end());

        backtracking(nums, 0, track, ans);
        return ans;   
    }

private:
    void backtracking(vector<int>& nums, int begin, vector<int>& track, vector<vector<int>>& res){
        //设置退出条件
        if(begin > nums.size()){//
            return;
        }

        //判断track是否已经包含在res中，如果没有包含则push_back(track);
        if(find(res.begin(), res.end(), track) == res.end())
            res.push_back(track);

        for(int i = begin; i < nums.size(); i++){
            //因为整型数组nums中可能包含重复元素，所以把重复判断去掉
            //改为判断当前数字和前一个数字是否相同，如果相同则跳过
            if(i > begin && nums[i] == nums[i - 1])
                continue;
            track.push_back(nums[i]);
                //进入递归
            backtracking(nums, i + 1, track, res);
            //恢复现场
            track.pop_back();
        }
    }
};
// @lc code=end


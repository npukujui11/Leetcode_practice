/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <map>

class Solution {
    /*
     *利用hash表来处理重复的问题
     */
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        map<int, int> hash;//初始化hash表
        for(auto i : nums)
            hash[i]++; //记录每个数出现的个数
        vector<vector<int>> ans;//用于存储结果
        vector<int> track;//用于追踪记录结果
        backtracking(hash, nums, track, ans);
        return ans;
    }

private:
    void backtracking(map<int, int>& hash, vector<int>& nums, vector<int>& track, vector<vector<int>>& res){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        //for(iterator it = hash.begin(); it != hash.end(); it++)
        for(auto& it: hash){
            if(it.second == 0)
                continue;
            it.second--;
            track.push_back(it.first);
            backtracking(hash, nums, track, res);
            it.second++;
            track.pop_back();
        }
    }
};
// @lc code=end


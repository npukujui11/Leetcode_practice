/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        if(candidates.size() == 0 || target < 0){
            return ans;
        }
        sort(candidates.begin(), candidates.end());

        backtrack(ans, curr, candidates, target, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, vector<int>& candidates, int target, int level){
        if(target == 0){
            ans.push_back(curr);
            return;
        }else if(target < 0){
            return;
        }
        for(int i = level; i < candidates.size(); i++){
            target -= candidates[i];
            curr.push_back(candidates[i]);
            backtrack(ans, curr, candidates, target, i+1);
            curr.pop_back();
            target += candidates[i];

            while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])//过滤相同的值，防止组合重复
                    i++;
        }
    }
};
// @lc code=end


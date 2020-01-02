/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;//用于存储结果
        vector<int> curr;//用于中转数据
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
        }
        else if(target < 0){
            return;
        }

        for(int i = level; i < candidates.size(); i++){
            target = target - candidates[i];
            curr.push_back(candidates[i]);
            backtrack(ans, curr, candidates, target, i);
            curr.pop_back();//回溯函数回退时候，需要把上一个增加进去的数弹出。
            target = target + candidates[i];
        }
    }

};
// @lc code=end


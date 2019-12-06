/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> dict(nums.begin(), nums.end());
        return dict.count(target);
    }
};
// @lc code=end


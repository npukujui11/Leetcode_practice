/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        //保证数组nums长度大于等于1
        if(nums.empty())
            return {-1, -1};
        //lower_bound：返回一个迭代器，指向键值 >= key的第一个元素。
        //upper_bound：返回一个迭代器，指向键值 > key的第一个元素。
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if(left == right)
            return {-1, -1};
        return {left - nums.begin(), right - nums.begin() - 1};        
    }

};
// @lc code=end


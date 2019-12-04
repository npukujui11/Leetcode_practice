/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.empty())
            return {-1,-1};
            
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);

        return {left, right};
    }
    
    int left_bound(vector<int>& nums, int target){//寻找左边界

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = left +(right - left) / 2;
            if(nums[mid] == target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }
        return (left <= nums.size() - 1) && nums[left] == target ? left : -1;
    }

/*
 * right_bound借鉴了Leetcode上的题解但是发现很多测试用例无法通过，例如[1] 0，很明显
 * 会出现数组访问越界
 * 所以对题解进行了相应的更改
 */

    int right_bound(vector<int>& nums, int target){//寻找右边界

        int left = 0;
        int right =nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
                left = mid + 1;
            else if(nums[mid] < target )
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }

        return ((left - 1) >= 0 && nums[left - 1] == target) ? left - 1 : -1;
    }

};
// @lc code=end


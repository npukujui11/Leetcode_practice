/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

/*对于不存在于数组中的数，查找插入位置就是返回left指针
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right -left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end


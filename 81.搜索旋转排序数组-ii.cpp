/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

/*算法思路：仍然是采用二分查找的思想。关键点在于如何去处理左右边界的问题，主要分为三个部分讨论。
 *①前半部分是有序的，后半部分无序
 *②后半部分是有序的，前半部分无序
 *③无法区分哪部分是有序的
 *****关键点在于如何在有序的部分去查找
 *对于第①类的情况，前半部分是有序，如果nums[left]<=target<nums[mid],就在前半部分去找，否则就在后半部分去找
 *对于第②类的情况，后半部分是有序，如果nums[mid]<target<=nums[right],就在后半部分去找，否则就在前半部分去找
 *对于第③类的情况，left++,continue进入循环即可。
 */


// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()){
            return false;
        }
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            
            int mid = left + (right -left) / 2;
            
            if(nums[mid] == target){
                return true;
            }
            if(nums[left] == nums[mid]){
                left++;
                continue;
            }//无法区分哪一部分是有序的
            if(nums[left] < nums[mid]){//前半部分是有序的
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else if(nums[left] > nums[mid]){//后半部分是有序的
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

        }
        return false;
    }
};
// @lc code=end


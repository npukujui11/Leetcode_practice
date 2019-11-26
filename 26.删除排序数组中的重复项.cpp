/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        //设置双指针i,j；
        int i = 0; 
        if(len == 0) return 0;
        for(int j = 1; j < len; j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];   
            }
        }
        return i + 1;
    }
};
// @lc code=end


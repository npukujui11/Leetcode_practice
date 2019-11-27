/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;//设置慢指针
        for(int j = 0;j < len;j++){
            if(nums[j] != val){//找到不需要剔除的元素
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
// @lc code=end


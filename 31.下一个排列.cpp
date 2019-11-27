/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.23%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    31.7K
 * Total Submissions: 98.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(),nums.end());
        
        for(int i = nums.size() - 1; i >= 0; i--){//从后往前遍历，寻找最长递减子序列
            if(i == 0){//遍历到头，是字典序的最后一个，输出递增排序序列
                reverse(nums, 0, nums.size() - 1);
                return;//结束函数
            }
            if(nums[i] > nums[i-1]){//直到找到最长递减子序列
                reverse(nums, i, nums.size() - 1);

                
                 //此时需要在最长递减子序列中找到比nums[i-1]大的数
                 //找到之后swap即可

                for(int j = i; j < nums.size(); j++){
                    if(nums[j] > nums[i-1]){
                        swap(nums,j , i - 1);
                        return;
                    }
                }
            }
        }
        
    }

    void reverse(vector<int>& nums, int begin , int end){//反转数组
        while(begin < end){
            swap(nums, begin++, end--);
        }
    }

    void swap(vector<int>& nums, int i, int j){//交换数组中的两个元素
        int flag = nums[i];
        nums[i] = nums[j];
        nums[j] = flag;
    }
};
// @lc code=end


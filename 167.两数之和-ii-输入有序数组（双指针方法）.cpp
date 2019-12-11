/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left <= right){

            int flag = numbers[left] + numbers[right];
            if(flag > target){
                right--;
            }else if(flag < target){
                left++;
            }else{
                return {left + 1, right + 1};
            }
        }    
        return {-1, -1};
    }
};
// @lc code=end


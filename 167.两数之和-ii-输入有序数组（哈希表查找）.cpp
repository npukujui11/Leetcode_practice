/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> sum;
        for (int i = 0; i < numbers.size(); i++){
            if(sum.count(target - numbers[i])){
                return {sum[target - numbers[i]] + 1, i + 1};
            }else{
                sum[numbers[i]] = i;
            }
        }
        return {0, 0};
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
/*
 *大致思路：排序+双指针；
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int sum = 0;
        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for(int i = 0; i< len - 2; i++){
            int start = i + 1;
            int end = len - 1;
            
            while(start < end){
                sum = nums[i] + nums[start] + nums[end];
                
                if(abs(target - sum) < abs(target - ans)){
                    ans = sum;
                }

                if(sum < target){
                    start++;
                }else if(sum > target){
                    end--;
                }else{
                    return ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


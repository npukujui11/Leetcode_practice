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
                    //去除重复遍历，可以显著节约时间，此处是去除start指针的重复
                    while(start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                }else if(sum > target){
                    end--;
                    //去除end指针的重复
                    while(start > end && nums[end] == nums[end+1]){
                        end--;
                    }
                }else{
                    return ans;
                }
            }
            //去除nums[i]的重复
            while(start > end && nums[i] == nums[i-1]){
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end


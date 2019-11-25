/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        int sum = 0;
        vector<vector<int>> res;//设置一个用于存储结果的容器

        sort(nums.begin(), nums.end());

        //特判
        if(len < 4) 
            return res;
        for(int i = 0; i < len - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < len - 2; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int start = j + 1;
                int end = len - 1;
                while(start < end){
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if(sum > target){
                        end--;
                    }else if(sum < target){
                        start++;
                    }else{
                        vector<int> flag{nums[i], nums[j], nums[start], nums[end]};
                        res.push_back(flag);

                        //去重
                        while(start < end && nums[start] == nums[++start]);
                        while(start < end && nums[end] == nums[--end]);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


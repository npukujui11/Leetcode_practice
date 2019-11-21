/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

/*//大致思路：用双指针法，设置左指针和右指针，随后遍历左右指针之间的序列。
 *再判断所遍历的序列是否满足条件。
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int m = nums.size();
        int sum = 0;//设置一个用于存储左右指针和的变量
        vector<vector<int>> result_arr;//设置一个用于存储结果的容器

        //对输出结果有个要求，即按大小排序
        sort(nums.begin(), nums.end());
        for(int i = 0; i < m - 2; ++i){    
            int left_arr = i + 1;
            int right_arr = m - 1;
            if(nums[i] > 0){
                break;
            }               
            //确保在移动的情况下能够去除重复
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            while(left_arr < right_arr){
                sum = nums[i] + nums[left_arr] + nums[right_arr];
                if(sum > 0){//和大于0，说明右边的数过大，需要移动右指针
                    --right_arr;
                    //cout << "case1" << endl;
                }else if(sum < 0){//和小于0，说明左边的数过小，需要移动左指针
                    ++left_arr;
                    //cout << "case2" << endl;
                }else{//和等于0，但还需要策略去完成双指针的移动
                    vector<int> flag{nums[i], nums[left_arr], nums[right_arr]};
                    result_arr.push_back(flag);
                    //cout << "case3" << endl;
                    while(left_arr < right_arr && nums[left_arr] == nums[++left_arr]);
                    while(left_arr < right_arr && nums[right_arr] == nums[--right_arr]);
                }
            }
        }
        return result_arr;
    }
};
// @lc code=end


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
        //设置左右指针
        int left_arr = 0;
        int right_arr = m - 1;

        int sum = 0;//设置一个用于存储左右指针和的变量
        vector<vector<int>> result_arr;//设置一个用于存储结果的容器

        //对输出结果有个要求，即按大小排序
        sort(nums.begin(), nums.end());

        while(left_arr != right_arr){
            
            sum = nums[left_arr] + nums[right_arr];
            for(int i = left_arr + 1; i < right_arr; i++){    
                if(sum == 0 && nums[i] == 0){//左右指针索引值相加等于0且中间搜索到的值也为0
                    
                    

                    vector<int> flag{nums[left_arr], nums[i], nums[right_arr]};
                 

                    result_arr.push_back(flag);
                    //cout << "case1" << endl;
                }else if(sum != 0 && (sum + nums[i]) == 0){//左右指针索引值和不等于0



                    vector<int> flag{nums[left_arr], nums[i], nums[right_arr]};
                


                    result_arr.push_back(flag);
                    //cout << "case2" << endl;
                }else{
                    //没有搜索到符合要求的值，所以不做任何处理
                    //cout << "case3" << endl;
                }    
            }
            if (abs(nums[left_arr]) > abs(nums[right_arr])){
                
                ++left_arr;

            }else{
                
                --right_arr;

            }    
        }
        return result_arr;
    }
};
// @lc code=end


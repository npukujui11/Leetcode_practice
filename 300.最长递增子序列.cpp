/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 定义dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < dp.size(); ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution res;
    cout << res.lengthOfLIS(nums) << endl;
    return 0;
}
// @lc code=end


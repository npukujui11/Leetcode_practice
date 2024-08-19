/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 按照w的升序排列，如果w一样，则按照h的降序排列。
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1]; // 如果第一个元素相等，则按第二元素降序
            return a[0] < b[0]; // 否则按照第一个元素升序
        });

        // 对高度数组寻找 LIS
        vector<int> height(envelopes.size(), 0);
        for (int i = 0; i < envelopes.size(); ++i) {
            height[i] = envelopes[i][1]
        }

        // 定义dp[i]表示以nums[i]这个数结尾的最长递增子序列的长度
        vector<int> dp(height.size(), 1);
        for (int i = 0; i < height.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (height[j] < height[i]) {
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
// @lc code=end


/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    /*
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(); // n为word1的长度，m为word2的长度

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j]表示word1的前i个字符转换为word2的前j个字符所需要的最少操作次数

        // 初始化
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i; // word2为空，word1删除所有字符
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j; // word1为空，word1插入所有字符
        }

        // 状态转移
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // 如果word1的第i个字符和word2的第j个字符相同，则不需要操作
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1,
                                    dp[i][j - 1] + 1,
                                    dp[i - 1][j - 1] + 1}); // 否则，有三种操作方式，分别是删除、插入和替换
                }
            }
        }

        return dp[n][m];
    }
    */
   int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        return dp(word1, word2, n, m, memo); 
   }

   int dp(const string& word1, const string& word2, int i, int j, vector<vector<int>>& memo) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i - 1] == word2[j - 1]) { // 如果word1的第i个字符和word2的第j个字符相同，则不需要操作
            memo[i][j] = dp(word1, word2, i - 1, j - 1, memo); 
        } else {
            memo[i][j] = min({dp(word1, word2, i - 1, j, memo) + 1,
                              dp(word1, word2, i, j - 1, memo) + 1,
                              dp(word1, word2, i - 1, j - 1, memo) + 1});
        }

        return memo[i][j];
    }
};
// @lc code=end


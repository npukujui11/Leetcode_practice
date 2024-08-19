/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 设置dp数组存储matrix[i][j]的最小的路径
        vector<vector<int>> dp(n, vector<int>(n));

        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        int res = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0 && j < n - 1) {
                    res = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]);
                } else if (j == 0){
                    res = min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else if (j == n - 1){
                    res = min(dp[i - 1][j], dp[i - 1][j - 1]); 
                }
                dp[i][j] = res + matrix[i][j];
            }
        }

        int min = __INT_MAX__;
        for (int i = 0; i < n; ++i) {
            if (dp[n - 1][i] < min) {
                min = dp[n - 1][i];
            }
        }

        return min;
    }
};
*/
// 暴力回溯法
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = __INTMAX__;

        for (int i = 0; i < n; ++i) {
            res = min(res, dp(matrix, n - 1, j))
        }
        
    }
private:
    int dp(vector<vector<int>>& matrix, int i, int j) {
        // 特殊情况
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix.size()) {
            return __INT_MAX__;
        }
        
        // base case
        if (i == 0) return matrix[i][j]

        // 状态转移方程
        return matrix[i][j] + min(min(dp(matrix, i - 1, j - 1), dp(matrix, i - 1, j)), dp(matrix, i - 1, j)) 
    }
};

// 采用备忘录的回溯方法
/*
class Solution {
public:
    vector<vector<int>> memo;

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = __INT_MAX__;

        memo = vector<vector<int>>(n, vector<int>(n, 10001)); // 初始备忘录
        
        for (int j = 0; j < n; ++j) {
            res = min(res, dp(matrix, n - 1, j));
        }
        return res;
    } 

private:
    int dp(vector<vector<int>>& matrix, int i, int j) {
        // 合法性检查
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix.size()) {
            return __INT_MAX__;
        }

        // base case
        if (i == 0) return matrix[0][j];

        // 查找备忘录
        if (memo != 10001) return memo[i][j];
        // 状态转移方程
        memo = matrix[i][j] + min(min(dp(matrix, i - 1, j - 1), dp(matrix, i - 1, j)), dp(matrix, i - 1, j + 1));
        return memo;
    }
};
*/
// @lc code=end


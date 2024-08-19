/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start

// 暴力回溯方法
/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();

        return dp(grid, m - 1, n - 1);
    }

    int dp(vector<vector<int>>& grid, int i, int j) {
        // 特殊情况
        if (i < 0 && j < 0) {
            return __INT_MAX__;
        }
        
        // base case
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        // 状态转移方程
        return min(dp(grid, i - 1, j), dp(grid, i, j - 1)) + grid[i][j];
    } 
};
*/

/*
// 使用备忘录的回溯方法
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(grid, m - 1, n - 1);
    }
private:
    vector<vector<int>> memo;

    int dp(vector<vector<int>>& grid, int i, int j) {
        // 特殊情况
        if (i < 0 || j < 0) return __INT_MAX__;

        // base case
        if (i == 0 && j == 0) return grid[][j];

        // 备忘录
        if (memo[i][j] != -1) return memo[i][j];
    
        // 将计算结果存储到备忘录中
        memo[i][j] = min(dp(grid, i - 1, j), dp(grid, i, j - 1)) + grid[i][j];

        return memo[i][j];
    }
};
*/

// 使用自顶向下的迭代方法
class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // 状态转移
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
// @lc code=start
/*
// 自顶向下的递归解法
class Solution {
public:
    int climbStairs(int n) {
        return helper(n);
    }
private:
    int helper(int n) {
        // base case
        if (n == 0 || n == 1) return 1; // 只有一级台阶，只有一种方法
        return helper(n - 1) + helper(n - 2); // 递归调用
    }
};
*/
/*
// 带备忘录的递归解法
class Solution {
public:
    // 备忘录用于记录已经计算过的值
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0); // 备忘录全初始化为0
        return helper(memo, n); // 进行带备忘录的递归
    }
private:
    int helper(vector<int>& memo, int n) {
        // base case
        if (n == 0 || n == 1) return 1; // 只有一级台阶，只有一种方法
        // 已经计算过
        if (memo[n] != 0) return memo[n]; // 直接返回备忘录中的结果
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2); // 计算并记录备忘录
        return memo[n]; // 返回结果
    }
};
*/
// dp数组的迭代解法
class Solution {
public:
    // dp[i]表示第i级台阶的方法数
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1; 
        int dp[n + 1]; // dp数组
        dp[0] = 1; // base case
        dp[1] = 1; // base case
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; // 状态转移方程
        }
        return dp[n]; // 返回结果
    }
};
// @lc code=end


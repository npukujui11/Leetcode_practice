/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
/*
 * 当n=20时，递归调用了21891次，时间复杂度为O(2^n)
 * 递归调用的次数是指数级增长的，所以时间复杂度是指数级的
 * 该算法会存在大量的重复计算，可以使用动态规划或者备忘录优化
 * 重叠子问题：在递归树中，存在大量重复的子问题
 */
/*
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};
*/
/*
// 动态规划
class Solution {
public:
    int fib(int n) {
        // 备忘录全初始化为0
        int memo[n + 1];
        for (int i = 0; i < n + 1; i++) {
            memo[i] = 0;
        }
        return helper(memo, n); // 进行带备忘录的递归
    }

private:
    int helper(int memo[], int n) {
        if (n == 0 || n == 1) return n;
        // 已经计算过
        if (memo[n] != 0) return memo[n]; // 直接返回备忘录中的结果
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2); // 计算并记录备忘录
        return memo[n];
    }
};
*/
// 迭代解法
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int dp[n + 1];

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start

// 带备忘录的动态规划解法
/*
class Solution {
public:
    vector<int> memo; // 备忘录
    int coinChange(vector<int>& coins, int amount) {
        memo = vector(amount + 1, -666); // 备忘录，初始化为-666
        return dp(coins, amount);
    }

private:
    // dp(n)是返回凑成总金额n所需的最少硬币数量
    int dp(vector<int>& coins, int amount) {
        // base case
        if (amount == 0) return 0; // 总金额为0，所需硬币数量为0
        if (amount < 0) return -1; // 总金额小于0，无解
        if (memo[amount] != -666) return memo[amount]; // 查备忘录，防止重复计算

        int res = INT_MAX; // 求最小值，初始化为正无穷
        for (int coin : coins) { // 遍历所有硬币
            // 计算子问题的结果
            int subproblem = dp(coins, amount - coin);
            // 子问题无解，跳过
            if (subproblem == -1) continue;
            // 在子问题的基础上加一，求最小值
            res = min(res, subproblem + 1);
        }

        memo[amount] = res == INT_MAX ? -1 : res; // 将结果存入备忘录
        return res == INT_MAX ? -1 : res; // 返回结果
    }
};
*/

// 自上而下的递归解法
/*
 * 构建状态转移方程
 * dp(n) = 0, n = 0
 * dp(n) = -1, n < 0
 * dp(n) = min{dp(n - coin) + 1}, coin ∈ coins
 */
/*
class Solution {
public:
    // coins: 硬币面额，amount: 总金额
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }
    // dp(n)是返回凑成总金额n所需的最少硬币数量
    int dp(vector<int>& coins, int amount) {
        // base case
        if (amount == 0) return 0; // 总金额为0，所需硬币数量为0
        if (amount < 0) return -1; // 总金额小于0，无解

        int res = INT_MAX; // 求最小值，初始化为正无穷
        
        // 构建树形递归结构，硬币的面额是树的分支，硬币的数量是树的深度
        for (int coin : coins) { // 在coins数组中遍历coin
            // 计算子问题的结构
            int subproblem = dp(coins, amount - coin);
            if (subproblem == -1) continue; // 子问题无解，跳过
            res = min(res, subproblem + 1); // 在子问题的基础上加一，求最小值
        }
        
        if (res == INT_MAX) {
            return -1; // 无解
        } else {
            return res; // 返回结果
        }
    }
};
*/

// 自底向上dp数组的迭代解法
class Solution {
public:
    // coins: 硬币面额，amount：总金额，dp数组表示凑成总金额n所需的最少硬币数量
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // dp数组，初始化为amount + 1
        dp[0] = 0; // base case

        for (int i = 0; i < dp.size(); i++) { // 遍历dp数组

            for (int coin : coins) { // 遍历硬币
                if (i - coin < 0) 
                    continue; // 子问题无解，跳过
                dp[i] = min(dp[i], 1 + dp[i - coin]); // 在子问题的基础上加一，求最小值
            }
        }
        if (dp[amount] == amount + 1) { // 凑成总金额amount的硬币数是amount + 1
            return -1; // 无解
        } else {
            return dp[amount]; // 返回结果
        }
    }
};
// @lc code=end


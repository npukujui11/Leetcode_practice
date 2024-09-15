/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); // 字符串s的长度

        if (n < 2) return s; // 如果字符串s的长度小于2，则直接返回s
        
        /*
        if (n == 2 && s[0] == s[1]) { 
            return s; // 如果字符串s的长度等于2，且两个字符相等，则直接返回s
        } else if (n == 2 && s[0] != s[1]){
            return s.substr(0, 1); // 否则返回s的第一个字符
        } 
        */

        int res = 1; // 记录最长回文子串的长度
        int start = 0;

        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j]表示s[i..j]是否为回文子串

        // 初始化
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1; // 单个字符一定是回文子串
        }
        
        // 状态转移
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i == 1) {
                        dp[i][j] = 1; // 两个相邻字符相等，且长度为2，不是回文子串
                    } else {
                        dp[i][j] = dp[i + 1][j - 1]; // 两个相邻字符相等，且长度大于2，取决于去掉两个字符后的子串是否为回文子串
                    }
                }

                if (dp[i][j] && j - i + 1 > res) { // 如果s[i..j]是回文子串，且长度大于res
                    start = i;
                    res = j - i + 1; 
                } else {
                    start = start;
                    res = res;
                }
            }  
        }

        return s.substr(start, res);
    }
};
// @lc code=end


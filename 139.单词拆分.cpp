/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
/*
// dp数组的迭代（递推）解法
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i]表示字符串s的前i个字符能否拆分成wordDict
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; // 空字符串可以拆分

        // 遍历字符串s的每个字符
        for (int i = 1; i <= s.size(); i++) {
            // 遍历wordDict
            for (string word : wordDict) {
                // 如果word的长度大于i，跳过
                if (word.size() > i) continue;
                // 如果s的前i个字符以word结尾，且s的前i-word.size()个字符可以拆分成wordDict
                if (s.substr(i - word.size(), word.size()) == word && dp[i - word.size()] == true) {
                    dp[i] = true;
                    break;
                }
                
            }
        }
        return dp[s.size()]; // 
    }
};
*/
// 自顶向下的递归解法
/* 
 * 构建状态转移方程
 * dp(s) = dp(s.substr(word.size())) for word in wordDict
 */
/*
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(s, wordDict);
    }
private:
    bool dp(string s, vector<string>& wordDict) {
        // base case
        if (s == "") return true; // 空字符串可以拆分
        for (string word : wordDict) {
            // 如果s的前缀匹配word
            if (s.find(word) == 0) {
                // 递归调用，判断s去掉word后的子串是否可以拆分
                if (dp(s.substr(word.size()), wordDict)) return true;
            } else {
                continue;
            }
        }
        return false;
    }
};
*/

// 带备忘录的递归解法
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo; // 备忘录
        return dp(s, wordDict, memo);
    }

private:
    // 备忘录主要用来保存已经计算过的子问题的结果，避免重复计算
    bool dp(string s, vector<string>& wordDict, unordered_map<string, bool>& memo) {
        // base case
        if (s == "") return true; // 空字符串可以拆分
        if (memo.find(s) != memo.end()) return memo[s]; // 查备忘录，避免重复计算    
        for (string word : wordDict) {
            // 如果s的前缀匹配word
            if (s.find(word) == 0) {
                // 递归调用，判断s去掉word后的子串是否可以拆分
                if (dp(s.substr(word.size()), wordDict, memo)) {
                    memo[s] = true; // 记录备忘录
                    return true;
                }
            } else {
                continue;
            }
        }
        memo[s] = false; // 记录备忘录
        return false;
    }

};
// @lc code=end


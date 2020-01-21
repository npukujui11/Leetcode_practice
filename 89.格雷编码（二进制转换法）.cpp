/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
#include <vector>

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < pow(2, n); i++){
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
// @lc code=end


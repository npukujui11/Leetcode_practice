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
        res.push_back(0);
        for(int i = 0; i < n; i++){
            for(int j = res.size() - 1; j >= 0 ; j--){
                res.push_back(res[j] ^ (1 << i));
            }
        }
        return res;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */ 

// @lc code=start
#include <vector>

class Solution {
public:
    /*康托展开法*/
    /* n是需要排列的位数，k是位于第几位*/
    string getPermutation(int n, int k) {
        vector<char> chs = {'1','2','3','4','5','6','7','8','9'};
        vector<int> factor = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string ans;
        /*
         k--是由于康托展开值+1才等于次序的值，所以逆康托展开需要-1;
         for循环的第二个条件n--，其操作描述是n-- < 0;
         k %= factor[n]放到每一次循环最后执行，求余;
         erase则在chs中删除掉每次查找到的值，举例如k=87，n=5，结果是43215;
         这样到n=1的时候，由于之前找到的4321都删除掉了，此时对应的chs[0]=5;
         */
        for(k--; n--; k %= factor[n]){
            int i = k/factor[n];
            ans.push_back(chs[i]);
            chs.erase(chs.begin() + i);
        }
        return ans;
    }
};
// @lc code=end


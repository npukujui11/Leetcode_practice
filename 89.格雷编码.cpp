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
        if(n == 0){
            res.push_back(0);
            return res;
        }

        backtracking(res, n, 0, 0, 0);
        return res;
    }
private:
    void backtracking(vector<int>& res, int n, int count, int index, int sum){
        /*
         * res用于存储记录答案
         * index表示当前到达二进制的第几位
         * count用于表示当前track中1的个数
         * sum用于记录值
         */

        //设置退出条件
        if(index == n){
            res.push_back(sum);
            return;
        }
        if(res.size() == pow(2, n))
            return;
        
        //由解空间树观察可以得出track中1的数量为偶数时候，子节点为0，1
        //track中1的数量为奇数的时候，子节点数为1，0；
        if(count % 2 == 0){//1的个数为偶数
            backtracking(res, n , count ,index + 1, sum * 2);
            backtracking(res, n , count + 1,index + 1, sum * 2 + 1);
        }
        else{//1的个数为奇数
            backtracking(res, n , count + 1, index + 1, sum * 2 + 1);
            backtracking(res, n , count, index + 1, sum * 2);
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
    //牛顿迭代法
public:
    int mySqrt(int x) {
        long int root = x;
        while(root * root > x){
            root = (root + x/root)/2;
        }
        return root;
    }
};
// @lc code=end


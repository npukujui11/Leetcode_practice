/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

/*思路：二分递归
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n == 1){
            return x;
        }else if(n == -1){
            return 1/x;
        }
     
        double root = myPow(x, n / 2);
        if(n % 2 == 0)
            return root * root;
        else
            return root * root * (n > 0 ? x : 1 / x);//这里容易出错,直接写x而不做判断会对于n<-2的情况会出错
    }
};
// @lc code=end


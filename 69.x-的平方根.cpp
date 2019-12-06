/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
    //二分查找
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int left = 0;
        int right = x;

        while(left <= right){
            int mid = left + (right - left) / 2;
            //注意不要用mid*mid==x来判断，这样会出现溢出错误
            if (mid == x / mid){//查找到目标
                return mid;
            }else if(mid > x / mid){//说明mid过大，应该继续向左搜索
                right = mid - 1;
            }else if(mid < x / mid){//说明mid过小，应该向右搜索
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
// @lc code=end


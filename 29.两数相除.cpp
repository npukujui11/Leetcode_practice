/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = ( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));

        long res = 0;//记录结果
        long count = 1;//用于计数

        long divisor_temp = abs((long)divisor);//用于存储除数的临时变量
        long dividend_temp = abs((long)dividend);//用于存储被除数的临时变量

        while(dividend_temp >= abs((long)divisor)){//跳出循环的条件：存储被除数的临时变量小于除数；
            dividend_temp = dividend_temp - divisor_temp;

            if(dividend_temp < 0){
                dividend_temp = dividend_temp + divisor_temp;
                divisor_temp = abs(divisor);
                count = 1;
            }else if(dividend_temp > 0){//说明已经整除了一次
                res = res + count;
                divisor_temp = divisor_temp + divisor_temp;//除数乘以2
                count = count + count;//相应的计数也乘以2
            }else if(dividend_temp == 0){//说明被除数能够被除数整除
                res = res + count;
                break;
            }
        }

        if(flag){//正数
            if(res > pow(2,31) - 1)
                return pow(2,31) - 1;
            return (int)res;
        }else{
            if(res > pow(2,31))
                return pow(2,31) - 1;
            return (int)(0 - res);
        }
    }
};
// @lc code=end


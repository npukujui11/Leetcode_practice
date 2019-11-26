/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        /*
		 * Algorithm idea:
		 * sort A
		 * start with the minimum of A each time
		 * take the negative number in turn，and K--，until K==0
		 * accumulate A
		 */
		while(K--){
			sort(A.begin(), A.end());//sort A
			A[0] = -A[0];//get negative number
		}
		return accumulate(A.begin(), A.end(), 0);
    }
};
// @lc code=end


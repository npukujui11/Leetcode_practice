/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
		
/*

* algorithm idea:

* gets the length of vector

** inverts the stones

*** judge the weight of the remaining stones

*/ 
		int length = stones.size();
		
		while(length>1){
			sort(stones.rbegin(), stones.rend());
			if(stones[1] == 0){
				break;
			}else{
				stones[0] -= stones[1];
				stones[1] -= stones[1];
			}
		}
		return stones[0];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int rowLen = dungeon.size();//行
        int colLen = dungeon[0].size();//列

        if (rowLen == 0 || colLen == 0)
            return -1;
        //当前数组到达公主所需要的最小生命值
        vector<vector<int>> dp(rowLen, vector<int>(colLen, 0));

        dp[rowLen-1][colLen-1] = 1 - min(dungeon[rowLen-1][colLen-1], 0);

        //从最后一个数字开始更新hp
        for(int i = rowLen - 1; i >= 0; i--){
            for(int j = colLen - 1; j >= 0; j--){
                if(i == rowLen - 1 && j==colLen - 1)
                    continue;  
                else if(i < rowLen - 1 && j < colLen - 1){
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]; 
                    dp[i][j] = max(dp[i][j], 1);
                }else if(i == rowLen - 1 && j < colLen - 1){
                    dp[i][j] = dp[i][j+1] - dungeon[i][j]; 
                    dp[i][j] = max(dp[i][j], 1);
                }else if(i < rowLen - 1 && j == colLen - 1){
                    dp[i][j] = dp[i+1][j] - dungeon[i][j]; 
                    dp[i][j] = max(dp[i][j], 1);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <vector>

class Solution {
public:
    /*
     * 算法思路：
     * 把二维数组转化为柱状图，然后用第84题的解法来做
     * 单调递增栈
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        //要加一个特判，测试用例中有空例
        if(matrix.size() == 0) 
            return 0;
        int max_area = 0;
        vector<int> dp(matrix[0].size(), 0); 
        // dp数组用于存储每一行的柱子高度，数组长度等于行数，初始值置为0
        for(int i = 0; i < matrix.size(); i++){ //rows
            for(int j =0; j < matrix[0].size(); j++){ //columns
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }

            max_area = max(max_area, largestRectangleArea(dp));
        }
        return max_area;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> stac_k;

        stac_k.push(-1); // 防止栈空

        int height, width, max_area = 0;

        for(int i = 0; i < heights.size(); i++){ // 遍历柱状图
            while(stac_k.top() != -1 && heights[i] <= heights[stac_k.top()]){
                // 当栈不为空且当前柱子高度小于栈顶序号对应的柱子高度时
                height = heights[stac_k.top()];
                stac_k.pop();
                width = i - stac_k.top() - 1;

                max_area = max(max_area, width * height);

            }
            stac_k.push(i);
        }

        while(stac_k.top() != -1){
            height = heights[stac_k.top()];
            stac_k.pop();
            width = heights.size() - stac_k.top() - 1;
            max_area = max(max_area, width * height);
        }

        return max_area;
    }
};
// @lc code=end


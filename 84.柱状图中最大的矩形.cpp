/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
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


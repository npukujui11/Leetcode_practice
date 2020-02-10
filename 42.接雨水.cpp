/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<int> stac_k;
        int ans = 0, i = 0;
        while(i < height.size()){
            //如果当前的高度是小于栈顶元素对应的高度且栈不为空就不退出循环
            while(height[i] > height[stac_k.top()] && !stac_k.empty()){
                int flag = stac_k.top();
                stac_k.pop();
                if(stac_k.empty())
                    break;
                int distance = i - stac_k.top() - 1;
                int bounded_height = min(height[i], height[stac_k.top()]) - height[flag];
                ans += distance * bounded_height;
            }
            stac_k.push(i++);
        }
        return ans;
    }
};
// @lc code=end


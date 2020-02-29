/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        /****思路和括号匹配相类似，找左边界和右边界
         * 遍历数组的同时，去维护一个栈，栈的作用是用于跟踪可能储水的最长的条形块；
         * 用栈存储每堵墙，当遍历墙的高度的时候，
         * 如果当前高度小于栈顶的高度，说明此处会存在积水，入栈；
         * 如果当前高度大于栈顶的墙的高度，说明找到了积水的右边界，当前栈顶出栈；
         */
        stack<int> stac_k;
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            //如果当前的高度是小于栈顶元素对应的高度且栈不为空就不退出循环
            while(!stac_k.empty() && height[i] > height[stac_k.top()]){
                //如果栈不为空且当前高度大于栈顶墙的高度
                int flag = height[stac_k.top()];
                stac_k.pop();
                if(stac_k.empty())
                    break;
                int distance = i - stac_k.top() - 1; //左右两个条形块之间的距离
                int bounded_height = min(height[i], height[stac_k.top()]) - flag;
                //局限高度=左右两个条形块中选最小的-中间有积水的条形块的高度
                ans += distance * bounded_height;
            }
            stac_k.push(i);
        }
        return ans;
    }
};
// @lc code=end


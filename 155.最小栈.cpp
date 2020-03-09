/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    int min = 0;
    stack<int> stac_k;
    stack<int> min_stac_k;
    MinStack() {
        
    }
    
    void push(int x) {
        if(min_stac_k.empty()){
            min_stac_k.push(x);
        }else{
            if(x < min_stac_k.top())
                min_stac_k.push(x);
            else min_stac_k.push(min_stac_k.top());
        }
        stac_k.push(x);
    }
    
    void pop() {
        stac_k.pop();
        min_stac_k.pop();
    }
    
    int top() {
        return stac_k.top();
    }
    
    int getMin() {
        return min_stac_k.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stac_k;
        int right, left;

        //遍历tokens
        for(int i = 0; i < tokens.size(); i++){

            if(tokens[i] == "+"){//碰到+号
               left = stac_k.top();
               stac_k.pop();
               right = stac_k.top();
               stac_k.pop();
               stac_k.push(right + left);
            }else if(tokens[i] == "-"){//碰到-号
                left = stac_k.top();
                stac_k.pop();
                right = stac_k.top();
                stac_k.pop();
                stac_k.push(right - left);
            }else if(tokens[i] == "*"){//碰到*号
                left = stac_k.top();
                stac_k.pop();
                right = stac_k.top();
                stac_k.pop();
                stac_k.push(right * left);
            }else if(tokens[i] == "/"){//碰到/号
                left = stac_k.top();
                stac_k.pop();
                right = stac_k.top();
                stac_k.pop();
                stac_k.push(right / left);
            }else{//碰到数字
                stac_k.push(atoi(tokens[i].c_str()));
            }

        }
        return stac_k.top();
    }
};
// @lc code=end


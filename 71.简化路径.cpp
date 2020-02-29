/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    /* 算法思路
     * 按顺序扫描路径，根据相关规则简化路径
     * 通过观察测试用例，我们知道在两个/之间如果是..，则直接去掉就好
     * 如果有连续的//，那么也直接去掉就好
     * 输入为空，则依旧要输出/
     * 
     * 以上描述，放到栈中来理解就是
     * 碰到..且栈不为空则出栈，
     * 如果是碰到文件名，即不是..或者.又或者是空，则入栈
     * 
     * 最后输入调用reverse函数逆向
     */
    string simplifyPath(string path) {
        path += "/"; //Unix中目录第一个字符肯定是/，所以直接在path中添加/
        stack<string> stac_k;
        string flag = ""; //设定一个中转变量,初始值设为空
        string ans; //存储结果

        for(auto str : path){ //遍历path路径
            if(str == '/'){ 
                if(flag == ".." && !stac_k.empty())
                    stac_k.pop();
                else if(flag != ".." && flag != "." && !flag.empty())
                    stac_k.push(flag);
                flag = "";
            }else
                flag += str;
        }

        while(!stac_k.empty()){
            auto tmp = stac_k.top();
            stac_k.pop();
            ans += string(tmp.rbegin(), tmp.rend()) + "/"; //先逆序排序
        }

        reverse(ans.begin(), ans.end()); //逆序的逆序等于正序
        if(ans.empty())
            return "/";
        return ans;

    }
};
// @lc code=end


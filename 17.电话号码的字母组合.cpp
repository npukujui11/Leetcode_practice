/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {

    unordered_map<string, string> phone {
        {"2", "abc"},
        {"3", "def"},
        {"4", "ghi"},
        {"5", "jkl"},
        {"6", "mno"},
        {"7", "pqrs"},
        {"8", "tuv"},
        {"9", "wxyz"},
    };

    vector<string> res;//用于存储结果
    

public:

    vector<string> letterCombinations(string digits) {
        


        int m = digits.size();

        if(m != 0){
            backtrack("", digits);
        }
        return res;

    }

    /* 给出如下回溯函数 backtrack(combination, next_digits) ，
     * 它将一个目前已经产生的组合 combination 
     * 和接下来准备要输入的数字 next_digits 作为参数。
     * 如果没有更多的数字需要被输入，那意味着当前的组合已经产生好了。
     * 如果还有数字需要被输入：
     * 遍历下一个数字所对应的所有映射的字母。
     * 将当前的字母添加到组合最后，也就是 combination = combination + letter 
     */

    void backtrack(string combination, string next_digits){
        if(next_digits.size() == 0){//如果没有更多需要被输入的数字，则把combination加入res
            res.push_back(combination);
        }
        else{
            string digits = next_digits.substr(0,1); //截取后续输入的数字的其中一位。
            string letters = phone.at(digits); //去hash表中查找索引
            for(int i = 0; i< letters.size(); i++){//循环回溯
                string letter =  phone.at(digits).substr(i, 1);
                backtrack(combination + letter, next_digits.substr(1));
            }
        }
    }
};
// @lc code=end


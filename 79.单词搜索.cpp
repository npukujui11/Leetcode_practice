/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtracking(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    //回溯函数需要增加一个整型变量，用于判断当前处于word的第几个字符
    bool backtracking(vector<vector<char>>& board, string& word, int row, int col, int index){
        //设置函数退出条件
        if(row >= board.size() || row < 0)
            return false;
        if(col >= board[0].size() || col < 0)
            return false;
        if(index >= word.size() || word[index] != board[row][col])
            return false;
        if(index == word.size() - 1 && word[index] == board[row][col])
            return true;     

        char temp = board[row][col];

        board[row][col] = '-';
        bool flag = (backtracking(board, word, row, col + 1, index + 1)
                        || backtracking(board, word, row, col - 1, index + 1)
                            || backtracking(board, word, row + 1, col, index + 1)
                                || backtracking(board, word, row - 1, col, index + 1));
        board[row][col] = temp;//恢复现场

        return flag;
    }
};
// @lc code=end


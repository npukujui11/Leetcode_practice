/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include<vector>
class Solution {
public:
    int N = 9;

    vector<vector<int>> rows;//用于存储每行可用的数字
    vector<vector<int>> cols;//用于存储每列可用的数字
    vector<vector<int>> block;//用于存储每宫格中可用的数字

    void update(vector<vector<char>>& board){//用于放置数字，并更新每行列宫格可用的数字

    }

    bool isPlace(int nums, int row, int col){//用于检查数字是否可以放到这个位置

    }

    void backtrack(int row, int col){
        if(row == 8 && col == 8){
            return;
        }

        if(board[row][col] == '.'){
            for(int i = 1; i < 10; i++){
                if(isPlace(i, row, col))
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < N; row++){
            for(int col = 0; col < N; col++){
                char nums = board[row][col];
                if(nums == "."){
                    placeNumber(nums, )
                }
            }
        }
    }
};
// @lc code=end


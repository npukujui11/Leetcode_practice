/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solvesudokuDFS(board);     
    }

private:
    bool solvesudokuDFS(vector<vector<char> >&board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    char flag = '1';
                    while(flag <= '9'){
                        if(isvalid(i, j, board, flag)){
                            board[i][j] = flag;
                            if (solvesudokuDFS(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        } 
                        flag++;
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvalid(int row, int col, vector<vector<char> >&board, char c){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == c){
                return false;
            }
        }

        for(int i = 0; i < 9; i++){
            if(board[i][col] == c){
                return false;
            }
        }

        int start_row = row / 3 * 3;//3*3宫格的起始位置
        int start_col = col / 3 * 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[start_row + i][start_col + j] == c){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end


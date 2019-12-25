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
        solvesudokuDFS(board, 0, 0);     
    }

    bool solvesudokuDFS(vector<vector<char> >&board, int i, int j)//回溯（深度优先遍历策略）
    {
        if(i == 9) //遍历到第9行
            return true;
        if(j >= 9) 
            return solvesudokuDFS(board, i + 1, 0);
        if(board[i][j] == '.')
        {
            for(int k = 1; k <= 9; ++k)
            {
                board[i][j] = (char)k+'0';
                if(isvalid(board, i, j)) 
                {
                    if(solvesudokuDFS(board, i, j + 1)) 
                        return true;
                }
                board[i][j]='.';
            }
        }
        else
        {
            return solvesudokuDFS(board, i, j+1);
        }
        return false;
    }

    bool isvalid(vector<vector<char> >&board, int i, int j) //判断数字放在相应位置是否合法
    {
        for(int col=0;col<9;++col)
        {
            if(col!=j&&board[i][j]==board[i][col]) return false;
        }
        for(int row=0;row<9;++row)
        {
            if(row!=i&&board[i][j]==board[row][j]) return false;
        }
        for(int l=i/3*3;l<i/3*3+3;++l)
            for(int m=j/3*3;m<j/3*3+3;++m)
            {
                if(l!=i&&m!=j&&board[i][j]==board[l][m]) return false;
            }
        return true;
    }
};
// @lc code=end


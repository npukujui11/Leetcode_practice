/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> track(n, string(n, '.'));
        backtracking(res, track, 0, n);
        return res;
    }

private:
    bool checkQueen(int row, int col, vector<string>& track){
        //用于判断放置的位置是否合法，合法返回true，不合法返回false
        int n = track.size();
        //检查列冲突
        for(int i = 0; i < n; i++){
            if(track[i][col] == 'Q')
                return false;
        }
        //检查左上方冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (track[i][j] == 'Q')
            return false;
        }
        //检查右上方冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (track[i][j] == 'Q')
            return false;
        }
        return true;
    }

    void backtracking(vector<vector<string>>& res, vector<string>& track, int row, int n){
        //设定退出回溯的条件
        if(track.size() == row){
            res.push_back(track);
            return;
        }

        for(int col = 0; col < n; col++){//列
            //判断放置的位置是否合法
            if(!checkQueen(row, col, track))//如果不合法
                continue;
            //合法
            track[row][col] = 'Q';
            backtracking(res, track, row + 1, n);
            //恢复现场
            track[row][col] = '.';
        }

    }    
};
// @lc code=end


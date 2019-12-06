/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    //典型的二分查找算法，但需要注意在二维数组中的索引问题，注意防止数组越界
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) 
            return false;
        int n = matrix[0].size();

        //二分查找
        int left = 0; 
        int right = m * n - 1;

        while(left <= right){
            
            int mid = left + (right - left) / 2;
            
            if(matrix[mid / n][mid % n] == target)
                return true;
            else if(matrix[mid / n][mid % n] > target)
                right = mid - 1;
            else if(matrix[mid / n][mid % n] < target)
                left = mid + 1;
        }
        return false;
    }
};
// @lc code=end


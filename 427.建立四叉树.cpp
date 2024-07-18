/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }

private:
    Node* construct(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 1) { // 递归退出条件
            return new Node(grid[x][y] == 1, true); // 叶子节点
        }

        int newSize = size / 2;
        Node* topLeft = construct(grid, x, y, newSize);
        Node* topRight = construct(grid, x, y + newSize, newSize);
        Node* bottomLeft = construct(grid, x + newSize, y, newSize);
        Node* bottomRight = construct(grid, x + newSize, y + newSize, newSize);

        // 检查四个子节点是否都是叶子节点，且值相同
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && 
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        }

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
// @lc code=end


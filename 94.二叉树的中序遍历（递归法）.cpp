/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL){ //如果二叉树存在
            if(root->left){ //如果左子树存在
                inorderTraversal(root->left); //先遍历左子树
            }
            res.push_back(root->val);
            if(root->right){ //如果右子树存在
                inorderTraversal(root->right); //最后遍历右子树
            }
        }
        return res;
    }
};
// @lc code=end


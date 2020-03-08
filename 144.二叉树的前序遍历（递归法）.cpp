/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL){ //如果二叉树存在
            res.push_back(root->val);
            if(root->left){
                preorderTraversal(root->left);
            }
            if(root->right){
                preorderTraversal(root->right);
            }
        }
        return res;
    }
};
// @lc code=end


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
#include <stack>

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stac_k;
        if(root == NULL)
            return res;

        TreeNode* curr = NULL;
        stac_k.push(root);
        while(stac_k.size() > 0){ 
            //栈不为空或当前二叉树不为空
            curr = stac_k.top();
            stac_k.pop();
            res.push_back(curr->val);

            if(curr->right != NULL)
                stac_k.push(curr->right);
            if(curr->left != NULL)
                stac_k.push(curr->left);
        }
        return res;
    }
};
// @lc code=end


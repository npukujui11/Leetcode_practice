/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stac_k;
        if(root == NULL)
            return res;
        
        TreeNode* curr = NULL;
        stac_k.push(root);
        while(stac_k.size() > 0){ //栈不为空或当前二叉树不为空
     
            curr = stac_k.top();
            stac_k.pop();
            res.push_back(curr->val);

            if(curr->left)
                stac_k.push(curr->left);
            if(curr->right)
                stac_k.push(curr->right);

        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end


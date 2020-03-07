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
#include <stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stac_k;

        TreeNode* curr = root;
        while(stac_k.size() > 0 || curr != NULL){ //栈不为空或二叉树不为空
            //向左子树方向遍历
            while(curr != NULL) {
                stac_k.push(curr); //每一次把当前节点保存到栈中
                curr = curr->left;
            }

            //如果当前节点为空
            curr = stac_k.top(); //保存栈顶节点
            stac_k.pop(); //从栈中弹出当前节点
            res.push_back(curr->val);
            curr = curr->right; //最后转向右子树方向遍历
        }
        return res;
    }
};
// @lc code=end


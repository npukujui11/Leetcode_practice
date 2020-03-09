/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
#include <stack>
class BSTIterator {
public:
    stack<TreeNode*> stac_k;
    BSTIterator(TreeNode* root) {
            leftmostInorder(root);
    }
    void leftmostInorder(TreeNode* root){
        //将给定节点中的所有左子树添加到栈中，直到节点没有左子树为止
        while(root != NULL){
            stac_k.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        //返回二叉树搜索树的最小元素
        TreeNode* flag = stac_k.top();
        stac_k.pop();
        if(flag != NULL){
            leftmostInorder(flag->right);
        }
        return flag->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stac_k.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end


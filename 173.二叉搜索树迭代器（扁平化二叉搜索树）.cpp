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
#include <vector>
class BSTIterator {
public:
    vector<int> res;
    int index = -1;

    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    void inorderTraversal(TreeNode* root){
        if(root != NULL){
            if(root->left)
                inorderTraversal(root->left);
            res.push_back(root->val);
            if(root->right)
                inorderTraversal(root->right);
        }
    }
    /** @return the next smallest number */
    int next() {
        return res[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index + 1 < res.size())
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end


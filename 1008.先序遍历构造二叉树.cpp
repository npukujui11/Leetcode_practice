/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 先序遍历构造二叉树
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
class Solution {
public:
    /*
	 * 算法思路:
	 * 先判断二叉树是否为空
	 * 
	 * 采用递归的方法，构造二叉搜索树
	 */
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty())
			return NULL;//判断是否为空
		
		TreeNode *root = NULL;
		
		for(int i=0; i<preorder.size(); i++){
			insert(root, preorder[i]);
		}
		return root;
    }
	
	void insert(TreeNode* &root, int x){
		if(root == NULL){
			root = new TreeNode(x);
		}else if(root->val<x){//如果根节点小于x,则插入到右子树
			insert(root->right, x);
		}else{//反之如果根节点大于x,则插入到左子树
			insert(root->left, x);
		}
	}
};
// @lc code=end


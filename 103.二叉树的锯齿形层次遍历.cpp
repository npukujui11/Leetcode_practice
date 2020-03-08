/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> stac_k1; //栈1用于存储从右到左的顺序
        stack<TreeNode*> stac_k2; //栈2用于存储从左到右的顺序
        
        if(root == NULL){ //当二叉树为空
            return res;
        }
        stac_k1.push(root); //根节点先入栈1
        //双栈交替使用，当双栈都为空时结束
        while(stac_k1.size() != 0 || stac_k2.size() != 0){
            vector<int> flag; //用于存储每一层的遍历结果
            TreeNode* curr = NULL; 

            if(stac_k1.size() != 0 && stac_k2.size() == 0){ 
                //栈1不为空，说明栈2为空，则用栈2存下一层从左到右遍历的数
                while(stac_k1.size() != 0){
                    curr = stac_k1.top();
                    stac_k1.pop();
                    flag.push_back(curr->val);

                    if(curr->left != NULL){ //左子树不空压入栈2
                        stac_k2.push(curr->left);
                    }
                    if(curr->right != NULL){ //右子树不空压入栈2
                        stac_k2.push(curr->right);
                    }
                }
                res.push_back(flag);
                flag.clear(); //存储结果后清空
            }

            if(stac_k1.size() == 0 && stac_k2.size() != 0)
            {
                //栈2不为空，栈1为空，则用栈1存下一层从右到左的遍历
                while(stac_k2.size() != 0){
                    curr = stac_k2.top();
                    stac_k2.pop();
                    flag.push_back(curr->val);

                    if(curr->right != NULL){ //右不空压入栈1
                        stac_k1.push(curr->right);
                    }
                    if(curr->left != NULL){ //左不空压入栈1
                        stac_k1.push(curr->left);
                    }
                }
                res.push_back(flag);
                flag.clear();
            }
        }
        return res;
    }
};
// @lc code=end


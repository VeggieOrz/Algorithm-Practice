/*
 * 题目：897. 递增顺序搜索树
 * 链接：https://leetcode-cn.com/problems/increasing-order-search-tree/
 * 知识点：二叉树的中序遍历
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *resNode = new TreeNode(-1);
        TreeNode *tempNode = resNode;
        inordered(root, tempNode);
        return resNode->right;
    }
    void inordered(TreeNode* root, TreeNode* &tempNode) {
        if (root == nullptr) {
            return ;
        }
        inordered(root->left, tempNode);
        // 改变指向
        tempNode->right = root;
        root->left = nullptr;
        tempNode = root;
        inordered(root->right, tempNode);
    }
};

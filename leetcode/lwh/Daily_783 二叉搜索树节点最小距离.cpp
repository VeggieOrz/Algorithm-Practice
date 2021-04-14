/*
 * 题目：783. 二叉搜索树节点最小距离
 * 链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * 知识点：二叉搜索树的性质、树的中序遍历
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
    void dfs(TreeNode* root, int& pre, int& ans) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX, pre = -1;
        dfs(root, pre, minDiff);
        return minDiff;
    }
};

/*
 * 题目：剑指 Offer 34. 二叉树中和为某一值的路径
 * 链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
 * 知识点：回溯法
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
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }
    void dfs(TreeNode *root, int target) {
        if (root == nullptr) {
            return ;
        }
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            res.push_back(vector<int>(path));
        }
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
};

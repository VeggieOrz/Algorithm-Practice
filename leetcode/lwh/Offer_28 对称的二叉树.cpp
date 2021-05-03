/*
 * 题目：剑指 Offer 28. 对称的二叉树
 * 链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 * 知识点：递归
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr || dfs(root->left, root->right)) {
            return true;
        }
        return false;
    }

    bool dfs(TreeNode *L, TreeNode *R) {
        if (L == nullptr && R == nullptr) {
            return true;
        } else if (L == nullptr || R == nullptr || L->val != R->val) {
            return false;
        } else {
            return dfs(L->left, R->right) && dfs(L->right, R->left);
        }
    }
};

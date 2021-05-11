/*
 * 题目：98. 验证二叉搜索树
 * 链接：https://leetcode-cn.com/problems/validate-binary-search-tree/
 * 知识点：二叉树的中序遍历
 */

class Solution {
private:
    long long preVal = LONG_MIN;
public:
    // 递归版
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->val <= preVal) {
            return false;
        }
        preVal = root->val;
        return isValidBST(root->right);
    }
    // 非递归版本
    bool isValidBST(TreeNode* root) {
        long long preVal = LONG_MIN;
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->val <= preVal) {
                return false;
            }
            preVal = root->val;
            root = root->right;
        }
        return true;
    }
};

/*
 * 题目：938. 二叉搜索树的范围和
 * 链接：https://leetcode-cn.com/problems/range-sum-of-bst/
 * 知识点：二叉树的遍历
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        } else if (root->val > high){
            return rangeSumBST(root->left, low, high);
        } else {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
    }
};

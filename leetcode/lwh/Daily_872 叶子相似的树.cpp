/*
 * 题目：872. 叶子相似的树
 * 链接：https://leetcode-cn.com/problems/leaf-similar-trees/
 * 知识点：树的深度优先遍历
 */

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafNodes1;
        dfs(root1, leafNodes1);
        vector<int> leafNodes2;
        dfs(root2, leafNodes2);
        return leafNodes1 == leafNodes2;
    }

private:
    void dfs(TreeNode* root, vector<int> &ans) {
        if (root == nullptr) {
            return ;
        }
        if (root->left != nullptr) {
            dfs(root->left, ans);
        }
        if (root->right != nullptr) {
            dfs(root->right, ans);
        }
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
        }
    }
};

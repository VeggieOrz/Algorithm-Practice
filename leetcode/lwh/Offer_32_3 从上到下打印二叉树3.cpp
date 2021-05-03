/*
 * 题目：剑指 Offer 32 - III. 从上到下打印二叉树 III
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 * 知识点：bfs
 */

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int sz = q.size(), lv = res.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (lv & 1) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
        }
        return res;
    }
};

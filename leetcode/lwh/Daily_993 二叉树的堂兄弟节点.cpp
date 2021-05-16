/*
 * 题目：993. 二叉树的堂兄弟节点
 * 链接：https://leetcode-cn.com/problems/cousins-in-binary-tree/
 * 知识点：dfs、bfs
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
    int depthX, depthY;
    TreeNode *fX, *fY;
    void dfs(TreeNode* root, TreeNode* pre, int x, int y, int depth) {
        if (root == nullptr) {
            return ;
        }
        dfs(root->left, root, x, y, depth + 1);
        if (root->val == x) {
            depthX = depth;
            fX = pre;
        }
        if (root->val == y) {
            depthY = depth;
            fY = pre;
        }
        dfs(root->right, root, x, y, depth + 1);
    }
public:
    // dfs 版
    bool isCousins(TreeNode* root, int x, int y) {
        depthX = -1, depthY = -1;
        fX = nullptr, fY = nullptr;
        dfs(root, nullptr, x, y, 0);
        return fX != fY && depthX == depthY;
    }
    // bfs 版
    using PTT = pair<TreeNode*, TreeNode*>; // 类似于 typedef
    bool isCousins(TreeNode* root, int x, int y) {
        queue<PTT> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode *> vec;
            // 访问所有下一层的节点
            for (int i = 0; i < n; i++) {
                // 学习这种语法
                auto [cur, pre] = q.front();
                q.pop();
                if (cur->val == x || cur->val == y) {
                    vec.push_back(pre);
                }
                if (cur->left != nullptr) {
                    q.push({cur->left, cur});
                }
                if (cur->right != nullptr) {
                    q.push({cur->right, cur});
                }
            }
            // 只有一个说明不同层；有两个则根据父节点是否相同进行判断
            if (vec.size() == 1) {
                return false;
            } else if (vec.size() == 2) {
                return vec[0] != vec[1];
            }
        }
        return false;
    }
};

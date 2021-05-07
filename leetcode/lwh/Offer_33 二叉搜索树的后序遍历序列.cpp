/*
 * 题目：剑指 Offer 33. 二叉搜索树的后序遍历序列
 * 链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 * 知识点：递归、单调栈
 */

class Solution {
private:
    bool verify(vector<int>& postorder, int left, int right) {
        if (left >= right) {
            return true;
        }
        int p = left;
        while (postorder[p] < postorder[right]) p++;

        int m = p;
        while (postorder[p] > postorder[right]) p++;
        return p == right && verify(postorder, left, m - 1) && verify(postorder, m, right - 1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }

    // 单调栈解法
        bool verifyPostorder(vector<int>& postorder) {
        stack<int> s; // 自底向上 单调递增 的栈
        int root = INT_MAX, n = postorder.size() - 1;
        for (int i = n; i >= 0; i--) {
            // 左子树不能小于根节点的值
            if (root < postorder[i]) {
                return false;
            }
            while (!s.empty() && postorder[i] < s.top()) {
                // 记录上一个根节点的值
                root = s.top();
                s.pop();
            }
            s.push(postorder[i]);
        }
        return true;
    }
};

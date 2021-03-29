/*
 * 题目：173. 二叉搜索树迭代器
 * 链接：https://leetcode-cn.com/problems/binary-search-tree-iterator/
 * 知识点；二叉树的中序遍历
 */
class BSTIterator {
private:
    // 递归版中序遍历
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }
        inorder(root->left);
        ret.push_back(root->val);
        inorder(root->right);
    }
    int cnt;
    vector<int> ret;
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        cnt = 0;
    }
    
    int next() {
        return ret[cnt++];
    }
    
    bool hasNext() {
        return cnt < ret.size();
    }
};

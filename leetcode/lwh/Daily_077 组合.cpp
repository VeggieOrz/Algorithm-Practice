/*
 * 题目：77. 组合
 * 链接：https://leetcode-cn.com/problems/combinations/
 * 知识点：回溯
 */

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(int now, int n, int k) {
        if (n - now < k) {
            return;
        }
        if (k == 0) {
            ans.push_back(vector<int>(temp));
            return ;
        }
        for (int i = now + 1; i <= n; i++) {
            temp.push_back(i);
            dfs(i, n, k - 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(0, n, k);
        return ans;
    }
};

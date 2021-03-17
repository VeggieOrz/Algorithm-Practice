/*
 * 题目：115. 不同的子序列
 * 链接：https://leetcode-cn.com/problems/distinct-subsequences/
 * 知识点：动态规划，记忆化搜索
 */

class Solution {
public:
    // 记忆化搜索
    int dfs(string &s, string &t, int i, int j) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            dp[i][j] = dfs(s, t, i - 1, j - 1) + dfs(s, t, i - 1, j);
        } else {
            dp[i][j] = dfs(s, t, i - 1, j);
        }
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        n = s.length(), m = t.length();
        dp.assign(n, vector<int>(m, -1));
        int ans = dfs(s, t, n - 1, m - 1);
        return ans;
    }

private:
    int n, m;
    vector<vector<int>> dp;
};

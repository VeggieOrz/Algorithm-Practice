/*
 * 题目：131. 分割回文串
 * 地址：https://leetcode-cn.com/problems/palindrome-partitioning/
 * 知识点：dfs + dp
 */

class Solution {
public:
    void dfs(string &s, int i) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                temp.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                temp.pop_back();
            }
        }
    } 
    vector<vector<string>> partition(string s) {
        n = s.length();
        dp.assign(n, vector<bool>(n, true));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ans;
    }
private:
    vector<string> temp;
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    int n;
};

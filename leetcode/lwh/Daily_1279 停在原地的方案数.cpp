/*
 * 题目：1269. 停在原地的方案数
 * 链接：https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
 * 知识点：动态规划
 */
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        int n = min(steps, arrLen - 1);
        vector<vector<int>> dp(steps + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if (j + 1 <= n) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
        return dp[steps][0];
    }
    // 空间优化版
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        int n = min(steps, arrLen - 1);
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            int cur = 0, pre = 0;
            for (int j = 0; j <= n; j++) {
                cur = dp[j];
                dp[j] = (dp[j] + pre) % MOD;
                if (j + 1 <= n) {
                    dp[j] = (dp[j] + dp[j + 1]) % MOD;
                }
                pre = cur;
            }
        }
        return dp[0];
    }
};

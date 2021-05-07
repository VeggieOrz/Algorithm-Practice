/*
 * 题目：1723. 完成所有工作的最短时间
 * 链接：https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/
 * 知识点：状态压缩+动态规划
 */

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        // sum[i] 表示子集 i 所需要的总工作时间
        vector<int> sum(1 << n, 0);
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum[i] = sum[i - (1 << j)] + jobs[j];
                    break;
                }
            }
        }
        vector<vector<int>> dp(k, vector<int>(1 << n, 0));
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int minn = INT_MAX;
                // 枚举子集
                for (int s = j; s; s = (s - 1) & j) {
                    // j ^ s 用于求补集
                    // 对于第i个工人，将工作集s分配给他，就意味着工作集j^s就是要分配给前i-1个工人的
                    // 因此，我们需要选出其中的较大值，表示该情况下耗费的最大工作时间
                    minn = min(minn, max(dp[i - 1][j ^ s], sum[s]));
                }
                // 维护 minn 的作用就是求出「最小」的最大工作时间
                dp[i][j] = minn;
            }

        }
        return dp[k - 1][(1 << n) - 1];
    }
};

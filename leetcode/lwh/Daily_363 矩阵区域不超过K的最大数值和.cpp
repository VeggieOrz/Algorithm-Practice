/*
 * 题目：363. 矩形区域不超过 K 的最大数值和
 * 链接：https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/
 * 知识点：二维前缀和+二分
 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        bool isRight = m > n;
        int ans = INT_MIN;
        for (int top = 1; top <= (isRight ? n : m); top++) {
            for (int bot = top; bot <= (isRight ? n : m); bot++) {
                set<int> st; // 存储【 子矩阵左边列 到 原矩阵左边列 】的区域和
                st.insert(0);
                for (int r = 1; r <= (isRight ? m : n); r++) {
                    // right 表示【 子矩阵右边列 到 原矩阵左边列 】的区域和
                    int right = isRight ? (sum[bot][r] - sum[top - 1][r]) : (sum[r][bot] - sum[r][top - 1]);
                    // 【 子矩阵左边列 到 原矩阵左边列 】中距离最接近的
                    auto left = st.lower_bound(right - k);
                    if (left != st.end()) {
                        int temp = right - *left;
                        ans = max(ans, temp);
                    }
                    st.insert(right);
                }
            }
        }
        return ans;
    }
};

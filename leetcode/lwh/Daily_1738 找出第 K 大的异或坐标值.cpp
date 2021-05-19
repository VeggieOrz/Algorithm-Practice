/*
 * 题目：1738. 找出第 K 大的异或坐标值
 * 链接：https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
 * 知识点：二维异或前缀和+排序
 */
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        vector<int> res;
        // 求异或和
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i + 1][j + 1] = sum[i][j + 1] ^ sum[i + 1][j] ^ sum[i][j] ^ matrix[i][j];
                res.push_back(sum[i + 1][j + 1]);
            }
        }
        // 排序
        sort(res.begin(), res.end(), [](const int &a, const int &b) {
            return a > b;
        });
        return res[k - 1];
    }
};

/*
 * 题目：剑指 Offer 29. 顺时针打印矩阵
 * 链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 * 知识点：模拟
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        int left = 0, right = m - 1, up = 0, down = n - 1;
        while (true) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[up][i]);
            }
            if (++up > down) {
                break;
            }
            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[down][i]);
            }
            if (--down < up) {
                break;
            }
            for (int i = down; i >= up; i--){
                ans.push_back(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};

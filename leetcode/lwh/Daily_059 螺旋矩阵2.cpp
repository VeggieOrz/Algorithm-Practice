/*
 * 题目：59. 螺旋矩阵 II
 * 链接：https://leetcode-cn.com/problems/spiral-matrix-ii/
 * 知识点：模拟，蛇形矩阵
 *
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int j = 1;
        int up = 0, down = n - 1;
        int left = 0, right = n - 1;
        while (j <= n * n) {
            for (int i = left; i <= right; i++) {
                res[up][i] = j++;
            }
            up++;
            for (int i = up; i <= down; i++) {
                res[i][right] = j++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                res[down][i] = j++;
            }
            down--;
            for (int i = down; i >= up; i--) {
                res[i][left] = j++;
            }
            left++;
        }
        return res;
    }
};

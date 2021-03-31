/*
 * 题目：74. 搜索二维矩阵
 * 链接：https://leetcode-cn.com/problems/search-a-2d-matrix/
 * 知识点：二分查找
 */
class Solution {
public:
    // 时间复杂度O(n+logm)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return false;
        }
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
                return binarySearch(matrix, i, m - 1, target);
            }
        }
        return false;
    }
    // 对整个矩阵中的元素进行二分，时间复杂度O(log(n*m))
    bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int i = mid / m, j = mid % m;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                right = mid - 1;
            } else if (matrix[i][j] < target) {
                left = mid + 1;
            }
        }
        return false;
    }

private:
    bool binarySearch(vector<vector<int>>& matrix, int i, int r, int target) {
        int left = 0, right = r, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[i][mid] == target) {
                return true;
            } else if (matrix[i][mid] > target) {
                right = mid - 1;
            } else if (matrix[i][mid] < target) {
                left = mid + 1;
            }
        } 
        return false;
    }
};

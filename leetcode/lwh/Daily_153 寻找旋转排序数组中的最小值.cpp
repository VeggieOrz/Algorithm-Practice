/*
 * 题目：153. 寻找旋转排序数组中的最小值
 * 链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 * 知识点：二分、区间选取
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 判断是不是在右边的递增区间
            if (nums[right] > nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

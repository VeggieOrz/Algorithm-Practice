/*
 * 题目：33. 搜索旋转排序数组
 * 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 知识点：二分查找
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        } else if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 寻找有序区间
            // 添加 = 是对 (left == mid) 时的判断
            if (nums[left] <= nums[mid]) {
                // 判断目标值是否在区间中
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // 判断目标值是否在区间中
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

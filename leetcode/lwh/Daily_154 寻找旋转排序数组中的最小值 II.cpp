/*
 * 题目：154. 寻找旋转排序数组中的最小值 II
 * 链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * 知识点：二分、分类讨论
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[right]) {
                right--;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

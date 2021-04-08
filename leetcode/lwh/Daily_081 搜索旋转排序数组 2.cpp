/*
 * 题目：81. 搜索旋转排序数组 II
 * 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 * 知识点：二分查找，思维
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        } else if (n == 1) {
            return nums[0] == target;
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            // nums[left], nums[mid], nums[right] 三个值相等时，无法判断递增区间，只能缩小范围
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

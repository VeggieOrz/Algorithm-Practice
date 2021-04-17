/*
 * 题目：26. 删除有序数组中的重复项
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};

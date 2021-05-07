/*
 * 题目：31. 下一个排列
 * 链接：https://leetcode-cn.com/problems/next-permutation/
 * 知识点：贪心、找规律
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        // 寻找靠右的最小数
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            // 逆序寻找第一个比nums[i]小的数
            while (j > 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
 * 题目：80. 删除有序数组中的重复项 II
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 * 知识点：双指针
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int length = 2;
        for (int i = 2; i < n; i++) {
            // 注意length-2的细节
            if (nums[i] != nums[length - 2]) { 
                nums[length++] = nums[i];
            }
        }
        return length;
    }
};

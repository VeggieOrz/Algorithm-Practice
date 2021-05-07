/*
 * 题目：75. 颜色分类
 * 链接：https://leetcode-cn.com/problems/sort-colors/
 * 知识点：双指针
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; i++) {
            // 要先处理 2，因为交换玩完之后可能那个位置是0，需要后续处理
            while (i <= p2 && nums[i] == 2) {
                    swap(nums[i], nums[p2]);
                    p2--;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};

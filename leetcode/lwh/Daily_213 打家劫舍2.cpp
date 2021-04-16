/*
 * 题目：213. 打家劫舍 II
 * 链接：https://leetcode-cn.com/problems/house-robber-ii/
 * 知识点：动态规划
 */

class Solution {
private:
    int DP(vector<int>& nums, int start, int end) {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        int a = nums[start], b = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int t = b;
            b = max(a + nums[i], b);
            a = t;
        }
        return b;
    }
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        } else if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        // 因为首尾相连，所以第一个和最后一个只能取一个，于是取两种情况中结果大的
        return max(DP(nums, 0, length - 2), DP(nums, 1, length - 1));
    }
};

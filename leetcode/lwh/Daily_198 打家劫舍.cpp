/*
 * 题目：198. 打家劫舍
 * 链接：https://leetcode-cn.com/problems/house-robber/
 * 知识点：动态规划
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        int a = nums[0], b = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int t = b;
            b = max(a + nums[i], b);
            a = t;
        }
        return b;
    }
};

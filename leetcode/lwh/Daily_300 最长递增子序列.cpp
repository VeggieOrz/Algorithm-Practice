/*
 * 题目：300. 最长递增子序列
 * 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * 知识点：动态规划+二分
 */

class Solution {
public:
    // 普通动态规划解法
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
    // 动态规划+二分
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int len = 1;
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int left = 0, right = len;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] >= nums[i]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            dp[left] = nums[i];
            if (left == len) {
                len++;
            }
        }
        return len;
    }
};

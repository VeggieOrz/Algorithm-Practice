/*
 * 题目：377. 组合总和 Ⅳ
 * 链接：https://leetcode-cn.com/problems/combination-sum-iv/
 * 知识点：动态规划
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);
        int n = nums.size();
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n && nums[j] <= i; j++) {
                dp[i] = (0LL + dp[i] + dp[i - nums[j]]) % INT_MAX;
            }
        }
        return dp[target];
    }
};

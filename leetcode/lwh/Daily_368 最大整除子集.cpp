/*
 * 题目：368. 最大整除子集
 * 链接：https://leetcode-cn.com/problems/largest-divisible-subset/
 * 知识点：动态规划
 */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);// dp[i]表示包含nums[i]的最大子集大小
        int maxSize = 1, maxNum = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    // 根据子集大小情况决定是否扩充
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxNum = nums[i];
            }
        }
        vector<int> res(maxSize);
        if (maxSize == 1) {
            res[0] = nums[0];
            return res;
        }

        for (int i = n - 1; i >= 0 && maxSize > 0; i--) {
            // dp[i] == maxSize 判断很重要
            if (dp[i] == maxSize && maxNum % nums[i] == 0) {
                res[--maxSize] = nums[i];
                maxNum = nums[i];
            }
        }
        return res;
    }
};

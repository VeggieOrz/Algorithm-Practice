/*
 * 题目：494. 目标和
 * 链接：https://leetcode-cn.com/problems/target-sum/
 * 知识点：回溯，记忆化搜索，动态规划
 */

class Solution {
private:
    int cnt = 0;
    // 回溯法
    void dfs(vector<int>& nums, int target, int pos, int sum) {
        if (pos == nums.size()) {
            if (sum == target) {
                cnt++;
            }
        } else {
            dfs(nums, target, pos + 1, sum + nums[pos]);
            dfs(nums, target, pos + 1, sum - nums[pos]);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0, 0);
        return cnt;
    }
};

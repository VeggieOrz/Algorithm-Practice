/*
 * 题目：740. 删除并获得点数
 * 链接：https://leetcode-cn.com/problems/delete-and-earn/
 * 知识点：动态规划
 */
class Solution {
private:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
public:
    // 转化为打家劫舍，未优化版本（nums 中元素范围比较小时，效率比较高）
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }
        vector<int> sum(maxVal + 1, 0), dp(maxVal + 1, 0);
        for (int num : nums) {
            sum[num] += num;
        }
        dp[1] = sum[1], dp[2] = max(sum[1], sum[2]);
        for (int i = 3; i <= maxVal; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
        }
        return dp[maxVal];
    }
    // 优化版，当 nums 中元素的范围比较大时，这种方法比较好用
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> sum = {nums[0]};
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                sum.back() += nums[i];
            } else if (nums[i] == nums[i - 1] + 1) {
                sum.push_back(nums[i]);
            } else {
                ans += rob(sum);
                sum = {nums[i]};
            }
        }
        ans += rob(sum);
        return ans;
    }
};

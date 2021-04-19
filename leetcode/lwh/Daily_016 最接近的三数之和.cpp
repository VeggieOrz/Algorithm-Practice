/*
 * 题目：16. 最接近的三数之和
 * 链接：https://leetcode-cn.com/problems/3sum-closest/
 * 知识点：排序+双指针
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                if (sum == target) { // 优化1：最优情况，直接返回
                    return ans;
                } else if (nums[left] == nums[right]) { // 优化2：中间的数都是重复的，直接跳过
                    break;
                } else if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                }
            }
        }
        return ans;
    }
};

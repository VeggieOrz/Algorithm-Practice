/*
 * 题目：523. 连续的子数组和
 * 链接：https://leetcode-cn.com/problems/continuous-subarray-sum/
 * 知识点：前缀和+哈希表
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mapper;
        mapper[0] = -1;
        int sum = 0, num;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            num = sum % k;
            // 不能直接 mapper[num]，因为有可能 mapper[num] == 0
            if (mapper.count(num)) {
                if (i - mapper[num] >= 2) {
                    return true;
                }
            } else {
                mapper[num] = i;
            }
        }
        return false;
    }
    // 更优雅的写法
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // 前缀和
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        unordered_set<int> s;
        for (int i = 2; i <= n; i++) {
            s.insert(sum[i - 2] % k);
            if (s.count(sum[i] % k)) {
                return true;
            }
        }
        return false;
    }
};

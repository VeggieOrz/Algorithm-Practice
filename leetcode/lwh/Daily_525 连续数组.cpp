/*
 * 题目：525. 连续数组
 * 链接：https://leetcode-cn.com/problems/contiguous-array/
 * 知识点：前缀和+哈希
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mapper;
        mapper[0] = 0;
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            cnt += nums[i - 1] ? 1 : -1;
            if (mapper.count(cnt)) {
                int pos = mapper[cnt];
                ans = max(ans, i - pos);
            } else {
                mapper[cnt] = i;
            }
        }
        return ans;
    }
};

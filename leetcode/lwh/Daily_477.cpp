/*
 * 题目：477. 汉明距离总和
 * 链接：https://leetcode-cn.com/problems/total-hamming-distance/
 * 知识点：位运算 + 按位贡献
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            int cnt = 0;
            for (auto num : nums) {
                cnt += (num >> i) & 1;
            }
            ans += cnt * (n - cnt);
        }
        return ans;
    }
};

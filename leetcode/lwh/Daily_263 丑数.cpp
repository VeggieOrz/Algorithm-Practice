/*
 * 题目：263. 丑数
 * 链接：https://leetcode-cn.com/problems/ugly-number/
 */
class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        vector<int> nums{2, 3, 5};
        for (auto num : nums) {
            while (n % num == 0) {
                n /= num;
            }
        }
        return n == 1;
    }
};

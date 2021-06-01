/*
 * 题目：342. 4的幂
 * 链接：https://leetcode-cn.com/problems/power-of-four/
 * 知识点：位运算
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        // 是 2 的 n 次幂，且模 3 等于 1
        return n > 0 && !(n & (n - 1)) && n % 3 == 1;
    }
};

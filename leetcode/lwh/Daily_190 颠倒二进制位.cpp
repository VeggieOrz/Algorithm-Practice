/*
 * 题目：190. 颠倒二进制位
 * 链接：https://leetcode-cn.com/problems/reverse-bits/
 * 知识点：位运算
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= n & 1;
            n >>= 1;
        }
        return ans;
    }
};

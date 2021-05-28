/*
 * 题目：461. 汉明距离
 * 链接：https://leetcode-cn.com/problems/hamming-distance/
 * 知识点：位运算
 */
class Solution {
public:
    // 方法一
    int hammingDistance(int x, int y) {
        int ans = 0;
        while (x || y) {
            if ((x & 1) != (y & 1)) {
                ans++;
            }
            x >>= 1;
            y >>= 1;
        }
        return ans;
    }
    // 方法二
    int lowbit(int x) {
        return x & -x;
    }
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = x ^ y; i > 0; i -= lowbit(i)) {
            ans++;
        }
        return ans;
    }
};

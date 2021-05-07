/*
 * 题目：1486. 数组异或操作
 * 链接：https://leetcode-cn.com/problems/xor-operation-in-an-array/
 */

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i = 1; i < n; i++) {
            int num = start + 2 * i;
            ans ^= num;
        }
        return ans;
    }
    // 数学方法
    // 题解链接：https://leetcode-cn.com/problems/xor-operation-in-an-array/solution/shu-zu-yi-huo-cao-zuo-by-leetcode-solution/
    int sumXor(int x) {
        if (x % 4 == 0) {
            return x;
        }
        if (x % 4 == 1) {
            return 1;
        }
        if (x % 4 == 2) {
            return x + 1;
        }
        return 0;
    }

    int xorOperation(int n, int start) {
        int s = start >> 1, e = n & start & 1;
        int ret = sumXor(s - 1) ^ sumXor(s + n - 1);
        return ret << 1 | e;
    }
};

/*
 * 题目：338. 比特位计数
 * 链接：https://leetcode-cn.com/problems/counting-bits/
 * 知识点：暴力，动态规划，位运算
 */

class Solution {
public:
    int getNum(int n) {
        int cnt = 0;
        while (n != 0) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
    // 方法一：暴力法
    vector<int> countBits_1(int num) {
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++) {
            ans[i] = getNum(i);
        }
        return ans;
    }
    // 方法二： 最高有效位
    // highBit 是小于等于 i 且是最大的 2 的整数倍的数
    // 令 j = i - highBit, 则 dp[i] = dp[j] + 1
    vector<int> countBits_2(int num) {
        vector<int> dp(num + 1);
        int highBit = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            dp[i] = dp[i - highBit] + 1;
        }
        return dp;
    }
    // 方法三：二进制低位 + 奇偶分类
    // 要想求 i 的二进制位 1 的个数，可以依据以求得的 (i >> 1) 的结果来求
    // 如果 i 为奇数，则 dp[i] = dp[i >> 1] + 1;
    // 如果 i 为偶数，则 dp[i] = dp[i >> 1];
    vector<int> countBits_3(int num) {
        vector<int> dp(num + 1);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
    // 方法四：最低设置位
    // i 的最低设置为 i & (i - 1)，即 i 二进制的最右边的 1 变为 0 的数
    // dp[i] = dp[i & (i - 1] + 1;
    vector<int> countBits_4(int num) {
        vector<int> dp(num + 1);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};

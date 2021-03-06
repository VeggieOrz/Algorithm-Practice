/*
 * 题目：7. 整数反转
 * 链接：https://leetcode-cn.com/problems/reverse-integer/
 */
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = x % 10;
            x /= 10;
            // 正数处理
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && temp > 7)) {
                return 0;
            }
            // 负数处理
            if (ans < INT_MIN / 10 || ans == INT_MIN / 10 && temp < -8) {
                return 0;
            }
            ans = ans * 10 + temp;
        }
        return ans;
    }
};

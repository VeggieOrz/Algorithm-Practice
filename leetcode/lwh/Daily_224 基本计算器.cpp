/*
 * 题目：224. 基本计算器
 * 链接：https://leetcode-cn.com/problems/basic-calculator/
 * 知识点：表达式展开+栈
 *
 */
class Solution {
public:
    int calculate(string s) {
        // 表示括号里面元素的真正符号
        stack<int> ops;
        ops.push(1);
        int sign = 1;
        int ans = 0, i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ans += num * sign;
            }
        }
        return ans;
    }
};

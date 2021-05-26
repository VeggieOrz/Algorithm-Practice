/*
 * 题目：1190. 反转每对括号间的子串
 * 链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * 知识点：模拟、栈
 */
class Solution {
public:
    // 方法一：栈
    string reverseParentheses(string s) {
        string str = "";
        stack<string> stk;
        for (auto &ch : s) {
            if (ch == '(') {
                stk.push(str);
                str = "";
            } else if (ch == ')') {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            } else {
                str.push_back(ch);
            }
        }
        return str;
    }
    // 方法二：预处理括号
    // 核心：在模拟中发现移动的规律
    string reverseParentheses(string s) {
        int n = s.length();
        string str = "";
        stack<int> stk;
        vector<int> next(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                next[i] = j;
                next[j] = i;
            }
        }
        int dir = 1;
        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = next[i]; // 移到与之匹配的括号位置
                dir = -dir; // 更改移动方向
            } else {
                str.push_back(s[i]);
            }
        }
        return str;
    }
};

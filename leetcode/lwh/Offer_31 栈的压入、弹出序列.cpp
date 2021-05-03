/*
 * 题目：剑指 Offer 31. 栈的压入、弹出序列
 * 链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 * 知识点：模拟、栈
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (auto &e : pushed) {
            s.push(e);
            while (!s.empty() && s.top() == popped[i]) {
                s.pop();
                i++;
            }
        }
        return s.empty();
    }
};

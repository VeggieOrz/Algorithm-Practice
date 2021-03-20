/*
 * 题目：150. 逆波兰表达式求值
 * 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * 知识点：栈+波兰表达式
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (isNum(token)) {
                // 将字符串装换为数字
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch(token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }
private:
    bool isNum(string &str) {
        return !(str == "+" || str == "-" || str == "*" || str == "/");
    }
};

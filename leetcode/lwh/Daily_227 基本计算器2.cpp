/*
 * 题目：227. 基本计算器 II
 * 链接：https://leetcode-cn.com/problems/basic-calculator-ii/
 * 知识点：栈、表达式计算
 */
class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        char preSign = '+';
        long num = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            if (((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i == n - 1) {
                switch (preSign) {
                    case '+':
                        nums.push_back(num);
                        break;
                    case '-':
                        nums.push_back(-num);
                        break;
                    case '*':
                        nums.back() *= num;
                        break;
                    case '/':
                        nums.back() /= num;
                        break;
                }
                preSign = s[i];
                num = 0;
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += nums[i];
        }
        return res;
    }
};

/*
 * 题目：12. 整数转罗马数字
 * 链接：https://leetcode-cn.com/problems/integer-to-roman/
 * 知识点：模拟
 */

const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                ans += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return ans;
    }
};

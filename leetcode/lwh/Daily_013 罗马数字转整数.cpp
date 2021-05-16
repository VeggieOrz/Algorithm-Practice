/*
 * 题目：13. 罗马数字转整数
 * 链接：https://leetcode-cn.com/problems/roman-to-integer/
 * 知识点：模拟
 */
class Solution {
private:
    unordered_map<char, int> mapper = {
        {'I' , 1},
        {'V' , 5},
        {'X' , 10},
        {'L' , 50},
        {'C' , 100},
        {'D' , 500},
        {'M' , 1000},
    };

public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && mapper[s[i]] < mapper[s[i + 1]]) {
                ans -= mapper[s[i]];
            } else {
                ans += mapper[s[i]];
            }
        }
        return ans;
    }
};

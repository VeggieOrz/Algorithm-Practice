/*
 * 题目：1047. 删除字符串中的所有相邻重复项
 * 链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * 知识点：栈
 */

class Solution {
public:
    string removeDuplicates(string S) {
        string str;
        for (int i = 0; i < S.length(); i++) {
            if (str.length() > 0 && str.back() == S[i]) {
                str.pop_back();
            } else {
                str.push_back(S[i]);
            }
        }
        return str;
    }
};

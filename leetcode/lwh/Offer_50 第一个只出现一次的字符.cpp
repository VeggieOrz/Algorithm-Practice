/*
 * 题目：剑指 Offer 50. 第一个只出现一次的字符
 * 链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 * 知识点：哈希表、队列
 */

class Solution {
public:
    // 哈希表解法
    char firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (cnt.count(s[i])) {
                cnt[s[i]] = -1;
            } else {
                cnt[s[i]] = i;
            }
        }
        int res = n;
        for (auto [ch, idx] : cnt) {
            if (idx != -1 && idx < res) {
                res = idx;
            }
        }
        return res != n ? s[res] : ' ';
    }
    // 哈希表+队列解法
    char firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        queue<char> q;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (cnt.count(s[i])) {
                cnt[s[i]] = -1;
                while (!q.empty() && cnt[q.front()] == -1) {
                    q.pop();
                }
            } else {
                cnt[s[i]] = i;
                q.push(s[i]);
            }
        }
        return q.empty() ? ' ' : q.front();
    }
};

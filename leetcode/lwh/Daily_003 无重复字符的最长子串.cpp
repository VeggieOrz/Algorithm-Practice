/*
 * 题目：3. 无重复字符的最长子串
 * 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * 知识点：双指针
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(128, -1); // 存储 vis[s[i]] 表示 s[i] 上次出现的位置
        int ans = 0, start = 0;
        for (int end = 0; end < s.length(); end++) {
            // 在 [start, end] 之间出现过
            if (vis[s[end]] >= start) {
                start = vis[s[end]] + 1;
            }
            vis[s[end]] = end;
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

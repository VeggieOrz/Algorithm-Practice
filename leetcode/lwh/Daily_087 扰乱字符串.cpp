/*
 * 题目：87. 扰乱字符串
 * 链接：https://leetcode-cn.com/problems/scramble-string/
 * 知识点：dp、记忆化搜索
 */
class Solution {
private:
    string s1, s2;
    // -1 表示 false, 0 表示未计算, 1 表示 true
    int dp[30][30][31];
    // 判断两个串中包含的字符是否一样
    bool isSimilar(int i1, int i2, int length) {
        unordered_map<int, int> cnt;
        for (int i = i1; i < i1 + length; i++) {
            cnt[s1[i]]++;
        }
        for (int i = i2; i < i2 + length; i++) {
            cnt[s2[i]]--;
        }
        if (any_of(cnt.begin(), cnt.end(), [](const auto &p){return p.second != 0;})) {
            return false;
        }
        return true;
    }

    bool dfs(int i1, int i2, int length) {
        // 判断是否已经计算过
        if (dp[i1][i2][length]) {
            return dp[i1][i2][length] == 1;
        }
        // 判断子串是否相等
        if (s1.substr(i1, length) == s2.substr(i2, length)) {
            dp[i1][i2][length] = 1;
            return true;
        }
        // 判断子串中同类型字符的数量是否相等
        if (!isSimilar(i1, i2, length)) {
            dp[i1][i2][length] = -1;
            return false;
        }
        // 枚举分隔长度
        for (int i = 1; i < length; i++) {
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
                // 未发生交换
                dp[i1][i2][length] = 1;
                return true;
            } else if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
                // 发生交换
                dp[i1][i2][length] = 1;
                return true;
            }
        }
        dp[i1][i2][length] = -1;
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        memset(dp, 0, sizeof(dp));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.length());
    }
};

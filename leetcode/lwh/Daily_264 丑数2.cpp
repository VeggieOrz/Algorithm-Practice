/*
 * 题目：264. 丑数 II
 * 链接：https://leetcode-cn.com/problems/ugly-number-ii/
 * 知识点：动态规划（三指针）、小根堆
 */
class Solution {
public:
    // 时间复杂度：O(nlogn)
    int nthUglyNumber(int n) {
        vector<int> nums{2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> vis;
        pq.push(1);
        for (int i = 2; i <= n; i++) {
            long ugly = pq.top();
            pq.pop();
            for (int &num : nums) {
                long t = ugly * num;
                if (!vis.count(t)) {
                    vis.insert(t);
                    pq.push(t);
                }
            }
        }
        return pq.top();
    }
    // 时间复杂度：O(n)
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int p2= 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num1 = dp[p2] * 2, num2 = dp[p3] * 3, num3 = dp[p5] * 5;
            dp[i] = min(min(num1, num2), num3);
            if (num1 == dp[i]) p2++;
            if (num2 == dp[i]) p3++;
            if (num3 == dp[i]) p5++;
        }
        return dp[n];
    }
};

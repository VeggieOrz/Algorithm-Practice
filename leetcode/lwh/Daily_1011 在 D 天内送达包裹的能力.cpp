/*
 * 题目：1011. 在 D 天内送达包裹的能力
 * 链接：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 * 知识点：二分
 */
class Solution {
public:
    bool isOk(vector<int>& weights, int D, int L) {
        int n = weights.size();
        int cnt = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + weights[i] > L) {
                sum = 0;
                cnt++;
            }
            sum += weights[i];
        }
        return cnt <= D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int left = 0, right = 0;
        for (auto weight : weights) {
            left = max(left, weight);
            right += weight;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isOk(weights, D, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

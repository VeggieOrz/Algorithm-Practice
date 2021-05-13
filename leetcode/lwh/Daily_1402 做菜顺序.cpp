/*
 * 题目：1402. 做菜顺序
 * 链接：https://leetcode-cn.com/problems/reducing-dishes/
 * 知识点：贪心
 */
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // 降序排序
        sort(satisfaction.begin(), satisfaction.end(), [](const int &a, const int &b) {
            return a > b;
        });
        int n = satisfaction.size();
        // pre 存储 satisfaction[0] 到 satisfaction[i - 1] 的和
        int pre = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            // 判断能否实现增长
            if (pre + satisfaction[i] > 0) {
                ans += pre + satisfaction[i];
                pre += satisfaction[i];
            } else {
                break;
            }
        }
        return ans;
    }
};


/*
 * 题目：179. 最大数
 * 链接：https://leetcode-cn.com/problems/largest-number/
 * 知识点：排序
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "";
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            long long ta = 10, tb = 10;
            while (ta <= a) {
                ta *= 10;
            }
            while (tb <= b) {
                tb *= 10;
            }
            return tb * a + b > ta * b + a;
        });
        if (nums[0] == 0) {
            return "0";
        }
        for (auto &num : nums) {
            s += to_string(num);
        }
        return s;
    }
};

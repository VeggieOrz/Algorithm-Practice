/*
 * 题目：456. 132 模式
 * 链接：https://leetcode-cn.com/problems/132-pattern/
 * 知识点：枚举+二分查找/单调栈
 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        multiset<int> s;
        int leftMin = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > leftMin) {
                // 二分查找第一个大于 leftMin(1) 的数
                auto it = s.upper_bound(leftMin);
                // 如果找到了，且小于nums[i](3)说明找到我们要的2了
                if (it != s.end() && *it < nums[i]) {
                    return true;
                }
            }
            leftMin = min(leftMin, nums[i]);
            s.erase(s.find(nums[i + 1]));
        }
        return false;
    }
};

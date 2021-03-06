/*
    题目：503. 下一个更大元素 II
    链接：https://leetcode-cn.com/problems/next-greater-element-ii/
    知识点：单调栈+循环数组
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s; // 单调栈，栈中下标对应的元素是单调递增的
        // 取下标的时候，用 % 达到循环的效果
        for (int i = 0; i < 2 * n - 1; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                ans[s.top()] = nums[i % n];
                s.pop(); 
            }
            s.push(i % n);
        }
        return ans;
    }
};

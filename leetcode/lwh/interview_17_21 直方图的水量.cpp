/*
 * 题目：面试题 17.21. 直方图的水量
 * 链接：https://leetcode-cn.com/problems/volume-of-histogram-lcci/
 * 知识点：动态规划、单调栈、双指针
 */
class Solution {
public:
    // 动态规划做法
    int trap_1(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n - 2; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
    // 单调栈写法
    int trap_2(vector<int>& height) {
        stack<int> s; // 单调栈，下标对应元素在栈中自底向上单调递减
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            // 条件判断保证单调性
            while (!s.empty() && height[i] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                int left = s.top();
                int curWidth = i - left - 1;
                int curHeight = min(height[left], height[i]) - height[top];
                ans += curWidth *curHeight;
            }
            s.push(i);
        }
        return ans;
    }
    // 双指针做法
    public int trap(int[] height) {
        int ans = 0;
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = Math.max(leftMax, height[left]);
            rightMax = Math.max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};

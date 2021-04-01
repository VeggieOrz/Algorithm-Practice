/*
 * 题目：1006. 笨阶乘
 * 链接：https://leetcode-cn.com/problems/clumsy-factorial/
 * 知识点：栈、数学
 */
class Solution {
public:
    int clumsy(int N) {
        vector<int> nums(1, N);
        int i = 0;
        while (--N) {
            switch(i%4) {
                // 符号*
                case 0:
                    nums.back() *= N;
                    break;
                // 符号/
                case 1:
                    nums.back() /= N;
                    break;
                // 符号+
                case 2:
                    nums.push_back(N);
                    break;
                // 符号-
                case 3:
                    nums.push_back(-N);
                    break;
            }
            i++;
        }
        int ans = 0;
        for (auto num : nums) {
            ans += num;
        }
        return ans;
    }
    // 数学方法
    // 题解链接：https://leetcode-cn.com/problems/clumsy-factorial/solution/ben-jie-cheng-by-leetcode-solution-deh2/
    int clumsy_(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};

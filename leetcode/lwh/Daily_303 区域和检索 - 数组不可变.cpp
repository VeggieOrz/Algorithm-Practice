/*
 * 题目：区域和检索 - 数组不可变
 * 链接：https://leetcode-cn.com/problems/range-sum-query-immutable/
 * 知识点：一维前缀和
 */
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        if (n > 0) {
            sums.resize(n, 0);
            sums[0] = nums[0];
            for (int i = 1; i < n; i++) {
                sums[i] = sums[i - 1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sums[j];
        } else {
            return sums[j] - sums[i - 1];
        }
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

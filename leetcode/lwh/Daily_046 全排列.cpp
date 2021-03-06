/*
 * 题目：全排列
 * 链接：https://leetcode-cn.com/problems/permutations/
 */
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int n) {
        if (nums.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis.count(i)) {
                vis.insert(i);
                temp.push_back(nums[i]);
                dfs(ans, nums, temp, n + 1); // 递归
                vis.erase(i);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans, nums, temp, 0);
        return ans;
    }
private:
    unordered_set<int> vis;
};

/*
 * 题目：1707. 与数组中元素的最大异或值
 * 链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
 * 知识点：字典树+离线查询
 */

// 01Trie 模板
const int SON_CNT = 2;
const int HIGH_BIT = 30;

struct TrieNode {
    TrieNode *son[SON_CNT];
    TrieNode() {
        for (int i = 0; i < SON_CNT; i++) {
            son[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insertNum(int num) {
        TrieNode *cur = root;
        for (int i = HIGH_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->son[bit] == nullptr) {
                cur->son[bit] = new TrieNode();
            }
            cur = cur->son[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode *cur = root;
        int res = 0;
        for (int i = HIGH_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->son[!bit] != nullptr) {
                res = (res << 1) | 1;
                cur = cur->son[!bit];
            } else {
                res = res << 1;
                cur = cur->son[bit];
            }
        }
        return res;
    }
};

class Solution {
private:
    Trie *trie;
public:
    Solution() {
        trie = new Trie();
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);
        }
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [] (const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        vector<int> ans(m);
        int pos = 0;
        for (auto q : queries) {
            int xi = q[0], mi = q[1], qid = q[2];
            while (pos < n && nums[pos] <= mi) {
                trie->insertNum(nums[pos]);
                pos++;
            }
            if (pos == 0) {
                ans[qid] = -1;
            } else {
                ans[qid] = trie->getMaxXor(xi);
            }
        }
        return ans;
    }
};

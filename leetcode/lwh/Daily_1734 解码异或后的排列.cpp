/*
 * 题目：1734. 解码异或后的排列
 * 链接：https://leetcode-cn.com/problems/decode-xored-permutation/
 * 知识点：找规律、异或的性质
 */
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        // 计算所有元素的异或和
        int all = 1;
        for (int i = 2; i <= n; i++) {
            all ^= i;
        }
        // 计算除了第一个元素以外所有元素的异或和
        int part = encoded[1];
        for (int i = 3; i <= n - 2; i += 2) {
            part ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = all ^ part;
        for (int i = 1; i < n; i++) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        return perm;
    }
};

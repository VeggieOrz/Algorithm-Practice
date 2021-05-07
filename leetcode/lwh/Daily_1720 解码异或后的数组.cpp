/*
 * 题目：1720. 解码异或后的数组
 * 链接：https://leetcode-cn.com/problems/decode-xored-array/
 * 知识点：异或的性质
 */

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr(n + 1);
        arr[0] = first;
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] ^ encoded[i - 1];
        }
        return arr;
    }
};

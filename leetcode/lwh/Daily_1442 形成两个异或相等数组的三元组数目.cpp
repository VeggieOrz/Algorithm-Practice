/*
 * 题目：1442. 形成两个异或相等数组的三元组数目
 * 链接：https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 * 知识点：前缀和
 */
class Solution {
public:
    // 三层循环
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] ^ arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if (s[i] == s[k + 1]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    // 双层循环
    // 当s[i] == s[k + 1], (i, k]范围内的数字都可以作为j
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] ^ arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (s[i] == s[k + 1]) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }
    // 单层循环，哈希表优化
    // 优化依据：(k - i1) + (k - i2) + ... + (k - im) = k * m - (i1 + i2 + ... + im)
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] ^ arr[i];
        }
        int ans = 0;
        unordered_map<int, int> cnt, total;
        for (int i = 0; i < n; i++) {
            if (cnt.count(s[i + 1])) {
                ans += i * cnt[s[i + 1]] - total[s[i + 1]];
            }
            cnt[s[i]]++;
            total[s[i]] += i;
        }
        return ans;
    }
    // 空间优化，将求前缀和过程和求解过程结合
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (cnt.count(s ^ arr[i])) {
                ans += i * cnt[s ^ arr[i]] - total[s ^ arr[i]];
            }
            cnt[s]++;
            total[s] += i;
            s ^= arr[i];
        }
        return ans;
    }
};

/*
 * 题目：692. 前K个高频单词
 * 链接：https://leetcode-cn.com/problems/top-k-frequent-words/
 * 知识点：哈希表、排序
 */
class Solution {
public:
    using psi = pair<string, int>;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        // 词频统计
        for (auto word : words ) {
            cnt[word]++;
        }
        // 放入 vector 中，方便按 value 排序
        vector<psi> wordVec;
        for (auto [word, c] : cnt) {
            wordVec.push_back({word, c});
        }
        // 排序，使用 lambda 表达式代替 cmp 函数
        sort(wordVec.begin(), wordVec.end(), [](const psi &a, const psi &b) {
            if (a.second !=  b.second) {
                return a.second >  b.second;
            } else {
                return a.first < b.first;
            }
        });
        // 取出词频前 k 高
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(wordVec[i].first);
        }
        return res;
    }
    // 相同思路，更好的写法
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& word : words) {
            ++cnt[word];
        }
        vector<string> rec;
        for (auto& [key, value] : cnt) {
            rec.emplace_back(key);
        }
        sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
        });
        rec.erase(rec.begin() + k, rec.end());
        return rec;
    }
};

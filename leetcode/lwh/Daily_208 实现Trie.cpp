/*
 * 题目：208. 实现 Trie (前缀树)
 * 链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 * 知识点：字典树
 */
class Trie {
private:
    vector<Trie *> next;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->next.resize(26, nullptr);
        this->isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            if (node->next[ch - 'a'] == nullptr) {
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char ch : word) {
            node = node->next[ch - 'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            node = node->next[ch - 'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

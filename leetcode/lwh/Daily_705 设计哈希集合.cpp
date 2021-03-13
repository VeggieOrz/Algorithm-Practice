/*
 * 题目：705. 设计哈希集合
 * 链接：https://leetcode-cn.com/problems/design-hashset/
 * 知识点：空间换时间 || 哈希表
 */
class MyHashSet {
private:
    vector<list<int>> hashSet;
    static const int base = 821;
    static int hash(int x) {
        return x % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet(): hashSet(base) {}
    
    void add(int key) {
        int h = hash(key);
        for (auto it = hashSet[h].begin(); it != hashSet[h].end(); it++) {
            if ((*it) == key) {
                return ;
            }
        }
        hashSet[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = hashSet[h].begin(); it != hashSet[h].end(); it++) {
            if ((*it) == key) {
                hashSet[h].erase(it);
                return ;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it = hashSet[h].begin(); it != hashSet[h].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

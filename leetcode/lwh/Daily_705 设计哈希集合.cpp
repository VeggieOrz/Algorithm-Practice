/*
 * 题目：705. 设计哈希集合
 * 链接：https://leetcode-cn.com/problems/design-hashset/
 * 知识点：空间换时间
 */
class MyHashSet {
private:
    vector<bool> hashSet;
    static const int base = 1e6 +10;

public:
    /** Initialize your data structure here. */
    MyHashSet():hashSet(base) {}

    void add(int key) {
        hashSet[key] = true;
    }

    void remove(int key) {
        hashSet[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashSet[key];
    }
};

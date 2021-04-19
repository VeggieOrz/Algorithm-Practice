/*
 * 题目：146. LRU 缓存机制
 * 链接：https://leetcode-cn.com/problems/lru-cache/
 * 知识点：哈希表+双向链表
 */
struct LRULinkedNode {
    int key, value;
    LRULinkedNode *pre;
    LRULinkedNode *next;
    LRULinkedNode():key(0), value(0), pre(nullptr), next(nullptr) {};
    LRULinkedNode(int _key, int _value):key(_key), value(_value), pre(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    unordered_map<int, LRULinkedNode *> cache; // 缓存
    LRULinkedNode *head; // 双端链表虚拟头结点 
    LRULinkedNode *tail; // 双端链表虚拟尾结点
    int capacity; // 可用容量
    int size; // 已用容量
    // 将 node 添加到头结点
    void addToHead(LRULinkedNode *node) {
        // 处理 node 节点
        node->next = head->next;
        node->pre = head;
        // 处理 head 节点
        head->next->pre = node;
        head->next = node;
    }
    // 删除 node 节点
    void removeNode(LRULinkedNode *node) {
        // 处理 node 的左右节点
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    // 将 node 移动到头部位置
    void moveToHead(LRULinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }
    // 淘汰尾部节点
    LRULinkedNode* removeTail() {
        LRULinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity):capacity(capacity), size(0) {
        head = new LRULinkedNode();
        tail = new LRULinkedNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        LRULinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 创建
            LRULinkedNode *node = new LRULinkedNode(key, value);
            // 插入
            addToHead(node);
            cache[key] = node;
            size++;
            // 判断是否淘汰
            if (size > capacity) {
                LRULinkedNode *node = removeTail();
                cache.erase(node->key);
                size--;
                delete node;
            }
        } else {
            // 通过获取节点
            LRULinkedNode *node = cache[key];
            // 修改节点值
            node->value = value;
            // 移动到前方
            moveToHead(node);
        }
    }
};

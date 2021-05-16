/*
 * 题目：23. 合并K个升序链表
 * 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 知识点：归并排序、优先队列
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* merge(ListNode *a, ListNode *b) {
        if (!a || !b) {
            return a ? a : b;
        }
        ListNode *tHead = new ListNode(-1);
        ListNode *node = tHead;
        while (a && b) {
            if (a->val < b->val) {
                node->next = a;
                a = a->next;
            } else {
                node->next = b;
                b = b->next;
            }
            node = node->next;
        }
        node->next = a ? a : b;
        return tHead->next;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        ListNode *left = mergeSort(lists, l, mid);
        ListNode *right = mergeSort(lists, mid + 1, r);
        return merge(left, right);
    }

public:
    // 归并排序
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, lists.size() - 1);
    }
    // 优先队列
    struct Status {
        int val;
        ListNode *node;
        // 重载运算符
        bool operator < (const Status &a) const {
            return val > a.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Status> pq;
        for (auto node : lists) {
            if (node) {
                pq.push({node->val, node});
            }
        }
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (!pq.empty()) {
            auto s = pq.top();
            pq.pop();
            cur->next = s.node;
            cur = cur->next;
            if (s.node->next != nullptr) {
                pq.push({(s.node->next)->val, s.node->next});
            }
        }
        return head->next;
    }
};

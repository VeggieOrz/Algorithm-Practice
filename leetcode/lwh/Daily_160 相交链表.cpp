/*
 * 题目：160. 相交链表
 * 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * 知识点：双指针
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = (p == nullptr) ? headB : p->next;
            q = (q == nullptr) ? headA : q->next;
        }
        return p;
    }
};

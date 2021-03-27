/*
 * 题目：61. 旋转链表
 * 链接：https://leetcode-cn.com/problems/rotate-list/
 * 知识点：数据结构、链表
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int Length = 1;
        ListNode *it = head;
        while (it->next != nullptr) {
            it = it->next;
            Length++;
        }
        int add = Length - (k % Length);
        if (add == 0) {
            return head;
        }
        // 从原本的最后一个节点起，走 add 步
        it->next = head;
        for (int i = 0; i < add; i++) {
            it = it->next;
        }
        ListNode *ret = it->next;
        it->next = nullptr;
        return ret;
    }
};

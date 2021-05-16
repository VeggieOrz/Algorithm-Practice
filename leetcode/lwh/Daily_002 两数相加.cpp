/*
 * 题目：2. 两数相加
 * 链接：https://leetcode-cn.com/problems/add-two-numbers/
 * 知识点：链表
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tHead = new ListNode(-1);
        ListNode *cur = tHead;
        // 处理相加
        int add = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + add;
            add = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // 处理长出来的部分
        ListNode *t = (l1 != nullptr) ? l1 : l2;
        while (t) {
            int sum = t->val + add;
            add = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            cur->next = node;
            cur = cur->next;
            t = t->next;
        }
        // 处理最后的进位
        if (add == 1) {
            ListNode *node = new ListNode(1);
            cur->next = node;
        }
        return tHead->next;
    }
};

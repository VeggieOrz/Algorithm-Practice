/*
 * 题目：92. 反转链表 II
 * 链接：https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * 知识点：数据结构、链表
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 虚拟节点，可以处理边界情况
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *pre = temp;
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next = nullptr;
        for (int i = m; i < n; i++) {
            // next 指向 cur 的下一个节点 
            next = cur->next;
            // cur 的 next 指针指向 next 的下一个节点
            cur->next = next->next;
            // next 的next 指针指向 pre 的下一个节点
            // （注意：不是 cur 的下一个节点）
            next->next = pre->next;
            // 将 next 移动到 pre 的后面
            pre->next = next;
        }
        return temp->next;
    }
};

/*
 * 题目：203. 移除链表元素
 * 链接：https://leetcode-cn.com/problems/remove-linked-list-elements/
 * 知识点：链表的遍历与节点删除
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tHead = new ListNode();
        tHead->next = head;
        ListNode *p = tHead;
        while (p != nullptr && p->next != nullptr) {
            ListNode *nextNode = p->next;
            if (nextNode->val == val) {
                p->next = nextNode->next;
            } else {
                p = p->next;
            }
        }
        return tHead->next;
    }
};

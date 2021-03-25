/*
 * 题目：83. 删除排序链表中的重复元素
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * 知识点：链表
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *Cur = head, *Next = nullptr;
        while (Cur != nullptr) {
            Next = Cur->next;
            if (Next != nullptr && Cur->val == Next->val) {
                while (Next != nullptr && Cur->val == Next->val) {
                    Next = Next->next;
                }
                Cur->next = Next;
            }
            Cur = Cur->next;
        }
        return temp->next;
    }
};

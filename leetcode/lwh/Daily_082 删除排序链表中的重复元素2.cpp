/*
 * 题目：82. 删除排序链表中的重复元素 II
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 * 知识点：链表的遍历和删除
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *pre = temp, *left = temp->next, *right = nullptr;
        while (left != nullptr) {
            right = left;
            while (right->next && left->val == right->next->val) {
                right = right->next;
            }
            if (left != right) {
                pre->next = right->next;
                right->next = nullptr; 
                left = pre->next;
            } else {
                pre = left;
                left = left->next;
            }
        }
        return temp->next;
    }
};

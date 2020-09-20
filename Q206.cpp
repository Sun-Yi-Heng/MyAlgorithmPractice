//
// Created by 孙一恒 on 2020/3/21.
// Q206、反转链表
//

#include "util.h"

class Solution {
public:
    /**
     * 迭代反转
     * 时间复杂度O(n),空间复杂度O(1)
     */
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *n1 = head, *n2 = head->next;
        n1->next = NULL;
        while (n2 != NULL) {
            ListNode *n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        return n1;
    }

    /**
     * 递归反转
     * 时间复杂度和空间复杂度都为O(1)
     */
    ListNode* reverseList1(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p =  reverseList1(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

//
// Created by ��һ�� on 2020/3/21.
// Q206����ת����
//

#include "util.h"

class Solution {
public:
    /**
     * ������ת
     * ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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
     * �ݹ鷴ת
     * ʱ�临�ӶȺͿռ临�Ӷȶ�ΪO(1)
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

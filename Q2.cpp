//
// Created by ��һ�� on 2020/3/18.
// Q2���������
//

#include "util.h"

class Solution {
public:
    /**
     * ����1:����ʵ�ʼӷ�������ͽ�λ������ý��
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* current = head;
        bool carry = false;
        while (l1 != NULL || l2 != NULL || carry) {
            int l1_val = (l1 != NULL ? l1->val : 0);
            int l2_val = (l2 != NULL ? l2->val : 0);
            ListNode* new_node = new ListNode((l1_val + l2_val + carry) % 10);
            carry = (l1_val + l2_val + carry) >= 10;
            current->next = new_node;
            current = new_node;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        return head->next;
    }

    /**
     * ����2: ����ȡ��l1��l2��ֵ,ֱ�ӽ��мӷ�����,��ת��������
     * ���Ƕ��ڴ���,���������int�ı�ʾ��Χ�ͻᱨ��(��Ҳ��ʾ����)
     */
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *current = head;
        int l1_val = 0, l2_val = 0;
        for (int i = 1; l1 != NULL; i = i * 10, l1 = l1->next) {
            l1_val += l1->val * i;
        }
        for (int i = 1; l2 != NULL; i = i * 10, l2 = l2->next) {
            l2_val += l2->val * i;
        }
        int result_val = l1_val + l2_val;
        if (result_val == 0) {
            return new ListNode(0);
        }
        while (result_val != 0) {
            ListNode* new_node = new ListNode(result_val % 10);
            result_val = result_val / 10;
            current->next = new_node;
            current = new_node;
        }
        return head->next;
    }
};


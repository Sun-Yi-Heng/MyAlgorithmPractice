//
// Created by ��һ�� on 2020/9/19.
// Q19��ɾ������ĵ�����N���ڵ�
//

#include "util.h"

class Solution {
public:
    /**
     * �������뵽�ķ���,����ɨ��:��һ���ó���,�ڶ������ɾ��
     * ʱ�临�Ӷ�O(N),NΪ����ĳ���
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        // ����һ���սڵ�
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // ͳ��������
        ListNode* current = head;
        while (current != NULL) {
            length++;
            current = current->next;
        }
        current = dummy;
        for (int i = 0; i < length - n; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        return dummy->next;
    }

    /**
     * ����2:������ĿҪ��1�α����������,�Կռ任ʱ�� (�Լ����)
     * ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(N)
     */
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        vector<ListNode*> v;
        // ����һ���սڵ�
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* current = dummy;
        while (current != NULL) {
            v.push_back(current);
            current = current->next;
        }
        v[v.size() - 1 - n]->next = v[v.size() - 1 - n]->next->next;
        return v[0]->next;
    }

    /**
     * ����3:������ĿҪ��1�α����������,ʹ��˫ָ�뷨(https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/dong-hua-tu-jie-leetcode-di-19-hao-wen-ti-shan-chu/)
     * ����Ҫɾ��������n���ڵ�,���ǿ�������front_pointer�ƶ�n��,Ȼ��front_pointer��behind_pointer��ͬ�ƶ�,������front_pointer�ƶ���ĩβ��ʱ��,behind_pointer������ָ���˺��ʵ�λ��
     * ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
     */
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* front_pointer = dummy;
        ListNode* back_pointer = dummy;
        for (int i = 0; i < n; i++) {
            front_pointer = front_pointer->next;
        }
        while (front_pointer->next != NULL) {
            front_pointer = front_pointer->next;
            back_pointer = back_pointer->next;
        }
        back_pointer->next = back_pointer->next->next;
        return dummy->next;
    }
};

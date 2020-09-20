//
// Created by ��һ�� on 2020/3/24.
// Q234����������
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:�����ж��ǻ����������ǲ��ÿ���ָ�뷨,����ǰ�벿�ֵ���������
     * �ú����벿�ֽ��бȽ�
     * ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
     */
    bool isPalindrome(ListNode* head) {
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        stack<ListNode*> front_part;
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            front_part.push(slow_ptr);
            slow_ptr = slow_ptr->next;
        }
        if (fast_ptr != NULL) {
            slow_ptr = slow_ptr->next;
        }

        while (front_part.size() != 0) {
            if (slow_ptr->val != front_part.top()->val) {
                return false;
            }
            front_part.pop();
            slow_ptr = slow_ptr->next;
        }
        return true;
    }
};


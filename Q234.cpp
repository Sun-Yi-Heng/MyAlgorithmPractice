//
// Created by 孙一恒 on 2020/3/24.
// Q234、回文链表
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:由于判断是回文链表我们采用快慢指针法,保存前半部分的链表内容
     * 让后与后半部分进行比较
     * 时间复杂度O(n),空间复杂度O(n)
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


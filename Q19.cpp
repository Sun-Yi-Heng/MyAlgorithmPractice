//
// Created by 孙一恒 on 2020/9/19.
// Q19、删除链表的倒数第N个节点
//

#include "util.h"

class Solution {
public:
    /**
     * 最容易想到的方法,两遍扫描:第一遍获得长度,第二遍进行删除
     * 时间复杂度O(N),N为链表的长度
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        // 引入一个空节点
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // 统计链表长度
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
     * 方法2:按照题目要求1次遍历完成任务,以空间换时间 (自己想的)
     * 时间复杂度O(N),空间复杂度O(N)
     */
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        vector<ListNode*> v;
        // 引入一个空节点
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
     * 方法3:按照题目要求1次遍历完成任务,使用双指针法(https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/dong-hua-tu-jie-leetcode-di-19-hao-wen-ti-shan-chu/)
     * 由于要删除倒数第n个节点,我们可以先让front_pointer移动n步,然后front_pointer和behind_pointer共同移动,这样当front_pointer移动到末尾的时候,behind_pointer就正好指向了合适的位置
     * 时间复杂度O(N),空间复杂度O(1)
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

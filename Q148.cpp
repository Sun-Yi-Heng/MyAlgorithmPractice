//
// Created by 孙一恒 on 2020/3/15.
// Q148、排序链表
//
#include <iostream>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 方法一:不考虑常数空间复杂度的限制,单纯是链表的归并排序
     * 时间复杂度O(nlgn),空间复杂度O(lgn)
     */
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast_ptr = head->next;
        ListNode* slow_ptr = head;
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        ListNode* right_head = slow_ptr->next;
        slow_ptr->next = NULL;
        ListNode* sorted_left = sortList(head);
        ListNode* sorted_right = sortList(right_head);
        // merge
        ListNode* empty_head = new ListNode(-1);
        ListNode* current_tail = empty_head;
        while (sorted_left != NULL && sorted_right != NULL) {
            if (sorted_left->val < sorted_right->val) {
                current_tail->next = sorted_left;
                sorted_left = sorted_left->next;
            } else {
                current_tail->next = sorted_right;
                sorted_right = sorted_right->next;
            }
            current_tail = current_tail->next;
        }
        current_tail->next = sorted_left != NULL ? sorted_left : sorted_right;
        return empty_head->next;
    }

    struct MergeResult {
        ListNode* head;
        ListNode* tail;
        MergeResult(ListNode* head, ListNode* tail): head(head), tail(tail){}
    };

    /**
     * 方法二:直接进行自底向上的归并排序,利用迭代,依次合并每组相邻长度为1的链表、相邻长度为2的链表...直至完全合并
     * 代码细节比较多,写了一个多小时...
     */
    ListNode* sortList1(ListNode* head) {
        // 特殊情况直接返回
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 一次遍历获得链表的长度
        int length = 0;
        ListNode* current = head;
        while (current != NULL) {
            current = current->next;
            length++;
        }
        ListNode* empty_head = new ListNode(-1);
        empty_head->next = head;
        // merge_length代表了当前每相邻的两个长度为merge_length的链表进行归并排序
        for (int merge_length = 1; merge_length < length; merge_length = merge_length * 2) {
            MergeResult* previous_result = new MergeResult(empty_head, empty_head);
            current = empty_head->next;
            bool flag = true;
            while (flag) {
                // 首先要判断剩余待处理的链表项长度,如果够长,正常处理;够短,不用处理
                ListNode* left = current;
                // 将指针移动到right的前一个位置,因为我们要先断链,在合并
                for (int i = 0; i < merge_length - 1; i++) {
                    // 这里如果current为NULL(剩余长度不足1个merge_length),则无需merge,当前merge_length的工作已经全部完成
                    if (current == NULL) {
                        break;
                    }
                    current = current->next;
                }
                if (current == NULL) {
                    // 不要忘记将前一步断掉的链表连接上
                    previous_result->tail->next = left;
                    break;
                }
                ListNode* right = current->next;
                current->next = NULL; // 断链
                // 同理,我们当前合并的第二部分的后边也要断链
                current = right;
                for (int i = 0; i < merge_length - 1; i++) {
                    // 剩余长度介于1~2个merge_length,则完成本次merge后,当前merge_length的工作全部完成
                    if (current == NULL) {
                        break;
                    }
                    current = current->next;
                }
                ListNode* next_part = NULL;
                if (current != NULL) {
                    next_part = current->next; // 记录下要合并的下一部分
                    current->next = NULL; // 断链
                } else {
                    flag = false;
                }
                MergeResult* current_result = merge(left, right);
                // 链接前一部分和后一部分
                previous_result->tail->next = current_result->head;
                previous_result = current_result;
                current = next_part;
            }
        }
        return empty_head->next;
    }

    // 合并两个有序链表,并返回合并后链表的头部
    MergeResult *merge(ListNode *left, ListNode *right) {
        ListNode *empty_head = new ListNode(-1);
        ListNode *current_tail = empty_head;
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                current_tail->next = left;
                left = left->next;
            } else {
                current_tail->next = right;
                right = right->next;
            }
            current_tail = current_tail->next;
        }
        current_tail->next = (left != NULL) ? left : right;
        while (current_tail->next != NULL) {
            current_tail = current_tail->next;
        }
        MergeResult *result = new MergeResult(empty_head->next, current_tail);
        return result;
    }
};


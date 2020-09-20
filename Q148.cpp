//
// Created by ��һ�� on 2020/3/15.
// Q148����������
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
     * ����һ:�����ǳ����ռ临�Ӷȵ�����,����������Ĺ鲢����
     * ʱ�临�Ӷ�O(nlgn),�ռ临�Ӷ�O(lgn)
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
     * ������:ֱ�ӽ����Ե����ϵĹ鲢����,���õ���,���κϲ�ÿ�����ڳ���Ϊ1���������ڳ���Ϊ2������...ֱ����ȫ�ϲ�
     * ����ϸ�ڱȽ϶�,д��һ����Сʱ...
     */
    ListNode* sortList1(ListNode* head) {
        // �������ֱ�ӷ���
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // һ�α����������ĳ���
        int length = 0;
        ListNode* current = head;
        while (current != NULL) {
            current = current->next;
            length++;
        }
        ListNode* empty_head = new ListNode(-1);
        empty_head->next = head;
        // merge_length�����˵�ǰÿ���ڵ���������Ϊmerge_length��������й鲢����
        for (int merge_length = 1; merge_length < length; merge_length = merge_length * 2) {
            MergeResult* previous_result = new MergeResult(empty_head, empty_head);
            current = empty_head->next;
            bool flag = true;
            while (flag) {
                // ����Ҫ�ж�ʣ���������������,�������,��������;����,���ô���
                ListNode* left = current;
                // ��ָ���ƶ���right��ǰһ��λ��,��Ϊ����Ҫ�ȶ���,�ںϲ�
                for (int i = 0; i < merge_length - 1; i++) {
                    // �������currentΪNULL(ʣ�೤�Ȳ���1��merge_length),������merge,��ǰmerge_length�Ĺ����Ѿ�ȫ�����
                    if (current == NULL) {
                        break;
                    }
                    current = current->next;
                }
                if (current == NULL) {
                    // ��Ҫ���ǽ�ǰһ���ϵ�������������
                    previous_result->tail->next = left;
                    break;
                }
                ListNode* right = current->next;
                current->next = NULL; // ����
                // ͬ��,���ǵ�ǰ�ϲ��ĵڶ����ֵĺ��ҲҪ����
                current = right;
                for (int i = 0; i < merge_length - 1; i++) {
                    // ʣ�೤�Ƚ���1~2��merge_length,����ɱ���merge��,��ǰmerge_length�Ĺ���ȫ�����
                    if (current == NULL) {
                        break;
                    }
                    current = current->next;
                }
                ListNode* next_part = NULL;
                if (current != NULL) {
                    next_part = current->next; // ��¼��Ҫ�ϲ�����һ����
                    current->next = NULL; // ����
                } else {
                    flag = false;
                }
                MergeResult* current_result = merge(left, right);
                // ����ǰһ���ֺͺ�һ����
                previous_result->tail->next = current_result->head;
                previous_result = current_result;
                current = next_part;
            }
        }
        return empty_head->next;
    }

    // �ϲ�������������,�����غϲ��������ͷ��
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


//
// Created by ��һ�� on 2020/3/18.
// Q155����Сջ
//
#include "util.h"

/**
 * ��Сջʵ�ַ���1:�ײ��������洢,��ȡ��СԪ��ʱ,ͨ������������ɡ�
 * ����getMin()��ʱ�临�Ӷ�ΪO(n),�����������ʱ�临�ӶȾ�ΪO(1)
 */
class MinStack {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* head = new ListNode(-1);

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        ListNode *current = new ListNode(x);
        current->next = head->next;
        head->next = current;
    }

    void pop() {
        head->next = head->next->next;
    }

    int top() {
        return head->next->val;
    }

    int getMin() {
        int minVal = head->next->val;
        ListNode *current = head->next;
        while (current != NULL) {
            minVal = min(minVal, current->val);
            current = current->next;
        }
        return minVal;
    }
};


/**
 * ��Сջʵ�ַ���2:�ײ��������洢,Ϊ���ܹ���O(1)��ʱ���ڻ����СԪ��
 * ����ά����������һ�����ǰ�ջ�Ľṹ������֯�ģ���һ�����ǰ���Ԫ����С�������е�,
 * ����,push��pop��ʱ�临�Ӷȱ�ΪO(n),��getMin()��ʱ�临�Ӷ�ΪO(1)
 */
class MinStack1 {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* stack_head = new ListNode(-1);
    ListNode *ordered_head = new ListNode(-1);

    /** initialize your data structure here. */
    MinStack1() {

    }

    void push(int x) {
        ListNode *new_stack_node = new ListNode(x);
        ListNode *new_ordered_node = new ListNode(x);
        new_stack_node->next = stack_head->next;
        stack_head->next = new_stack_node;
        ListNode* previous = ordered_head;
        ListNode *current = ordered_head->next;
        while (current!= NULL && x > current->val) {
            previous = current;
            current = current->next;
        }
        new_ordered_node->next = previous->next;
        previous->next = new_ordered_node;
    }

    void pop() {
        int value = stack_head->next->val;
        stack_head->next = stack_head->next->next;
        ListNode *current = ordered_head->next;
        ListNode *previous = ordered_head;
        while (true) {
            if (current->val == value) {
                previous->next = previous->next->next;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    int top() {
        return stack_head->next->val;
    }

    int getMin() {
        return ordered_head->next->val;
    }
};


/**
 * ��Сջʵ�ַ���3:�ײ��������洢,Ϊ���ܹ���O(1)��ʱ���ڻ����СԪ��
 * ����ά����������һ�����ǰ�ջ�Ľṹ������֯�ģ���һ������ֻҪ��¼ջ����״̬�µ�ǰ��СԪ�ؼ���,�����񷽷�2��������������
 * �������в�����ʱ�临�Ӷ�ΪO(1),�ռ临�Ӷ�ΪO(n)
 */
class MinStack2 {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* stack_head = new ListNode(-1);
    ListNode *helper_head = new ListNode(-1);

    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        ListNode *new_stack_node = new ListNode(x);
        new_stack_node->next = stack_head->next;
        stack_head->next = new_stack_node;

        if (helper_head->next == NULL || x < helper_head->next->val) {
            ListNode *helper_node = new ListNode(x);
            helper_node->next = helper_head->next;
            helper_head->next = helper_node;
        } else {
            ListNode *helper_node = new ListNode(helper_head->next->val);
            helper_node->next = helper_head->next;
            helper_head->next = helper_node;
        }
    }

    void pop() {
        stack_head->next = stack_head->next->next;
        helper_head->next = helper_head->next->next;
    }

    int top() {
        return stack_head->next->val;
    }

    int getMin() {
        return helper_head->next->val;
    }
};
